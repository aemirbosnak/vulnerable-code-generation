//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the types of activities that can be tracked.
typedef enum activity_type {
  WALKING,
  RUNNING,
  CYCLING,
  SWIMMING,
  OTHER
} activity_type;

// Define the structure of a fitness tracker entry.
typedef struct fitness_tracker_entry {
  time_t timestamp;
  activity_type activity;
  int duration;  // in minutes
  int distance;  // in meters
  int calories;  // in kcal
} fitness_tracker_entry;

// Generate a random fitness tracker entry.
fitness_tracker_entry generate_random_entry() {
  fitness_tracker_entry entry;

  // Generate a random timestamp.
  entry.timestamp = time(NULL) - rand() % (24 * 60 * 60);  // within the last 24 hours

  // Generate a random activity type.
  entry.activity = rand() % 5;

  // Generate a random duration.
  entry.duration = rand() % 60 + 1;  // between 1 and 60 minutes

  // Generate a random distance.
  entry.distance = rand() % 10000 + 1;  // between 1 and 10,000 meters

  // Generate a random number of calories burned.
  entry.calories = rand() % 500 + 1;  // between 1 and 500 kcal

  return entry;
}

// Print a fitness tracker entry.
void print_entry(fitness_tracker_entry entry) {
  printf("%s, %d, %d, %d, %d\n",
         ctime(&entry.timestamp),
         entry.activity,
         entry.duration,
         entry.distance,
         entry.calories);
}

// Main function.
int main() {
  // Generate a random fitness tracker entry.
  fitness_tracker_entry entry = generate_random_entry();

  // Print the fitness tracker entry.
  print_entry(entry);

  return 0;
}