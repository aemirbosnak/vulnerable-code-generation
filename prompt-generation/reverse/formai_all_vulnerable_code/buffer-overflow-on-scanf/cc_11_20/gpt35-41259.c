//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of exercises that can be tracked
#define MAX_EXERCISES 5

// Declare a struct that represents a single exercise
struct Exercise {
    char name[50];
    int sets;
    int reps;
    float weight;
};

int main() {
    // Declare an array of exercises and a variable for the number of exercises
    struct Exercise exercises[MAX_EXERCISES];
    int numExercises = 0;

    // Declare variables for user input
    char name[50];
    int sets, reps;
    float weight;

    // Declare a variable for the user's choice of action
    int choice;

    // Loop until the user chooses to exit
    while (1) {
        // Print the menu of options
        printf("\n--- Fitness Tracker Menu ---\n");
        printf("1. Add an exercise\n");
        printf("2. View all exercises\n");
        printf("3. Delete an exercise\n");
        printf("4. Exit\n");

        // Get the user's choice of action
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Clear the input buffer
        fflush(stdin);

        switch (choice) {
            case 1: // Add an exercise
                // Make sure we haven't reached the maximum number of exercises
                if (numExercises == MAX_EXERCISES) {
                    printf("Sorry, you have reached the maximum number of exercises (%d)\n", MAX_EXERCISES);
                    break;
                }

                // Get the exercise details from the user
                printf("\nEnter the exercise name: ");
                fgets(name, 50, stdin);
                printf("Enter the number of sets: ");
                scanf("%d", &sets);
                printf("Enter the number of reps: ");
                scanf("%d", &reps);
                printf("Enter the weight lifted (in kg): ");
                scanf("%f", &weight);

                // Create a new Exercise struct and add it to the array
                struct Exercise exercise;
                strcpy(exercise.name, name);
                exercise.sets = sets;
                exercise.reps = reps;
                exercise.weight = weight;
                exercises[numExercises++] = exercise;

                printf("\nExercise added successfully!\n");
                break;

            case 2: // View all exercises
                if (numExercises == 0) {
                    printf("\nNo exercises to display.\n");
                    break;
                }

                printf("\n--- All Exercises (%d) ---\n", numExercises);
                printf("%-30s %-10s %-10s %-10s\n", "Name", "Sets", "Reps", "Weight (kg)");
                for (int i = 0; i < numExercises; i++) {
                    printf("%-30s %-10d %-10d %-10.2f\n", exercises[i].name, exercises[i].sets, exercises[i].reps, exercises[i].weight);
                }
                break;

            case 3: // Delete an exercise
                if (numExercises == 0) {
                    printf("\nNo exercises to delete.\n");
                    break;
                }

                printf("\n--- All Exercises (%d) ---\n", numExercises);
                printf("%-30s %-10s %-10s %-10s\n", "Name", "Sets", "Reps", "Weight (kg)");
                for (int i = 0; i < numExercises; i++) {
                    printf("%-30s %-10d %-10d %-10.2f\n", exercises[i].name, exercises[i].sets, exercises[i].reps, exercises[i].weight);
                }

                // Get the index of the exercise to delete
                int indexToDelete;
                printf("\nEnter the index of the exercise to delete: ");
                scanf("%d", &indexToDelete);

                // Make sure the index is valid
                if (indexToDelete < 0 || indexToDelete >= numExercises) {
                    printf("\nInvalid index.\n");
                    break;
                }

                // Shift all the exercises after the deleted exercise one position to the left
                for (int i = indexToDelete; i < numExercises - 1; i++) {
                    exercises[i] = exercises[i + 1];
                }

                // Decrement the number of exercises
                numExercises--;

                printf("\nExercise deleted successfully!\n");
                break;

            case 4: // Exit
                exit(0);

            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }

    return 0;
}