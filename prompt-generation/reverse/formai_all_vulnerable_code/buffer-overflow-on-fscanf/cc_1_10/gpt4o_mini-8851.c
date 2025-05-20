//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    Date date;
    float steps;
    float distance;  // in kilometers
    float calories;  // burned calories
} FitnessEntry;

typedef struct {
    FitnessEntry entries[MAX_ENTRIES];
    int count;
} FitnessTracker;

void initializeTracker(FitnessTracker *tracker) {
    tracker->count = 0;
}

void addEntry(FitnessTracker *tracker, int day, int month, int year, float steps, float distance, float calories) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Maximum entries reached. Cannot add more!\n");
        return;
    }
    FitnessEntry entry = {{day, month, year}, steps, distance, calories};
    tracker->entries[tracker->count++] = entry;
    printf("Entry added: %02d/%02d/%d, Steps: %.2f, Distance: %.2f km, Calories: %.2f\n",
           day, month, year, steps, distance, calories);
}

void displayEntries(const FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No entries found.\n");
        return;
    }
    printf("\nFitness Tracker Entries:\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < tracker->count; i++) {
        FitnessEntry entry = tracker->entries[i];
        printf("Date: %02d/%02d/%d | Steps: %.2f | Distance: %.2f km | Calories: %.2f\n",
               entry.date.day, entry.date.month, entry.date.year, 
               entry.steps, entry.distance, entry.calories);
    }
    printf("---------------------------------------------------\n");
}

void saveEntriesToFile(const FitnessTracker *tracker, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Failed to open file for writing.\n");
        return;
    }

    for (int i = 0; i < tracker->count; i++) {
        FitnessEntry entry = tracker->entries[i];
        fprintf(file, "%02d/%02d/%d,%.2f,%.2f,%.2f\n",
                entry.date.day, entry.date.month, entry.date.year, 
                entry.steps, entry.distance, entry.calories);
    }
    fclose(file);
    printf("Entries saved to %s\n", filename);
}

void loadEntriesFromFile(FitnessTracker *tracker, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file for reading.\n");
        return;
    }
    
    while (!feof(file) && tracker->count < MAX_ENTRIES) {
        FitnessEntry entry;
        fscanf(file, "%02d/%02d/%d,%f,%f,%f\n", 
                &entry.date.day, &entry.date.month, &entry.date.year, 
                &entry.steps, &entry.distance, &entry.calories);
        tracker->entries[tracker->count++] = entry;
    }
    fclose(file);
    printf("Entries loaded from %s\n", filename);
}

void showMenu() {
    printf("\n=== Fitness Tracker ===\n");
    printf("1. Add Entry\n");
    printf("2. Display Entries\n");
    printf("3. Save Entries to File\n");
    printf("4. Load Entries from File\n");
    printf("5. Exit\n");
    printf("======================\n");
}

int main() {
    FitnessTracker tracker;
    initializeTracker(&tracker);
    int choice;

    do {
        showMenu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int day, month, year;
                float steps, distance, calories;
                printf("Enter Date (dd mm yyyy): ");
                scanf("%d %d %d", &day, &month, &year);
                printf("Enter Steps Count: ");
                scanf("%f", &steps);
                printf("Enter Distance (in km): ");
                scanf("%f", &distance);
                printf("Enter Calories Burned: ");
                scanf("%f", &calories);
                addEntry(&tracker, day, month, year, steps, distance, calories);
                break;
            }
            case 2:
                displayEntries(&tracker);
                break;
            case 3: {
                char filename[100];
                printf("Enter filename to save: ");
                scanf("%s", filename);
                saveEntriesToFile(&tracker, filename);
                break;
            }
            case 4: {
                char filename[100];
                printf("Enter filename to load: ");
                scanf("%s", filename);
                loadEntriesFromFile(&tracker, filename);
                break;
            }
            case 5:
                printf("Exiting the Fitness Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}