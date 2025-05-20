//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXERCISES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float duration; // in minutes
    float caloriesBurned;
} Exercise;

typedef struct {
    Exercise exercises[MAX_EXERCISES];
    int count;
} FitnessTracker;

void addExercise(FitnessTracker *tracker) {
    if (tracker->count >= MAX_EXERCISES) {
        printf("Maximum exercise limit reached. Cannot add more exercises.\n");
        return;
    }

    Exercise newExercise;
    printf("Enter exercise name: ");
    scanf("%s", newExercise.name);
    printf("Enter duration (in minutes): ");
    scanf("%f", &newExercise.duration);
    printf("Enter calories burned: ");
    scanf("%f", &newExercise.caloriesBurned);

    tracker->exercises[tracker->count] = newExercise;
    tracker->count++;
    printf("Exercise added successfully.\n");
}

void viewExercises(FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No exercises recorded yet.\n");
        return;
    }

    printf("\n=== Recorded Exercises ===\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Exercise %d:\n", i + 1);
        printf("Name: %s\n", tracker->exercises[i].name);
        printf("Duration: %.2f minutes\n", tracker->exercises[i].duration);
        printf("Calories Burned: %.2f\n", tracker->exercises[i].caloriesBurned);
        printf("---------------------\n");
    }
}

void totalStats(FitnessTracker *tracker) {
    float totalDuration = 0;
    float totalCalories = 0;

    for (int i = 0; i < tracker->count; i++) {
        totalDuration += tracker->exercises[i].duration;
        totalCalories += tracker->exercises[i].caloriesBurned;
    }

    printf("\n=== Total Stats ===\n");
    printf("Total duration: %.2f minutes\n", totalDuration);
    printf("Total calories burned: %.2f\n", totalCalories);
}

void sortExercises(FitnessTracker *tracker) {
    for (int i = 0; i < tracker->count - 1; i++) {
        for (int j = i + 1; j < tracker->count; j++) {
            if (tracker->exercises[i].caloriesBurned < tracker->exercises[j].caloriesBurned) {
                Exercise temp = tracker->exercises[i];
                tracker->exercises[i] = tracker->exercises[j];
                tracker->exercises[j] = temp;
            }
        }
    }
    printf("Exercises sorted by calories burned (descending).\n");
}

void displayMenu() {
    printf("\n=== Fitness Tracker Menu ===\n");
    printf("1. Add Exercise\n");
    printf("2. View Exercises\n");
    printf("3. Show Total Stats\n");
    printf("4. Sort Exercises\n");
    printf("5. Exit\n");
    printf("===========================\n");
}

int main() {
    FitnessTracker tracker = {{0}, 0};
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExercise(&tracker);
                break;
            case 2:
                viewExercises(&tracker);
                break;
            case 3:
                totalStats(&tracker);
                break;
            case 4:
                sortExercises(&tracker);
                break;
            case 5:
                printf("Exiting the Fitness Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}