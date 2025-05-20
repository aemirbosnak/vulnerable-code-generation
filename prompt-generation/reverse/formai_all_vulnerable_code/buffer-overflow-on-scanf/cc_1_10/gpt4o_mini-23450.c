//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define DATE_LENGTH 11

typedef struct {
    char date[DATE_LENGTH];
    char exercise[NAME_LENGTH];
    int duration; // in minutes
    int caloriesBurned;
} WorkoutEntry;

typedef struct {
    WorkoutEntry entries[MAX_ENTRIES];
    int count;
} FitnessTracker;

void initializeTracker(FitnessTracker *tracker) {
    tracker->count = 0;
}

void logWorkout(FitnessTracker *tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Error: Workout log is full!\n");
        return;
    }
    
    WorkoutEntry entry;
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%10s", entry.date);
    printf("Enter exercise name: ");
    scanf("%49s", entry.exercise);
    printf("Enter duration in minutes: ");
    scanf("%d", &entry.duration);
    printf("Enter calories burned: ");
    scanf("%d", &entry.caloriesBurned);
    
    tracker->entries[tracker->count] = entry;
    tracker->count++;
    printf("Workout logged successfully!\n");
}

void displayWorkouts(const FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No workouts logged yet.\n");
        return;
    }
    
    printf("\nWorkout Log:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Entry %d:\n", i + 1);
        printf("  Date: %s\n", tracker->entries[i].date);
        printf("  Exercise: %s\n", tracker->entries[i].exercise);
        printf("  Duration: %d minutes\n", tracker->entries[i].duration);
        printf("  Calories Burned: %d\n\n", tracker->entries[i].caloriesBurned);
    }
}

void displayStatistics(const FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No workouts logged yet.\n");
        return;
    }
    
    int totalDuration = 0, totalCalories = 0;
    for (int i = 0; i < tracker->count; i++) {
        totalDuration += tracker->entries[i].duration;
        totalCalories += tracker->entries[i].caloriesBurned;
    }
    
    printf("Statistics:\n");
    printf("  Total Workouts Logged: %d\n", tracker->count);
    printf("  Total Duration: %d minutes\n", totalDuration);
    printf("  Total Calories Burned: %d\n", totalCalories);
    
    float averageDuration = (float)totalDuration / tracker->count;
    float averageCalories = (float)totalCalories / tracker->count;
    
    printf("  Average Duration: %.2f minutes\n", averageDuration);
    printf("  Average Calories Burned: %.2f\n", averageCalories);
}

int main() {
    FitnessTracker tracker;
    initializeTracker(&tracker);
    
    int choice;
    do {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Log Workout\n");
        printf("2. Display Workouts\n");
        printf("3. Display Statistics\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                logWorkout(&tracker);
                break;
            case 2:
                displayWorkouts(&tracker);
                break;
            case 3:
                displayStatistics(&tracker);
                break;
            case 4:
                printf("Exiting Fitness Tracker. Have a great day!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}