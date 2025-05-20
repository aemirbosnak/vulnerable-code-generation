//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of steps taken
int steps = 0;

// Define the number of calories burned
int calories = 0;

// Define the time spent exercising
int time = 0;

// Function to track steps
void track_steps() {
  // Prompt the user to enter the number of steps taken
  printf("Enter the number of steps taken: ");
  scanf("%d", &steps);

  // Increment the number of steps taken
  steps++;
}

// Function to track calories
void track_calories() {
  // Prompt the user to enter the number of calories burned
  printf("Enter the number of calories burned: ");
  scanf("%d", &calories);

  // Increment the number of calories burned
  calories++;
}

// Function to track time
void track_time() {
  // Prompt the user to enter the time spent exercising
  printf("Enter the time spent exercising (in minutes): ");
  scanf("%d", &time);

  // Increment the time spent exercising
  time++;
}

// Function to display the tracking data
void display_tracking_data() {
  // Print the number of steps taken
  printf("Number of steps taken: %d\n", steps);

  // Print the number of calories burned
  printf("Number of calories burned: %d\n", calories);

  // Print the time spent exercising
  printf("Time spent exercising: %d minutes\n", time);
}

int main() {
  // Track steps, calories, and time
  track_steps();
  track_calories();
  track_time();

  // Display the tracking data
  display_tracking_data();

  return 0;
}