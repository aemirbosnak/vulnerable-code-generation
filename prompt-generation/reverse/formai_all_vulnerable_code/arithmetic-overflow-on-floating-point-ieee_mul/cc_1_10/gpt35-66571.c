//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: standalone
#include <stdio.h>
#include <stdbool.h>

int main() {
  // Initializing variables
  bool isRunning = true;
  float weight, height, bmi;
  int age, steps = 0;

  // Asking for user inputs
  printf("Welcome to the C Fitness Tracker!\n");
  printf("Please enter your age: ");
  scanf("%d", &age);
  printf("Please enter your weight in kilograms: ");
  scanf("%f", &weight);
  printf("Please enter your height in meters: ");
  scanf("%f", &height);

  // Calculating initial BMI
  bmi = weight / (height * height);

  // Starting step tracking loop
  printf("Step tracking has started!\n");
  while (isRunning) {
    printf("Enter the number of steps you took (or -1 to end): ");
    scanf("%d", &steps);
    if (steps == -1) {
      isRunning = false;
      break;
    }

    // Updating BMI and displaying feedback based on steps taken
    bmi = weight / ((height + (steps * 0.0007)) * (height + (steps * 0.0007)));

    printf("Your current steps: %d\n", steps);
    printf("Your current BMI: %.1f\n", bmi);

    if (bmi < 18.5) {
      printf("You are underweight. Consider increasing your calorie intake.\n");
    } else if (bmi >= 18.5 && bmi <= 24.9) {
      printf("You are in the healthy weight range. Keep up the good work!\n");
    } else if (bmi >= 25 && bmi <= 29.9) {
      printf("You are overweight. Consider decreasing your calorie intake and increasing your exercise.\n");
    } else {
      printf("You are obese. Consider speaking with a healthcare professional for assistance.\n");
    }
  }

  printf("Thank you for using the C Fitness Tracker!");

  return 0;
}