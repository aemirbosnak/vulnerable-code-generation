//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXERCISES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int duration; // in minutes
    int caloriesBurned;
} Exercise;

typedef struct {
    Exercise exercises[MAX_EXERCISES];
    int count;
} FitnessTracker;

// Function declarations
void addExercise(FitnessTracker *tracker);
void displayExercises(const FitnessTracker *tracker);
void calculateTotalCalories(const FitnessTracker *tracker);
void menu();

int main() {
    FitnessTracker tracker = { .count = 0 };
    int choice;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addExercise(&tracker);
                break;
            case 2:
                displayExercises(&tracker);
                break;
            case 3:
                calculateTotalCalories(&tracker);
                break;
            case 4:
                printf("Exiting the Fitness Tracker. Stay fit!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void menu() {
    printf("\n=== Fitness Tracker Menu ===\n");
    printf("1. Add Exercise\n");
    printf("2. Display Exercises\n");
    printf("3. Calculate Total Calories Burned\n");
    printf("4. Exit\n");
    printf("===========================\n");
}

void addExercise(FitnessTracker *tracker) {
    if (tracker->count >= MAX_EXERCISES) {
        printf("Cannot add more exercises. Maximum limit reached!\n");
        return;
    }

    Exercise newExercise;

    printf("Enter exercise name: ");
    scanf("%s", newExercise.name);
    
    printf("Enter duration in minutes: ");
    scanf("%d", &newExercise.duration);
    
    printf("Enter calories burned: ");
    scanf("%d", &newExercise.caloriesBurned);
    
    tracker->exercises[tracker->count++] = newExercise;
    printf("Exercise added successfully!\n");
}

void displayExercises(const FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No exercises logged yet.\n");
        return;
    }
    
    printf("\n=== Logged Exercises ===\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Exercise %d: \n", i + 1);
        printf("  Name: %s\n", tracker->exercises[i].name);
        printf("  Duration: %d minutes\n", tracker->exercises[i].duration);
        printf("  Calories Burned: %d\n", tracker->exercises[i].caloriesBurned);
    }
    printf("===========================\n");
}

void calculateTotalCalories(const FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No exercises logged yet.\n");
        return;
    }

    int totalCalories = 0;
    for (int i = 0; i < tracker->count; i++) {
        totalCalories += tracker->exercises[i].caloriesBurned;
    }
    
    printf("Total calories burned: %d\n", totalCalories);
}