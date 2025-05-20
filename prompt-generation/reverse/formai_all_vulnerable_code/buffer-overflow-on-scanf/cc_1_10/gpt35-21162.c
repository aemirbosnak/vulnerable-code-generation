//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of workouts allowed
#define MAX_WORKOUTS 10

// Struct to hold workout information
typedef struct {
    char name[50];
    int duration;
    int caloriesBurned;
} Workout;

// Function to add a workout to the tracker
void addWorkout(Workout workouts[], int *numWorkouts) {
    // Only allow up to MAX_WORKOUTS workouts
    if (*numWorkouts == MAX_WORKOUTS) {
        printf("Sorry, you have reached the maximum number of workouts allowed.");
        return;
    }

    // Get workout name from user
    char workoutName[50];
    printf("Enter workout name: ");
    scanf("%s", workoutName);

    // Get workout duration from user
    int workoutDuration;
    printf("Enter workout duration (in minutes): ");
    scanf("%d", &workoutDuration);

    // Get calories burned from user
    int caloriesBurned;
    printf("Enter calories burned during workout: ");
    scanf("%d", &caloriesBurned);

    // Create new Workout struct and add it to the workouts array
    Workout newWorkout;
    strcpy(newWorkout.name, workoutName);
    newWorkout.duration = workoutDuration;
    newWorkout.caloriesBurned = caloriesBurned;
    workouts[*numWorkouts] = newWorkout;
    *numWorkouts += 1;

    printf("Workout added successfully!\n");
}

// Function to display all workouts in the tracker
void viewWorkouts(Workout workouts[], int numWorkouts) {
    // Check if there are any workouts to display
    if (numWorkouts == 0) {
        printf("No workouts to display.\n");
        return;
    }

    // Display each workout in the tracker
    printf("Workouts:\n");
    for (int i = 0; i < numWorkouts; i++) {
        printf("%d. %s - %d minutes, %d calories burned\n", i+1, workouts[i].name, workouts[i].duration, workouts[i].caloriesBurned);
    }
}

int main() {
    // Create an array to hold workouts and a variable to track the number of workouts
    Workout workouts[MAX_WORKOUTS];
    int numWorkouts = 0;

    // Display welcome message
    printf("Welcome to the C Fitness Tracker!\n");

    // Loop to display menu and allow user to choose options
    while (1) {
        // Display menu options
        printf("\nMenu:\n");
        printf("1. Add a workout\n");
        printf("2. View workouts\n");
        printf("3. Exit\n");

        // Get user choice
        int choice;
        printf("Choose an option: ");
        scanf("%d", &choice);

        // Handle menu choice
        switch (choice) {
            case 1:
                addWorkout(workouts, &numWorkouts);
                break;
            case 2:
                viewWorkouts(workouts, numWorkouts);
                break;
            case 3:
                printf("Thanks for using the C Fitness Tracker! Goodbye.\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose a valid option.\n");
        }
    }

    return 0;
}