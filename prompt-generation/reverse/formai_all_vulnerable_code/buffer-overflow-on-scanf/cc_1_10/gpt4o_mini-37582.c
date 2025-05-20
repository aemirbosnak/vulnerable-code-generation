//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 30

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

void initializeTracker(FitnessTracker *tracker) {
    tracker->count = 0;
}

void addEntry(FitnessTracker *tracker, const char *date, int steps, float distance, int calories) {
    if (tracker->count < MAX_ENTRIES) {
        strcpy(tracker->entries[tracker->count].date, date);
        tracker->entries[tracker->count].steps = steps;
        tracker->entries[tracker->count].distance = distance;
        tracker->entries[tracker->count].calories = calories;
        tracker->count++;
    } else {
        printf("Fitness Tracker full. Cannot add more entries.\n");
    }
}

void printSummary(const FitnessTracker *tracker) {
    printf("\n--- Fitness Summary ---\n");
    if (tracker->count == 0) {
        printf("No entries found.\n");
        return;
    }
    for (int i = 0; i < tracker->count; i++) {
        printf("Date: %s | Steps: %d | Distance: %.2f km | Calories: %d\n",
               tracker->entries[i].date,
               tracker->entries[i].steps,
               tracker->entries[i].distance,
               tracker->entries[i].calories);
    }
    printf("----------------------\n");
}

void displayMenu() {
    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Add Entry\n");
    printf("2. Show Summary\n");
    printf("3. Exit\n");
    printf("----------------------------\n");
}

void captureInput(char *buffer, int length) {
    fgets(buffer, length, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
}

int main() {
    FitnessTracker tracker;
    initializeTracker(&tracker);
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the buffer
        
        switch (choice) {
            case 1: {
                char date[11];
                int steps;
                float distance;
                int calories;

                printf("Enter date (YYYY-MM-DD): ");
                captureInput(date, sizeof(date));
                printf("Enter steps: ");
                scanf("%d", &steps);
                printf("Enter distance in km: ");
                scanf("%f", &distance);
                printf("Enter calories burned: ");
                scanf("%d", &calories);
                getchar(); // Clear the newline
                
                addEntry(&tracker, date, steps, distance, calories);
                printf("Entry added successfully!\n");
                break;
            }
            case 2: {
                printSummary(&tracker);
                break;
            }
            case 3:
                printf("Exiting the Fitness Tracker. Stay fit!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}