//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: multivariable
#include <stdio.h>

// function to calculate BMI
double calculateBMI(double weight, double height) {
  double bmi = weight / (height * height);
  return bmi;
}

// function to calculate BMR
double calculateBMR(double weight, double height, int age, char gender) {
  double bmr;

  if (gender == 'M') {
    bmr = 66 + (6.23 * weight) + (12.7 * height) - (6.8 * age);
  } else if (gender == 'F') {
    bmr = 655 + (4.35 * weight) + (4.7 * height) - (4.7 * age);
  }

  return bmr;
}

int main() {
  // input variables
  double weight, height;
  int age;
  char gender;

  // get user inputs
  printf("Enter your weight in kilograms: ");
  scanf("%lf", &weight);

  printf("Enter your height in meters: ");
  scanf("%lf", &height);

  printf("Enter your age in years: ");
  scanf("%d", &age);

  printf("Enter your gender (M/F): ");
  scanf(" %c", &gender);

  // calculate BMI and BMR
  double bmi = calculateBMI(weight, height);
  double bmr = calculateBMR(weight, height, age, gender);

  // print results
  printf("\nYour BMI is: %.2f\n", bmi);
  printf("Your BMR is: %.2f\n", bmr);

  // determine fitness level based on BMI
  if (bmi < 18.5) {
    printf("You are underweight.\n");
  } else if (bmi >= 18.5 && bmi <= 24.9) {
    printf("You are normal weight.\n");
  } else if (bmi >= 25 && bmi <= 29.9) {
    printf("You are overweight.\n");
  } else {
    printf("You are obese.\n");
  }

  return 0;
}