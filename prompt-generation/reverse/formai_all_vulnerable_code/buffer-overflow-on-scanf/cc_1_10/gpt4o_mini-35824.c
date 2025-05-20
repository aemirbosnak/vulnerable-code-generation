//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 30
#define ACTIVITY_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char activity[ACTIVITY_LENGTH];
    int duration; // in minutes
    int caloriesBurned;
} FitnessEntry;

void enterFitnessData(FitnessEntry *entry) {
    printf("Enter your name: ");
    fgets(entry->name, NAME_LENGTH, stdin);
    entry->name[strcspn(entry->name, "\n")] = 0; // Remove newline

    printf("Enter activity (e.g., Running, Cycling): ");
    fgets(entry->activity, ACTIVITY_LENGTH, stdin);
    entry->activity[strcspn(entry->activity, "\n")] = 0; // Remove newline

    printf("Enter duration in minutes: ");
    scanf("%d", &entry->duration);

    printf("Enter calories burned: ");
    scanf("%d", &entry->caloriesBurned);
    getchar(); // Consume newline character after number input
}

void displayFitnessData(FitnessEntry *entry) {
    printf("\n--- Fitness Entry ---\n");
    printf("Name: %s\n", entry->name);
    printf("Activity: %s\n", entry->activity);
    printf("Duration: %d minutes\n", entry->duration);
    printf("Calories Burned: %d\n", entry->caloriesBurned);
}

void displayMenu() {
    printf("\nFitness Tracker Menu:\n");
    printf("1. Enter Fitness Data\n");
    printf("2. Display All Entries\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    FitnessEntry entries[MAX_ENTRIES];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume newline character after number input

        switch (choice) {
            case 1:
                if (count < MAX_ENTRIES) {
                    enterFitnessData(&entries[count]);
                    count++;
                } else {
                    printf("Maximum number of entries reached.\n");
                }
                break;

            case 2:
                if (count == 0) {
                    printf("No entries to display.\n");
                } else {
                    for (int i = 0; i < count; i++) {
                        displayFitnessData(&entries[i]);
                    }
                }
                break;

            case 3:
                printf("Exiting the Fitness Tracker. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }

    return 0;
}