//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAX_STEPS 10000
#define MAX_DISTANCE 1000
#define MAX_CALORIES 10000

// Define the structure for the fitness data
typedef struct {
  int steps;
  float distance;
  int calories;
} fitness_data;

// Function to initialize the fitness data
void init_fitness_data(fitness_data* data) {
  data->steps = 0;
  data->distance = 0;
  data->calories = 0;
}

// Function to calculate the distance based on the number of steps
float calculate_distance(int steps) {
  float distance = 0;
  if (steps > 0) {
    distance = (float)steps * 0.1;
  }
  return distance;
}

// Function to calculate the calories burned based on the distance
int calculate_calories(float distance) {
  int calories = 0;
  if (distance > 0) {
    calories = (int)(distance * 10);
  }
  return calories;
}

// Function to add a step to the fitness data
void add_step(fitness_data* data) {
  data->steps++;
  data->distance += calculate_distance(data->steps);
  data->calories += calculate_calories(data->distance);
}

// Function to print the fitness data
void print_fitness_data(fitness_data* data) {
  printf("Steps: %d\n", data->steps);
  printf("Distance: %.2f km\n", data->distance);
  printf("Calories burned: %d\n", data->calories);
}

int main() {
  // Initialize the fitness data
  fitness_data data;
  init_fitness_data(&data);

  // Start the fitness tracker
  printf("Starting fitness tracker...\n");
  time_t start_time = time(NULL);
  while (1) {
    // Get the current time
    time_t current_time = time(NULL);
    if (current_time - start_time > 60) {
      break;
    }
    // Add a step to the fitness data
    add_step(&data);
    // Print the fitness data every 10 steps
    if (data.steps % 10 == 0) {
      print_fitness_data(&data);
    }
  }

  // Stop the fitness tracker
  printf("Stopping fitness tracker...\n");
  return 0;
}