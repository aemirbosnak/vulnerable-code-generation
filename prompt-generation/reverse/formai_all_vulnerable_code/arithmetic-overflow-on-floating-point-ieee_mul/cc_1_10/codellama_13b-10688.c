//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: irregular
/*
 * C Fitness Tracker Example Program
 *
 * This program is an example of a simple fitness tracker that tracks
 * the user's daily physical activity and calculates their daily
 * calorie burn based on their activity level.
 *
 * The program uses a struct to store the user's data and a function
 * to calculate the daily calorie burn.
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>

struct UserData {
  int age;
  float weight;
  float height;
  float activityLevel;
};

void getUserData(struct UserData* data) {
  printf("Enter your age: ");
  scanf("%d", &data->age);

  printf("Enter your weight in kg: ");
  scanf("%f", &data->weight);

  printf("Enter your height in cm: ");
  scanf("%f", &data->height);

  printf("Enter your activity level (1-3): ");
  scanf("%f", &data->activityLevel);
}

float calculateCaloriesBurned(struct UserData data) {
  float bmr = data.weight * 10 + data.height * 6.25 - data.age * 5;
  float dailyCalories = bmr * data.activityLevel;
  return dailyCalories;
}

int main() {
  struct UserData userData;
  getUserData(&userData);

  float dailyCalories = calculateCaloriesBurned(userData);
  printf("You have burned %f calories today.\n", dailyCalories);

  return 0;
}