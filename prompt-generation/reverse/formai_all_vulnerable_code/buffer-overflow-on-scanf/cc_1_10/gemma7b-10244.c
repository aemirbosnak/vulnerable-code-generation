//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of steps that can be tracked
#define MAX_STEPS 10000

// Define the maximum number of calories that can be burned
#define MAX_CALORIES 2000

// Define the maximum number of minutes that can be spent exercising
#define MAX_MINUTES 60

// Struct to store fitness tracker data
typedef struct fitness_tracker_data {
  int steps_taken;
  int calories_burned;
  int minutes_spent_exercising;
} fitness_tracker_data;

// Function to track steps taken
void track_steps(fitness_tracker_data *data) {
  printf("Enter the number of steps taken: ");
  scanf("%d", &data->steps_taken);

  // Check if the number of steps taken is valid
  if (data->steps_taken < 0 || data->steps_taken > MAX_STEPS) {
    printf("Error: Invalid number of steps taken.\n");
  } else {
    data->steps_taken++;
  }
}

// Function to track calories burned
void track_calories(fitness_tracker_data *data) {
  printf("Enter the number of calories burned: ");
  scanf("%d", &data->calories_burned);

  // Check if the number of calories burned is valid
  if (data->calories_burned < 0 || data->calories_burned > MAX_CALORIES) {
    printf("Error: Invalid number of calories burned.\n");
  } else {
    data->calories_burned++;
  }
}

// Function to track minutes spent exercising
void track_minutes(fitness_tracker_data *data) {
  printf("Enter the number of minutes spent exercising: ");
  scanf("%d", &data->minutes_spent_exercising);

  // Check if the number of minutes spent exercising is valid
  if (data->minutes_spent_exercising < 0 || data->minutes_spent_exercising > MAX_MINUTES) {
    printf("Error: Invalid number of minutes spent exercising.\n");
  } else {
    data->minutes_spent_exercising++;
  }
}

// Main function
int main() {
  // Create a struct to store fitness tracker data
  fitness_tracker_data data;

  // Initialize the fitness tracker data
  data.steps_taken = 0;
  data.calories_burned = 0;
  data.minutes_spent_exercising = 0;

  // Track steps taken
  track_steps(&data);

  // Track calories burned
  track_calories(&data);

  // Track minutes spent exercising
  track_minutes(&data);

  // Print the fitness tracker data
  printf("Your fitness tracker data is:\n");
  printf("Steps taken: %d\n", data.steps_taken);
  printf("Calories burned: %d\n", data.calories_burned);
  printf("Minutes spent exercising: %d\n", data.minutes_spent_exercising);

  return 0;
}