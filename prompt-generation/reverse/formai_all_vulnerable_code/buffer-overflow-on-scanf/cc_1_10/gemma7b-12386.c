//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <time.h>

// Define the maximum number of steps a person can take in a day
#define MAX_STEPS 10000

// Define the maximum number of calories a person can burn in a day
#define MAX_CALORIES 2000

// Define the number of steps taken by the user today
int steps_taken = 0;

// Define the number of calories burned by the user today
int calories_burned = 0;

// Define the user's name
char user_name[20];

// Function to track steps taken
void track_steps(int num_steps) {
  steps_taken += num_steps;
  if (steps_taken > MAX_STEPS) {
    steps_taken = MAX_STEPS;
  }
}

// Function to track calories burned
void track_calories(int num_calories) {
  calories_burned += num_calories;
  if (calories_burned > MAX_CALORIES) {
    calories_burned = MAX_CALORIES;
  }
}

// Function to display the user's progress
void display_progress() {
  printf("Hello, %s!\n", user_name);
  printf("Your steps taken today: %d\n", steps_taken);
  printf("Your calories burned today: %d\n", calories_burned);
  printf("Your progress for today: %f%%\n", (double)steps_taken / MAX_STEPS * 100);
}

int main() {
  // Get the user's name
  printf("Enter your name: ");
  scanf("%s", user_name);

  // Track the user's steps and calories burned
  track_steps(2000);
  track_calories(1500);

  // Display the user's progress
  display_progress();

  return 0;
}