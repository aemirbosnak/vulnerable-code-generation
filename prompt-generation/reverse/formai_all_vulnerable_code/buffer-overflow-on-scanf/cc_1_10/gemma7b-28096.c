//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: cheerful
#include <stdio.h>
#include <string.h>

// Define a structure to store fitness tracker data
typedef struct FitTrackerData {
  int stepsTaken;
  float distanceTraveled;
  int caloriesBurned;
  char workoutType;
} FitTrackerData;

// Function to calculate the number of steps taken
int calculateStepsTaken(float distanceTraveled) {
  return (int)(distanceTraveled * 1000);
}

// Function to calculate the distance traveled
float calculateDistanceTraveled(int stepsTaken) {
  return (float)stepsTaken / 1000;
}

// Function to calculate the number of calories burned
int calculateCaloriesBurned(int stepsTaken, char workoutType) {
  switch (workoutType) {
    case 'a':
      return stepsTaken * 10;
    case 'c':
      return stepsTaken * 12;
    case 't':
      return stepsTaken * 14;
    default:
      return 0;
  }
}

int main() {
  FitTrackerData fitTrackerData;

  // Get the user's input
  printf("Enter the number of steps taken: ");
  scanf("%d", &fitTrackerData.stepsTaken);

  // Get the user's input
  printf("Enter the workout type (a, c, t): ");
  scanf(" %c", &fitTrackerData.workoutType);

  // Calculate the distance traveled
  fitTrackerData.distanceTraveled = calculateDistanceTraveled(fitTrackerData.stepsTaken);

  // Calculate the number of calories burned
  fitTrackerData.caloriesBurned = calculateCaloriesBurned(fitTrackerData.stepsTaken, fitTrackerData.workoutType);

  // Display the results
  printf("Distance traveled: %.2f miles\n", fitTrackerData.distanceTraveled);
  printf("Calories burned: %d\n", fitTrackerData.caloriesBurned);

  return 0;
}