//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the maximum number of steps that can be recorded
#define MAX_STEPS 1000000

// Define the structure of a fitness tracker entry
typedef struct {
  time_t timestamp;  // The time when the entry was recorded
  int steps;         // The number of steps taken since the last entry
} fitness_tracker_entry;

// Create a new fitness tracker
fitness_tracker_entry *create_fitness_tracker() {
  fitness_tracker_entry *tracker = malloc(sizeof(fitness_tracker_entry));
  if (tracker == NULL) {
    return NULL;
  }
  tracker->timestamp = time(NULL);
  tracker->steps = 0;
  return tracker;
}

// Add a new entry to the fitness tracker
void add_entry(fitness_tracker_entry *tracker, int steps) {
  tracker->timestamp = time(NULL);
  tracker->steps += steps;
}

// Get the total number of steps recorded by the fitness tracker
int get_total_steps(fitness_tracker_entry *tracker) {
  return tracker->steps;
}

// Get the average number of steps per day recorded by the fitness tracker
double get_average_steps_per_day(fitness_tracker_entry *tracker) {
  time_t now = time(NULL);
  double days_elapsed = difftime(now, tracker->timestamp) / (60 * 60 * 24);
  return (double)tracker->steps / days_elapsed;
}

// Print a report of the fitness tracker data
void print_report(fitness_tracker_entry *tracker) {
  printf("Fitness Tracker Report\n");
  printf("Total steps: %d\n", get_total_steps(tracker));
  printf("Average steps per day: %.2f\n", get_average_steps_per_day(tracker));
}

// Free the memory allocated for the fitness tracker
void free_fitness_tracker(fitness_tracker_entry *tracker) {
  free(tracker);
}

// Main function
int main() {
  // Create a new fitness tracker
  fitness_tracker_entry *tracker = create_fitness_tracker();
  if (tracker == NULL) {
    printf("Error: Could not create fitness tracker.\n");
    return EXIT_FAILURE;
  }

  // Add some sample entries to the fitness tracker
  add_entry(tracker, 1000);
  add_entry(tracker, 2000);
  add_entry(tracker, 3000);

  // Print a report of the fitness tracker data
  print_report(tracker);

  // Free the memory allocated for the fitness tracker
  free_fitness_tracker(tracker);

  return EXIT_SUCCESS;
}