//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure to store fitness tracker data
typedef struct FitnessTrackerData {
  int stepsTaken;
  int caloriesBurned;
  int distanceTraveled;
  time_t timestamp;
} FitnessTrackerData;

// Function to calculate the number of steps taken
int calculateStepsTaken(int distanceTraveled) {
  return distanceTraveled * 2;
}

// Function to calculate the number of calories burned
int calculateCaloriesBurned(int stepsTaken) {
  return stepsTaken * 10;
}

// Function to calculate the distance traveled
int calculateDistanceTraveled(int stepsTaken) {
  return stepsTaken / 2;
}

int main() {
  // Create a fitness tracker data structure
  FitnessTrackerData fitnessTrackerData;

  // Initialize the fitness tracker data structure
  fitnessTrackerData.stepsTaken = 0;
  fitnessTrackerData.caloriesBurned = 0;
  fitnessTrackerData.distanceTraveled = 0;
  fitnessTrackerData.timestamp = time(NULL);

  // Get the user's input
  int distanceTraveled = 0;
  printf("Enter the distance traveled (in miles): ");
  scanf("%d", &distanceTraveled);

  // Calculate the number of steps taken
  fitnessTrackerData.stepsTaken = calculateStepsTaken(distanceTraveled);

  // Calculate the number of calories burned
  fitnessTrackerData.caloriesBurned = calculateCaloriesBurned(fitnessTrackerData.stepsTaken);

  // Calculate the distance traveled
  fitnessTrackerData.distanceTraveled = calculateDistanceTraveled(fitnessTrackerData.stepsTaken);

  // Print the fitness tracker data
  printf("Your fitness tracker data:\n");
  printf("Steps taken: %d\n", fitnessTrackerData.stepsTaken);
  printf("Calories burned: %d\n", fitnessTrackerData.caloriesBurned);
  printf("Distance traveled: %d miles\n", fitnessTrackerData.distanceTraveled);
  printf("Timestamp: %s\n", ctime(fitnessTrackerData.timestamp));

  return 0;
}