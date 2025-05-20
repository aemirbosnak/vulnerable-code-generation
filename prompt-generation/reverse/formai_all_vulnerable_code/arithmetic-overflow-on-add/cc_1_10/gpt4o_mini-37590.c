//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[11]; // format: YYYY-MM-DD
    int steps;
    float distance; // in kilometers
    float calories; // consumed calories
} FitnessEntry;

typedef struct {
    FitnessEntry entries[MAX_ENTRIES];
    int count;
} FitnessTracker;

void initializeTracker(FitnessTracker *tracker) {
    tracker->count = 0;
}

void addEntry(FitnessTracker *tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Cannot add more entries. Please delete some entries first.\n");
        return;
    }

    FitnessEntry newEntry;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(newEntry.date, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    printf("Enter steps for %s: ", newEntry.date);
    scanf("%d", &newEntry.steps);
    
    printf("Enter distance (in km) for %s: ", newEntry.date);
    scanf("%f", &newEntry.distance);
    
    printf("Enter calories burned for %s: ", newEntry.date);
    scanf("%f", &newEntry.calories);

    tracker->entries[tracker->count++] = newEntry;
    printf("Entry added for date: %s\n", newEntry.date);
}

void displayEntries(const FitnessTracker *tracker) {
    printf("\n--- Fitness Tracker Entries ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Date: %s | Steps: %d | Distance: %.2f km | Calories: %.2f\n",
               tracker->entries[i].date,
               tracker->entries[i].steps,
               tracker->entries[i].distance,
               tracker->entries[i].calories);
    }
    printf("--- End of Entries ---\n");
}

void deleteEntry(FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No entries to delete.\n");
        return;
    }

    printf("Enter the index of the entry to delete (0 to %d): ", tracker->count - 1);
    int index;
    scanf("%d", &index);
    
    if (index < 0 || index >= tracker->count) {
        printf("Invalid index. Please try again.\n");
        return;
    }

    for (int i = index; i < tracker->count - 1; i++) {
        tracker->entries[i] = tracker->entries[i + 1];
    }
    tracker->count--;
    printf("Entry at index %d deleted.\n", index);
}

void calculateStats(const FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No entries to calculate statistics.\n");
        return;
    }

    int totalSteps = 0;
    float totalDistance = 0.0;
    float totalCalories = 0.0;

    for (int i = 0; i < tracker->count; i++) {
        totalSteps += tracker->entries[i].steps;
        totalDistance += tracker->entries[i].distance;
        totalCalories += tracker->entries[i].calories;
    }

    printf("\n--- Statistics ---\n");
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Calories: %.2f\n", totalCalories);
    printf("--- End of Statistics ---\n");
}

void displayMenu() {
    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Add Entry\n");
    printf("2. Display Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Calculate Stats\n");
    printf("5. Exit\n");
    printf("---------------------------\n");
}

int main() {
    FitnessTracker tracker;
    initializeTracker(&tracker);
    
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEntry(&tracker);
                break;
            case 2:
                displayEntries(&tracker);
                break;
            case 3:
                deleteEntry(&tracker);
                break;
            case 4:
                calculateStats(&tracker);
                break;
            case 5:
                printf("Thank you for using the Fitness Tracker. Stay healthy!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}