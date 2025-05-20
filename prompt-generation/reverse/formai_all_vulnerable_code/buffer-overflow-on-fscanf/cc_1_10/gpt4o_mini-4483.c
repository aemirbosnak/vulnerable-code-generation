//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[11]; // YYYY-MM-DD
    int steps;
    float distance; // in kilometers
    int calories;
} FitnessEntry;

FitnessEntry entries[MAX_ENTRIES];
int entryCount = 0;

void addEntry();
void viewEntries();
void saveEntries();
void loadEntries();
void displayMenu();

int main() {
    loadEntries();

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                saveEntries();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\nFitness Tracker Menu:\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Save Entries\n");
    printf("4. Exit\n");
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Maximum entries reached. Please save and clear.\n");
        return;
    }

    FitnessEntry newEntry;
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", newEntry.date);
    printf("Enter steps: ");
    scanf("%d", &newEntry.steps);
    printf("Enter distance (in km): ");
    scanf("%f", &newEntry.distance);
    printf("Enter calories burned: ");
    scanf("%d", &newEntry.calories);

    entries[entryCount++] = newEntry;
    printf("Entry added successfully.\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("\nAll Fitness Entries:\n");
    printf("Date\t\tSteps\tDistance (km)\tCalories\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%s\t%d\t%.2f\t\t%d\n",
               entries[i].date,
               entries[i].steps,
               entries[i].distance,
               entries[i].calories);
    }
}

void saveEntries() {
    FILE *file = fopen("fitness_data.txt", "w");
    if (file == NULL) {
        perror("Unable to open file for writing");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s,%d,%.2f,%d\n",
                entries[i].date,
                entries[i].steps,
                entries[i].distance,
                entries[i].calories);
    }
    fclose(file);
    printf("Entries saved successfully.\n");
}

void loadEntries() {
    FILE *file = fopen("fitness_data.txt", "r");
    if (file == NULL) {
        printf("No previous data found. Starting fresh.\n");
        return;
    }

    while (!feof(file) && entryCount < MAX_ENTRIES) {
        FitnessEntry entry;
        fscanf(file, "%[^,],%d,%f,%d\n",
               entry.date,
               &entry.steps,
               &entry.distance,
               &entry.calories);
        entries[entryCount++] = entry;
    }
    fclose(file);
    printf("Entries loaded successfully.\n");
}