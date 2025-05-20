//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

typedef struct _Data {
  char name[MAX_CHAR];
  int age;
  float height;
  float weight;
  int activity_level;
  float target_heart_rate;
  int steps_taken;
  int calories_burned;
} Data;

int main() {
  Data user_data;

  // Initialize user data
  user_data.name[0] = '\0';
  user_data.age = 0;
  user_data.height = 0.0f;
  user_data.weight = 0.0f;
  user_data.activity_level = 0;
  user_data.target_heart_rate = 0.0f;
  user_data.steps_taken = 0;
  user_data.calories_burned = 0;

  // Get user input
  printf("Enter your name: ");
  scanf("%s", user_data.name);

  printf("Enter your age: ");
  scanf("%d", &user_data.age);

  printf("Enter your height (in meters): ");
  scanf("%f", &user_data.height);

  printf("Enter your weight (in kilograms): ");
  scanf("%f", &user_data.weight);

  printf("Enter your activity level (1-3): ");
  scanf("%d", &user_data.activity_level);

  // Calculate target heart rate
  user_data.target_heart_rate = 220 - (user_data.age * 2);

  // Calculate steps taken
  user_data.steps_taken = (int)(user_data.height * 2) * user_data.activity_level;

  // Calculate calories burned
  user_data.calories_burned = user_data.steps_taken * 10;

  // Display results
  printf("\nName: %s", user_data.name);
  printf("\nAge: %d", user_data.age);
  printf("\nHeight: %.2f meters", user_data.height);
  printf("\nWeight: %.2f kilograms", user_data.weight);
  printf("\nActivity Level: %d", user_data.activity_level);
  printf("\nTarget Heart Rate: %.2f bpm", user_data.target_heart_rate);
  printf("\nSteps Taken: %d", user_data.steps_taken);
  printf("\nCalories Burned: %d", user_data.calories_burned);

  return 0;
}