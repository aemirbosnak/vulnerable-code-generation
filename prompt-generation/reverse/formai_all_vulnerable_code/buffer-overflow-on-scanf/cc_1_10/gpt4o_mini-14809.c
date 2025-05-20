//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define DATE_LENGTH 11

typedef struct {
    char name[NAME_LENGTH];
    int steps;
    float distance; // in kilometers
    float calories;
    char date[DATE_LENGTH];
} FitnessRecord;

typedef struct {
    FitnessRecord records[MAX_RECORDS];
    int count;
} FitnessTracker;

void addRecord(FitnessTracker* tracker);
void displayRecords(const FitnessTracker* tracker);
void calculateAverages(const FitnessTracker* tracker);
void clearRecords(FitnessTracker* tracker);
void displayMenu();

int main() {
    FitnessTracker tracker = { .count = 0 };
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(&tracker);
                break;
            case 2:
                displayRecords(&tracker);
                break;
            case 3:
                calculateAverages(&tracker);
                break;
            case 4:
                clearRecords(&tracker);
                break;
            case 5:
                printf("Exiting the Fitness Tracker. Stay fit!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addRecord(FitnessTracker* tracker) {
    if (tracker->count >= MAX_RECORDS) {
        printf("Record limit reached! Cannot add more records.\n");
        return;
    }

    FitnessRecord record;

    printf("Enter your name: ");
    scanf("%s", record.name);
    printf("Enter steps taken: ");
    scanf("%d", &record.steps);
    printf("Enter distance covered (in km): ");
    scanf("%f", &record.distance);
    printf("Enter calories burned: ");
    scanf("%f", &record.calories);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", record.date);

    tracker->records[tracker->count] = record;
    tracker->count++;

    printf("Record added successfully!\n");
}

void displayRecords(const FitnessTracker* tracker) {
    if (tracker->count == 0) {
        printf("No records to display!\n");
        return;
    }

    printf("\n--- Fitness Records ---\n");
    for (int i = 0; i < tracker->count; i++) {
        FitnessRecord record = tracker->records[i];
        printf("Name: %s\n", record.name);
        printf("Steps: %d\n", record.steps);
        printf("Distance: %.2f km\n", record.distance);
        printf("Calories: %.2f\n", record.calories);
        printf("Date: %s\n", record.date);
        printf("----------------------\n");
    }
}

void calculateAverages(const FitnessTracker* tracker) {
    if (tracker->count == 0) {
        printf("No records to calculate averages!\n");
        return;
    }

    int totalSteps = 0;
    float totalDistance = 0.0f;
    float totalCalories = 0.0f;

    for (int i = 0; i < tracker->count; i++) {
        totalSteps += tracker->records[i].steps;
        totalDistance += tracker->records[i].distance;
        totalCalories += tracker->records[i].calories;
    }

    printf("Average Steps: %.2f\n", (float)totalSteps / tracker->count);
    printf("Average Distance: %.2f km\n", totalDistance / tracker->count);
    printf("Average Calories: %.2f\n", totalCalories / tracker->count);
}

void clearRecords(FitnessTracker* tracker) {
    tracker->count = 0;
    printf("All records cleared!\n");
}

void displayMenu() {
    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Add Record\n");
    printf("2. Display Records\n");
    printf("3. Calculate Averages\n");
    printf("4. Clear All Records\n");
    printf("5. Exit\n");
}