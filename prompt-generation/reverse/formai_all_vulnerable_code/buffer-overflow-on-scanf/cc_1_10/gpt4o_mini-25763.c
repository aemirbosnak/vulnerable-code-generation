//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50

struct FitnessEntry {
    char date[11]; // Format: YYYY-MM-DD
    char activity[MAX_NAME_LENGTH];
    int duration; // In minutes
    int caloriesBurned;
};

struct FitnessTracker {
    struct FitnessEntry entries[MAX_ENTRIES];
    int count;
};

void addEntry(struct FitnessTracker *tracker, const char *activity, int duration, int calories) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Error: Maximum entries reached.\n");
        return;
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    sprintf(tracker->entries[tracker->count].date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    strncpy(tracker->entries[tracker->count].activity, activity, MAX_NAME_LENGTH - 1);
    tracker->entries[tracker->count].activity[MAX_NAME_LENGTH - 1] = '\0'; // Null-terminate
    tracker->entries[tracker->count].duration = duration;
    tracker->entries[tracker->count].caloriesBurned = calories;

    tracker->count++;
    printf("Entry added: %s, Duration: %d min, Calories: %d\n", activity, duration, calories);
}

void displayEntries(const struct FitnessTracker *tracker) {
    printf("\nFitness Tracker Entries:\n");
    printf("Date         Activity                      Duration (min)  Calories Burned\n");
    printf("--------------------------------------------------------------------------\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%s      %-30s      %d                %d\n",
               tracker->entries[i].date,
               tracker->entries[i].activity,
               tracker->entries[i].duration,
               tracker->entries[i].caloriesBurned);
    }
}

int main() {
    struct FitnessTracker tracker;
    tracker.count = 0;

    int choice;
    char activity[MAX_NAME_LENGTH];
    int duration, calories;

    while (1) {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter activity name: ");
                scanf(" %[^\n]s", activity); // Read string with spaces
                printf("Enter duration in minutes: ");
                scanf("%d", &duration);
                printf("Enter calories burned: ");
                scanf("%d", &calories);
                addEntry(&tracker, activity, duration, calories);
                break;
            case 2:
                displayEntries(&tracker);
                break;
            case 3:
                printf("Exiting program. Stay fit!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}