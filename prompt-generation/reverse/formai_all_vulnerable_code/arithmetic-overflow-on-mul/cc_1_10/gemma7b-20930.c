//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void morph_fitness_tracker() {
  system("clear");
  printf("I am a morphing fitness tracker, ready to track your progress.\n");

  // Get the user's current weight and height
  int weight = 0;
  printf("Enter your current weight (in kilograms): ");
  scanf("%d", &weight);

  int height = 0;
  printf("Enter your current height (in centimeters): ");
  scanf("%d", &height);

  // Calculate the user's body mass index (BMI)
  int bmi = weight * 10000 / (height * height);

  // Display the user's BMI
  printf("Your BMI is: %d\n", bmi);

  // Offer suggestions for improving fitness
  if (bmi < 25) {
    printf("You are underweight. You should consider gaining weight.\n");
  } else if (bmi >= 25 && bmi < 30) {
    printf("You are at a healthy weight. Keep up the good work!\n");
  } else if (bmi >= 30) {
    printf("You are overweight. You should consider losing weight.\n");
  }

  // Encourage the user to take action
  printf("To improve your fitness, you can:\n");
  printf("1. Eat a healthy diet.\n");
  printf("2. Get regular exercise.\n");
  printf("3. Sleep well.\n");
  printf("4. Manage stress.\n");

  // Ask the user if they have any questions
  printf("Do you have any questions? (Y/N): ");
  char answer = getchar();

  // Respond to the user's questions
  if (answer == 'Y') {
    printf("I am here to help you. Please ask me any questions.\n");
  } else {
    printf("Thank you for using the morphing fitness tracker. Have a great day!\n");
  }
}

int main() {
  morph_fitness_tracker();

  return 0;
}