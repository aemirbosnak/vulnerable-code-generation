//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
  char name[50];
  int age;
  float weight;
  float height;
  float current_weight;
  float calories_burned;
  int days_tracked;
};

int main() {

  // Create a new user
  struct User new_user;
  printf("Welcome to the C Fitness Tracker!\n\n");
  printf("Please enter your name: ");
  scanf("%s", &new_user.name);
  printf("Please enter your age: ");
  scanf("%d", &new_user.age);
  printf("Please enter your weight (in kilograms): ");
  scanf("%f", &new_user.weight);
  printf("Please enter your height (in meters): ");
  scanf("%f", &new_user.height);
  printf("\n");

  // Initialize user's current weight and number of days tracked
  new_user.current_weight = new_user.weight;
  new_user.days_tracked = 0;

  // Prompt user to enter number of calories burned and track weight for the next 7 days
  printf("Let's get started!\n\n");
  printf("How many calories did you burn today? ");
  scanf("%f", &new_user.calories_burned);
  printf("\n");

  // Track weight for 7 days
  for (int i = 0; i < 7; i++) {
    printf("Day %d\n", i+1);
    printf("Current weight: %.2fkg\n", new_user.current_weight);
    printf("Enter your weight for today (in kilograms): ");
    scanf("%f", &new_user.current_weight);
    printf("How many calories did you burn today? ");
    scanf("%f", &new_user.calories_burned);
    printf("\n");
  }

  // Calculate average weight loss per day
  float weight_loss = new_user.weight - new_user.current_weight;
  float average_weight_loss = weight_loss / new_user.days_tracked;

  printf("Well done, %s! You have successfully tracked your weight for 7 days!\n\n", new_user.name);
  printf("Here are your results:\n\n");
  printf("Starting weight: %.2fkg\n", new_user.weight);
  printf("Ending weight: %.2fkg\n", new_user.current_weight);
  printf("Average weight loss per day: %.2fkg\n", average_weight_loss);
  printf("Total calories burned: %.2f\n", new_user.calories_burned);

  return 0;
}