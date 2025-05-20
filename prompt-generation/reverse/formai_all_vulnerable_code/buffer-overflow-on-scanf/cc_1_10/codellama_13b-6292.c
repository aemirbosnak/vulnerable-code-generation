//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: dynamic
// Fitness Tracker Example Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to store user information
struct User {
  char name[50];
  int age;
  int height;
  int weight;
  int activity_level;
};

// Function to display user information
void display_user_info(struct User user) {
  printf("Name: %s\n", user.name);
  printf("Age: %d\n", user.age);
  printf("Height: %d\n", user.height);
  printf("Weight: %d\n", user.weight);
  printf("Activity Level: %d\n", user.activity_level);
}

// Function to calculate BMI
double calculate_bmi(struct User user) {
  return (user.weight / (user.height * user.height)) * 703;
}

// Function to calculate calorie intake
int calculate_calorie_intake(struct User user) {
  return 1.2 * user.weight + 1.5 * user.height - 5.5 * user.age;
}

// Function to calculate daily activity
void calculate_daily_activity(struct User user) {
  // Calculate total minutes of exercise
  int total_minutes = 0;
  switch (user.activity_level) {
    case 1: // Sedentary
      total_minutes = 120;
      break;
    case 2: // Lightly Active
      total_minutes = 150;
      break;
    case 3: // Moderately Active
      total_minutes = 180;
      break;
    case 4: // Very Active
      total_minutes = 210;
      break;
    case 5: // Extremely Active
      total_minutes = 240;
      break;
  }

  // Calculate calories burned
  int calories_burned = total_minutes * 50;

  // Calculate net calorie intake
  int net_calorie_intake = calculate_calorie_intake(user) - calories_burned;

  // Display daily activity
  printf("Daily Activity:\n");
  printf("Total Minutes of Exercise: %d\n", total_minutes);
  printf("Calories Burned: %d\n", calories_burned);
  printf("Net Calorie Intake: %d\n", net_calorie_intake);
}

int main() {
  // Get user information
  struct User user;
  printf("Enter your name: ");
  scanf("%s", user.name);
  printf("Enter your age: ");
  scanf("%d", &user.age);
  printf("Enter your height (in inches): ");
  scanf("%d", &user.height);
  printf("Enter your weight (in pounds): ");
  scanf("%d", &user.weight);
  printf("Enter your activity level (1-5): ");
  scanf("%d", &user.activity_level);

  // Display user information
  display_user_info(user);

  // Calculate BMI
  double bmi = calculate_bmi(user);
  printf("BMI: %lf\n", bmi);

  // Calculate daily activity
  calculate_daily_activity(user);

  return 0;
}