//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare struct for workout log
typedef struct workout_log_t {
  int num_workouts;
  int* workout_lengths;
  float* calories_burned;
} workout_log;

// Declare function to create a new workout log
workout_log* create_workout_log(int num_workouts) {
  workout_log* new_log = malloc(sizeof(workout_log));
  new_log->num_workouts = num_workouts;
  new_log->workout_lengths = calloc(num_workouts, sizeof(int));
  new_log->calories_burned = calloc(num_workouts, sizeof(float));
  return new_log;
}

// Declare function to add a workout to a log
void add_workout(workout_log* log, int length, float calories) {
  int index = log->num_workouts;
  log->workout_lengths[index] = length;
  log->calories_burned[index] = calories;
  log->num_workouts += 1;
}

// Declare function to print out the workout log
void print_log(workout_log* log) {
  printf("Workout Log:\n");
  for (int i=0; i < log->num_workouts; i++) {
    printf("Workout %d:\n", i+1);
    printf("  Length: %d minutes\n", log->workout_lengths[i]);
    printf("  Calories Burned: %.2f\n", log->calories_burned[i]);
  }
}

int main() {
  // Set up workout log
  workout_log* log = create_workout_log(0);

  // Loop for adding workouts
  int user_choice = 1;
  while (user_choice != 0) {
    printf("\nEnter a workout length (in minutes): ");
    int length;
    scanf("%d", &length);
    printf("Enter the number of calories burned during the workout: ");
    float calories;
    scanf("%f", &calories);
    add_workout(log, length, calories);
    printf("\nWorkout added to log!\n");
    printf("Enter 0 to finish, or any other number to add another workout: ");
    scanf("%d", &user_choice);
  }

  // Print out log
  printf("\n");
  print_log(log);

  // Free memory
  free(log->workout_lengths);
  free(log->calories_burned);
  free(log);
  
  return 0;
}