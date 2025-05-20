//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float distance; // kilometers
    int duration; // minutes
    int caloriesBurned;
} ActivityEntry;

typedef struct {
    ActivityEntry entries[MAX_ENTRIES];
    int count;
} ActivityTracker;

// Function prototypes
void addActivity(ActivityTracker* tracker);
void displayActivities(const ActivityTracker* tracker);
void calculateStats(const ActivityTracker* tracker);
void clearBuffer();

int main() {
    ActivityTracker tracker;
    tracker.count = 0;

    int choice;
    do {
        printf("\n--- Fitness Tracker Menu ---\n");
        printf("1. Add Activity\n");
        printf("2. Display Activities\n");
        printf("3. Calculate Statistics\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addActivity(&tracker);
                break;
            case 2:
                displayActivities(&tracker);
                break;
            case 3:
                calculateStats(&tracker);
                break;
            case 4:
                printf("Exiting the Fitness Tracker. Stay fit!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void addActivity(ActivityTracker* tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Cannot add more activities. Activity log is full.\n");
        return;
    }

    ActivityEntry* entry = &tracker->entries[tracker->count];

    printf("Enter activity name: ");
    fgets(entry->name, MAX_NAME_LENGTH, stdin);
    entry->name[strcspn(entry->name, "\n")] = 0; // Remove newline

    printf("Enter distance (in kilometers): ");
    scanf("%f", &entry->distance);
    clearBuffer();

    printf("Enter duration (in minutes): ");
    scanf("%d", &entry->duration);
    clearBuffer();

    // Example calorie calculation (rough estimate)
    entry->caloriesBurned = (int)(entry->distance * 60); // Assuming 60 calories per km

    tracker->count++;
    printf("Activity added successfully!\n");
}

void displayActivities(const ActivityTracker* tracker) {
    if (tracker->count == 0) {
        printf("No activities recorded yet!\n");
        return;
    }

    printf("\n--- Activity Log ---\n");
    for (int i = 0; i < tracker->count; i++) {
        const ActivityEntry* entry = &tracker->entries[i];
        printf("Activity %d:\n", i + 1);
        printf("Name: %s\n", entry->name);
        printf("Distance: %.2f km\n", entry->distance);
        printf("Duration: %d minutes\n", entry->duration);
        printf("Calories Burned: %d\n\n", entry->caloriesBurned);
    }
}

void calculateStats(const ActivityTracker* tracker) {
    if (tracker->count == 0) {
        printf("No activities recorded yet!\n");
        return;
    }

    float totalDistance = 0.0;
    int totalDuration = 0;
    int totalCalories = 0;

    for (int i = 0; i < tracker->count; i++) {
        totalDistance += tracker->entries[i].distance;
        totalDuration += tracker->entries[i].duration;
        totalCalories += tracker->entries[i].caloriesBurned;
    }

    printf("\n--- Fitness Statistics ---\n");
    printf("Total Activities: %d\n", tracker->count);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Duration: %d minutes\n", totalDuration);
    printf("Total Calories Burned: %d\n", totalCalories);
    printf("Average Distance per Activity: %.2f km\n", totalDistance / tracker->count);
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}