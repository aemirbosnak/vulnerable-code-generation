//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define macros for ease of use
#define MAX_SPEED 100 // Maximum speed allowed on road in km/h
#define MAX_CARS 60 // Maximum number of cars allowed on road
#define MAX_LANE 2 // Maximum number of lanes on road
#define TIME_STEP 1 // Simulation time step in seconds
#define ROAD_LENGTH 1000 // Length of the road in meters
#define CAR_LENGTH 4 // Length of a single car in meters
#define MIN_CAR_SEPARATION 2 // Minimum distance between two cars in meters
#define ACCELERATION 2 // Rate of acceleration in m/s^2
#define DECELERATION 4 // Rate of deceleration in m/s^2
#define REACTION_TIME 1.5 // Time taken by driver to react to situation

// struct to represent a car on the road
typedef struct Car {
  int id; // unique identifier for each car
  int lane; // current lane on the road
  float position; // current position on the road in meters
  float speed; // current speed of car in km/h
} Car;

// Initialize a car with given values
Car *initCar(int id, int lane, float position, float speed) {
  Car *car = malloc(sizeof(Car));
  car->id = id;
  car->lane = lane;
  car->position = position;
  car->speed = speed;
  return car;
}

int main() {
  // Initialize variable to hold car data
  Car *cars[MAX_CARS];
  int numCars = 0;
  
  // Seed random number generator
  srand(time(NULL));
  
  // Initialize variables to hold simulation data
  float time = 0; // simulation time in seconds
  
  // Start simulation loop
  while (time < 3600) { // run simulation for 1 hour
    // Generate new cars at random intervals and add to road
    if (rand() % 10 == 0 && numCars < MAX_CARS) { // add new car every 10 seconds
      int lane = rand() % MAX_LANE + 1;
      float position = rand() % (ROAD_LENGTH - CAR_LENGTH);
      float speed = rand() % MAX_SPEED;
      Car *car = initCar(numCars, lane, position, speed);
      cars[numCars] = car;
      numCars++;
    }
    // Update position of each car based on speed and time step
    for (int i = 0; i < numCars; i++) {
      Car *car = cars[i];
      float prevPosition = car->position;
      car->position += (car->speed / 3.6) * TIME_STEP; // convert speed from km/h to m/s
      // Check if car has completed a lap and move to start of road again
      if (car->position >= ROAD_LENGTH) {
        car->position = car->position - ROAD_LENGTH;
      }
      // Check if car has collided with any other car and slow down or stop
      for (int j = 0; j < numCars; j++) {
        if (i != j) {
          Car *otherCar = cars[j];
          if (car->lane == otherCar->lane) {
            float separation = otherCar->position - car->position;
            if (separation < MIN_CAR_SEPARATION) {
              // Calculate time taken for car to come to stop
              float stopTime = car->speed / DECELERATION + REACTION_TIME;
              // Calculate distance travelled by other car during stop time
              float otherDistance = otherCar->speed / 3.6 * stopTime;
              if (separation - otherDistance < MIN_CAR_SEPARATION) {
                // Cars collided, bring both to halt
                car->speed = 0;
                otherCar->speed = 0;
                // Move cars slightly apart to prevent re-collision
                car->position = prevPosition + MIN_CAR_SEPARATION / 2;
                otherCar->position = otherCar->position - (MIN_CAR_SEPARATION - separation) / 2;
              }
              else {
                // Slow down car so that separation is maintained
                car->speed = (separation - MIN_CAR_SEPARATION - otherDistance) / REACTION_TIME * 3.6;
              }
            }
          }
        }
      }
      // Update speed of car based on acceleration and deceleration
      float targetSpeed = MAX_SPEED;
      for (int j = 0; j < numCars; j++) {
        if (i != j) {
          Car *otherCar = cars[j];
          if (car->lane == otherCar->lane) {
            float separation = otherCar->position - car->position;
            if (separation < MIN_CAR_SEPARATION * 3) {
              // Car is too close to other car, slow down
              targetSpeed = otherCar->speed * 0.4;
              break;
            }
          }
        }
      }
      if (car->speed < targetSpeed) {
        car->speed = fmin(car->speed + ACCELERATION * TIME_STEP, targetSpeed);
      }
      else if (car->speed > targetSpeed) {
        car->speed = fmax(car->speed - DECELERATION * TIME_STEP, targetSpeed);
      }
    }
    // Print current status of road every 30 seconds
    if (time == 0 || (int) time % 30 == 0) {
      printf("Time: %d s\n", (int) time);
      printf("Number of cars: %d\n", numCars);
      for (int i = 0; i < MAX_LANE; i++) {
        printf("Lane %d: ", i + 1);
        int count = 0;
        for (int j = 0; j < numCars; j++) {
          if (cars[j]->lane == i + 1) {
            printf("%d ", cars[j]->id);
            count++;
          }
        }
        if (count == 0) {
          printf("Empty");
        }
        printf("\n");
      }
      printf("--------------------\n");
    }
    // Increment time by time step
    time += TIME_STEP;
  }
  // Free memory used for cars
  for (int i = 0; i < numCars; i++) {
    free(cars[i]);
  }
  return 0;
}