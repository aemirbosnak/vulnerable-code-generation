//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int steps;
    float distance; // in kilometers
    float calories; // in calories
} FitnessEntry;

void addEntry(FitnessEntry entries[], int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Maximum number of entries reached.\n");
        return;
    }
    
    FitnessEntry newEntry;
    printf("Enter your name: ");
    scanf("%s", newEntry.name);
    printf("Enter steps walked: ");
    scanf("%d", &newEntry.steps);
    printf("Enter distance covered (in km): ");
    scanf("%f", &newEntry.distance);
    printf("Enter calories burned: ");
    scanf("%f", &newEntry.calories);
    
    entries[*count] = newEntry;
    (*count)++;
    printf("Entry added successfully!\n");
}

void viewEntries(FitnessEntry entries[], int count) {
    if (count == 0) {
        printf("No entries to display.\n");
        return;
    }

    printf("\nFitness Tracker Entries:\n");
    printf("-----------------------------------------------------------\n");
    printf("%-20s %-10s %-10s %-10s\n", "Name", "Steps", "Distance", "Calories");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10d %-10.2f %-10.2f\n", entries[i].name, entries[i].steps, entries[i].distance, entries[i].calories);
    }
    printf("-----------------------------------------------------------\n");
}

void calculateTotals(FitnessEntry entries[], int count) {
    int totalSteps = 0;
    float totalDistance = 0.0f;
    float totalCalories = 0.0f;

    for (int i = 0; i < count; i++) {
        totalSteps += entries[i].steps;
        totalDistance += entries[i].distance;
        totalCalories += entries[i].calories;
    }

    printf("\nTotal Steps: %d\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Calories Burned: %.2f kcal\n", totalCalories);
}

void saveToFile(FitnessEntry entries[], int count) {
    FILE *file = fopen("fitness_entries.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d %.2f %.2f\n", entries[i].name, entries[i].steps, entries[i].distance, entries[i].calories);
    }

    fclose(file);
    printf("Entries saved to fitness_entries.txt\n");
}

void loadFromFile(FitnessEntry entries[], int *count) {
    FILE *file = fopen("fitness_entries.txt", "r");
    if (file == NULL) {
        printf("No saved entries found.\n");
        return;
    }

    while (fscanf(file, "%s %d %f %f", entries[*count].name, &entries[*count].steps,
                  &entries[*count].distance, &entries[*count].calories) != EOF) {
        (*count)++;
    }

    fclose(file);
    printf("Entries loaded from fitness_entries.txt\n");
}

int main() {
    FitnessEntry entries[MAX_ENTRIES];
    int entryCount = 0;
    int choice;

    loadFromFile(entries, &entryCount);

    do {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Calculate Totals\n");
        printf("4. Save Entries to File\n");
        printf("5. Load Entries from File\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(entries, &entryCount);
                break;
            case 2:
                viewEntries(entries, entryCount);
                break;
            case 3:
                calculateTotals(entries, entryCount);
                break;
            case 4:
                saveToFile(entries, entryCount);
                break;
            case 5:
                loadFromFile(entries, &entryCount);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}