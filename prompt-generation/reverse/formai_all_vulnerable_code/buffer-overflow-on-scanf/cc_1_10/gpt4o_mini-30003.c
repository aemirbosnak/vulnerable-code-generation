//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int duration; // duration in minutes
    int calories; // calories burned
} Workout;

typedef struct {
    Workout workouts[MAX_WORKOUTS];
    int count;
} FitnessTracker;

void addWorkout(FitnessTracker *tracker) {
    if (tracker->count >= MAX_WORKOUTS) {
        printf("Workout history is full!\n");
        return;
    }

    Workout newWorkout;
    printf("Enter workout name: ");
    scanf("%s", newWorkout.name);
    printf("Enter workout duration (in minutes): ");
    scanf("%d", &newWorkout.duration);
    printf("Enter calories burned: ");
    scanf("%d", &newWorkout.calories);

    tracker->workouts[tracker->count] = newWorkout;
    tracker->count++;

    printf("Workout added successfully!\n");
}

void viewWorkouts(FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No workouts logged yet!\n");
        return;
    }

    printf("\nWorkout History:\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d - %s | Duration: %d min | Calories: %d\n", 
               i + 1, tracker->workouts[i].name, 
               tracker->workouts[i].duration, tracker->workouts[i].calories);
    }
    printf("-------------------------------------------------\n");
}

void viewStatistics(FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No workouts logged yet!\n");
        return;
    }

    int totalDuration = 0;
    int totalCalories = 0;
    for (int i = 0; i < tracker->count; i++) {
        totalDuration += tracker->workouts[i].duration;
        totalCalories += tracker->workouts[i].calories;
    }

    printf("\nFitness Statistics:\n");
    printf("Total Workouts: %d\n", tracker->count);
    printf("Total Duration: %d minutes\n", totalDuration);
    printf("Total Calories Burned: %d kcal\n", totalCalories);
    printf("Average Duration: %.2f minutes\n", (float)totalDuration / tracker->count);
    printf("Average Calories Burned: %.2f kcal\n", (float)totalCalories / tracker->count);
}

void displayMenu() {
    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Add Workout\n");
    printf("2. View Workouts\n");
    printf("3. View Statistics\n");
    printf("4. Exit\n");
    printf("----------------------------\n");
}

int main() {
    FitnessTracker tracker;
    tracker.count = 0;

    int choice;
    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addWorkout(&tracker);
                break;
            case 2:
                viewWorkouts(&tracker);
                break;
            case 3:
                viewStatistics(&tracker);
                break;
            case 4:
                printf("Exiting the Fitness Tracker. Stay fit!\n");
                break;
            default:
                printf("Invalid option! Please choose again.\n");
        }
    } while (choice != 4);

    return 0;
}