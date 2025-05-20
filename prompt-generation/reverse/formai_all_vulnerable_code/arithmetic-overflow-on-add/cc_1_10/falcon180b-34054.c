//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of exercises that can be tracked
#define MAX_EXERCISES 10

// Define the structure for an exercise
typedef struct {
    char name[50];
    int duration;
    int calories;
} Exercise;

// Define the structure for a workout
typedef struct {
    int numExercises;
    Exercise exercises[MAX_EXERCISES];
} Workout;

// Function to add an exercise to a workout
void addExercise(Workout *workout) {
    int i;

    // Check if the workout is full
    if (workout->numExercises >= MAX_EXERCISES) {
        printf("Workout is full.\n");
        return;
    }

    // Get the exercise details from the user
    printf("Enter the name of the exercise: ");
    scanf("%s", workout->exercises[workout->numExercises].name);
    printf("Enter the duration of the exercise (in minutes): ");
    scanf("%d", &workout->exercises[workout->numExercises].duration);
    printf("Enter the number of calories burned during the exercise: ");
    scanf("%d", &workout->exercises[workout->numExercises].calories);

    // Increment the number of exercises in the workout
    workout->numExercises++;
}

// Function to display the details of a workout
void displayWorkout(Workout workout) {
    int i;

    // Display the total number of exercises in the workout
    printf("Total number of exercises in the workout: %d\n", workout.numExercises);

    // Display the details of each exercise in the workout
    for (i = 0; i < workout.numExercises; i++) {
        printf("\nName: %s\n", workout.exercises[i].name);
        printf("Duration: %d minutes\n", workout.exercises[i].duration);
        printf("Calories burned: %d\n\n", workout.exercises[i].calories);
    }
}

// Main function
int main() {
    Workout workout;
    int choice;

    // Initialize the workout
    workout.numExercises = 0;

    // Display the main menu
    while (1) {
        printf("\nC Fitness Tracker\n");
        printf("1. Add an exercise\n");
        printf("2. Display workout details\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the chosen action
        switch (choice) {
        case 1:
            addExercise(&workout);
            break;
        case 2:
            displayWorkout(workout);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}