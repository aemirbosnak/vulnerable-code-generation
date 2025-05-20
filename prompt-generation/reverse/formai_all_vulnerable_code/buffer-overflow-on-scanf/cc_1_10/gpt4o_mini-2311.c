//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    int steps;
    float distance; // in kilometers
    int calories;
} Entry;

Entry fitnessTracker[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Oh no!!! You can't add more entries, limit reached!\n");
        return;
    }

    Entry newEntry; // Behold! A new entry is being created!
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", newEntry.date);
    printf("Enter steps: ");
    scanf("%d", &newEntry.steps);
    printf("Enter distance (in km): ");
    scanf("%f", &newEntry.distance);
    printf("Enter calories burned: ");
    scanf("%d", &newEntry.calories);

    fitnessTracker[entryCount] = newEntry; // Entry is stored!
    entryCount++;
    printf("Wow! Entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("Oh dear! No entries found!\n");
        return;
    }
    
    printf("Here are your fitness entries:\n");
    printf("Date        | Steps | Distance (km) | Calories\n");
    printf("------------|-------|----------------|---------\n");
    
    for (int i = 0; i < entryCount; i++) {
        printf("%-11s | %-5d | %-13.2f | %-7d\n", 
               fitnessTracker[i].date, 
               fitnessTracker[i].steps,
               fitnessTracker[i].distance, 
               fitnessTracker[i].calories);
    }
}

void analyzeData() {
    if (entryCount == 0) {
        printf("Yikes! Nothing to analyze!\n");
        return;
    }

    int totalSteps = 0;
    float totalDistance = 0.0;
    int totalCalories = 0;
    
    for (int i = 0; i < entryCount; i++) {
        totalSteps += fitnessTracker[i].steps;
        totalDistance += fitnessTracker[i].distance;
        totalCalories += fitnessTracker[i].calories;
    }
    
    printf("Analysis Report:\n");
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Calories Burned: %d\n", totalCalories);
    
    float averageSteps = (float)totalSteps / entryCount;
    printf("Average Steps per Entry: %.2f\n", averageSteps);
    
    float averageDistance = totalDistance / entryCount;
    printf("Average Distance per Entry: %.2f km\n", averageDistance);
    
    float averageCalories = (float)totalCalories / entryCount;
    printf("Average Calories Burned per Entry: %.2f\n", averageCalories);
}

void displayMenu() {
    printf("\nFitness Tracker Menu:\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Analyze Data\n");
    printf("4. Exit\n");
    printf("Please choose an option: ");
}

int main() {
    int choice;

    printf("!!! Welcome to the Ultimate Fitness Tracker !!!\n");
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                analyzeData();
                break;
            case 4:
                printf("Exiting the program. Keep moving and stay fit!!!\n");
                break;
            default:
                printf("What?! Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}