//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    time_t date;
    int steps;
    double distance; // in kilometers
    double calories; // burned calories
} FitnessEntry;

void addFitnessEntry(FitnessEntry entries[], int *entryCount) {
    if (*entryCount >= MAX_ENTRIES) {
        printf("Maximum entries reached. Cannot add more.\n");
        return;
    }

    FitnessEntry newEntry;
    newEntry.date = time(NULL); // current time
    printf("Enter number of steps: ");
    scanf("%d", &newEntry.steps);
    printf("Enter distance traveled (in km): ");
    scanf("%lf", &newEntry.distance);
    printf("Enter calories burned: ");
    scanf("%lf", &newEntry.calories);

    entries[*entryCount] = newEntry;
    (*entryCount)++;
    printf("Fitness entry added successfully!\n");
}

void displayFitnessData(FitnessEntry entries[], int entryCount) {
    if (entryCount == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("\nFitness Data:\n");
    printf("---------------------------------------------------\n");
    printf("| Date           | Steps | Distance (km) | Calories  |\n");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < entryCount; i++) {
        char dateBuffer[26];
        struct tm* tm_info;
        tm_info = localtime(&entries[i].date);
        strftime(dateBuffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
        
        printf("| %-15s | %-5d | %-14.2f | %-8.2f |\n", dateBuffer, entries[i].steps, entries[i].distance, entries[i].calories);
    }

    printf("---------------------------------------------------\n");
}

void analyzeFitnessData(FitnessEntry entries[], int entryCount) {
    if (entryCount == 0) {
        printf("No entries available for analysis.\n");
        return;
    }

    double totalSteps = 0, totalDistance = 0, totalCalories = 0;

    for (int i = 0; i < entryCount; i++) {
        totalSteps += entries[i].steps;
        totalDistance += entries[i].distance;
        totalCalories += entries[i].calories;
    }

    double averageSteps = totalSteps / entryCount;
    double averageDistance = totalDistance / entryCount;
    double averageCalories = totalCalories / entryCount;

    printf("\nFitness Analysis:\n");
    printf("---------------------------------------------------\n");
    printf("Total Entries: %d\n", entryCount);
    printf("Total Steps: %.0f\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Calories Burned: %.2f\n", totalCalories);
    printf("Average Steps per entry: %.2f\n", averageSteps);
    printf("Average Distance per entry: %.2f km\n", averageDistance);
    printf("Average Calories per entry: %.2f\n", averageCalories);
    printf("---------------------------------------------------\n");
}

int main() {
    FitnessEntry entries[MAX_ENTRIES];
    int entryCount = 0;
    int choice;

    do {
        printf("\nFitness Tracker Menu\n");
        printf("1. Add Fitness Entry\n");
        printf("2. Display Fitness Data\n");
        printf("3. Analyze Fitness Data\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addFitnessEntry(entries, &entryCount);
                break;
            case 2:
                displayFitnessData(entries, entryCount);
                break;
            case 3:
                analyzeFitnessData(entries, entryCount);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}