//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

// Structure to hold fitness data
typedef struct {
    char date[11];
    int steps;
    float distance; // in kilometers
    float caloriesBurned;
} FitnessEntry;

// Function prototypes
void addEntry(FitnessEntry entries[], int *count);
void viewEntries(FitnessEntry entries[], int count);
float calculateAverageSteps(FitnessEntry entries[], int count);
float calculateTotalCalories(FitnessEntry entries[], int count);
void displayMenu();
void initializeEntries(FitnessEntry entries[], int *count);

int main() {
    FitnessEntry entries[MAX_ENTRIES];
    int count = 0;
    initializeEntries(entries, &count);

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEntry(entries, &count);
                break;
            case 2:
                viewEntries(entries, count);
                break;
            case 3:
                printf("Average steps: %.2f\n", calculateAverageSteps(entries, count));
                printf("Total calories burned: %.2f\n", calculateTotalCalories(entries, count));
                break;
            case 4:
                printf("Exiting the Fitness Tracker. Keep moving!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void initializeEntries(FitnessEntry entries[], int *count) {
    *count = 0;
}

void displayMenu() {
    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Add Fitness Entry\n");
    printf("2. View All Entries\n");
    printf("3. Generate Statistics\n");
    printf("4. Exit\n");
}

void addEntry(FitnessEntry entries[], int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Maximum entries reached. Cannot add more.\n");
        return;
    }

    FitnessEntry newEntry;
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", newEntry.date);
    printf("Enter steps: ");
    scanf("%d", &newEntry.steps);
    printf("Enter distance in km: ");
    scanf("%f", &newEntry.distance);
    printf("Enter calories burned: ");
    scanf("%f", &newEntry.caloriesBurned);

    entries[*count] = newEntry;
    (*count)++;
    printf("Entry added successfully!\n");
}

void viewEntries(FitnessEntry entries[], int count) {
    if (count == 0) {
        printf("No entries available.\n");
        return;
    }
    printf("\n--- Fitness Entries ---\n");
    for (int i = 0; i < count; i++) {
        printf("Date: %s, Steps: %d, Distance: %.2f km, Calories Burned: %.2f\n",
                entries[i].date, entries[i].steps, entries[i].distance, entries[i].caloriesBurned);
    }
}

float calculateAverageSteps(FitnessEntry entries[], int count) {
    if (count == 0) return 0.0f;
    int totalSteps = 0;
    for (int i = 0; i < count; i++) {
        totalSteps += entries[i].steps;
    }
    return (float)totalSteps / count;
}

float calculateTotalCalories(FitnessEntry entries[], int count) {
    float totalCalories = 0.0f;
    for (int i = 0; i < count; i++) {
        totalCalories += entries[i].caloriesBurned;
    }
    return totalCalories;
}