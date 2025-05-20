//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    int steps;
    float distance; // in kilometers
    int calories;
} FitnessEntry;

typedef struct {
    FitnessEntry entries[MAX_ENTRIES];
    int count;
} FitnessTracker;

void initializeTracker(FitnessTracker* tracker) {
    tracker->count = 0;
}

void addEntry(FitnessTracker* tracker, const char* date, int steps, float distance, int calories) {
    if (tracker->count < MAX_ENTRIES) {
        strcpy(tracker->entries[tracker->count].date, date);
        tracker->entries[tracker->count].steps = steps;
        tracker->entries[tracker->count].distance = distance;
        tracker->entries[tracker->count].calories = calories;
        tracker->count++;
    } else {
        printf("Tracker is full! Cannot add more entries.\n");
    }
}

void displayEntries(const FitnessTracker* tracker) {
    if (tracker->count == 0) {
        printf("No entries to display.\n");
        return;
    }

    printf("\nFitness Tracker Entries:\n");
    printf("Date         Steps    Distance (km)  Calories\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%s   %d      %.2f            %d\n", 
               tracker->entries[i].date, 
               tracker->entries[i].steps, 
               tracker->entries[i].distance, 
               tracker->entries[i].calories);
    }
}

void calculateSummary(const FitnessTracker* tracker) {
    if (tracker->count == 0) {
        printf("No entries to summarize.\n");
        return;
    }
    
    int totalSteps = 0;
    float totalDistance = 0.0f;
    int totalCalories = 0;

    for (int i = 0; i < tracker->count; i++) {
        totalSteps += tracker->entries[i].steps;
        totalDistance += tracker->entries[i].distance;
        totalCalories += tracker->entries[i].calories;
    }

    printf("\nSummary:\n");
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Calories Burned: %d\n", totalCalories);
}

void clearEntries(FitnessTracker* tracker) {
    tracker->count = 0;
    printf("All entries cleared!\n");
}

void getCurrentDate(char* buffer, size_t size) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, size, "%Y-%m-%d", t);
}

int main() {
    FitnessTracker tracker;
    initializeTracker(&tracker);
    
    int choice;
    char date[11];
    int steps;
    float distance;
    int calories;

    do {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Calculate Summary\n");
        printf("4. Clear Entries\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                getCurrentDate(date, sizeof(date));
                printf("Enter steps: ");
                scanf("%d", &steps);
                printf("Enter distance (in km): ");
                scanf("%f", &distance);
                printf("Enter calories burned: ");
                scanf("%d", &calories);
                addEntry(&tracker, date, steps, distance, calories);
                printf("Entry added!\n");
                break;

            case 2:
                displayEntries(&tracker);
                break;

            case 3:
                calculateSummary(&tracker);
                break;

            case 4:
                clearEntries(&tracker);
                break;

            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}