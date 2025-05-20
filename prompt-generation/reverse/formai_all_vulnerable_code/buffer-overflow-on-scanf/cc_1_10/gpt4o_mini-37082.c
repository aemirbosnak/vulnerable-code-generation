//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50

typedef struct {
    char exerciseName[NAME_LENGTH];
    int duration; // in minutes
    int caloriesBurned;
} WorkoutEntry;

typedef struct {
    WorkoutEntry entries[MAX_ENTRIES];
    int count;
} FitnessTracker;

void initTracker(FitnessTracker* tracker) {
    tracker->count = 0;
}

void addEntry(FitnessTracker* tracker, const char* name, int duration, int calories) {
    if (tracker->count < MAX_ENTRIES) {
        strncpy(tracker->entries[tracker->count].exerciseName, name, NAME_LENGTH);
        tracker->entries[tracker->count].duration = duration;
        tracker->entries[tracker->count].caloriesBurned = calories;
        tracker->count++;
    } else {
        printf("Error: Workout entry limit reached.\n");
    }
}

void printWorkoutSummary(const FitnessTracker* tracker) {
    printf("\n--- Workout Summary ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Exercise: %s, Duration: %d mins, Calories Burned: %d kcal\n",
               tracker->entries[i].exerciseName,
               tracker->entries[i].duration,
               tracker->entries[i].caloriesBurned);
    }
    printf("-----------------------\n");
}

int totalCalories(const FitnessTracker* tracker) {
    int total = 0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->entries[i].caloriesBurned;
    }
    return total;
}

void getUserInput(char* name, int* duration, int* calories) {
    printf("Enter exercise name: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    printf("Enter duration in minutes: ");
    scanf("%d", duration);
    
    printf("Enter calories burned: ");
    scanf("%d", calories);
    
    // Clear buffer
    while (getchar() != '\n');
}

void displayMenu() {
    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Add Workout Entry\n");
    printf("2. View Workout Summary\n");
    printf("3. View Total Calories Burned\n");
    printf("4. Exit\n");
    printf("----------------------------\n");
    printf("Select an option: ");
}

int main() {
    FitnessTracker tracker;
    initTracker(&tracker);
    
    int choice;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                char name[NAME_LENGTH];
                int duration, calories;
                getUserInput(name, &duration, &calories);
                addEntry(&tracker, name, duration, calories);
                break;
            }
            case 2:
                printWorkoutSummary(&tracker);
                break;
            case 3:
                printf("\nTotal Calories Burned: %d kcal\n", totalCalories(&tracker));
                break;
            case 4:
                printf("Exiting the fitness tracker. Keep fit!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}