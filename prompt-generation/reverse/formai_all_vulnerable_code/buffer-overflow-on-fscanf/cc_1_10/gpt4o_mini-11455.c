//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int steps;
    int calories;
} FitnessEntry;

FitnessEntry fitnessLog[MAX_ENTRIES];
int entryCount = 0;

void addEntry(const char *name, int steps, int calories) {
    if (entryCount >= MAX_ENTRIES) {
        printf("Log is full. Cannot add more entries.\n");
        return;
    }

    strcpy(fitnessLog[entryCount].name, name);
    fitnessLog[entryCount].steps = steps;
    fitnessLog[entryCount].calories = calories;
    entryCount++;
    printf("Entry added for %s: %d steps, %d calories.\n", name, steps, calories);
}

void displaySummary() {
    printf("\nFitness Tracker Summary:\n");
    printf("--------------------------------\n");
    printf("Name\t\tSteps\tCalories\n");
    printf("--------------------------------\n");
    
    for (int i = 0; i < entryCount; i++) {
        printf("%s\t\t%d\t%d\n", fitnessLog[i].name, fitnessLog[i].steps, fitnessLog[i].calories);
    }
    printf("--------------------------------\n");
}

void saveToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s,%d,%d\n", fitnessLog[i].name, fitnessLog[i].steps, fitnessLog[i].calories);
    }
    fclose(file);
    printf("Data saved to %s\n", filename);
}

void loadFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for reading. Make sure the file exists.\n");
        return;
    }

    while (fscanf(file, "%49[^,],%d,%d\n", fitnessLog[entryCount].name,
                  &fitnessLog[entryCount].steps,
                  &fitnessLog[entryCount].calories) == 3) {
        entryCount++;
        if (entryCount >= MAX_ENTRIES) {
            printf("Log is full. Ignoring additional entries from file.\n");
            break;
        }
    }
    
    fclose(file);
    printf("Data loaded from %s. Total entries: %d\n", filename, entryCount);
}

void clearLog() {
    entryCount = 0;
    printf("Fitness log cleared.\n");
}

void displayMenu() {
    printf("\nFitness Tracker Menu:\n");
    printf("1. Add Entry\n");
    printf("2. Display Summary\n");
    printf("3. Save to File\n");
    printf("4. Load from File\n");
    printf("5. Clear Log\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    int steps, calories, keepGoing = 1;

    while (keepGoing) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Steps: ");
                scanf("%d", &steps);
                printf("Enter Calories: ");
                scanf("%d", &calories);
                addEntry(name, steps, calories);
                break;

            case 2:
                displaySummary();
                break;

            case 3:
                saveToFile("fitness_log.txt");
                break;

            case 4:
                loadFromFile("fitness_log.txt");
                break;

            case 5:
                clearLog();
                break;

            case 6:
                keepGoing = 0;
                printf("Exiting Fitness Tracker. Stay fit!\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}