//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: light-weight
#include <stdio.h>
#include <stdbool.h>

// declare struct to store fitness information
struct FitnessInfo {
  float weight;
  float height;
  float bmi;
  int steps;
  int caloriesBurned;
};

// function to calculate BMI
float calcBMI(float weight, float height) {
  return weight / (height * height);
}

// function to calculate calories burned
int calcCalories(int steps) {
  return steps * 0.05;
}

int main() {
  // prompt user to input weight and height
  printf("Please enter your weight in kg: ");
  float weight;
  scanf("%f", &weight);

  printf("Please enter your height in m: ");
  float height;
  scanf("%f", &height);

  // create struct to store fitness information
  struct FitnessInfo userFitness = {
    weight,
    height,
    calcBMI(weight, height),
    0,
    0
  };

  // prompt user to input steps taken
  printf("Please enter the number of steps you have taken today: ");
  int steps;
  scanf("%d", &steps);

  // update struct with steps and caloriesBurned information
  userFitness.steps = steps;
  userFitness.caloriesBurned = calcCalories(steps);

  // output fitness information to user
  printf("\nFitness Tracker Information\n");
  printf("----------------------------\n");
  printf("Weight: %.1f kg\n", userFitness.weight);
  printf("Height: %.2f m\n", userFitness.height);
  printf("BMI: %.2f\n", userFitness.bmi);
  printf("Steps taken: %d\n", userFitness.steps);
  printf("Calories burned: %d\n", userFitness.caloriesBurned);

  return 0;
}