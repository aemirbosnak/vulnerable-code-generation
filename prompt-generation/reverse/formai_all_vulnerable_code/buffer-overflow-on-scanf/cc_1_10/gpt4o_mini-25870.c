//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[11];
    int steps;
    float distance; // km
    int calories;
} Entry;

void addEntry(Entry *entries, int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Maximum entries reached. Cannot add more.\n");
        return;
    }

    Entry newEntry;
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", newEntry.date);
    printf("Enter steps: ");
    scanf("%d", &newEntry.steps);
    printf("Enter distance (in km): ");
    scanf("%f", &newEntry.distance);
    printf("Enter calories burned: ");
    scanf("%d", &newEntry.calories);
    
    entries[*count] = newEntry;
    (*count)++;
    printf("Entry added successfully!\n");
}

void displayEntries(Entry *entries, int count) {
    if (count == 0) {
        printf("No entries to display.\n");
        return;
    }
    printf("\nFitness Tracker Entries:\n");
    printf("-----------------------------------------------------\n");
    printf("| Date       | Steps | Distance (km) | Calories   |\n");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("| %-10s | %-5d | %-14.2f | %-10d |\n",
               entries[i].date, entries[i].steps, entries[i].distance, entries[i].calories);
    }
    printf("-----------------------------------------------------\n");
}

void calculateTotalStats(Entry *entries, int count) {
    int totalSteps = 0, totalCalories = 0;
    float totalDistance = 0.0;
    
    for (int i = 0; i < count; i++) {
        totalSteps += entries[i].steps;
        totalDistance += entries[i].distance;
        totalCalories += entries[i].calories;
    }

    printf("\nTotal Stats:\n");
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Calories Burned: %d\n", totalCalories);
}

void saveEntriesToFile(Entry *entries, int count) {
    FILE *file = fopen("fitness_tracker.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d %.2f %d\n", entries[i].date, entries[i].steps, entries[i].distance, entries[i].calories);
    }
    fclose(file);
    printf("Entries saved to fitness_tracker.txt\n");
}

void loadEntriesFromFile(Entry *entries, int *count) {
    FILE *file = fopen("fitness_tracker.txt", "r");
    if (file == NULL) {
        printf("No log file found. Starting fresh.\n");
        return;
    }
    
    while (fscanf(file, "%s %d %f %d", entries[*count].date, &entries[*count].steps, &entries[*count].distance, &entries[*count].calories) != EOF) {
        (*count)++;
        if (*count >= MAX_ENTRIES) break;
    }
    fclose(file);
    printf("Entries loaded from fitness_tracker.txt\n");
}

int main() {
    Entry entries[MAX_ENTRIES];
    int count = 0;
    int choice;

    loadEntriesFromFile(entries, &count);

    do {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Calculate Total Stats\n");
        printf("4. Save Entries to File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(entries, &count);
                break;
            case 2:
                displayEntries(entries, count);
                break;
            case 3:
                calculateTotalStats(entries, count);
                break;
            case 4:
                saveEntriesToFile(entries, count);
                break;
            case 5:
                printf("Exiting the Fitness Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}