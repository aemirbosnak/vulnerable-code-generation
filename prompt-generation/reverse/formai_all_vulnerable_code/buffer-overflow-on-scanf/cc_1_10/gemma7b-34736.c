//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void fitness_tracker() {
  char name[20];
  int age, weight, height, steps_taken = 0, calories_burned = 0;
  float bmi, heart_rate;

  printf("Welcome to the Fitness Tracker, %s!\n", name);

  // Get user information
  printf("Please enter your name: ");
  scanf("%s", name);

  printf("Please enter your age: ");
  scanf("%d", &age);

  printf("Please enter your weight (in kilograms): ");
  scanf("%d", &weight);

  printf("Please enter your height (in meters): ");
  scanf("%d", &height);

  // Calculate BMI
  bmi = (weight * 70) / (height * height);

  // Calculate heart rate
  heart_rate = 220 - (age * 2);

  // Display results
  printf("\nHere are your results:**\n");
  printf("Name: %s\n", name);
  printf("Age: %d\n", age);
  printf("Weight: %d kg\n", weight);
  printf("Height: %d m\n", height);
  printf("BMI: %.2f\n", bmi);
  printf("Heart Rate: %d bpm\n", heart_rate);

  // Calculate number of steps taken and calories burned
  steps_taken = steps_taken + 1000;
  calories_burned = calories_burned + (steps_taken * 2);

  // Display number of steps taken and calories burned
  printf("\nYou have taken %d steps today.\n", steps_taken);
  printf("You have burned %d calories today.\n", calories_burned);

  // Encourage user to stay active
  printf("\nKeep up the good work, %s! Stay active and healthy!\n", name);
}

int main() {
  fitness_tracker();

  return 0;
}