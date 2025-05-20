//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int duration; // in minutes
    int calorieBurn; // in calories
} Workout;

typedef struct {
    Workout workouts[MAX_WORKOUTS];
    int count;
} FitnessTracker;

void addWorkout(FitnessTracker *tracker, const char *name, int duration, int calorieBurn) {
    if (tracker->count < MAX_WORKOUTS) {
        strncpy(tracker->workouts[tracker->count].name, name, NAME_LENGTH);
        tracker->workouts[tracker->count].duration = duration;
        tracker->workouts[tracker->count].calorieBurn = calorieBurn;
        tracker->count++;
        printf("Workout added: %s, Duration: %d mins, Calories Burned: %d\n", name, duration, calorieBurn);
    } else {
        printf("Workout log is full. Cannot add more workouts.\n");
    }
}

void displayWorkouts(const FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No workouts logged yet.\n");
        return;
    }

    printf("Logged Workouts:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s - Duration: %d mins, Calories Burned: %d\n",
               i + 1, tracker->workouts[i].name, tracker->workouts[i].duration, tracker->workouts[i].calorieBurn);
    }
}

void calculateTotalStats(const FitnessTracker *tracker) {
    int totalDuration = 0;
    int totalCalories = 0;

    for (int i = 0; i < tracker->count; i++) {
        totalDuration += tracker->workouts[i].duration;
        totalCalories += tracker->workouts[i].calorieBurn;
    }

    printf("Total Duration: %d mins\n", totalDuration);
    printf("Total Calories Burned: %d\n", totalCalories);
}

void deleteWorkout(FitnessTracker *tracker, int index) {
    if (index < 0 || index >= tracker->count) {
        printf("Invalid workout index. Cannot delete.\n");
        return;
    }

    for (int i = index; i < tracker->count - 1; i++) {
        tracker->workouts[i] = tracker->workouts[i + 1];
    }
    tracker->count--;
    printf("Workout deleted successfully.\n");
}

void showMenu() {
    printf("\n=== Fitness Tracker Menu ===\n");
    printf("1. Add Workout\n");
    printf("2. View Workouts\n");
    printf("3. View Total Stats\n");
    printf("4. Delete Workout\n");
    printf("5. Exit\n");
}

int main() {
    FitnessTracker tracker;
    tracker.count = 0;

    int choice;
    char name[NAME_LENGTH];
    int duration, calories, index;

    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter workout name: ");
            scanf("%s", name);
            printf("Enter duration in minutes: ");
            scanf("%d", &duration);
            printf("Enter calories burned: ");
            scanf("%d", &calories);
            addWorkout(&tracker, name, duration, calories);
            break;

        case 2:
            displayWorkouts(&tracker);
            break;

        case 3:
            calculateTotalStats(&tracker);
            break;

        case 4:
            printf("Enter the workout index to delete: ");
            scanf("%d", &index);
            deleteWorkout(&tracker, index - 1); // Adjust for 0-indexing
            break;

        case 5:
            printf("Exiting the program. Stay fit!\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 5);

    return 0;
}