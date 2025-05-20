//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of workouts that can be tracked
#define MAX_WORKOUTS 10

// Define the structure for a workout
typedef struct {
    char name[50];
    int duration;
    int caloriesBurned;
} Workout;

// Declare an array of workouts
Workout workouts[MAX_WORKOUTS];

// Declare variables for tracking progress
int totalWorkouts = 0;
int totalDuration = 0;
int totalCaloriesBurned = 0;

// Function to add a new workout
void addWorkout() {
    if (totalWorkouts >= MAX_WORKOUTS) {
        printf("Sorry, you have reached the maximum number of workouts.\n");
        return;
    }

    printf("Enter the name of the workout: ");
    scanf("%s", workouts[totalWorkouts].name);

    printf("Enter the duration of the workout in minutes: ");
    scanf("%d", &workouts[totalWorkouts].duration);

    printf("Enter the number of calories burned during the workout: ");
    scanf("%d", &workouts[totalWorkouts].caloriesBurned);

    totalWorkouts++;
}

// Function to display all workouts
void displayWorkouts() {
    printf("\nWorkout Summary:\n");
    printf("-----------------\n");

    for (int i = 0; i < totalWorkouts; i++) {
        printf("Workout %d:\n", i + 1);
        printf("Name: %s\n", workouts[i].name);
        printf("Duration: %d minutes\n", workouts[i].duration);
        printf("Calories Burned: %d\n\n", workouts[i].caloriesBurned);
    }

    printf("Total Workouts: %d\n", totalWorkouts);
    printf("Total Duration: %d minutes\n", totalDuration);
    printf("Total Calories Burned: %d\n", totalCaloriesBurned);
}

// Main function
int main() {
    int choice;

    do {
        printf("\nWelcome to the Fitness Tracker!\n");
        printf("-----------------------------\n");
        printf("1. Add a new workout\n");
        printf("2. Display workout summary\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addWorkout();
            break;
        case 2:
            displayWorkouts();
            break;
        case 3:
            printf("Thank you for using the Fitness Tracker!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (true);

    return 0;
}