//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int steps;
    float distance; // in kilometers
    float calories; // burn calories
} FitnessTrackerEntry;

typedef struct {
    FitnessTrackerEntry entries[MAX_ENTRIES];
    int count;
} FitnessTracker;

// Function declarations
void addEntry(FitnessTracker *tracker);
void viewEntries(const FitnessTracker *tracker);
void viewSummary(const FitnessTracker *tracker);
void saveToFile(const FitnessTracker *tracker, const char *filename);
void loadFromFile(FitnessTracker *tracker, const char *filename);

int main() {
    FitnessTracker tracker;
    tracker.count = 0;

    loadFromFile(&tracker, "fitness_data.txt");

    int choice;
    do {
        printf("\n=== Fitness Tracker ===\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. View Summary\n");
        printf("4. Save Data\n");
        printf("5. Load Data\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(&tracker);
                break;
            case 2:
                viewEntries(&tracker);
                break;
            case 3:
                viewSummary(&tracker);
                break;
            case 4:
                saveToFile(&tracker, "fitness_data.txt");
                printf("Data saved successfully.\n");
                break;
            case 5:
                loadFromFile(&tracker, "fitness_data.txt");
                printf("Data loaded successfully.\n");
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void addEntry(FitnessTracker *tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Maximum entries reached. Cannot add more entries.\n");
        return;
    }

    FitnessTrackerEntry entry;
    printf("Enter your name: ");
    scanf("%s", entry.name);
    printf("Enter steps taken: ");
    scanf("%d", &entry.steps);
    printf("Enter distance walked (in km): ");
    scanf("%f", &entry.distance);
    printf("Enter calories burned: ");
    scanf("%f", &entry.calories);

    tracker->entries[tracker->count] = entry;
    tracker->count++;
    printf("Entry added successfully!\n");
}

void viewEntries(const FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("\n=== Fitness Entries ===\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Entry %d: %s -> Steps: %d, Distance: %.2f km, Calories Burned: %.2f\n",
               i + 1, tracker->entries[i].name, tracker->entries[i].steps,
               tracker->entries[i].distance, tracker->entries[i].calories);
    }
}

void viewSummary(const FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No entries to summarize.\n");
        return;
    }

    int totalSteps = 0;
    float totalDistance = 0;
    float totalCalories = 0;

    for (int i = 0; i < tracker->count; i++) {
        totalSteps += tracker->entries[i].steps;
        totalDistance += tracker->entries[i].distance;
        totalCalories += tracker->entries[i].calories;
    }

    printf("\n=== Fitness Summary ===\n");
    printf("Total Entries: %d\n", tracker->count);
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Calories Burned: %.2f\n", totalCalories);
}

void saveToFile(const FitnessTracker *tracker, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s %d %.2f %.2f\n",
                tracker->entries[i].name,
                tracker->entries[i].steps,
                tracker->entries[i].distance,
                tracker->entries[i].calories);
    }
    fclose(file);
}

void loadFromFile(FitnessTracker *tracker, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for reading. Starting fresh.\n");
        return;
    }

    tracker->count = 0;
    while (fscanf(file, "%s %d %f %f",
                  tracker->entries[tracker->count].name,
                  &tracker->entries[tracker->count].steps,
                  &tracker->entries[tracker->count].distance,
                  &tracker->entries[tracker->count].calories) != EOF) {
        tracker->count++;
        if (tracker->count >= MAX_ENTRIES) {
            break; // Avoid overflow
        }
    }
    fclose(file);
}