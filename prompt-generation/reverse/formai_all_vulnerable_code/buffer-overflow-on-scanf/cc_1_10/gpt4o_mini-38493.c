//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[11];
    int steps;
    float distance; // in kilometers
    int caloriesBurned;
} FitnessEntry;

FitnessEntry entries[MAX_ENTRIES];
int count = 0;

void addEntry() {
    if (count >= MAX_ENTRIES) {
        printf("Entry limit reached.\n");
        return;
    }
    
    FitnessEntry newEntry;

    // Get current date in YYYY-MM-DD format
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(newEntry.date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    
    printf("Enter the number of steps: ");
    scanf("%d", &newEntry.steps);
    
    printf("Enter the distance in kilometers: ");
    scanf("%f", &newEntry.distance);
    
    printf("Enter calories burned: ");
    scanf("%d", &newEntry.caloriesBurned);

    entries[count++] = newEntry;
    printf("Entry added successfully!\n");
}

void showEntries() {
    if (count == 0) {
        printf("No entries available.\n");
        return;
    }

    printf("Fitness Tracker Entries:\n");
    printf("%-12s %-10s %-10s %-15s\n", "Date", "Steps", "Distance", "Calories");
    for (int i = 0; i < count; i++) {
        printf("%-12s %-10d %-10.2f %-15d\n", entries[i].date, entries[i].steps, entries[i].distance, entries[i].caloriesBurned);
    }
}

void deleteEntry() {
    if (count == 0) {
        printf("No entries to delete.\n");
        return;
    }

    int index;
    printf("Enter the index of the entry to delete (0 to %d): ", count - 1);
    scanf("%d", &index);

    if (index < 0 || index >= count) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index; i < count - 1; i++) {
        entries[i] = entries[i + 1];
    }
    count--;
    printf("Entry deleted successfully!\n");
}

void summary() {
    if (count == 0) {
        printf("No entries available for summary.\n");
        return;
    }

    int totalSteps = 0;
    float totalDistance = 0.0;
    int totalCalories = 0;

    for (int i = 0; i < count; i++) {
        totalSteps += entries[i].steps;
        totalDistance += entries[i].distance;
        totalCalories += entries[i].caloriesBurned;
    }

    printf("Summary of Entries:\n");
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Calories Burned: %d\n", totalCalories);
}

void displayMenu() {
    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Add Entry\n");
    printf("2. Show Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Summary\n");
    printf("5. Exit\n");
    printf("---------------------------\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                showEntries();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                summary();
                break;
            case 5:
                printf("Exiting the Fitness Tracker. Stay healthy!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}