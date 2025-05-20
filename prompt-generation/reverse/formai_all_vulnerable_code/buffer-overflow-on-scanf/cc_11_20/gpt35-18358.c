//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: standalone
#include <stdio.h>

// Define constants for maximum and minimum values
#define MAX_WEIGHT 300
#define MIN_WEIGHT 20
#define MAX_HEIGHT 84
#define MIN_HEIGHT 48
#define MAX_AGE 120
#define MIN_AGE 1

int main() {
  // Define variables to store user input
  int weight, height, age;

  // Get user weight input
  printf("Enter your weight in pounds (between %d and %d):\n", MIN_WEIGHT, MAX_WEIGHT);
  scanf("%d", &weight);

  // Validate user weight input
  if (weight < MIN_WEIGHT || weight > MAX_WEIGHT) {
    printf("Invalid weight entered.\n");
    return 1;
  }

  // Get user height input
  printf("Enter your height in inches (between %d and %d):\n", MIN_HEIGHT, MAX_HEIGHT);
  scanf("%d", &height);

  // Validate user height input
  if (height < MIN_HEIGHT || height > MAX_HEIGHT) {
    printf("Invalid height entered.\n");
    return 1;
  }

  // Get user age input
  printf("Enter your age in years (between %d and %d):\n", MIN_AGE, MAX_AGE);
  scanf("%d", &age);

  // Validate user age input
  if (age < MIN_AGE || age > MAX_AGE) {
    printf("Invalid age entered.\n");
    return 1;
  }

  // Calculate user BMI
  float bmi = (weight * 703) / (height * height);

  // Display user BMI with two decimal places
  printf("Your BMI is %.2f\n", bmi);

  // Determine user BMI category based on calculated BMI
  if (bmi < 18.5) {
    printf("Underweight\n");
  } else if (bmi >= 18.5 && bmi < 25) {
    printf("Normal\n");
  } else if (bmi >= 25 && bmi < 30) {
    printf("Overweight\n");
  } else {
    printf("Obese\n");
  }

  // Calculate user max heart rate
  int max_heart_rate = 220 - age;

  // Calculate user target heartrate range
  int target_hr_min = max_heart_rate * 0.6;
  int target_hr_max = max_heart_rate * 0.8;

  // Display user max heart rate and target heartrate range
  printf("Your max heart rate is %d beats per minute\n", max_heart_rate);
  printf("Your target heart rate range is between %d and %d beats per minute\n", target_hr_min, target_hr_max);

  return 0;
}