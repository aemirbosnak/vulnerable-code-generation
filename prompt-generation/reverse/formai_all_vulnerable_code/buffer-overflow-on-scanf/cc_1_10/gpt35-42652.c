//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: puzzling
#include <stdio.h>
#include <math.h>

// Define the maximum number of days to track fitness
#define MAX_DAYS 7

// Define the maximum number of exercises to track
#define MAX_EXERCISES 5

/**
 * The main function runs the fitness tracker program.
 */
int main() {
  int daysCompleted = 0;
  int numExercises = 0;
  char exerciseNames[MAX_EXERCISES][25];
  int exerciseMinutes[MAX_EXERCISES][MAX_DAYS];

  // Welcome the user to the fitness tracker
  printf("\nWelcome to the Fitness Tracker!\n\n");

  // Prompt the user for the number of exercises
  printf("How many exercises would you like to track? ");
  scanf("%d", &numExercises);

  // Prompt the user for the exercise names
  printf("\nPlease enter the names of each exercise:\n");
  for (int i = 0; i < numExercises; i++) {
    printf("Exercise %d: ", i + 1);
    scanf("%s", exerciseNames[i]);
  }

  // Prompt the user for the minutes spent on each exercise for each day
  printf("\nPlease enter the minutes spent on each exercise for each day:\n");
  for (int day = 1; day <= MAX_DAYS; day++) {
    printf("Day %d:\n", day);
    for (int exercise = 0; exercise < numExercises; exercise++) {
      printf("%s: ", exerciseNames[exercise]);
      scanf("%d", &exerciseMinutes[exercise][day-1]);
    }
    daysCompleted++;
    printf("\n");
  }

  // Print the results summary for the fitness tracker
  printf("\n\nResults Summary:\n\n");
  printf("Days Tracked: %d/%d\n\n", daysCompleted, MAX_DAYS);

  // Print the total minutes spent on each exercise for the week
  printf("Minutes Spent on Each Exercise:\n");
  for (int exercise = 0; exercise < numExercises; exercise++) {
    int totalMinutes = 0;
    for (int day = 0; day < MAX_DAYS; day++) {
      totalMinutes += exerciseMinutes[exercise][day];
    }
    printf("%s: %d minutes\n", exerciseNames[exercise], totalMinutes);
  }
  printf("\n");

  // Calculate the average minutes per day for each exercise
  printf("Average Minutes per Day for Each Exercise:\n");
  for (int exercise = 0; exercise < numExercises; exercise++) {
    int totalMinutes = 0;
    for (int day = 0; day < MAX_DAYS; day++) {
      totalMinutes += exerciseMinutes[exercise][day];
    }
    int averageMinutes = round((float)totalMinutes / daysCompleted);
    printf("%s: %d minutes\n", exerciseNames[exercise], averageMinutes);
  }
  printf("\n");

  // Calculate the total minutes spent on all exercises for the week
  int totalMinutes = 0;
  for (int exercise = 0; exercise < numExercises; exercise++) {
    for (int day = 0; day < MAX_DAYS; day++) {
      totalMinutes += exerciseMinutes[exercise][day];
    }
  }

  // Print the total minutes spent on all exercises for the week
  printf("Total Minutes Spent on All Exercises: %d minutes\n\n", totalMinutes);

  // Exit the program
  return 0;
}