//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int steps;
    float distance; // Distance in kilometers
    int calories;   // Calories burned
    time_t date;    // Date of entry
} FitnessEntry;

void addEntry(FitnessEntry entries[], int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Maximum entries reached! Cannot add more.\n\n");
        return;
    }

    FitnessEntry newEntry;
    printf("Enter the name of the activity: ");
    scanf("%s", newEntry.name);
    printf("Enter the number of steps: ");
    scanf("%d", &newEntry.steps);
    printf("Enter the distance covered (in km): ");
    scanf("%f", &newEntry.distance);
    printf("Enter calories burned: ");
    scanf("%d", &newEntry.calories);
    newEntry.date = time(NULL);

    entries[*count] = newEntry;
    (*count)++;
    printf("Entry added successfully!\n\n");
}

void displayEntries(FitnessEntry entries[], int count) {
    if (count == 0) {
        printf("No entries to display.\n\n");
        return;
    }

    printf("Fitness Tracker Entries:\n");
    printf("-------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("Activity: %s\n", entries[i].name);
        printf("Steps: %d, Distance: %.2f km, Calories: %d\n",
               entries[i].steps, entries[i].distance, entries[i].calories);
        printf("Date: %s", ctime(&entries[i].date));
        printf("-------------------------\n");
    }
}

void displaySummary(FitnessEntry entries[], int count) {
    if (count == 0) {
        printf("No entries to summarize.\n\n");
        return;
    }

    int totalSteps = 0;
    float totalDistance = 0.0;
    int totalCalories = 0;

    for (int i = 0; i < count; i++) {
        totalSteps += entries[i].steps;
        totalDistance += entries[i].distance;
        totalCalories += entries[i].calories;
    }

    printf("Fitness Summary:\n");
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Calories Burned: %d\n", totalCalories);
    printf("-------------------------\n\n");
}

void clearEntries(FitnessEntry entries[], int *count) {
    *count = 0;
    printf("All entries cleared.\n\n");
}

int main() {
    FitnessEntry entries[MAX_ENTRIES];
    int count = 0;
    int choice;

    do {
        printf("Welcome to the Artistic Fitness Tracker!\n");
        printf("1. Add Activity Entry\n");
        printf("2. Display All Entries\n");
        printf("3. Display Summary\n");
        printf("4. Clear All Entries\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                addEntry(entries, &count);
                break;
            case 2:
                displayEntries(entries, count);
                break;
            case 3:
                displaySummary(entries, count);
                break;
            case 4:
                clearEntries(entries, &count);
                break;
            case 5:
                printf("Exiting the program. Stay fit!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n\n");
        }
    } while (choice != 5);

    return 0;
}