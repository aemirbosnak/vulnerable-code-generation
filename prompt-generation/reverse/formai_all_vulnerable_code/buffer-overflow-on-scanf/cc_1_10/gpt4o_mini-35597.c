//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    int steps;
    float distance; // in kilometers
    int calories; // calories burned
} FitnessEntry;

FitnessEntry tracker[MAX_ENTRIES];
int entryCount = 0;

void addEntry(const char *date, int steps, float distance, int calories) {
    if (entryCount >= MAX_ENTRIES) {
        printf("Tracker is full! Cannot add more entries.\n");
        return;
    }
    
    strncpy(tracker[entryCount].date, date, 10);
    tracker[entryCount].steps = steps;
    tracker[entryCount].distance = distance;
    tracker[entryCount].calories = calories;
    entryCount++;
    printf("Entry added for date: %s\n", date);
}

void displayEntries() {
    if (entryCount == 0) {
        printf("No entries found.\n");
        return;
    }
    
    printf("\nFitness Tracker Entries:\n");
    printf("%-12s %-10s %-10s %-10s\n", "Date", "Steps", "Distance", "Calories");
    for (int i = 0; i < entryCount; i++) {
        printf("%-12s %-10d %-10.2f %-10d\n", 
               tracker[i].date, 
               tracker[i].steps, 
               tracker[i].distance, 
               tracker[i].calories);
    }
}

void getStats() {
    if (entryCount == 0) {
        printf("No entries available for statistics.\n");
        return;
    }
    
    int totalSteps = 0;
    float totalDistance = 0;
    int totalCalories = 0;

    for (int i = 0; i < entryCount; i++) {
        totalSteps += tracker[i].steps;
        totalDistance += tracker[i].distance;
        totalCalories += tracker[i].calories;
    }
    
    printf("\nFitness Tracker Statistics:\n");
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Calories Burned: %d\n", totalCalories);
    printf("Average Steps per Entry: %.2f\n", (float)totalSteps / entryCount);
    printf("Average Distance per Entry: %.2f km\n", totalDistance / entryCount);
    printf("Average Calories per Entry: %.2f\n", (float)totalCalories / entryCount);
}

void clearEntries() {
    entryCount = 0;
    printf("All entries cleared.\n");
}

void menu() {
    printf("\nFitness Tracker Menu:\n");
    printf("1. Add Entry\n");
    printf("2. Display All Entries\n");
    printf("3. Get Statistics\n");
    printf("4. Clear All Entries\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    char date[11];
    int steps;
    float distance;
    int calories;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Enter steps: ");
                scanf("%d", &steps);
                printf("Enter distance (in km): ");
                scanf("%f", &distance);
                printf("Enter calories burned: ");
                scanf("%d", &calories);
                addEntry(date, steps, distance, calories);
                break;
            case 2:
                displayEntries();
                break;
            case 3:
                getStats();
                break;
            case 4:
                clearEntries();
                break;
            case 5:
                printf("Exiting the Fitness Tracker.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}