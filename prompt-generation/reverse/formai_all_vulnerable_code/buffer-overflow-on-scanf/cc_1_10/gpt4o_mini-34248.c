//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    time_t date;
    int steps;
    float caloriesBurned;
    int distance; // in meters
} FitnessEntry;

typedef struct {
    FitnessEntry entries[MAX_ENTRIES];
    int entryCount;
} FitnessTracker;

void addEntry(FitnessTracker *tracker);
void viewEntries(FitnessTracker *tracker);
void viewStatistics(FitnessTracker *tracker);
void clearEntries(FitnessTracker *tracker);
void displayMenu();

int main() {
    FitnessTracker tracker = {{0}, 0};
    int choice;

    while (1) {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(&tracker);
                break;
            case 2:
                viewEntries(&tracker);
                break;
            case 3:
                viewStatistics(&tracker);
                break;
            case 4:
                clearEntries(&tracker);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n==== Fitness Tracker ====\n");
    printf("1. Add Fitness Entry\n");
    printf("2. View Fitness Entries\n");
    printf("3. View Statistics\n");
    printf("4. Clear All Entries\n");
    printf("5. Exit\n");
    printf("=========================\n");
}

void addEntry(FitnessTracker *tracker) {
    if (tracker->entryCount >= MAX_ENTRIES) {
        printf("Maximum entries reached. Cannot add more.\n");
        return;
    }
    
    FitnessEntry newEntry;
    newEntry.date = time(NULL);

    printf("Enter steps taken: ");
    scanf("%d", &newEntry.steps);
    printf("Enter calories burned: ");
    scanf("%f", &newEntry.caloriesBurned);
    printf("Enter distance covered (meters): ");
    scanf("%d", &newEntry.distance);

    tracker->entries[tracker->entryCount] = newEntry;
    tracker->entryCount++;
    printf("Entry added successfully!\n");
}

void viewEntries(FitnessTracker *tracker) {
    if (tracker->entryCount == 0) {
        printf("No entries to display.\n");
        return;
    }

    printf("\n=== Fitness Entries ===\n");
    for (int i = 0; i < tracker->entryCount; i++) {
        char buffer[26];
        struct tm* tm_info;

        tm_info = localtime(&tracker->entries[i].date);
        strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);

        printf("Date: %s | Steps: %d | Calories Burned: %.2f | Distance: %d m\n", buffer,
               tracker->entries[i].steps, tracker->entries[i].caloriesBurned, tracker->entries[i].distance);
    }
    printf("=========================\n");
}

void viewStatistics(FitnessTracker *tracker) {
    if (tracker->entryCount == 0) {
        printf("No entries to calculate statistics.\n");
        return;
    }

    int totalSteps = 0;
    float totalCalories = 0;
    int totalDistance = 0;

    for (int i = 0; i < tracker->entryCount; i++) {
        totalSteps += tracker->entries[i].steps;
        totalCalories += tracker->entries[i].caloriesBurned;
        totalDistance += tracker->entries[i].distance;
    }

    float avgSteps = (float)totalSteps / tracker->entryCount;
    float avgCalories = totalCalories / tracker->entryCount;
    float avgDistance = (float)totalDistance / tracker->entryCount;

    printf("\n=== Fitness Statistics ===\n");
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Calories Burned: %.2f\n", totalCalories);
    printf("Total Distance Covered: %d m\n", totalDistance);
    printf("Average Steps/Day: %.2f\n", avgSteps);
    printf("Average Calories/Day: %.2f\n", avgCalories);
    printf("Average Distance/Day: %.2f m\n", avgDistance);
    printf("=========================\n");
}

void clearEntries(FitnessTracker *tracker) {
    tracker->entryCount = 0;
    printf("All entries cleared successfully.\n");
}