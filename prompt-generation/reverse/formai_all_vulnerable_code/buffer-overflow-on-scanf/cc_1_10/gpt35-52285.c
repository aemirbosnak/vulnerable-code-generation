//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seeding random number generator

  int traffic_density;  // percentage of road occupied by cars
  int road_length;      // length of the road (in km)
  int sim_time;         // duration of simulation (in mins)
  int num_cars;         // number of cars on the road
  int car_speed;        // constant speed of each car (in km/h)
  int time_elapsed = 0; // elapsed time in the simulation (in mins)

  printf("Enter traffic density (percentage, 1 - 100): ");
  scanf("%d", &traffic_density);

  printf("Enter road length (in km): ");
  scanf("%d", &road_length);

  printf("Enter simulation time (in mins): ");
  scanf("%d", &sim_time);

  // Calculate number of cars on the road
  num_cars = (traffic_density * road_length) / 100;

  // Initialize the position of each car
  int car_position[num_cars];
  for (int i = 0; i < num_cars; i++) {
    car_position[i] = i * (road_length / num_cars);
  }

  // Set the constant speed for each car between 60 and 120 km/h
  car_speed = (rand() % 61) + 60;

  // Start the simulation loop
  while (time_elapsed <= sim_time) {
    printf("Time elapsed: %d min\n", time_elapsed);

    // Move each car forward by its constant speed
    for (int i = 0; i < num_cars; i++) {
      car_position[i] += car_speed;
    }

    // Print the current position of each car
    for (int i = 0; i < num_cars; i++) {
      printf("Car %d at position %d km\n", i+1, car_position[i]);
    }

    // Randomly slow down or speed up each car
    for (int i = 0; i < num_cars; i++) {
      if (rand() % 2) {
        car_speed += rand() % 11;   // speed up by 0-10 km/h
      } else {
        car_speed -= rand() % 11;   // slow down by 0-10 km/h
      }
      // Keep speed within 60-120 km/h
      if (car_speed < 60) {
        car_speed = 60;
      } else if (car_speed > 120) {
        car_speed = 120;
      }
    }

    time_elapsed++;
  }

  return 0;
}