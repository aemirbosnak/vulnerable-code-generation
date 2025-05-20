//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define the maximum length of the exercise name
#define MAX_EXERCISE_NAME_LENGTH 50

// Define the maximum number of exercises that can be tracked
#define MAX_EXERCISES 10

// Define the structure of an exercise
typedef struct {
    char name[MAX_EXERCISE_NAME_LENGTH];
    int duration;
    int caloriesBurned;
} Exercise;

// Define the structure of the fitness tracker
typedef struct {
    int numExercises;
    Exercise exercises[MAX_EXERCISES];
} FitnessTracker;

// Function to initialize the fitness tracker
void initializeFitnessTracker(FitnessTracker* tracker) {
    tracker->numExercises = 0;
}

// Function to add an exercise to the fitness tracker
void addExercise(FitnessTracker* tracker, char* name, int duration, int caloriesBurned) {
    if (tracker->numExercises >= MAX_EXERCISES) {
        printf("Error: Maximum number of exercises reached\n");
        return;
    }

    // Add the new exercise to the tracker
    tracker->exercises[tracker->numExercises] = (Exercise) {
       .name = name,
       .duration = duration,
       .caloriesBurned = caloriesBurned
    };

    tracker->numExercises++;
}

// Function to display the summary of the fitness tracker
void displaySummary(FitnessTracker* tracker) {
    printf("Fitness Tracker Summary:\n");
    printf("-------------------------\n");
    printf("Number of exercises: %d\n", tracker->numExercises);

    if (tracker->numExercises == 0) {
        printf("No exercises added yet.\n");
        return;
    }

    int totalDuration = 0;
    int totalCaloriesBurned = 0;

    for (int i = 0; i < tracker->numExercises; i++) {
        totalDuration += tracker->exercises[i].duration;
        totalCaloriesBurned += tracker->exercises[i].caloriesBurned;
    }

    printf("Total duration: %d minutes\n", totalDuration);
    printf("Total calories burned: %d\n", totalCaloriesBurned);
}

// Main function
int main() {
    FitnessTracker tracker;
    initializeFitnessTracker(&tracker);

    addExercise(&tracker, "Running", 30, 300);
    addExercise(&tracker, "Cycling", 45, 400);

    displaySummary(&tracker);

    return 0;
}