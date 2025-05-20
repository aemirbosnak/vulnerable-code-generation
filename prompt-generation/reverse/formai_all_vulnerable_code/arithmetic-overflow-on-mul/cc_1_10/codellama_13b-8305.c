//Code Llama-13B DATASET v1.0 Category: Traffic Flow Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_CARS 100
#define CAR_SPEED 50
#define INTERSECTION_DISTANCE 50

// Structure to represent a car
typedef struct {
  int id;
  int lane;
  int speed;
  int time_to_cross;
} Car;

// Function to generate a random number between min and max
int rand_range(int min, int max) {
  return min + (int)(rand() * (max - min) / (RAND_MAX + 1.0));
}

// Function to simulate a single car crossing the intersection
void simulate_car(Car *car) {
  // Generate a random speed for the car
  car->speed = rand_range(20, 60);

  // Calculate the time it takes for the car to cross the intersection
  car->time_to_cross = INTERSECTION_DISTANCE / car->speed;

  // Print the car's information
  printf("Car %d is driving in lane %d at a speed of %d km/h\n", car->id, car->lane, car->speed);

  // Wait for the car to cross the intersection
  sleep(car->time_to_cross);

  // Print the car's information again
  printf("Car %d has crossed the intersection\n", car->id);
}

// Function to simulate a traffic flow
void simulate_traffic_flow() {
  // Create an array of cars
  Car cars[NUM_CARS];

  // Initialize the cars
  for (int i = 0; i < NUM_CARS; i++) {
    cars[i].id = i;
    cars[i].lane = rand_range(1, 3);
    cars[i].speed = 0;
    cars[i].time_to_cross = 0;
  }

  // Simulate the traffic flow
  for (int i = 0; i < NUM_CARS; i++) {
    simulate_car(&cars[i]);
  }
}

int main() {
  // Set the random seed
  srand(time(NULL));

  // Simulate the traffic flow
  simulate_traffic_flow();

  return 0;
}