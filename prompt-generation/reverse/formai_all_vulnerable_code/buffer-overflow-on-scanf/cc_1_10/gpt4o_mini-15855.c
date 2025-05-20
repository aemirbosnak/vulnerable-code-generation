//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORKOUTS 100
#define MAX_DESC_LENGTH 100

typedef struct {
    char description[MAX_DESC_LENGTH];
    int calories;
    time_t timestamp;
} Workout;

typedef struct {
    Workout workouts[MAX_WORKOUTS];
    int count;
} FitnessTracker;

void addWorkout(FitnessTracker *tracker) {
    if (tracker->count >= MAX_WORKOUTS) {
        printf("Workout log is full!\n");
        return;
    }

    Workout newWorkout;
    
    printf("Enter workout description: ");
    getchar();  // Clear newline from input buffer
    fgets(newWorkout.description, MAX_DESC_LENGTH, stdin);
    newWorkout.description[strcspn(newWorkout.description, "\n")] = 0; // Remove the newline
    
    printf("Enter calories burned: ");
    scanf("%d", &newWorkout.calories);
    
    newWorkout.timestamp = time(NULL); // Get the current time

    tracker->workouts[tracker->count] = newWorkout;
    tracker->count++;

    printf("Workout added!\n");
}

void viewWorkouts(FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No workouts logged yet.\n");
        return;
    }

    printf("\nWorkout History:\n");
    for (int i = 0; i < tracker->count; i++) {
        char timeBuf[26];
        struct tm* tm_info;

        tm_info = localtime(&tracker->workouts[i].timestamp);
        strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", tm_info);
        
        printf("Workout %d:\n", i + 1);
        printf(" Description: %s\n", tracker->workouts[i].description);
        printf(" Calories Burned: %d\n", tracker->workouts[i].calories);
        printf(" Date and Time: %s\n\n", timeBuf);
    }
}

int main() {
    FitnessTracker tracker;
    tracker.count = 0;

    int choice;

    do {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add Workout\n");
        printf("2. View Workouts\n");
        printf("3. Exit\n");
        printf("Choose an option (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addWorkout(&tracker);
                break;
            case 2:
                viewWorkouts(&tracker);
                break;
            case 3:
                printf("Exiting Fitness Tracker. Keep up the good work!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}