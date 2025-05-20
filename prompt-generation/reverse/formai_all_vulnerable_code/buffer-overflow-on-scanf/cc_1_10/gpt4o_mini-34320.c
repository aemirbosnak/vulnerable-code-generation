//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXERCISES 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int duration; // in minutes
    int caloriesBurned;
} Exercise;

typedef struct {
    Exercise exercises[MAX_EXERCISES];
    int count;
} FitnessTracker;

void addExercise(FitnessTracker *tracker);
void displayExercises(const FitnessTracker *tracker);
void calculateTotalBurned(const FitnessTracker *tracker);
void visualizeProgress(const FitnessTracker *tracker);

int main() {
    FitnessTracker tracker;
    tracker.count = 0;

    int choice;
    do {
        printf("\n--- Welcome to Your Fitness Tracker! ---\n");
        printf("1. Add Exercise\n");
        printf("2. Display Exercises\n");
        printf("3. Calculate Total Calories Burned\n");
        printf("4. Visualize Progress\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExercise(&tracker);
                break;
            case 2:
                displayExercises(&tracker);
                break;
            case 3:
                calculateTotalBurned(&tracker);
                break;
            case 4:
                visualizeProgress(&tracker);
                break;
            case 5:
                printf("Thank you for using the Fitness Tracker. Stay fit!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}

void addExercise(FitnessTracker *tracker) {
    if (tracker->count >= MAX_EXERCISES) {
        printf("Maximum exercises reached! Unable to add more.\n");
        return;
    }

    Exercise newExercise;
    printf("Enter the name of the exercise: ");
    scanf("%s", newExercise.name);
    printf("Enter the duration (in minutes): ");
    scanf("%d", &newExercise.duration);
    printf("Enter calories burned: ");
    scanf("%d", &newExercise.caloriesBurned);
    
    tracker->exercises[tracker->count] = newExercise;
    tracker->count++;
    printf("Exercise added successfully!\n");
}

void displayExercises(const FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No exercises recorded yet.\n");
        return;
    }

    printf("\n--- List of Exercises ---\n");
    for (int i = 0; i < tracker->count; ++i) {
        printf("Exercise %d: %s | Duration: %d minutes | Calories Burned: %d\n",
               i + 1, tracker->exercises[i].name,
               tracker->exercises[i].duration,
               tracker->exercises[i].caloriesBurned);
    }
}

void calculateTotalBurned(const FitnessTracker *tracker) {
    int totalCalories = 0;
    
    for (int i = 0; i < tracker->count; ++i) {
        totalCalories += tracker->exercises[i].caloriesBurned;
    }

    printf("Total Calories Burned: %d kcal\n", totalCalories);
}

void visualizeProgress(const FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No data available to visualize. Please add exercises first.\n");
        return;
    }

    printf("\n--- Your Fitness Progress Visualization ---\n");
    int maxCalories = tracker->exercises[0].caloriesBurned;

    for (int i = 1; i < tracker->count; ++i) {
        if (tracker->exercises[i].caloriesBurned > maxCalories) {
            maxCalories = tracker->exercises[i].caloriesBurned;
        }
    }

    for (int i = 0; i < tracker->count; ++i) {
        int barLength = (tracker->exercises[i].caloriesBurned * 50) / maxCalories;
        printf("%s: ", tracker->exercises[i].name);
        for (int j = 0; j < barLength; ++j) {
            printf("#");
        }
        printf(" (%d calories)\n", tracker->exercises[i].caloriesBurned);
    }
}