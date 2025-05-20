//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float duration;  // in minutes
    float calories_burned;
} Workout;

typedef struct {
    Workout workouts[MAX_WORKOUTS];
    int workout_count;
} FitnessTracker;

void initTracker(FitnessTracker *tracker) {
    tracker->workout_count = 0;
}

void addWorkout(FitnessTracker *tracker) {
    if (tracker->workout_count < MAX_WORKOUTS) {
        Workout new_workout;
        printf("Enter workout name: ");
        fgets(new_workout.name, MAX_NAME_LENGTH, stdin);
        strtok(new_workout.name, "\n");  // Remove newline character
        printf("Enter duration (in minutes): ");
        scanf("%f", &new_workout.duration);
        printf("Enter calories burned: ");
        scanf("%f", &new_workout.calories_burned);
        getchar();  // Consume leftover newline character

        tracker->workouts[tracker->workout_count++] = new_workout;
        printf("Workout added successfully!\n");
    } else {
        printf("Workout log is full! Can't add more workouts.\n");
    }
}

void viewWorkouts(const FitnessTracker *tracker) {
    if (tracker->workout_count == 0) {
        printf("No workouts logged yet.\n");
        return;
    }

    printf("\n--- Your Workouts ---\n");
    for (int i = 0; i < tracker->workout_count; i++) {
        printf("Workout %d: %s\n", i + 1, tracker->workouts[i].name);
        printf("Duration: %.2f minutes\n", tracker->workouts[i].duration);
        printf("Calories burned: %.2f\n\n", tracker->workouts[i].calories_burned);
    }
}

void calculateTotalCalories(const FitnessTracker *tracker) {
    float total_calories = 0;
    for (int i = 0; i < tracker->workout_count; i++) {
        total_calories += tracker->workouts[i].calories_burned;
    }
    printf("Total calories burned from all workouts: %.2f\n", total_calories);
}

void displayMenu() {
    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Add a Workout\n");
    printf("2. View Workouts\n");
    printf("3. Calculate Total Calories\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    FitnessTracker tracker;
    initTracker(&tracker);
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar();  // Consume leftover newline character

        switch (choice) {
            case 1:
                addWorkout(&tracker);
                break;
            case 2:
                viewWorkouts(&tracker);
                break;
            case 3:
                calculateTotalCalories(&tracker);
                break;
            case 4:
                printf("Exiting Fitness Tracker. Keep up the good work!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    
    return 0;
}