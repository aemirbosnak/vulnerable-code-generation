//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define STRING_LENGTH 20

typedef struct {
    char date[STRING_LENGTH];
    int steps;
    int calories;
} FitnessEntry;

FitnessEntry entries[MAX_ENTRIES];
int entryCount = 0;

// Function Prototypes
void addEntry();
void displayEntries();
void calculateTotal();
void saveEntriesToFile();
void loadEntriesFromFile();

void displayMenu() {
    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Add a New Entry\n");
    printf("2. Display All Entries\n");
    printf("3. Calculate Total Steps and Calories\n");
    printf("4. Save Entries to File\n");
    printf("5. Load Entries from File\n");
    printf("0. Exit\n");
    printf("-------------------------------\n");
    printf("Please select an option: ");
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Entry limit reached! Cannot add more entries.\n");
        return;
    }

    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", entries[entryCount].date);
    printf("Enter the number of steps: ");
    scanf("%d", &entries[entryCount].steps);
    printf("Enter the calories burned: ");
    scanf("%d", &entries[entryCount].calories);

    entryCount++;
    printf("Entry added successfully!\n");
}

void displayEntries() {
    if (entryCount == 0) {
        printf("No entries to display.\n");
        return;
    }
    
    printf("\n--- Fitness Entries ---\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%d. Date: %s, Steps: %d, Calories: %d\n",
               i + 1, entries[i].date,
               entries[i].steps,
               entries[i].calories);
    }
    printf("-------------------------\n");
}

void calculateTotal() {
    int totalSteps = 0;
    int totalCalories = 0;

    for (int i = 0; i < entryCount; i++) {
        totalSteps += entries[i].steps;
        totalCalories += entries[i].calories;
    }
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Calories Burned: %d\n", totalCalories);
}

void saveEntriesToFile() {
    FILE *file = fopen("fitness_entries.txt", "w");
    if (!file) {
        printf("Error saving to file!\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s %d %d\n", entries[i].date, entries[i].steps, entries[i].calories);
    }

    fclose(file);
    printf("Entries saved to fitness_entries.txt\n");
}

void loadEntriesFromFile() {
    FILE *file = fopen("fitness_entries.txt", "r");
    if (!file) {
        printf("Error loading from file, file may not exist.\n");
        return;
    }

    entryCount = 0;
    while (fscanf(file, "%s %d %d", entries[entryCount].date, &entries[entryCount].steps, &entries[entryCount].calories) == 3) {
        entryCount++;
        if (entryCount >= MAX_ENTRIES) {
            printf("Maximum entries reached while loading from file.\n");
            break;
        }
    }

    fclose(file);
    printf("Entries loaded from fitness_entries.txt\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addEntry(); break;
            case 2: displayEntries(); break;
            case 3: calculateTotal(); break;
            case 4: saveEntriesToFile(); break;
            case 5: loadEntriesFromFile(); break;
            case 0: 
                printf("Exiting the Fitness Tracker. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}