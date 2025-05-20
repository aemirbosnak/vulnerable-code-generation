//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WATER_INTAKE 5000
#define MAX_STEP_GOAL 20000
#define MAX_EXERCISES 10

typedef struct {
    int dailySteps;
    int waterIntake; // in milliliters
    char exercises[MAX_EXERCISES][30]; // Names of exercises
    int numExercises;
} FitnessTracker;

void initializeTracker(FitnessTracker *tracker) {
    tracker->dailySteps = 0;
    tracker->waterIntake = 0;
    tracker->numExercises = 0;
}

void displayMenu() {
    printf("\n=== Happy Fitness Tracker ===\n");
    printf("1. Log Steps\n");
    printf("2. Log Water Intake\n");
    printf("3. Add Exercise\n");
    printf("4. View Summary\n");
    printf("5. Exit\n");
}

void logSteps(FitnessTracker *tracker) {
    int steps;
    printf("Enter number of steps you walked today: ");
    scanf("%d", &steps);
    
    if (steps < 0) {
        printf("Steps cannot be negative! Keep moving forward!\n");
    } else {
        tracker->dailySteps += steps;
        printf("You've logged %d steps! Keep it up! 🎉\n", steps);
    }
}

void logWaterIntake(FitnessTracker *tracker) {
    int water;
    printf("Enter amount of water you drank today (in ml): ");
    scanf("%d", &water);
    
    if (water < 0) {
        printf("Water intake cannot be negative! Hydrate yourself! 💧\n");
    } else if (tracker->waterIntake + water > MAX_WATER_INTAKE) {
        printf("Whoa! You've exceeded the daily water limit! Take it easy! 🚰\n");
    } else {
        tracker->waterIntake += water;
        printf("Great job! You've logged %d ml of water! 💦\n", water);
    }
}

void addExercise(FitnessTracker *tracker) {
    if (tracker->numExercises >= MAX_EXERCISES) {
        printf("You've reached the maximum number of exercises! 🏋️‍♂️ Time to review your routine!\n");
        return;
    }

    char exercise[30];
    printf("Enter the name of the exercise: ");
    scanf("%s", exercise);
    strcpy(tracker->exercises[tracker->numExercises++], exercise);
    printf("Awesome! You've added %s to your workout routine! 🎈\n", exercise);
}

void viewSummary(FitnessTracker *tracker) {
    printf("\n=== Fitness Summary ===\n");
    printf("Total Steps: %d\n", tracker->dailySteps);
    printf("Total Water Intake: %d ml\n", tracker->waterIntake);
    printf("Exercises Completed: \n");
    for (int i = 0; i < tracker->numExercises; i++) {
        printf("  - %s\n", tracker->exercises[i]);
    }
    printf("========================\n");
    printf("Keep pushing towards your goals! 🌟\n\n");
}

int main() {
    FitnessTracker myTracker;
    initializeTracker(&myTracker);
    int choice;

    do {
        displayMenu();
        printf("Select an option (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                logSteps(&myTracker);
                break;
            case 2:
                logWaterIntake(&myTracker);
                break;
            case 3:
                addExercise(&myTracker);
                break;
            case 4:
                viewSummary(&myTracker);
                break;
            case 5:
                printf("Thank you for using the Happy Fitness Tracker! Keep moving and stay healthy! ✌️\n");
                break;
            default:
                printf("Invalid choice! Please select a number between 1 and 5.\n");
        }
    } while (choice != 5);
    
    return 0;
}