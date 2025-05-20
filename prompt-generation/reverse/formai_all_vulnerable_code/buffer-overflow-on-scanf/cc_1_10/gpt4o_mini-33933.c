//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    int steps;
    float distance; // in kilometers
    int calories;
} FitnessEntry;

FitnessEntry entries[MAX_ENTRIES];
int entryCount = 0;

void addEntry(const char *date, int steps, float distance, int calories);
void viewEntries();
void totalSummary();
void inputEntry();
void clearEntries();

int main() {
    int choice;

    while (1) {
        printf("\n=== Fitness Tracker ===\n");
        printf("1. Add Fitness Entry\n");
        printf("2. View All Entries\n");
        printf("3. Total Summary\n");
        printf("4. Clear All Entries\n");
        printf("5. Quit\n");
        printf("Choose an option: ");
        
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                inputEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                totalSummary();
                break;
            case 4:
                clearEntries();
                break;
            case 5:
                printf("Exiting... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void inputEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Maximum entries reached. Cannot add more entries.\n");
        return;
    }

    FitnessEntry newEntry;
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", newEntry.date);
    printf("Enter steps: ");
    scanf("%d", &newEntry.steps);
    printf("Enter distance (in km): ");
    scanf("%f", &newEntry.distance);
    printf("Enter calories: ");
    scanf("%d", &newEntry.calories);

    addEntry(newEntry.date, newEntry.steps, newEntry.distance, newEntry.calories);
}

void addEntry(const char *date, int steps, float distance, int calories) {
    strcpy(entries[entryCount].date, date);
    entries[entryCount].steps = steps;
    entries[entryCount].distance = distance;
    entries[entryCount].calories = calories;
    entryCount++;
    printf("Entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries to display.\n");
        return;
    }

    printf("\n=== All Fitness Entries ===\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Date: %s, Steps: %d, Distance: %.2f km, Calories: %d\n",
               entries[i].date, entries[i].steps, entries[i].distance, entries[i].calories);
    }
}

void totalSummary() {
    if (entryCount == 0) {
        printf("No entries to summarize.\n");
        return;
    }

    int totalSteps = 0;
    float totalDistance = 0.0;
    int totalCalories = 0;

    for (int i = 0; i < entryCount; i++) {
        totalSteps += entries[i].steps;
        totalDistance += entries[i].distance;
        totalCalories += entries[i].calories;
    }

    printf("\n=== Total Summary ===\n");
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Calories: %d\n", totalCalories);
}

void clearEntries() {
    entryCount = 0;
    printf("All entries cleared successfully!\n");
}