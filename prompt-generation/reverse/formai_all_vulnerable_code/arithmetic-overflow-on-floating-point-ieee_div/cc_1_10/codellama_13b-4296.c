//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: grateful
// Grateful Fitness Tracker Example Program

#include <stdio.h>
#include <stdlib.h>

// Structure to store user data
typedef struct {
  char name[20];
  int age;
  float height;
  float weight;
  float BMI;
  char gender[10];
  char goal[50];
} User;

// Function to calculate BMI
float calculateBMI(float weight, float height) {
  return weight / (height * height);
}

// Function to print user data
void printUserData(User user) {
  printf("Name: %s\n", user.name);
  printf("Age: %d\n", user.age);
  printf("Height: %f\n", user.height);
  printf("Weight: %f\n", user.weight);
  printf("BMI: %f\n", user.BMI);
  printf("Gender: %s\n", user.gender);
  printf("Goal: %s\n", user.goal);
}

// Main function
int main() {
  // Create a user object
  User user;

  // Get user input
  printf("Enter your name: ");
  scanf("%s", user.name);

  printf("Enter your age: ");
  scanf("%d", &user.age);

  printf("Enter your height (in inches): ");
  scanf("%f", &user.height);

  printf("Enter your weight (in pounds): ");
  scanf("%f", &user.weight);

  printf("Enter your gender (M/F): ");
  scanf("%s", user.gender);

  printf("Enter your fitness goal: ");
  scanf("%s", user.goal);

  // Calculate BMI
  user.BMI = calculateBMI(user.weight, user.height);

  // Print user data
  printUserData(user);

  return 0;
}