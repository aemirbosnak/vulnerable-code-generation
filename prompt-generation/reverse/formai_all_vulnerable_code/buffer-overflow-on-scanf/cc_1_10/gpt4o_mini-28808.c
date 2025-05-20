//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float height; // in centimeters
    float weight; // in kilograms
    float steps;
    float distance; // in kilometers
    float calories; // calories burned
} FitnessEntry;

FitnessEntry entries[MAX_ENTRIES];
int entryCount = 0;

// Function to add a new fitness entry
void addFitnessEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Maximum entries reached! Cannot add more.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", entries[entryCount].name);
    printf("Enter age: ");
    scanf("%d", &entries[entryCount].age);
    printf("Enter height (cm): ");
    scanf("%f", &entries[entryCount].height);
    printf("Enter weight (kg): ");
    scanf("%f", &entries[entryCount].weight);
    printf("Enter steps taken: ");
    scanf("%f", &entries[entryCount].steps);
    printf("Enter distance traveled (km): ");
    scanf("%f", &entries[entryCount].distance);
    printf("Enter calories burned: ");
    scanf("%f", &entries[entryCount].calories);

    entryCount++;
    printf("Fitness entry added successfully!\n");
}

// Function to display fitness entries
void displayEntries() {
    if (entryCount == 0) {
        printf("No entries to display.\n");
        return;
    }

    printf("\nFitness Entries:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Name: %s\n", entries[i].name);
        printf("Age: %d\n", entries[i].age);
        printf("Height: %.2f cm\n", entries[i].height);
        printf("Weight: %.2f kg\n", entries[i].weight);
        printf("Steps: %.2f\n", entries[i].steps);
        printf("Distance: %.2f km\n", entries[i].distance);
        printf("Calories: %.2f kcal\n", entries[i].calories);
        printf("---------------------\n");
    }
}

// Function to compute statistics
void computeStatistics() {
    if (entryCount == 0) {
        printf("No entries to compute statistics.\n");
        return;
    }

    float totalWeight = 0, totalDistance = 0, totalCalories = 0;
    for (int i = 0; i < entryCount; i++) {
        totalWeight += entries[i].weight;
        totalDistance += entries[i].distance;
        totalCalories += entries[i].calories;
    }

    float averageWeight = totalWeight / entryCount;
    float averageDistance = totalDistance / entryCount;
    float averageCalories = totalCalories / entryCount;

    printf("\nStatistics:\n");
    printf("Average Weight: %.2f kg\n", averageWeight);
    printf("Average Distance: %.2f km\n", averageDistance);
    printf("Average Calories Burned: %.2f kcal\n", averageCalories);
}

// Function to save entries to a file
void saveEntriesToFile() {
    FILE *file = fopen("fitness_data.txt", "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s %d %.2f %.2f %.2f %.2f %.2f\n", 
            entries[i].name, 
            entries[i].age, 
            entries[i].height, 
            entries[i].weight, 
            entries[i].steps, 
            entries[i].distance, 
            entries[i].calories);
    }

    fclose(file);
    printf("Entries saved to fitness_data.txt!\n");
}

// Function to load entries from a file
void loadEntriesFromFile() {
    FILE *file = fopen("fitness_data.txt", "r");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }

    while (fscanf(file, "%s %d %f %f %f %f %f", 
        entries[entryCount].name, 
        &entries[entryCount].age, 
        &entries[entryCount].height, 
        &entries[entryCount].weight, 
        &entries[entryCount].steps, 
        &entries[entryCount].distance, 
        &entries[entryCount].calories) == 7) {
        entryCount++;
        if (entryCount >= MAX_ENTRIES) {
            printf("Maximum entries reached while loading from file.\n");
            break;
        }
    }

    fclose(file);
    printf("Entries loaded from fitness_data.txt!\n");
}

// Main menu function
void menu() {
    int choice;
    do {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add Fitness Entry\n");
        printf("2. Display Fitness Entries\n");
        printf("3. Compute Statistics\n");
        printf("4. Save Entries to File\n");
        printf("5. Load Entries from File\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addFitnessEntry();
                break;
            case 2:
                displayEntries();
                break;
            case 3:
                computeStatistics();
                break;
            case 4:
                saveEntriesToFile();
                break;
            case 5:
                loadEntriesFromFile();
                break;
            case 0:
                printf("Exiting program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}