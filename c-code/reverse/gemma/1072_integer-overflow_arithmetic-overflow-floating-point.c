#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  int weight, height, age, activity_level;
  float bmi, daily_calorie_needs;

  printf("Enter your weight (in kilograms): ");
  scanf("%d", &weight);

  printf("Enter your height (in meters): ");
  scanf("%d", &height);

  printf("Enter your age (in years): ");
  scanf("%d", &age);

  printf("Enter your activity level (1 for sedentary, 2 for lightly active, 3 for moderately active, 4 for very active): ");
  scanf("%d", &activity_level);

  bmi = (weight * 22) / (height * height);

  switch (activity_level) {
    case 1:
      daily_calorie_needs = 1.2 * bmi * age * 10;
      break;
    case 2:
      daily_calorie_needs = 1.3 * bmi * age * 10;
      break;
    case 3:
      daily_calorie_needs = 1.4 * bmi * age * 10;
      break;
    case 4:
      daily_calorie_needs = 1.5 * bmi * age * 10;
      break;
  }

  printf("Your BMI is: %.2f", bmi);
  printf("\nYour daily calorie needs are: %.2f", daily_calorie_needs);

  return 0;
}
