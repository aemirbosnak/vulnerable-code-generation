//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_EXERCISE_NAME 50

typedef struct {
    char exerciseName[MAX_EXERCISE_NAME];
    float duration;                 // in minutes
    float distance;                 // in kilometers
    float caloriesBurned;           // in calories
} ExerciseEntry;

typedef struct {
    ExerciseEntry entries[MAX_ENTRIES];
    int count;
} FitnessTracker;

void initializeTracker(FitnessTracker *tracker) {
    tracker->count = 0;
}

void addExerciseEntry(FitnessTracker *tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Cannot add more entries, tracker is full!\n");
        return;
    }

    ExerciseEntry newEntry;

    printf("Enter the exercise name: ");
    fgets(newEntry.exerciseName, MAX_EXERCISE_NAME, stdin);
    newEntry.exerciseName[strcspn(newEntry.exerciseName, "\n")] = 0; // Remove newline character

    printf("Enter the duration in minutes: ");
    scanf("%f", &newEntry.duration);
    
    printf("Enter the distance in kilometers: ");
    scanf("%f", &newEntry.distance);
    
    // Using a basic calculation for calories burned (this can vary based on many factors)
    newEntry.caloriesBurned = (newEntry.distance * 60) + (newEntry.duration * 5);

    tracker->entries[tracker->count] = newEntry;
    tracker->count++;

    // Clear the input buffer
    while ((getchar()) != '\n');
}

void displayWorkoutLog(FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No workout entries found.\n");
        return;
    }

    printf("\n--- Workout Log ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Entry %d:\n", i + 1);
        printf("  Exercise Name: %s\n", tracker->entries[i].exerciseName);
        printf("  Duration: %.2f minutes\n", tracker->entries[i].duration);
        printf("  Distance: %.2f kilometers\n", tracker->entries[i].distance);
        printf("  Calories Burned: %.2f calories\n", tracker->entries[i].caloriesBurned);
        printf("-------------------------\n");
    }
}

void displayMenu() {
    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Add Exercise Entry\n");
    printf("2. Display Workout Log\n");
    printf("3. Exit\n");
}

int main() {
    FitnessTracker tracker;
    initializeTracker(&tracker);
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        // Clear the input buffer
        while ((getchar()) != '\n');

        switch (choice) {
            case 1:
                addExerciseEntry(&tracker);
                break;
            case 2:
                displayWorkoutLog(&tracker);
                break;
            case 3:
                printf("Exiting the fitness tracker. Stay healthy!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}