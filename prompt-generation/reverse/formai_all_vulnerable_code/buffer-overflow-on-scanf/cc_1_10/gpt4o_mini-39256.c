//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_EXERCISES 10
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int duration; // in minutes
    int caloriesBurned;
} Exercise;

typedef struct {
    Exercise exercises[MAX_EXERCISES];
    int exerciseCount;
} Workout;

typedef struct {
    Workout workouts[MAX_WORKOUTS];
    int workoutCount;
} FitnessTracker;

void addWorkout(FitnessTracker *tracker);
void displayWorkouts(const FitnessTracker *tracker);
void calculateTotalCalories(const FitnessTracker *tracker);
void menu();

int main() {
    FitnessTracker tracker = {0}; // Initialize the tracker with 0 workouts
    int choice;

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the input buffer

        switch (choice) {
            case 1:
                addWorkout(&tracker);
                break;
            case 2:
                displayWorkouts(&tracker);
                break;
            case 3:
                calculateTotalCalories(&tracker);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void menu() {
    printf("\n=== Fitness Tracker Menu ===\n");
    printf("1. Add a Workout\n");
    printf("2. Display Workouts\n");
    printf("3. Calculate Total Calories Burned\n");
    printf("4. Exit\n");
}

void addWorkout(FitnessTracker *tracker) {
    if (tracker->workoutCount >= MAX_WORKOUTS) {
        printf("Maximum workout limit reached. Cannot add more workouts.\n");
        return;
    }

    Workout newWorkout = {0};
    int exerciseCount;

    printf("Enter the number of exercises in this workout (max %d): ", MAX_EXERCISES);
    scanf("%d", &exerciseCount);
    getchar(); // Clear the newline character

    if (exerciseCount > MAX_EXERCISES) {
        printf("You can enter a maximum of %d exercises only.\n", MAX_EXERCISES);
        return;
    }

    for (int i = 0; i < exerciseCount; i++) {
        printf("Enter name of exercise %d: ", i + 1);
        fgets(newWorkout.exercises[i].name, MAX_NAME_LENGTH, stdin);
        newWorkout.exercises[i].name[strcspn(newWorkout.exercises[i].name, "\n")] = 0; // Remove newline character

        printf("Enter duration (in minutes) for %s: ", newWorkout.exercises[i].name);
        scanf("%d", &newWorkout.exercises[i].duration);
        getchar(); // Clear the newline character

        printf("Enter calories burned for %s: ", newWorkout.exercises[i].name);
        scanf("%d", &newWorkout.exercises[i].caloriesBurned);
        getchar(); // Clear the newline character
    }

    newWorkout.exerciseCount = exerciseCount;
    tracker->workouts[tracker->workoutCount] = newWorkout;
    tracker->workoutCount++;

    printf("Workout added successfully!\n");
}

void displayWorkouts(const FitnessTracker *tracker) {
    if (tracker->workoutCount == 0) {
        printf("No workouts to display.\n");
        return;
    }

    for (int i = 0; i < tracker->workoutCount; i++) {
        printf("\nWorkout %d:\n", i + 1);
        for (int j = 0; j < tracker->workouts[i].exerciseCount; j++) {
            printf("  Exercise %d: %s\n", j + 1, tracker->workouts[i].exercises[j].name);
            printf("    Duration: %d minutes\n", tracker->workouts[i].exercises[j].duration);
            printf("    Calories Burned: %d\n", tracker->workouts[i].exercises[j].caloriesBurned);
        }
    }
}

void calculateTotalCalories(const FitnessTracker *tracker) {
    int totalCalories = 0;

    for (int i = 0; i < tracker->workoutCount; i++) {
        for (int j = 0; j < tracker->workouts[i].exerciseCount; j++) {
            totalCalories += tracker->workouts[i].exercises[j].caloriesBurned;
        }
    }

    printf("Total calories burned across all workouts: %d\n", totalCalories);
}