//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float distance; // in kilometers
    int steps;
    time_t date;
} FitnessEntry;

typedef struct {
    FitnessEntry entries[MAX_ENTRIES];
    int count;
} FitnessTracker;

void addEntry(FitnessTracker* tracker, const char* name, float distance, int steps) {
    if (tracker->count < MAX_ENTRIES) {
        strncpy(tracker->entries[tracker->count].name, name, MAX_NAME_LENGTH);
        tracker->entries[tracker->count].distance = distance;
        tracker->entries[tracker->count].steps = steps;
        tracker->entries[tracker->count].date = time(NULL);
        tracker->count++;
        printf("New entry added for %s: %.2f km and %d steps.\n", name, distance, steps);
    } else {
        printf("Fitness tracker is full! Cannot add more entries.\n");
    }
}

void displayEntries(const FitnessTracker* tracker) {
    printf("\n--- Fitness Tracker Entries ---\n");
    for (int i = 0; i < tracker->count; i++) {
        struct tm* timeInfo = localtime(&tracker->entries[i].date);
        char dateBuffer[20];
        strftime(dateBuffer, sizeof(dateBuffer), "%Y-%m-%d %H:%M", timeInfo);
        
        printf("Entry #%d: Date: %s, Name: %s, Distance: %.2f km, Steps: %d\n",
               i + 1, dateBuffer, tracker->entries[i].name,
               tracker->entries[i].distance, tracker->entries[i].steps);
    }
}

void calculateStats(const FitnessTracker* tracker) {
    if (tracker->count == 0) {
        printf("No entries to calculate statistics.\n");
        return;
    }

    float totalDistance = 0.0;
    int totalSteps = 0;

    for (int i = 0; i < tracker->count; i++) {
        totalDistance += tracker->entries[i].distance;
        totalSteps += tracker->entries[i].steps;
    }

    float averageDistance = totalDistance / tracker->count;
    float averageSteps = totalSteps / (float)tracker->count;
    
    printf("\n--- Fitness Tracker Statistics ---\n");
    printf("Total Entries: %d\n", tracker->count);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Steps: %d\n", totalSteps);
    printf("Average Distance: %.2f km\n", averageDistance);
    printf("Average Steps: %.2f\n", averageSteps);
}

int main() {
    FitnessTracker tracker;
    tracker.count = 0;

    int choice;
    char name[MAX_NAME_LENGTH];
    float distance;
    int steps;

    do {
        printf("\n--- Fitness Tracker Menu ---\n");
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Calculate Statistics\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter distance (in km): ");
                scanf("%f", &distance);
                printf("Enter steps: ");
                scanf("%d", &steps);
                addEntry(&tracker, name, distance, steps);
                break;
            case 2:
                displayEntries(&tracker);
                break;
            case 3:
                calculateStats(&tracker);
                break;
            case 4:
                printf("Exiting Fitness Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}