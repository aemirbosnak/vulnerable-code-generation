//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: Dennis Ritchie
#include <stdio.h>

// Struct to store user data
struct UserData {
  int age;
  float height;
  float weight;
};

// Function to calculate BMI
float calculate_bmi(float weight, float height) {
  return weight / (height * height);
}

// Function to determine fitness level based on BMI
char* determine_fitness_level(float bmi) {
  if (bmi < 18.5) {
    return "Underweight";
  } else if (bmi >= 18.5 && bmi < 25) {
    return "Normal weight";
  } else if (bmi >= 25 && bmi < 30) {
    return "Overweight";
  } else {
    return "Obese";
  }
}

// Main function
int main() {
  // Declare variables
  struct UserData user;
  float bmi;
  char* fitness_level;

  // Get user input
  printf("Enter your age: ");
  scanf("%d", &user.age);
  printf("Enter your height (in inches): ");
  scanf("%f", &user.height);
  printf("Enter your weight (in pounds): ");
  scanf("%f", &user.weight);

  // Calculate BMI
  bmi = calculate_bmi(user.weight, user.height);

  // Determine fitness level
  fitness_level = determine_fitness_level(bmi);

  // Print results
  printf("Your BMI is: %f\n", bmi);
  printf("Your fitness level is: %s\n", fitness_level);

  return 0;
}