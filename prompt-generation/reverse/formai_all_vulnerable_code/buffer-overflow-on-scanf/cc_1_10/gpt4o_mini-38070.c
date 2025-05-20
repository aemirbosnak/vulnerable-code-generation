//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    int steps;
    float calories;
    float duration; // In hours
} FitnessData;

FitnessData fitnessEntries[MAX_ENTRIES];
int totalEntries = 0;

// Function declarations
void addEntry();
void viewEntries();
void saveData();
void loadData();
void clearEntries();
void displayMenu();

int main() {
    loadData();
    int choice;
    
    do {
        displayMenu();
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
                saveData();
                break;
            case 4:
                clearEntries();
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}

void displayMenu() {
    printf("\nFitness Tracker Menu:\n");
    printf("1. Add Fitness Entry\n");
    printf("2. View Fitness Entries\n");
    printf("3. Save Data to File\n");
    printf("4. Clear All Entries\n");
    printf("5. Exit\n");
}

void addEntry() {
    if (totalEntries >= MAX_ENTRIES) {
        printf("Maximum entries reached. Cannot add more.\n");
        return;
    }
    
    FitnessData newData;
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", newData.date);
    printf("Enter steps taken: ");
    scanf("%d", &newData.steps);
    printf("Enter calories burned: ");
    scanf("%f", &newData.calories);
    printf("Enter exercise duration (in hours): ");
    scanf("%f", &newData.duration);
    
    fitnessEntries[totalEntries++] = newData;
    printf("Entry added successfully!\n");
}

void viewEntries() {
    if (totalEntries == 0) {
        printf("No entries to display.\n");
        return;
    }
    
    printf("\nFitness Entries:\n");
    printf("%-15s %-10s %-10s %-10s\n", "Date", "Steps", "Calories", "Duration");
    for (int i = 0; i < totalEntries; i++) {
        printf("%-15s %-10d %-10.2f %-10.2f\n", 
               fitnessEntries[i].date, 
               fitnessEntries[i].steps, 
               fitnessEntries[i].calories, 
               fitnessEntries[i].duration);
    }
}

void saveData() {
    FILE *file = fopen("fitness_data.txt", "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    for (int i = 0; i < totalEntries; i++) {
        fprintf(file, "%s %d %.2f %.2f\n", 
                fitnessEntries[i].date, 
                fitnessEntries[i].steps, 
                fitnessEntries[i].calories, 
                fitnessEntries[i].duration);
    }
    
    fclose(file);
    printf("Data saved successfully!\n");
}

void loadData() {
    FILE *file = fopen("fitness_data.txt", "r");
    if (!file) {
        printf("No previous data found, starting fresh.\n");
        return;
    }
    
    while (fscanf(file, "%s %d %f %f", 
                  fitnessEntries[totalEntries].date, 
                  &fitnessEntries[totalEntries].steps, 
                  &fitnessEntries[totalEntries].calories, 
                  &fitnessEntries[totalEntries].duration) != EOF) {
        totalEntries++;
    }
    
    fclose(file);
    printf("Data loaded successfully!\n");
}

void clearEntries() {
    totalEntries = 0;
    printf("All entries cleared.\n");
}