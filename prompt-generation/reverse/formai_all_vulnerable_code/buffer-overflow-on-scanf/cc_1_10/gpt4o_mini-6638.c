//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define DESCRIPTION_LENGTH 50

typedef struct {
    char description[DESCRIPTION_LENGTH];
    int duration; // in minutes
    int caloriesBurned; // calories burned
} Workout;

void addWorkout(Workout workouts[], int *workoutCount) {
    if (*workoutCount >= MAX_WORKOUTS) {
        printf("Workout log is full!\n");
        return;
    }
    
    printf("Enter workout description: ");
    fgets(workouts[*workoutCount].description, DESCRIPTION_LENGTH, stdin);
    workouts[*workoutCount].description[strcspn(workouts[*workoutCount].description, "\n")] = 0; // Remove newline

    printf("Enter duration in minutes: ");
    scanf("%d", &workouts[*workoutCount].duration);
    
    printf("Enter calories burned: ");
    scanf("%d", &workouts[*workoutCount].caloriesBurned);
    
    // Clear the newline character left by scanf
    getchar();

    (*workoutCount)++;
    printf("Workout added!\n");
}

void displayWorkouts(Workout workouts[], int workoutCount) {
    if (workoutCount == 0) {
        printf("No workouts logged yet.\n");
        return;
    }

    printf("\nLogged Workouts:\n");
    for (int i = 0; i < workoutCount; i++) {
        printf("Workout %d:\n", i + 1);
        printf("Description: %s\n", workouts[i].description);
        printf("Duration: %d minutes\n", workouts[i].duration);
        printf("Calories Burned: %d\n", workouts[i].caloriesBurned);
        printf("\n");
    }
}

int main() {
    Workout workouts[MAX_WORKOUTS];
    int workoutCount = 0;
    int choice;

    printf("Welcome to the Fitness Tracker!\n");
    
    do {
        printf("Menu:\n");
        printf("1. Add Workout\n");
        printf("2. Display Workouts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Clear the newline character left by scanf
        getchar();

        switch (choice) {
            case 1:
                addWorkout(workouts, &workoutCount);
                break;
            case 2:
                displayWorkouts(workouts, workoutCount);
                break;
            case 3:
                printf("Exiting Fitness Tracker. Stay fit!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}