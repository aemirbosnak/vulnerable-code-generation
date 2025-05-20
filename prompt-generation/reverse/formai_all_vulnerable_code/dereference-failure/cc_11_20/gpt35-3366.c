//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int roadLength = 10;
  int* road = (int*)malloc(roadLength * sizeof(int));    // Creating an array to represent the road
  srand(time(NULL));                                    // Setting the random seed

  for(int i = 0; i < roadLength; i++) {                  // Initializing the road with random values (0 or 1)
    road[i] = rand() % 2;
  }

  printf("Initial road state: ");                          // Printing the initial road state
  for(int i = 0; i < roadLength; i++) {
    printf("%d ", road[i]);
  }
  printf("\n");

  int speedLimit = 5;                                      // Setting a speed limit
  int carsOnRoad = 0;                                      // Keeping track of the number of cars on the road
  int timeLimit = 20;                                      // Setting a time limit for the simulation

  for(int i = 0; i < timeLimit; i++) {                        // Main simulation loop
    int carsMoved = 0;                                        // Counter for the number of cars that moved in this iteration
    for(int j = 0; j < roadLength; j++) {
      if(road[j] == 1) {                                      // Checking if there's a car on this segment
        carsOnRoad++;

        int speed = rand() % speedLimit;                       // Randomly assigning a speed to the car
        if(speed > 0) {                                          // If the speed is greater than 0, the car tries to move forward
          int newPosition = j + speed;                             // Calculating the new position of the car
          if(newPosition >= roadLength) {                            // If the new position is greater than or equal to the length of the road, the car has reached the end of the road
            road[j] = 0;
            carsOnRoad--;
            carsMoved++;
          } else {                                                    // Otherwise, the car tries to move forward
            int carAhead = 0;
            for(int k = j + 1; k <= newPosition; k++) {
              if(road[k] == 1) {
                carAhead = 1;                                             // Checking if there's a car ahead of this car
                break;
              }
            }
            if(carAhead == 0) {                                         // If there's no car ahead, the car moves forward
              road[j] = 0;
              road[newPosition] = 1;
              carsMoved++;
            }
          }
        }
      }
    }

    if(carsMoved == 0) {                                        // If no cars moved in this iteration, the simulation ends
      break;
    }

    printf("Road state after iteration %d: ", i+1);              // Printing the current road state
    for(int j = 0; j < roadLength; j++) {
      printf("%d ", road[j]);
    }
    printf("\n");
  }

  printf("Simulation ended after %d iterations. %d cars traveled on the road.\n", timeLimit, carsOnRoad);    // Printing the final statistics

  free(road);                        // Freeing the memory used by the road array

  return 0;
}