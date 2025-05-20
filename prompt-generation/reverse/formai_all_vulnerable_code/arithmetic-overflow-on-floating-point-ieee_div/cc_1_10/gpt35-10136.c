//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// define struct for fitness data
struct FitnessData {
  int steps;
  double calories;
  double distance;
};

// function to input fitness data
void inputFitnessData(struct FitnessData *data) {
  printf("Enter number of steps taken: ");
  scanf("%d", &(data->steps));
  printf("Enter calories burned: ");
  scanf("%lf", &(data->calories));
  printf("Enter distance traveled (in km): ");
  scanf("%lf", &(data->distance));
}

// function to display fitness data
void displayFitnessData(struct FitnessData data) {
  printf("Steps taken: %d\n", data.steps);
  printf("Calories burned: %.2lf\n", data.calories);
  printf("Distance traveled: %.2lf km\n", data.distance);
}

// function to calculate BMI
double calculateBMI(double height, double weight) {
  return weight / (height * height);
}

int main() {
  struct FitnessData data;
  inputFitnessData(&data);
  displayFitnessData(data);

  double height, weight;
  printf("Enter height (in meters): ");
  scanf("%lf", &height);
  printf("Enter weight (in kg): ");
  scanf("%lf", &weight);

  double bmi = calculateBMI(height, weight);
  printf("Your BMI is: %.2lf\n", bmi);

  // TODO: add more features such as setting fitness goals, monitoring progress, and providing feedback to the user

  return 0;
}