#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int calculate_bmi(int weight, int height) {
  int bmi = (weight * 703) / (height * height);
  return bmi;
}

int calculate_daily_caloric_needs(int bmi, int activity_level) {
  int needs = (10 * bmi) + (6.25 * activity_level) + 5;
  return needs;
}

int main() {
  int weight = 0;
  int height = 0;
  int activity_level = 0;

  printf("Enter your weight (kg): ");
  scanf("%d", &weight);

  printf("Enter your height (cm): ");
  scanf("%d", &height);

  printf("Enter your activity level (1-3): ");
  scanf("%d", &activity_level);

  int bmi = calculate_bmi(weight, height);
  int needs = calculate_daily_caloric_needs(bmi, activity_level);

  printf("Your BMI is: %d\n", bmi);
  printf("Your daily caloric needs are: %d\n", needs);

  return 0;
}
