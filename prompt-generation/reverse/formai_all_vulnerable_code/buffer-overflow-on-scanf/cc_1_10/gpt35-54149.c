//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: future-proof
#include <stdio.h>

struct FitnessTracker {
  char name[20];
  int age;
  float weight;
  float height;
  int stepCount;
  float caloriesBurned;
};

void main() {
  struct FitnessTracker user;

  printf("Welcome to FitnessTracker!\n");

  printf("Please enter your name: ");
  scanf("%s", user.name);

  printf("Please enter your age: ");
  scanf("%d", &user.age);

  printf("Please enter your weight (in kg): ");
  scanf("%f", &user.weight);

  printf("Please enter your height (in meters): ");
  scanf("%f", &user.height);

  printf("Please enter your initial step count: ");
  scanf("%d", &user.stepCount);

  printf("Calculating your initial calories burned...\n");

  // Formula to calculate calories burned based on user's weight, height, and step count
  user.caloriesBurned = (0.57 * user.weight) + (0.415 * user.height) + (0.19 * user.stepCount);

  printf("\nInitial FitnessTracker data:");

  printf("\nName: %s", user.name);
  printf("\nAge: %d", user.age);
  printf("\nWeight: %.2f kg", user.weight);
  printf("\nHeight: %.2f meters", user.height);
  printf("\nStep Count: %d", user.stepCount);
  printf("\nCalories Burned: %.2f", user.caloriesBurned);

  printf("\n\nFitnessTracker Menu:");
  printf("\n1. Record steps taken");
  printf("\n2. View daily overview");

  int choice;
  printf("\n\nPlease choose an option (1 or 2): ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("\nPlease enter the number of steps taken today: ");
      int steps;
      scanf("%d", &steps);

      // Update step count and calculate new calories burned
      user.stepCount += steps;
      user.caloriesBurned = (0.57 * user.weight) + (0.415 * user.height) + (0.19 * user.stepCount);

      printf("\nSteps recorded successfully!");
      printf("\nCalories burned today: %.2f", user.caloriesBurned);
      break;

    case 2:
      printf("\nFitnessTracker daily overview for %s:", user.name);
      printf("\nTotal Steps Taken: %d", user.stepCount);
      printf("\nCalories Burned Today: %.2f", user.caloriesBurned);
      break;

    default:
      printf("\nInvalid choice! Please choose 1 or 2.");
      break;
  }
}