//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the struct to hold the fitness data
typedef struct {
  float weight;
  int steps;
  int calories;
  bool slept;
  int hours_slept;
} Fitness_Data;

// Define a function to input the user's fitness data
void input_fitness_data(Fitness_Data * user_data) {
  printf("Enter your weight (in kg): ");
  scanf("%f", &(user_data->weight));

  printf("Enter the number of steps you took today: ");
  scanf("%d", &(user_data->steps));

  printf("Enter the number of calories you burned today: ");
  scanf("%d", &(user_data->calories));

  printf("Did you sleep last night? (true/false): ");
  scanf("%d", &(user_data->slept));

  if (user_data->slept) {
    printf("How many hours did you sleep? ");
    scanf("%d", &(user_data->hours_slept));
  }
}

// Define a function to output the user's fitness data
void output_fitness_data(Fitness_Data * user_data) {
  printf("\n\nHere is your fitness data for today:\n\n");
  printf("Weight: %.1f kg\n", user_data->weight);
  printf("Steps taken: %d\n", user_data->steps);
  printf("Calories burned: %d\n", user_data->calories);
  printf("Slept last night: %s\n", user_data->slept ? "true" : "false");
  if (user_data->slept) {
    printf("Hours slept: %d\n", user_data->hours_slept);
  }
}

// Define a function to calculate the user's fitness score
float calculate_fitness_score(Fitness_Data * user_data) {
  float score = 0;
  score += user_data->steps / 1000.0;
  score += user_data->calories / 100.0;
  score += user_data->slept ? (float) user_data->hours_slept / 2.0 : 0.0;
  return score;
}

int main() {
  Fitness_Data user_data;

  printf("Welcome to the Fitness Tracker!\n\n");

  // Get the user's fitness data
  input_fitness_data(&user_data);

  // Output the user's fitness data
  output_fitness_data(&user_data);

  // Calculate the user's fitness score
  float score = calculate_fitness_score(&user_data);

  printf("\n\nYour fitness score for today is: %.2f\n", score);
  printf("Keep up the good work!\n");

  return 0;
}