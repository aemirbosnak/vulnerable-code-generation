//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define macros for data types
typedef int bool;
#define true 1
#define false 0

typedef struct Exercise {
    char name[20];
    int totalReps;
} Exercise;

typedef struct Workout {
    Exercise exercises[3];
    int duration;
} Workout;

// Define global variables
int numWorkouts = 0;
Workout workouts[10];

// Declare function prototypes
void addWorkout();
void viewWorkouts();
int generateRandomNum(int min, int max);

int main() {
    printf("Welcome to the Surrealist Fitness Tracker!\n\n");
    printf("Please select an option:\n");
    printf("1. Add Workout\n");
    printf("2. View Workouts\n");
    printf("3. Exit\n\n");

    int option;
    bool isRunning = true;
    while (isRunning) {
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addWorkout();
                break;
            case 2:
                viewWorkouts();
                break;
            case 3:
                printf("\nThank you for using the Surrealist Fitness Tracker! Have a surreal day!\n");
                isRunning = false;
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
        }
    }

    return 0;
}

void addWorkout() {
    printf("\nAdding a new workout...\n");

    Workout newWorkout;

    // Choose 3 random exercises and set their total reps
    char exerciseNames[6][20] = {"Dream Squats", "Teleportation Lunges", "Galactic Push-ups", "Aurora Borealis Sit-ups", "Parallel Universe Planks", "Quantum Leap Crunches"};
    for (int i = 0; i < 3; i++) {
        Exercise newExercise;
        strcpy(newExercise.name, exerciseNames[generateRandomNum(0, 5)]);
        newExercise.totalReps = generateRandomNum(5, 20);
        newWorkout.exercises[i] = newExercise;
    }

    // Set the workout duration
    newWorkout.duration = generateRandomNum(10, 60);

    workouts[numWorkouts] = newWorkout;
    numWorkouts++;

    printf("\nWorkout added!\n\n");
}

void viewWorkouts() {
    printf("\nViewing your surreal workouts...\n\n");

    if (numWorkouts == 0) {
        printf("No workouts found.\n\n");
        return;
    }

    for (int i = 0; i < numWorkouts; i++) {
        Workout currentWorkout = workouts[i];

        printf("Workout %d:\n", i+1);
        printf("Duration: %d minutes\n", currentWorkout.duration);
        printf("Exercises:\n");

        for (int j = 0; j < 3; j++) {
            Exercise currentExercise = currentWorkout.exercises[j];
            printf("- %d %s\n", currentExercise.totalReps, currentExercise.name);
        }

        printf("\n");
    }
}

int generateRandomNum(int min, int max) {
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}