//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>

/* This program is a basic fitness tracker that allows users to enter their daily workouts and track their progress over time. */

int main() {
  int days = 0;
  float total_calories = 0;
  float total_distance = 0;
  float total_time = 0;

  printf("*** Welcome to the Happy Fitness Tracker! ***\n\n");

  printf("How many days would you like to track? ");
  scanf("%d", &days);

  for (int i = 1; i <= days; i++) {
    printf("\n**** Day %d ****\n", i);

    int minutes = 0;
    float calories = 0;
    float distance = 0;

    printf("Enter the number of minutes you worked out: ");
    scanf("%d", &minutes);

    // Calculate calories burned based on minutes worked out
    calories = minutes * 10;

    printf("Enter the distance you covered (in km): ");
    scanf("%f", &distance);

    // Add calories, distance, and time to total counters
    total_calories += calories;
    total_distance += distance;
    total_time += minutes;

    printf("\n*** Workout Summary ***\n");
    printf("Duration: %d minutes.\n", minutes);
    printf("Calories burned: %.2f.\n", calories);
    printf("Distance covered: %.2f km.\n", distance);
  }

  // Calculate average time and distance per day
  float avg_time = total_time / days;
  float avg_distance = total_distance / days;

  printf("\n*** Total Summary ***\n");
  printf("Total duration: %.2f minutes.\n", total_time);
  printf("Total calories burned: %.2f.\n", total_calories);
  printf("Total distance covered: %.2f km.\n", total_distance);
  printf("Average time per day: %.2f minutes.\n", avg_time);
  printf("Average distance per day: %.2f km.\n\n", avg_distance);

  printf("Congratulations on your progress! Keep up the great work!\n");

  return 0;
}