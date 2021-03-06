/**
 * @file bus_factory.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include <vector>
#include <random>
#include <ctime>

#include "src/bus.h"
#include "src/bus_factory.h"

int BusFactory::state_ = 0;

Bus* BusFactory::generate(std::string name, Route * out,
    Route * in, double speed) {

      time_t theTime = time(NULL);
      struct tm *aTime = localtime(&theTime);
      int currentHour = aTime->tm_hour;

      // 6am or later but before 8 am
      // strategy 1: Small, Regular, etc.
      if (currentHour > 6 && currentHour < 8) {
        if (state_ == 0) {
          std::cout << "Time: " << currentHour
           << ", Strategy 1, Small Bus" << std::endl;
          state_++;
          state_ = state_%2;
          return new SmallBus (name, out, in, speed);

        } else {
          std::cout << "Time: " << currentHour
            << ", Strategy 1, Regular Bus Generated" << std::endl;
          state_++;
          state_ = state_%2;
          return new RegularBus (name, out, in, speed);
        }

      } else if (currentHour > 8 && currentHour < 15) {
        // 8am or later but before 3pm
        // strategy 2: Regular, Large, etc.
        if (state_ == 0) {
          std::cout << "Time: " << currentHour
           << ", Strategy 2, Regular Bus Generated" << std::endl;
          state_++;
          state_ = state_%2;
          return new RegularBus (name, out, in, speed);

        } else {
          std::cout << "Time: " << currentHour
           << ", Strategy 2, Large Bus Generated" << std::endl;
          state_++;
          state_ = state_%2;
          return new LargeBus (name, out, in, speed);
        }

      } else if (currentHour > 15 && currentHour < 20) {
        // 3pm or later but before 8pm
        // strategy 3: Small, Regular, Large, etc.
        if (state_ == 0) {
          std::cout << "Time: " << currentHour
           << ", Strategy 3, Small Bus Generated" << std::endl;
          state_++;
          state_ = state_%3;
          return new SmallBus (name, out, in, speed);

        } else if (state_ == 1) {
          std::cout << "Time: " << currentHour
           << ", Strategy 3, Regular Bus Generated" << std::endl;
          state_++;
          state_ = state_%3;
          return new RegularBus (name, out, in, speed);

        } else {
          std::cout << "Time: " << currentHour
           << ", Strategy 3, Large Bus Generated" << std::endl;
          state_++;
          state_ = state_%3;
          return new LargeBus (name, out, in, speed);
        }
      } else {
        // Strategy Other: Small bus 
        std::cout << "Time: " << currentHour
         << ", Strategy OTHER, Small Bus Generated" << std::endl;
        return new SmallBus (name, out, in, speed);
      }

/*
 * Old Bus Factory code to randomly
 * generate busses from vis_sim integer
 * called busType
 */
/*

    Bus* busPtr = NULL;
    switch (busType) {
      // Small Bus
      case 1:
        busPtr = new SmallBus (name, out, in, speed);
        break;
      // Regular Bus
      case 2:
        busPtr = new RegularBus (name, out, in, speed);
        break;
      // Large Bus
      case 3:
        busPtr = new LargeBus (name, out, in, speed);
        break;

      // Fail Case
      default:
        std::cout << "Error: bus_type (random int) not recognized" << std::endl;
        break;
    }
    return busPtr;
*/
}
