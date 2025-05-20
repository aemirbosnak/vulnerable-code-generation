//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: accurate
#include <stdio.h>

int main() {
  // Declare variables to store user input
  int age, weight, height;
  char gender;

  // Get user input for age
  printf("Enter your age in years: ");
  scanf("%d", &age);

  // Get user input for weight
  printf("Enter your weight in kilograms: ");
  scanf("%d", &weight);

  // Get user input for height
  printf("Enter your height in centimeters: ");
  scanf("%d", &height);

  // Get user input for gender
  printf("Enter your gender (M or F): ");
  scanf(" %c", &gender);

  // Calculate BMI
  float height_in_m = height/100.0;
  float bmi = weight/(height_in_m*height_in_m);

  // Output BMI
  printf("Your BMI is: %0.2f\n", bmi);

  // Calculate BMR
  float bmr;
  if (gender == 'M') {
      bmr = 88.362 + (13.397*weight) + (4.799*height) - (5.677*age);
  } else if (gender == 'F') {
      bmr = 447.593 + (9.247*weight) + (3.098*height) - (4.330*age);
  } else {
      printf("Invalid gender input.\n");
      return 1;
  }

  // Output BMR
  printf("Your BMR is: %0.2f\n", bmr);

  // Calculate daily calorie needs based on activity level
  float activity_level;
  printf("Enter your activity level (1.2 for sedentary, 1.375 for light activity, 1.55 for moderate activity, 1.725 for very active, 1.9 for extra active): ");
  scanf("%f", &activity_level);

  float daily_calories = bmr * activity_level;

  // Output daily calorie needs
  printf("Your daily calorie needs are: %0.2f\n", daily_calories);

  return 0;
}