//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  // Declare variables
  char name[20];
  int age;
  float weight;
  int heartRate;
  char exerciseType[50];
  int duration;
  int sets;
  int reps;

  // Get user input
  printf("Enter your name: ");
  scanf("%s", name);

  printf("Enter your age: ");
  scanf("%d", &age);

  printf("Enter your weight: ");
  scanf("%f", &weight);

  printf("Enter your heart rate: ");
  scanf("%d", &heartRate);

  printf("Enter the type of exercise you did: ");
  scanf("%s", exerciseType);

  printf("Enter the duration of your exercise in minutes: ");
  scanf("%d", &duration);

  printf("Enter the number of sets: ");
  scanf("%d", &sets);

  printf("Enter the number of repetitions per set: ");
  scanf("%d", &reps);

  // Calculate total number of repetitions
  int totalReps = sets * reps;

  // Display results
  printf("\n**Fitness Tracker Report**\n");
  printf("Name: %s\n", name);
  printf("Age: %d\n", age);
  printf("Weight: %.2f kg\n", weight);
  printf("Heart Rate: %d bpm\n", heartRate);
  printf("Exercise Type: %s\n", exerciseType);
  printf("Duration: %d minutes\n", duration);
  printf("Number of Sets: %d\n", sets);
  printf("Number of Reps per Set: %d\n", reps);
  printf("Total Number of Reps: %d\n", totalReps);

  return 0;
}