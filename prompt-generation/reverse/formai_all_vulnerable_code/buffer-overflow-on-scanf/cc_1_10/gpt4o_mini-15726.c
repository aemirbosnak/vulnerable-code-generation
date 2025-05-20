//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORKOUTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 11

typedef struct {
    char date[MAX_DATE_LENGTH];
    char workoutType[MAX_NAME_LENGTH];
    int durationMinutes;
    int caloriesBurned;
} Workout;

typedef struct {
    Workout workouts[MAX_WORKOUTS];
    int totalWorkouts;
} FitnessTracker;

void logWorkout(FitnessTracker *tracker) {
    if (tracker->totalWorkouts >= MAX_WORKOUTS) {
        printf("Workout log is full! Cannot log more workouts.\n");
        return;
    }

    Workout newWorkout;
    char dateBuffer[MAX_DATE_LENGTH];

    // Get the current date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    snprintf(dateBuffer, sizeof(dateBuffer), "%04d-%02d-%02d", 
             tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
   
    strcpy(newWorkout.date, dateBuffer);

    printf("Enter workout type (e.g., Running, Cycling, Swimming): ");
    scanf(" %[^\n]s", newWorkout.workoutType);
    
    printf("Enter duration in minutes: ");
    scanf("%d", &newWorkout.durationMinutes);
    
    printf("Enter calories burned: ");
    scanf("%d", &newWorkout.caloriesBurned);
    
    tracker->workouts[tracker->totalWorkouts++] = newWorkout;
    printf("Workout logged successfully on %s!\n", newWorkout.date);
}

void viewWorkouts(FitnessTracker *tracker) {
    if (tracker->totalWorkouts == 0) {
        printf("No workouts logged yet.\n");
        return;
    }

    printf("\nYour Workouts:\n");
    for (int i = 0; i < tracker->totalWorkouts; ++i) {
        printf("Date: %s, Type: %s, Duration: %d min, Calories: %d kcal\n", 
               tracker->workouts[i].date, 
               tracker->workouts[i].workoutType, 
               tracker->workouts[i].durationMinutes, 
               tracker->workouts[i].caloriesBurned);
    }
}

void calculateTotals(FitnessTracker *tracker) {
    int totalDuration = 0;
    int totalCalories = 0;

    for (int i = 0; i < tracker->totalWorkouts; ++i) {
        totalDuration += tracker->workouts[i].durationMinutes;
        totalCalories += tracker->workouts[i].caloriesBurned;
    }

    printf("\nTotal Workouts: %d\n", tracker->totalWorkouts);
    printf("Total Duration: %d minutes\n", totalDuration);
    printf("Total Calories Burned: %d kcal\n", totalCalories);
}

void displayMenu() {
    printf("\n=== Fitness Tracker Menu ===\n");
    printf("1. Log a Workout\n");
    printf("2. View Workouts\n");
    printf("3. Calculate Totals\n");
    printf("4. Exit\n");
}

int main() {
    FitnessTracker myTracker;
    myTracker.totalWorkouts = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                logWorkout(&myTracker);
                break;
            case 2:
                viewWorkouts(&myTracker);
                break;
            case 3:
                calculateTotals(&myTracker);
                break;
            case 4:
                printf("Exiting the Fitness Tracker. Stay active!\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}