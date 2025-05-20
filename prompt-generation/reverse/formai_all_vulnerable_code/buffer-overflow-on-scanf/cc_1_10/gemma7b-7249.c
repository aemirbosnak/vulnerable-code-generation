//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store fitness tracker data
typedef struct FitnessTrackerData {
  int stepsTaken;
  int caloriesBurned;
  char activityType;
} FitnessTrackerData;

// Function to calculate the number of calories burned
int calculateCalories(int stepsTaken) {
  int caloriesBurned = (stepsTaken / 100) * 10;
  return caloriesBurned;
}

// Function to store fitness tracker data
void storeFitnessTrackerData(FitnessTrackerData data) {
  FILE *fp = fopen("fitness_tracker_data.txt", "a");
  fprintf(fp, "%d, %d, %c\n", data.stepsTaken, data.caloriesBurned, data.activityType);
  fclose(fp);
}

// Main function
int main() {
  // Create a fitness tracker data structure
  FitnessTrackerData data;

  // Get the user's input
  printf("Enter the number of steps taken: ");
  scanf("%d", &data.stepsTaken);

  // Get the user's activity type
  printf("Enter the activity type (e.g. walking, running): ");
  scanf("%s", &data.activityType);

  // Calculate the number of calories burned
  data.caloriesBurned = calculateCalories(data.stepsTaken);

  // Store the fitness tracker data
  storeFitnessTrackerData(data);

  // Print the fitness tracker data
  printf("Steps taken: %d\n", data.stepsTaken);
  printf("Calories burned: %d\n", data.caloriesBurned);
  printf("Activity type: %s\n", data.activityType);

  return 0;
}