//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORKOUTS 100
#define MAX_EXERCISE_NAME 50
#define MAX_DATE_LENGTH 11
#define CONFIG_FILE "config.txt"

typedef struct {
    char name[MAX_EXERCISE_NAME];
    int duration; // minutes
    int caloriesBurned;
} Workout;

typedef struct {
    Workout workouts[MAX_WORKOUTS];
    int workoutCount;
    int calorieGoal;
} FitnessTracker;

void printMenu() {
    printf("\n=== Fitness Tracker Menu ===\n");
    printf("1. Add Workout\n");
    printf("2. View Workouts\n");
    printf("3. View Goals\n");
    printf("4. Exit\n");
    printf("===========================\n");
}

void saveConfig(FitnessTracker *tracker) {
    FILE *file = fopen(CONFIG_FILE, "w");
    if (file != NULL) {
        fprintf(file, "CalorieGoal: %d\n", tracker->calorieGoal);
        fclose(file);
    } else {
        printf("Error saving configuration.\n");
    }
}

void loadConfig(FitnessTracker *tracker) {
    FILE *file = fopen(CONFIG_FILE, "r");
    if (file != NULL) {
        fscanf(file, "CalorieGoal: %d\n", &tracker->calorieGoal);
        fclose(file);
    } else {
        tracker->calorieGoal = 2000; // Default goal
    }
}

void addWorkout(FitnessTracker *tracker) {
    if (tracker->workoutCount < MAX_WORKOUTS) {
        Workout newWorkout;
        printf("Enter exercise name: ");
        scanf("%s", newWorkout.name);
        printf("Enter duration (minutes): ");
        scanf("%d", &newWorkout.duration);
        printf("Enter calories burned: ");
        scanf("%d", &newWorkout.caloriesBurned);

        tracker->workouts[tracker->workoutCount] = newWorkout;
        tracker->workoutCount++;

        saveConfig(tracker); // Save the calorie goal after adding a workout
        printf("Workout added!\n");
    } else {
        printf("Workout limit reached!\n");
    }
}

void viewWorkouts(FitnessTracker *tracker) {
    printf("\n=== Workouts Log ===\n");
    for (int i = 0; i < tracker->workoutCount; i++) {
        printf("Workout %d: %s, Duration: %d min, Calories Burned: %d\n",
               i + 1, tracker->workouts[i].name, tracker->workouts[i].duration, tracker->workouts[i].caloriesBurned);
    }
    printf("=====================\n");
}

void viewGoals(FitnessTracker *tracker) {
    printf("\nCalorie Goal: %d\n", tracker->calorieGoal);
    int totalCalories = 0;
    for (int i = 0; i < tracker->workoutCount; i++) {
        totalCalories += tracker->workouts[i].caloriesBurned;
    }
    printf("Total Calories Burned: %d\n", totalCalories);
    printf("Remaining Calories to Goal: %d\n", tracker->calorieGoal - totalCalories);
}

int main() {
    FitnessTracker tracker;
    tracker.workoutCount = 0;
    loadConfig(&tracker);

    int choice;
    do {
        printMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addWorkout(&tracker);
                break;
            case 2:
                viewWorkouts(&tracker);
                break;
            case 3:
                viewGoals(&tracker);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}