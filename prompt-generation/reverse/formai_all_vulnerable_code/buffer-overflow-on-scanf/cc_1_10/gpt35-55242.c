//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: satisfied
#include <stdio.h>

#define MAX_WORKOUTS 10 // Maximum number of workouts to track
#define MAX_NAME_LENGTH 30 // Maximum length of a workout name

// Struct to represent a workout
typedef struct {
  char name[MAX_NAME_LENGTH];
  int duration;
  float calories;
} Workout;

// Function to add a workout to the tracker
int add_workout(Workout *workouts, int count) {
  // Check if we've exceeded the maximum number of workouts
  if (count >= MAX_WORKOUTS) {
    printf("Sorry, you have reached the maximum number of workouts.\n");
    return count;
  }

  // Prompt the user for the workout name
  printf("Enter the name of your workout: ");
  scanf("%s", workouts[count].name);

  // Prompt the user for the workout duration
  printf("Enter the duration of your workout (in minutes): ");
  scanf("%d", &workouts[count].duration);

  // Prompt the user for the number of calories burned during the workout
  printf("Enter the number of calories burned during your workout: ");
  scanf("%f", &workouts[count].calories);

  // Increment the workout count and return it
  return count + 1;
}

// Function to print the list of workouts in the tracker
void print_workouts(Workout *workouts, int count) {
  printf("\nWorkouts:\n");
  printf("----------\n");

  // Loop through each workout in the tracker and print its information
  for (int i = 0; i < count; i++) {
    printf("%s | Duration: %d minutes | Calories burned: %.2f\n", workouts[i].name, workouts[i].duration, workouts[i].calories);
  }

  printf("----------\n");
}

// Function to calculate the total number of calories burned across all workouts
float calculate_total_calories(Workout *workouts, int count) {
  float total_calories = 0.0;

  // Loop through each workout in the tracker and add its calories burned to the total
  for (int i = 0; i < count; i++) {
    total_calories += workouts[i].calories;
  }

  return total_calories;
}

int main() {
  Workout workouts[MAX_WORKOUTS]; // Array to store all of the workouts
  int workout_count = 0; // Number of workouts in the array

  // Menu loop
  while (1) {
    // Print the main menu
    printf("\nFITNESS TRACKER\n");
    printf("---------------\n");
    printf("1. Add workout\n");
    printf("2. View workouts\n");
    printf("3. View total calories burned\n");
    printf("4. Exit\n");
    printf("---------------\n");

    // Prompt the user for their menu choice
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        // Add a workout to the tracker
        workout_count = add_workout(workouts, workout_count);
        break;
      case 2:
        // Print the list of workouts in the tracker
        print_workouts(workouts, workout_count);
        break;
      case 3:
        // Calculate and print the total number of calories burned across all workouts
        printf("Total calories burned: %.2f\n", calculate_total_calories(workouts, workout_count));
        break;
      case 4:
        // Exit the program
        return 0;
      default:
        // Invalid menu choice
        printf("Invalid choice. Please select a valid option.\n");
        break;
    }
  }

  return 0;
}