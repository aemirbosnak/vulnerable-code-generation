#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int weight, height, age;
  float bmi, recommended_calories;

  printf("Enter your weight (in kilograms): ");
  scanf("%d", &weight);

  printf("Enter your height (in meters): ");
  scanf("%d", &height);

  printf("Enter your age (in years): ");
  scanf("%d", &age);

  bmi = (weight * 25) / (height * height);

  if (bmi < 18.5) {
    recommended_calories = (10 * weight) + (6.25 * height) - (5 * age);
  } else if (bmi >= 18.5 && bmi < 25) {
    recommended_calories = (10 * weight) + (6.25 * height) - (5 * age) + 200;
  } else if (bmi >= 25) {
    recommended_calories = (10 * weight) + (6.25 * height) - (5 * age) + 400;
  }

  printf("Your BMI is: %.2f\n", bmi);
  printf("Your recommended daily calorie burn is: %.0f\n", recommended_calories);

  return 0;
}
