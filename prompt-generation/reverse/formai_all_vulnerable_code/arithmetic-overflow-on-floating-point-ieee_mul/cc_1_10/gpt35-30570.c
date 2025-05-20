//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: genious
#include <stdio.h>

int main() {
  int weight, height, age, gender, activity_level, goal, bmr, tdee, calories_to_consume;
  float body_fat_percentage, lean_body_mass;

  // Get user inputs
  printf("Enter your weight in pounds: ");
  scanf("%d", &weight);

  printf("Enter your height in inches: ");
  scanf("%d", &height);

  printf("Enter your age in years: ");
  scanf("%d", &age);

  printf("Enter your gender (0 for female, 1 for male): ");
  scanf("%d", &gender);

  printf("Enter your body fat percentage: ");
  scanf("%f", &body_fat_percentage);

  printf("Enter your activity level (1 for sedentary, 2 for lightly active, 3 for moderately active, 4 for very active, 5 for extra active): ");
  scanf("%d", &activity_level);

  printf("Enter your goal (1 for lose weight, 2 for maintain weight, 3 for gain weight): ");
  scanf("%d", &goal);

  // Calculate lean body mass
  lean_body_mass = weight * (100 - body_fat_percentage) / 100;

  // Calculate basal metabolic rate (BMR)
  if (gender == 0) {
    // Female
    bmr = 655 + (4.35 * weight) + (4.7 * height) - (4.7 * age);
  } else {
    // Male
    bmr = 66 + (6.23 * weight) + (12.7 * height) - (6.8 * age);
  }

  // Calculate total daily energy expenditure (TDEE)
  switch (activity_level) {
    case 1:
      tdee = bmr * 1.2;
      break;
    case 2:
      tdee = bmr * 1.375;
      break;
    case 3:
      tdee = bmr * 1.55;
      break;
    case 4:
      tdee = bmr * 1.725;
      break;
    case 5:
      tdee = bmr * 1.9;
      break;
    default:
      printf("Invalid activity level!");
      return 1;
  }

  // Calculate calories to consume based on goal
  switch (goal) {
    case 1:
      calories_to_consume = tdee - 500;
      break;
    case 2:
      calories_to_consume = tdee;
      break;
    case 3:
      calories_to_consume = tdee + 500;
      break;
    default:
      printf("Invalid goal!");
      return 1;
  }

  // Output results
  printf("\nResults\n");
  printf("Lean body mass: %.2f pounds\n", lean_body_mass);
  printf("BMR: %d calories\n", bmr);
  printf("TDEE: %d calories\n", tdee);
  printf("Calories to consume: %d calories\n", calories_to_consume);

  return 0;
}