#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  float weight, height, age, activity_level;
  int bmi, recommended_calories;

  printf("Enter your weight (in kilograms): ");
  scanf("%f", &weight);

  printf("Enter your height (in meters): ");
  scanf("%f", &height);

  printf("Enter your age (in years): ");
  scanf("%d", &age);

  printf("Enter your activity level (1 for sedentary, 2 for lightly active, 3 for moderately active, 4 for very active): ");
  scanf("%d", &activity_level);

  bmi = (int) ((weight * 70 / height) * height);
  recommended_calories = (int) (10 * weight + 6.25 * height - 5 * age - activity_level * 1.2);

  printf("Your BMI is: %d\n", bmi);
  printf("Your recommended daily calorie burn is: %d\n", recommended_calories);

  return 0;
}
