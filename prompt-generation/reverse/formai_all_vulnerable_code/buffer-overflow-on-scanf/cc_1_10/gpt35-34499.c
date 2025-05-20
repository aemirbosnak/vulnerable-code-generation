//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of exercises that can be tracked
#define MAX_EXERCISES 10

// Define a structure to represent an exercise
typedef struct Exercise {
  char name[20];
  int reps;
  int sets;
  int weight;
} Exercise;

// Function declarations
void print_menu();
void add_exercise(Exercise *exercises, int *num_exercises);
void remove_exercise(Exercise *exercises, int *num_exercises);
void view_exercises(Exercise *exercises, int num_exercises);

// Main function
int main() {

  // Declare variables
  int choice, num_exercises = 0;
  Exercise exercises[MAX_EXERCISES];

  // Print welcome message
  printf("Welcome to the Fitness Tracker!\n\n");

  // Loop until the user chooses to exit
  do {

    // Print the menu and prompt for a choice
    print_menu();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Handle the user's choice
    switch (choice) {
      case 1:
        add_exercise(exercises, &num_exercises);
        break;
      case 2:
        remove_exercise(exercises, &num_exercises);
        break;
      case 3:
        view_exercises(exercises, num_exercises);
        break;
      case 4:
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }

    // Print a line break for readability
    printf("\n");

  } while (choice != 4);

  // Exit the program
  return 0;
}

// Function to print the menu
void print_menu() {
  printf("Fitness Tracker Menu\n");
  printf("---------------------\n");
  printf("1. Add an exercise\n");
  printf("2. Remove an exercise\n");
  printf("3. View all exercises\n");
  printf("4. Exit\n");
}

// Function to add an exercise
void add_exercise(Exercise *exercises, int *num_exercises) {

  // Check if there is room to add another exercise
  if (*num_exercises >= MAX_EXERCISES) {
    printf("You have reached the maximum number of exercises that can be tracked.\n");
    return;
  }

  // Prompt for exercise details
  printf("Enter exercise name: ");
  scanf("%s", exercises[*num_exercises].name);
  printf("Enter number of reps: ");
  scanf("%d", &exercises[*num_exercises].reps);
  printf("Enter number of sets: ");
  scanf("%d", &exercises[*num_exercises].sets);
  printf("Enter weight (in kg): ");
  scanf("%d", &exercises[*num_exercises].weight);

  // Increment the number of exercises
  (*num_exercises)++;

  // Print success message
  printf("Exercise added successfully!\n");
}

// Function to remove an exercise
void remove_exercise(Exercise *exercises, int *num_exercises) {

  // Check if there are any tracked exercises
  if (*num_exercises <= 0) {
    printf("You have not yet tracked any exercises.\n");
    return;
  }

  // Print current exercises
  printf("Current exercises:\n");
  for (int i = 0; i < *num_exercises; i++) {
    printf("%d. %s (%d x %d @ %d kg)\n", i+1, exercises[i].name, exercises[i].reps, exercises[i].sets, exercises[i].weight);
  }

  // Prompt for exercise to remove
  int choice;
  printf("Enter the number of the exercise to remove: ");
  scanf("%d", &choice);

  // Remove the chosen exercise by shifting all exercises after it over one position to the left
  for (int i = choice-1; i < *num_exercises-1; i++) {
    exercises[i] = exercises[i+1];
  }

  // Decrement the number of exercises
  (*num_exercises)--;

  // Print success message
  printf("Exercise removed successfully!\n");
}

// Function to view all exercises
void view_exercises(Exercise *exercises, int num_exercises) {

  // Check if there are any tracked exercises
  if (num_exercises <= 0) {
    printf("You have not yet tracked any exercises.\n");
    return;
  }

  // Print all tracked exercises
  printf("Tracked exercises:\n");
  for (int i = 0; i < num_exercises; i++) {
    printf("%d. %s (%d x %d @ %d kg)\n", i+1, exercises[i].name, exercises[i].reps, exercises[i].sets, exercises[i].weight);
  }
}