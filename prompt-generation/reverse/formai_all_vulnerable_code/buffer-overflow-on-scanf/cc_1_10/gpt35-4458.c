//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: unmistakable
#include <stdio.h>
#include <string.h>

int main() {
  int age, weight, height, workout_time, calories_burnt;
  char gender[10], activity_level[20];

  printf("Welcome to C Fitness Tracker!\n");
  printf("Please enter your age: ");
  scanf("%d", &age);

  printf("Please enter your gender (male/female): ");
  scanf("%s", gender);

  printf("Please enter your weight in pounds: ");
  scanf("%d", &weight);

  printf("Please enter your height in inches: ");
  scanf("%d", &height);

  printf("Please enter your activity level (sedentary/lightly active/moderately active/very active): ");
  scanf("%s", activity_level);

  printf("Please enter the time spent on your workout in minutes: ");
  scanf("%d", &workout_time);

  // Calculate calories burnt based on user input
  if (strcmp(activity_level, "sedentary") == 0) {
    calories_burnt = 12 * weight * (workout_time / 60.0);
  } else if (strcmp(activity_level, "lightly active") == 0) {
    calories_burnt = 15 * weight * (workout_time / 60.0);
  } else if (strcmp(activity_level, "moderately active") == 0) {
    calories_burnt = 18 * weight * (workout_time / 60.0);
  } else if (strcmp(activity_level, "very active") == 0) {
    calories_burnt = 22 * weight * (workout_time / 60.0);
  } else {
    printf("Invalid activity level entered. Please try again.\n");
    return 0;
  }

  // Display results to user
  printf("\n\n");
  printf("Results:\n");
  printf("Age: %d\n", age);
  printf("Gender: %s\n", gender);
  printf("Weight: %d lbs\n", weight);
  printf("Height: %d inches\n", height);
  printf("Activity Level: %s\n", activity_level);
  printf("Workout Time: %d minutes\n", workout_time);
  printf("Calories Burnt: %d\n", calories_burnt);

  return 0;
}