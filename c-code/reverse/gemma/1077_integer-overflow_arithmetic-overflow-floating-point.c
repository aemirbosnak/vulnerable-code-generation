#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <math.h>

int main() {
  float weight, height, age, activity_level;
  float bmi, daily_calorie_needs;

  printf("Enter your weight (kg): ");
  scanf("%f", &weight);

  printf("Enter your height (cm): ");
  scanf("%f", &height);

  printf("Enter your age (years): ");
  scanf("%f", &age);

  printf("Enter your activity level (1-5): ");
  scanf("%f", &activity_level);

  bmi = (weight * 22.0) / (height / 100) * height / 100;

  daily_calorie_needs = 10 * bmi + 6.25 * weight + 5 * age - 161.22 * activity_level;

  printf("Your BMI is: %.2f\n", bmi);
  printf("Your daily calorie needs are: %.2f\n", daily_calorie_needs);

  return 0;
}
