//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct FitTrackerData {
  char name[20];
  int age;
  double height;
  double weight;
  double heartRate;
  double stepsTaken;
  double distanceTraveled;
  time_t timestamp;
} FitTrackerData;

int main() {
  FitTrackerData trackerData;

  // Initialize the data structure
  trackerData.name[0] = '\0';
  trackerData.age = -1;
  trackerData.height = -1.0;
  trackerData.weight = -1.0;
  trackerData.heartRate = -1.0;
  trackerData.stepsTaken = -1;
  trackerData.distanceTraveled = -1.0;
  trackerData.timestamp = time(NULL);

  // Get the user's name, age, height, weight, and heart rate
  printf("Enter your name: ");
  scanf("%s", trackerData.name);

  printf("Enter your age: ");
  scanf("%d", &trackerData.age);

  printf("Enter your height (in meters): ");
  scanf("%lf", &trackerData.height);

  printf("Enter your weight (in kilograms): ");
  scanf("%lf", &trackerData.weight);

  printf("Enter your heart rate: ");
  scanf("%lf", &trackerData.heartRate);

  // Calculate the user's BMI and resting heart rate
  double bmi = (trackerData.weight * 70.0) / (trackerData.height * trackerData.height);
  int restingHeartRate = (int) (220 - (1.05 * trackerData.age) - (0.676 * bmi));

  // Display the user's data
  printf("\nName: %s", trackerData.name);
  printf("\nAge: %d", trackerData.age);
  printf("\nHeight: %.2f meters", trackerData.height);
  printf("\nWeight: %.2f kilograms", trackerData.weight);
  printf("\nHeart Rate: %.2f bpm", trackerData.heartRate);
  printf("\nBMI: %.2f", bmi);
  printf("\nResting Heart Rate: %d bpm", restingHeartRate);

  return 0;
}