//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int steps;
    float distance; // in kilometers
    float calories; // burned
} FitnessEntry;

FitnessEntry entries[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Maximum number of entries reached. Cannot add more.\n");
        return;
    }

    FitnessEntry entry;

    printf("Enter your name: ");
    getchar(); // Clear newline before using fgets
    fgets(entry.name, NAME_LENGTH, stdin);
    entry.name[strcspn(entry.name, "\n")] = 0; // Remove newline character

    printf("Enter steps taken today: ");
    scanf("%d", &entry.steps);

    printf("Enter distance covered today (in km): ");
    scanf("%f", &entry.distance);

    printf("Enter calories burned today: ");
    scanf("%f", &entry.calories);
    
    // Store the entry
    entries[entryCount++] = entry;

    printf("Entry added successfully.\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries to display.\n");
        return;
    }

    printf("\nFitness Tracker Entries:\n");
    printf("-------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s | %-10s |\n", "Name", "Steps", "Distance", "Calories");
    printf("-------------------------------------------------\n");
    
    for (int i = 0; i < entryCount; i++) {
        printf("| %-20s | %-10d | %-10.2f | %-10.2f |\n", 
                entries[i].name, 
                entries[i].steps, 
                entries[i].distance, 
                entries[i].calories);
    }
    
    printf("-------------------------------------------------\n");
}

void calculateStatistics() {
    if (entryCount == 0) {
        printf("No entries to calculate statistics.\n");
        return;
    }

    int totalSteps = 0;
    float totalDistance = 0.0;
    float totalCalories = 0.0;

    for (int i = 0; i < entryCount; i++) {
        totalSteps += entries[i].steps;
        totalDistance += entries[i].distance;
        totalCalories += entries[i].calories;
    }

    printf("\nFitness Tracker Statistics:\n");
    printf("-------------------------------------------------\n");
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Calories Burned: %.2f\n", totalCalories);
    printf("Average Steps per Entry: %.2f\n", (float)totalSteps / entryCount);
    printf("Average Distance per Entry: %.2f km\n", totalDistance / entryCount);
    printf("Average Calories per Entry: %.2f\n", totalCalories / entryCount);
    printf("-------------------------------------------------\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Calculate Statistics\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                calculateStatistics();
                break;
            case 4:
                printf("Exiting Fitness Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}