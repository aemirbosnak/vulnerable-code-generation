#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  float weight, height, age, activity_level;
  float bmi, recommended_calories;

  printf("Enter your weight (kg): ");
  scanf("%f", &weight);

  printf("Enter your height (cm): ");
  scanf("%f", &height);

  printf("Enter your age (years): ");
  scanf("%f", &age);

  printf("Enter your self-reported activity level (low, moderate, high): ");
  scanf("%s", activity_level);

  bmi = (weight * 22.0) / (height / 100) * height;
  recommended_calories = 10 * bmi + 6.25 * weight - 5 * age + activity_level * 1.2;

  printf("Your BMI is: %.2f\n", bmi);
  printf("Your recommended daily calorie burn is: %.2f\n", recommended_calories);

  return 0;
}
