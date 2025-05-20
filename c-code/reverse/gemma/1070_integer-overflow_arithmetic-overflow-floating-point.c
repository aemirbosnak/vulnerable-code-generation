#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int weight, height, age;
  char activity_level;

  printf("Enter your weight (in kilograms): ");
  scanf("%d", &weight);

  printf("Enter your height (in meters): ");
  scanf("%d", &height);

  printf("Enter your age (in years): ");
  scanf("%d", &age);

  printf("Enter your activity level (A, B, C, D): ");
  scanf(" %c", &activity_level);

  int bmi = (weight * 22) / height;
  int daily_calorie_needs = 10 * weight + 6.25 * height - 5 * age + 100 * activity_level;

  printf("Your BMI is: %d", bmi);
  printf("\nYour daily calorie needs are: %d", daily_calorie_needs);

  return 0;
}
