//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: energetic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[20];
  int age;
  double height;
  double weight;
  double bmi;
  int steps;
  int calories;
  int distance;
  time_t timestamp;
} FitnessRecord;

void printWelcomeMessage() {
  printf("Welcome to the FitTrack Fitness Tracker!\n");
  printf("Let's get you moving and feeling your best.\n");
}

void getUserInfo(FitnessRecord *record) {
  printf("What's your name, champ?\n");
  scanf("%s", record->name);
  printf("Age is just a number, right? How old are you?\n");
  scanf("%d", &record->age);
  printf("Let's see how tall you are, in meters please.\n");
  scanf("%lf", &record->height);
  printf("And finally, how much do you weigh, in kilograms?\n");
  scanf("%lf", &record->weight);
}

void calculateBmi(FitnessRecord *record) {
  record->bmi = record->weight / (record->height * record->height);
}

void startTracking(FitnessRecord *record) {
  printf("Let's start tracking your progress!\n");
  time(&record->timestamp);
  record->steps = 0;
  record->calories = 0;
  record->distance = 0;
  printf("Hit enter to stop tracking.\n");
  getchar();
}

void trackSteps(FitnessRecord *record) {
  while (getchar() != '\n') {
    record->steps++;
  }
}

void calculateCalories(FitnessRecord *record) {
  record->calories = record->steps * 0.05;
}

void calculateDistance(FitnessRecord *record) {
  record->distance = record->steps * 0.762;
}

void displayResults(FitnessRecord *record) {
  printf("Congratulations, %s! You rocked it!\n", record->name);
  printf("Steps: %d\n", record->steps);
  printf("Calories Burned: %d\n", record->calories);
  printf("Distance Covered: %.2f meters\n", record->distance);
  printf("BMI: %.2f\n", record->bmi);
}

int main() {
  FitnessRecord record;

  printWelcomeMessage();
  getUserInfo(&record);
  calculateBmi(&record);
  startTracking(&record);
  trackSteps(&record);
  calculateCalories(&record);
  calculateDistance(&record);
  displayResults(&record);

  return 0;
}