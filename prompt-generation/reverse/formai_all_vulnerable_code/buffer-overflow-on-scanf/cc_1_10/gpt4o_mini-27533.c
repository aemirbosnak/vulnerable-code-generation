//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 30
#define DATE_LENGTH 11

typedef struct {
    char date[DATE_LENGTH];
    int steps;
    float distance; // in kilometers
    int calories;   // burned calories
} FitnessEntry;

FitnessEntry fitnessLog[MAX_ENTRIES];
int entryCount = 0;

void addEntry();
void viewEntries();
void editEntry();
void deleteEntry();
void showMenu();

int main() {
    int choice;
    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addEntry(); break;
            case 2: viewEntries(); break;
            case 3: editEntry(); break;
            case 4: deleteEntry(); break;
            case 5: printf("Exiting the Fitness Tracker. Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n"); break;
        }
    } while (choice != 5);
    
    return 0;
}

void showMenu() {
    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Edit Entry\n");
    printf("4. Delete Entry\n");
    printf("5. Exit\n");
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Fitness log is full! Cannot add more entries.\n");
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
    
    fitnessLog[entryCount++] = newEntry;
    printf("Entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries recorded yet.\n");
        return;
    }
    
    printf("\n--- Fitness Log Entries ---\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%d. Date: %s, Steps: %d, Distance: %.2f km, Calories: %d\n",
                i + 1, fitnessLog[i].date, fitnessLog[i].steps,
                fitnessLog[i].distance, fitnessLog[i].calories);
    }
}

void editEntry() {
    if (entryCount == 0) {
        printf("No entries to edit.\n");
        return;
    }
    
    int index;
    viewEntries();
    printf("Select entry number to edit: ");
    scanf("%d", &index);
    
    if (index < 1 || index > entryCount) {
        printf("Invalid entry number.\n");
        return;
    }
    
    FitnessEntry *entry = &fitnessLog[index - 1];
    
    printf("Editing entry for date: %s\n", entry->date);
    printf("Enter new steps (current: %d): ", entry->steps);
    scanf("%d", &entry->steps);
    
    printf("Enter new distance (km) (current: %.2f): ", entry->distance);
    scanf("%f", &entry->distance);
    
    printf("Enter new calories burned (current: %d): ", entry->calories);
    scanf("%d", &entry->calories);
    
    printf("Entry updated successfully!\n");
}

void deleteEntry() {
    if (entryCount == 0) {
        printf("No entries to delete.\n");
        return;
    }
    
    int index;
    viewEntries();
    printf("Select entry number to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > entryCount) {
        printf("Invalid entry number.\n");
        return;
    }
    
    for (int i = index - 1; i < entryCount - 1; i++) {
        fitnessLog[i] = fitnessLog[i + 1];
    }
    
    entryCount--;
    printf("Entry deleted successfully!\n");
}