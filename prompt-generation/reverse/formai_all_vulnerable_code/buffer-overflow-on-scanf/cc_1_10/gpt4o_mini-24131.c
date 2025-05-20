//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char workoutName[MAX_NAME_LENGTH];
    int duration; // in minutes
    int caloriesBurnedPerMinute; // calories burned per minute
} Workout;

typedef struct {
    Workout workouts[MAX_WORKOUTS];
    int workoutCount;
} FitnessTracker;

void addWorkout(FitnessTracker* tracker);
void displayWorkouts(const FitnessTracker* tracker);
void calculateTotalCalories(const FitnessTracker* tracker);
void menu();

int main() {
    FitnessTracker tracker;
    tracker.workoutCount = 0;

    int choice;
    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

void menu() {
    printf("\nFitness Tracker Menu:\n");
    printf("1. Add Workout\n");
    printf("2. Display Workouts\n");
    printf("3. Calculate Total Calories Burned\n");
    printf("4. Exit\n");
}

void addWorkout(FitnessTracker* tracker) {
    if (tracker->workoutCount >= MAX_WORKOUTS) {
        printf("Cannot add more workouts. Maximum limit reached!\n");
        return;
    }

    Workout newWorkout;
    printf("Enter workout name: ");
    scanf("%s", newWorkout.workoutName);
    printf("Enter duration in minutes: ");
    scanf("%d", &newWorkout.duration);
    printf("Enter calories burned per minute: ");
    scanf("%d", &newWorkout.caloriesBurnedPerMinute);

    tracker->workouts[tracker->workoutCount] = newWorkout;
    tracker->workoutCount++;
    printf("Workout added successfully!\n");
}

void displayWorkouts(const FitnessTracker* tracker) {
    if (tracker->workoutCount == 0) {
        printf("No workouts logged yet!\n");
        return;
    }

    printf("\nLogged Workouts:\n");
    for (int i = 0; i < tracker->workoutCount; i++) {
        printf("Workout %d: %s, Duration: %d minutes, Calories Burned/Minute: %d\n",
               i + 1, tracker->workouts[i].workoutName, tracker->workouts[i].duration,
               tracker->workouts[i].caloriesBurnedPerMinute);
    }
}

void calculateTotalCalories(const FitnessTracker* tracker) {
    if (tracker->workoutCount == 0) {
        printf("No workouts logged yet!\n");
        return;
    }

    int totalCalories = 0;
    for (int i = 0; i < tracker->workoutCount; i++) {
        totalCalories += tracker->workouts[i].duration * tracker->workouts[i].caloriesBurnedPerMinute;
    }

    printf("Total calories burned from logged workouts: %d\n", totalCalories);
}