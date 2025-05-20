//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRACKING_POINTS 100

typedef struct {
  char name[20];
  int age;
  double height;
  double weight;
  double heartRate;
  double stepsTaken;
  double distanceTraveled;
  double caloriesBurned;
  double trainingIntensity;
  double sleepQuality;
} FitnessTrackerData;

FitnessTrackerData fitnessTrackerData[MAX_TRACKING_POINTS];

int main() {
  // Initialization
  for (int i = 0; i < MAX_TRACKING_POINTS; i++) {
    fitnessTrackerData[i].name[0] = '\0';
    fitnessTrackerData[i].age = 0;
    fitnessTrackerData[i].height = 0.0;
    fitnessTrackerData[i].weight = 0.0;
    fitnessTrackerData[i].heartRate = 0.0;
    fitnessTrackerData[i].stepsTaken = 0.0;
    fitnessTrackerData[i].distanceTraveled = 0.0;
    fitnessTrackerData[i].caloriesBurned = 0.0;
    fitnessTrackerData[i].trainingIntensity = 0.0;
    fitnessTrackerData[i].sleepQuality = 0.0;
  }

  // Data Collection
  FitnessTrackerData currentData;
  printf("Enter your name: ");
  scanf("%s", currentData.name);
  printf("Enter your age: ");
  scanf("%d", &currentData.age);
  printf("Enter your height (in meters): ");
  scanf("%lf", &currentData.height);
  printf("Enter your weight (in kilograms): ");
  scanf("%lf", &currentData.weight);
  printf("Enter your heart rate: ");
  scanf("%lf", &currentData.heartRate);
  printf("Enter the number of steps taken: ");
  scanf("%lf", &currentData.stepsTaken);
  printf("Enter the distance traveled (in kilometers): ");
  scanf("%lf", &currentData.distanceTraveled);
  printf("Enter the number of calories burned: ");
  scanf("%lf", &currentData.caloriesBurned);
  printf("Enter your training intensity (1-10): ");
  scanf("%lf", &currentData.trainingIntensity);
  printf("Enter your sleep quality (1-10): ");
  scanf("%lf", &currentData.sleepQuality);

  // Data Storage
  int index = 0;
  fitnessTrackerData[index] = currentData;
  index++;

  // Data Display
  printf("Name: %s\n", fitnessTrackerData[0].name);
  printf("Age: %d\n", fitnessTrackerData[0].age);
  printf("Height: %.2lf meters\n", fitnessTrackerData[0].height);
  printf("Weight: %.2lf kilograms\n", fitnessTrackerData[0].weight);
  printf("Heart Rate: %.2lf\n", fitnessTrackerData[0].heartRate);
  printf("Steps Taken: %.2lf\n", fitnessTrackerData[0].stepsTaken);
  printf("Distance Traveled: %.2lf kilometers\n", fitnessTrackerData[0].distanceTraveled);
  printf("Calories Burned: %.2lf\n", fitnessTrackerData[0].caloriesBurned);
  printf("Training Intensity: %.2lf\n", fitnessTrackerData[0].trainingIntensity);
  printf("Sleep Quality: %.2lf\n", fitnessTrackerData[0].sleepQuality);

  return 0;
}