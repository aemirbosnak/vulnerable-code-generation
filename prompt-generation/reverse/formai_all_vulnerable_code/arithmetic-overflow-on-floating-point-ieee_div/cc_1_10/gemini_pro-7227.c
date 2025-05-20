//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: systematic
#include <stdio.h>
#include <time.h>

// Define the maximum number of steps that can be recorded
#define MAX_STEPS 100000

// Define the data structure for a fitness tracker entry
typedef struct {
  time_t timestamp;
  int steps;
} fitness_tracker_entry;

// Define the fitness tracker data
fitness_tracker_entry fitness_tracker[MAX_STEPS];

// Define the current index of the fitness tracker data
int fitness_tracker_index = 0;

// Function to add a new fitness tracker entry
void add_fitness_tracker_entry(int steps) {
  // Check if the fitness tracker is full
  if (fitness_tracker_index >= MAX_STEPS) {
    printf("Error: Fitness tracker is full\n");
    return;
  }

  // Add the new entry to the fitness tracker
  fitness_tracker[fitness_tracker_index].timestamp = time(NULL);
  fitness_tracker[fitness_tracker_index].steps = steps;

  // Increment the fitness tracker index
  fitness_tracker_index++;
}

// Function to print the fitness tracker data
void print_fitness_tracker_data() {
  // Print the header
  printf("Timestamp\tSteps\n");

  // Print each entry in the fitness tracker
  for (int i = 0; i < fitness_tracker_index; i++) {
    printf("%ld\t%d\n", fitness_tracker[i].timestamp, fitness_tracker[i].steps);
  }
}

// Function to get the total number of steps recorded
int get_total_steps() {
  // Initialize the total number of steps to 0
  int total_steps = 0;

  // Add the number of steps from each entry in the fitness tracker
  for (int i = 0; i < fitness_tracker_index; i++) {
    total_steps += fitness_tracker[i].steps;
  }

  // Return the total number of steps
  return total_steps;
}

// Function to get the average number of steps per day
double get_average_steps_per_day() {
  // Get the total number of steps recorded
  int total_steps = get_total_steps();

  // Get the number of days since the first entry was recorded
  time_t first_timestamp = fitness_tracker[0].timestamp;
  time_t last_timestamp = fitness_tracker[fitness_tracker_index - 1].timestamp;
  double days = difftime(last_timestamp, first_timestamp) / (60 * 60 * 24);

  // Calculate the average number of steps per day
  double average_steps_per_day = total_steps / days;

  // Return the average number of steps per day
  return average_steps_per_day;
}

// Main function
int main() {
  // Add some sample fitness tracker entries
  add_fitness_tracker_entry(1000);
  add_fitness_tracker_entry(2000);
  add_fitness_tracker_entry(3000);

  // Print the fitness tracker data
  print_fitness_tracker_data();

  // Get the total number of steps recorded
  int total_steps = get_total_steps();
  printf("Total steps: %d\n", total_steps);

  // Get the average number of steps per day
  double average_steps_per_day = get_average_steps_per_day();
  printf("Average steps per day: %.2f\n", average_steps_per_day);

  return 0;
}