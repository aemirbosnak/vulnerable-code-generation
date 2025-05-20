//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of exercises
#define MAX_EXERCISES 5

// Define the maximum length of an exercise name
#define MAX_NAME_LENGTH 20

// Define a struct to hold the exercise data
typedef struct {
  char name[MAX_NAME_LENGTH];
  float calories;
  float duration;
} Exercise;

int main() {

  // Create an array to hold the exercises
  Exercise exercises[MAX_EXERCISES];

  // Ask the user to input the exercises and their information 
  for (int i = 0; i < MAX_EXERCISES; i++) {
    printf("Enter the name of exercise %d: ", i+1);
    scanf("%s", exercises[i].name);

    printf("Enter the number of calories burned during exercise %d: ", i+1);
    scanf("%f", &exercises[i].calories);

    printf("Enter the duration of exercise %d (in minutes): ", i+1);
    scanf("%f", &exercises[i].duration);

    printf("\n");
  }

  // Calculate the total calories burned and total duration
  float total_calories = 0;
  float total_duration = 0;

  for (int i = 0; i < MAX_EXERCISES; i++) {
    total_calories += exercises[i].calories;
    total_duration += exercises[i].duration;
  }

  // Print out the summary information
  printf("Exercise Summary:\n");
  printf("Total Calories Burned: %0.2f\n", total_calories);
  printf("Total Duration: %0.2f minutes\n", total_duration);

  // Determine the most and least effective exercises
  Exercise most_effective = exercises[0];
  Exercise least_effective = exercises[0];

  for (int i = 1; i < MAX_EXERCISES; i++) {
    if (exercises[i].calories > most_effective.calories) {
      most_effective = exercises[i];
    }

    if (exercises[i].calories < least_effective.calories) {
      least_effective = exercises[i];
    }
  }

  // Print out the most and least effective exercises
  printf("\n");
  printf("Most Effective Exercise:\n");
  printf("Name: %s\n", most_effective.name);
  printf("Calories Burned: %0.2f\n", most_effective.calories);
  printf("Duration: %0.2f minutes\n", most_effective.duration);

  printf("\n");
  printf("Least Effective Exercise:\n");
  printf("Name: %s\n", least_effective.name);
  printf("Calories Burned: %0.2f\n", least_effective.calories);
  printf("Duration: %0.2f minutes\n", least_effective.duration);

  return 0;
}