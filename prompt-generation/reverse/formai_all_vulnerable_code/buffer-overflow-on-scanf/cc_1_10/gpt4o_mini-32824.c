//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Dennis Ritchie
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

void addEntry(FitnessEntry *entries, int *count);
void displayEntries(FitnessEntry *entries, int count);
void calculateSummary(FitnessEntry *entries, int count);
void sortEntries(FitnessEntry *entries, int count);
void displayMenu();

int main() {
    FitnessEntry entries[MAX_ENTRIES];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count < MAX_ENTRIES) {
                    addEntry(entries, &count);
                } else {
                    printf("Maximum entries reached!\n");
                }
                break;
            case 2:
                displayEntries(entries, count);
                break;
            case 3:
                calculateSummary(entries, count);
                break;
            case 4:
                sortEntries(entries, count);
                printf("Entries sorted by steps.\n");
                break;
            case 5:
                printf("Exiting the program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

void displayMenu() {
    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Add Fitness Entry\n");
    printf("2. Display All Entries\n");
    printf("3. Calculate Summary\n");
    printf("4. Sort Entries\n");
    printf("5. Exit\n");
}

void addEntry(FitnessEntry *entries, int *count) {
    printf("Enter name: ");
    scanf("%s", entries[*count].name);
    printf("Enter steps: ");
    scanf("%d", &entries[*count].steps);
    printf("Enter distance (in km): ");
    scanf("%f", &entries[*count].distance);
    printf("Enter calories burned: ");
    scanf("%f", &entries[*count].calories);
    
    (*count)++;
    printf("Entry added successfully!\n");
}

void displayEntries(FitnessEntry *entries, int count) {
    if (count == 0) {
        printf("No entries to display.\n");
        return;
    }
    
    printf("\n--- Fitness Entries ---\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Steps: %d, Distance: %.2f km, Calories: %.2f\n",
               entries[i].name, entries[i].steps,
               entries[i].distance, entries[i].calories);
    }
}

void calculateSummary(FitnessEntry *entries, int count) {
    if (count == 0) {
        printf("No entries to summarize.\n");
        return;
    }

    int totalSteps = 0;
    float totalDistance = 0.0;
    float totalCalories = 0.0;

    for (int i = 0; i < count; i++) {
        totalSteps += entries[i].steps;
        totalDistance += entries[i].distance;
        totalCalories += entries[i].calories;
    }

    printf("\n--- Summary ---\n");
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Calories Burned: %.2f\n", totalCalories);
}

void sortEntries(FitnessEntry *entries, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (entries[j].steps > entries[j + 1].steps) {
                FitnessEntry temp = entries[j];
                entries[j] = entries[j + 1];
                entries[j + 1] = temp;
            }
        }
    }
}