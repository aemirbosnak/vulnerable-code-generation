//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct FitnessTracker {
  char name[MAX_SIZE];
  int age;
  double weight;
  double height;
  double targetHeartRate;
  double currentHeartRate;
  double distanceTraveled;
  double timeSpent;
  double caloriesBurned;
} FitnessTracker;

void initializeFitnessTracker(FitnessTracker *tracker) {
  tracker->name[0] = '\0';
  tracker->age = 0;
  tracker->weight = 0.0;
  tracker->height = 0.0;
  tracker->targetHeartRate = 0.0;
  tracker->currentHeartRate = 0.0;
  tracker->distanceTraveled = 0.0;
  tracker->timeSpent = 0.0;
  tracker->caloriesBurned = 0.0;
}

void calculateTargetHeartRate(FitnessTracker *tracker) {
  int age = tracker->age;
  double targetHeartRate = (220 - age) * 0.6;
  tracker->targetHeartRate = targetHeartRate;
}

void calculateCurrentHeartRate(FitnessTracker *tracker) {
  double currentHeartRate = (tracker->distanceTraveled * 0.062) + (tracker->timeSpent * 0.036);
  tracker->currentHeartRate = currentHeartRate;
}

void calculateCaloriesBurned(FitnessTracker *tracker) {
  double weight = tracker->weight;
  double height = tracker->height;
  double distanceTraveled = tracker->distanceTraveled;
  double timeSpent = tracker->timeSpent;
  double caloriesBurned = (weight * height) * distanceTraveled * timeSpent * 0.012;
  tracker->caloriesBurned = caloriesBurned;
}

int main() {
  FitnessTracker tracker;
  initializeFitnessTracker(&tracker);

  printf("Name: ");
  scanf("%s", tracker.name);

  printf("Age: ");
  scanf("%d", &tracker.age);

  printf("Weight: ");
  scanf("%lf", &tracker.weight);

  printf("Height: ");
  scanf("%lf", &tracker.height);

  calculateTargetHeartRate(&tracker);
  calculateCurrentHeartRate(&tracker);
  calculateCaloriesBurned(&tracker);

  printf("Target Heart Rate: %.2lf", tracker.targetHeartRate);

  printf("Current Heart Rate: %.2lf", tracker.currentHeartRate);

  printf("Calories Burned: %.2lf", tracker.caloriesBurned);

  return 0;
}