//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STEPS 1000000
#define GOAL_STEPS 10000

int main() {
  // Initialize the fitness tracker.
  int steps = 0;
  int calories = 0;
  int distance = 0;
  time_t start_time = time(NULL);

  // Start the fitness tracker.
  while (steps < GOAL_STEPS) {
    // Get the current time.
    time_t current_time = time(NULL);

    // Calculate the time elapsed since the start time.
    long time_elapsed = current_time - start_time;

    // Calculate the number of steps taken in the last second.
    int steps_taken = rand() % 10;

    // Increment the total number of steps taken.
    steps += steps_taken;

    // Calculate the number of calories burned in the last second.
    int calories_burned = steps_taken * 0.05;

    // Increment the total number of calories burned.
    calories += calories_burned;

    // Calculate the distance traveled in the last second.
    int distance_traveled = steps_taken * 0.001;

    // Increment the total distance traveled.
    distance += distance_traveled;

    // Print the fitness tracker data.
    printf("Steps: %d\n", steps);
    printf("Calories: %d\n", calories);
    printf("Distance: %d\n", distance);
    printf("Time elapsed: %ld\n", time_elapsed);
  }

  // Stop the fitness tracker.
  time_t end_time = time(NULL);

  // Calculate the total time spent exercising.
  long total_time = end_time - start_time;

  // Print the fitness tracker data.
  printf("Total steps: %d\n", steps);
  printf("Total calories: %d\n", calories);
  printf("Total distance: %d\n", distance);
  printf("Total time: %ld\n", total_time);

  return 0;
}