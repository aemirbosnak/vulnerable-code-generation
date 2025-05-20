//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: grateful
#include <stdio.h>
#include <stdbool.h>

// Define constants for menu options
#define ADD_EXERCISE 1
#define VIEW_PROGRESS 2
#define EXIT_PROGRAM 3

// Define structure for exercise data
typedef struct {
    char name[20];
    int caloriesBurned;
    int duration;
} Exercise;

// Define functions
void printMenu();
Exercise addExercise();
void viewProgress(Exercise exercises[], int numExercises);

int main() {
    // Define variables
    Exercise exercises[100];
    int numExercises = 0;
    bool running = true;
    int menuOption;

    // Loop until user chooses to exit program
    while (running) {
        // Display menu options and get user input
        printMenu();
        printf("Enter your option: ");
        scanf("%d", &menuOption);

        switch (menuOption) {
            case ADD_EXERCISE:
                // Add exercise to array and increment numExercises
                exercises[numExercises++] = addExercise();
                printf("Exercise added successfully!\n\n");
                break;
            case VIEW_PROGRESS:
                // View progress by displaying all exercises in array
                viewProgress(exercises, numExercises);
                printf("\n");
                break;
            case EXIT_PROGRAM:
                // Exit program
                running = false;
                printf("Thank you for using the C Fitness Tracker! Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n\n");
                break;
        }
    }

    return 0;
}

void printMenu() {
    printf("C Fitness Tracker Menu:\n");
    printf("1. Add Exercise\n");
    printf("2. View Progress\n");
    printf("3. Exit Program\n");
}

Exercise addExercise() {
    Exercise exercise;

    // Get exercise details from user
    printf("Enter exercise name: ");
    scanf("%s", exercise.name);
    printf("Enter calories burned: ");
    scanf("%d", &exercise.caloriesBurned);
    printf("Enter duration (in minutes): ");
    scanf("%d", &exercise.duration);

    return exercise;
}

void viewProgress(Exercise exercises[], int numExercises) {
    printf("Progress:\n");
    printf("Exercise Name\tCalories Burned\tDuration\n");

    // Loop through exercises array and display details for each exercise
    for (int i = 0; i < numExercises; i++) {
        printf("%s\t\t%d\t\t%d minutes\n", exercises[i].name, exercises[i].caloriesBurned, exercises[i].duration);
    }
}