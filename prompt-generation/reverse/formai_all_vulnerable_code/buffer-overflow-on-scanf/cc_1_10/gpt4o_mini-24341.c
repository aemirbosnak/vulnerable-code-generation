//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[11]; // format: YYYY-MM-DD
    int steps;
    float distance; // in kilometers
    int calories; // calories burned
} FitnessEntry;

typedef struct {
    FitnessEntry entries[MAX_ENTRIES];
    int count;
} FitnessTracker;

void addEntry(FitnessTracker *tracker);
void displayEntries(const FitnessTracker *tracker);
void generateReport(const FitnessTracker *tracker);
void clearEntries(FitnessTracker *tracker);

int main() {
    FitnessTracker tracker = { .count = 0 };
    int choice;

    printf("Welcome to the C Fitness Tracker!\n");
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Generate Report\n");
        printf("4. Clear All Entries\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(&tracker);
                break;
            case 2:
                displayEntries(&tracker);
                break;
            case 3:
                generateReport(&tracker);
                break;
            case 4:
                clearEntries(&tracker);
                break;
            case 5:
                printf("Exiting the Fitness Tracker. Stay fit and keep moving!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void addEntry(FitnessTracker *tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Maximum entries reached. Please clear some entries to add new ones.\n");
        return;
    }
    
    FitnessEntry newEntry;
    
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", newEntry.date);
    
    printf("Enter steps taken: ");
    scanf("%d", &newEntry.steps);
    
    printf("Enter distance covered (in km): ");
    scanf("%f", &newEntry.distance);
    
    printf("Enter calories burned: ");
    scanf("%d", &newEntry.calories);
    
    tracker->entries[tracker->count] = newEntry;
    tracker->count++;
    printf("Entry added successfully!\n");
}

void displayEntries(const FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No entries to display.\n");
        return;
    }

    printf("\nFitness Tracker Entries:\n");
    printf("Date\t\tSteps\tDistance (km)\tCalories\n");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%s\t%d\t%.2f\t\t%d\n", 
            tracker->entries[i].date, 
            tracker->entries[i].steps, 
            tracker->entries[i].distance, 
            tracker->entries[i].calories);
    }
}

void generateReport(const FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No entries to generate a report.\n");
        return;
    }

    int totalSteps = 0;
    float totalDistance = 0.0;
    int totalCalories = 0;

    for (int i = 0; i < tracker->count; i++) {
        totalSteps += tracker->entries[i].steps;
        totalDistance += tracker->entries[i].distance;
        totalCalories += tracker->entries[i].calories;
    }

    printf("\nFitness Tracker Report:\n");
    printf("Total Entries: %d\n", tracker->count);
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Calories Burned: %d\n", totalCalories);
}

void clearEntries(FitnessTracker *tracker) {
    tracker->count = 0;
    printf("All entries cleared!\n");
}