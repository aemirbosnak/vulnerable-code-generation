//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of steps that can be stored
#define MAX_STEPS 1000

// Define the structure of a step
typedef struct {
  time_t timestamp;  // The time the step was taken
  int count;         // The number of steps taken
} Step;

// Function to initialize the fitness tracker
void init_fitness_tracker(Step** steps, int* num_steps) {
  *steps = malloc(MAX_STEPS * sizeof(Step));
  *num_steps = 0;
}

// Function to add a step to the fitness tracker
void add_step(Step* steps, int* num_steps, time_t timestamp, int count) {
  if (*num_steps < MAX_STEPS) {
    steps[*num_steps].timestamp = timestamp;
    steps[*num_steps].count = count;
    (*num_steps)++;
  }
}

// Function to print the fitness tracker data
void print_fitness_tracker(Step* steps, int num_steps) {
  for (int i = 0; i < num_steps; i++) {
    printf("%ld: %d steps\n", steps[i].timestamp, steps[i].count);
  }
}

// Main function
int main() {
  // Initialize the fitness tracker
  Step* steps;
  int num_steps;
  init_fitness_tracker(&steps, &num_steps);

  // Add some steps to the fitness tracker
  add_step(steps, &num_steps, time(NULL), 100);
  add_step(steps, &num_steps, time(NULL) + 3600, 200);
  add_step(steps, &num_steps, time(NULL) + 7200, 300);

  // Print the fitness tracker data
  print_fitness_tracker(steps, num_steps);

  // Free the memory allocated for the fitness tracker
  free(steps);

  return 0;
}