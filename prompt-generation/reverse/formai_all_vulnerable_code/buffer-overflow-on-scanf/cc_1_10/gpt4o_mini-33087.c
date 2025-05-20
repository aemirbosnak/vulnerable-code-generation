//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[11]; // format: YYYY-MM-DD
    int steps;
    float distance; // in kilometers
    int calories;
} FitnessEntry;

FitnessEntry entries[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Database is full, cannot add more entries!\n");
        return;
    }
    
    FitnessEntry newEntry;
    
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", newEntry.date);
    
    printf("Enter steps: ");
    scanf("%d", &newEntry.steps);
    
    printf("Enter distance (km): ");
    scanf("%f", &newEntry.distance);
    
    printf("Enter calories burned: ");
    scanf("%d", &newEntry.calories);
    
    entries[entryCount++] = newEntry;
    printf("Entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries available!\n");
        return;
    }
    
    printf("\nFitness Tracker Entries:\n");
    printf("Date        | Steps | Distance (km) | Calories\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%s | %5d | %10.2f | %8d\n", entries[i].date, entries[i].steps, entries[i].distance, entries[i].calories);
    }
}

void calculateTotal() {
    int totalSteps = 0;
    float totalDistance = 0.0;
    int totalCalories = 0;

    for (int i = 0; i < entryCount; i++) {
        totalSteps += entries[i].steps;
        totalDistance += entries[i].distance;
        totalCalories += entries[i].calories;
    }
    
    printf("\nTotal Summary:\n");
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Calories Burned: %d\n", totalCalories);
}

void saveEntriesToFile() {
    FILE *file = fopen("fitness_data.txt", "w");
    if (!file) {
        printf("Could not open file for writing!\n");
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
    printf("Entries saved to fitness_data.txt\n");
}

void loadEntriesFromFile() {
    FILE *file = fopen("fitness_data.txt", "r");
    if (!file) {
        printf("No save file found. Starting fresh.\n");
        return;
    }

    while (fscanf(file, "%10[^,],%d,%f,%d\n", entries[entryCount].date, &entries[entryCount].steps, 
            &entries[entryCount].distance, &entries[entryCount].calories) != EOF) {
        entryCount++;
        if (entryCount >= MAX_ENTRIES) break; // Prevent overflow
    }
    
    fclose(file);
    printf("Entries loaded from fitness_data.txt\n");
}

int main() {
    int choice;

    loadEntriesFromFile();

    do {
        printf("\n--- Fitness Tracker ---\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Calculate Total\n");
        printf("4. Save Entries\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                calculateTotal();
                break;
            case 4:
                saveEntriesToFile();
                break;
            case 5:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}