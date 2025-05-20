//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_EXERCISE_LENGTH 50
#define DATE_LENGTH 11 // Format: YYYY-MM-DD

typedef struct {
    char date[DATE_LENGTH];
    char exercise[MAX_EXERCISE_LENGTH];
    int duration; // Duration in minutes
    int calories; // Calories burned
} ExerciseEntry;

typedef struct {
    ExerciseEntry entries[MAX_ENTRIES];
    int count;
} FitnessTracker;

void initializeTracker(FitnessTracker *tracker) {
    tracker->count = 0;
}

void addEntry(FitnessTracker *tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Fitness Tracker is full! Cannot add more entries.\n");
        return;
    }
    
    ExerciseEntry entry;
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", entry.date);
    printf("Enter exercise name: ");
    scanf(" %[^\n]", entry.exercise);
    printf("Enter duration (in minutes): ");
    scanf("%d", &entry.duration);
    printf("Enter calories burned: ");
    scanf("%d", &entry.calories);

    tracker->entries[tracker->count] = entry;
    tracker->count++;
    printf("Entry added successfully!\n");
}

void displayEntries(FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No exercise entries to display.\n");
        return;
    }

    printf("\n--- Fitness Tracker Entries ---\n");
    for (int i = 0; i < tracker->count; i++) {
        ExerciseEntry entry = tracker->entries[i];
        printf("Date: %s, Exercise: %s, Duration: %d min, Calories: %d\n", 
                entry.date, entry.exercise, entry.duration, entry.calories);
    }
}

void calculateTotals(FitnessTracker *tracker) {
    int totalDuration = 0;
    int totalCalories = 0;

    for (int i = 0; i < tracker->count; i++) {
        totalDuration += tracker->entries[i].duration;
        totalCalories += tracker->entries[i].calories;
    }

    printf("\n--- Total Exercise Summary ---\n");
    printf("Total Duration: %d minutes\n", totalDuration);
    printf("Total Calories Burned: %d calories\n", totalCalories);
}

void displayMenu() {
    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Add Exercise Entry\n");
    printf("2. Display Entries\n");
    printf("3. Calculate Totals\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    FitnessTracker tracker;
    initializeTracker(&tracker);
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(&tracker);
                break;
            case 2:
                displayEntries(&tracker);
                break;
            case 3:
                calculateTotals(&tracker);
                break;
            case 4:
                printf("Exiting the Fitness Tracker. Keep moving!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}