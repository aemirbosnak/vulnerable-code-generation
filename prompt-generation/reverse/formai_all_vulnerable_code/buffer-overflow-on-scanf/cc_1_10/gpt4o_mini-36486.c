//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int steps;
    float distance; // in kilometers
    float calories; // in kilocalories
} Activity;

typedef struct {
    Activity activities[MAX_ENTRIES];
    int count;
} ActivityLog;

// Function Prototypes
void addActivity(ActivityLog *log);
void viewActivities(const ActivityLog *log);
void totalStatistics(const ActivityLog *log);
void menu();

int main() {
    ActivityLog log;
    log.count = 0;

    int choice;

    while (1) {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addActivity(&log);
                break;
            case 2:
                viewActivities(&log);
                break;
            case 3:
                totalStatistics(&log);
                break;
            case 4:
                printf("Exiting the Fitness Tracker. Stay Fit!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

void menu() {
    printf("\n=== Fitness Tracker Menu ===\n");
    printf("1. Add Activity\n");
    printf("2. View Activities\n");
    printf("3. View Total Statistics\n");
    printf("4. Exit\n");
}

void addActivity(ActivityLog *log) {
    if (log->count >= MAX_ENTRIES) {
        printf("Activity Log is full! Cannot add more activities.\n");
        return;
    }

    Activity newActivity;
    printf("Enter activity name (e.g., Walking, Running): ");
    scanf("%s", newActivity.name);
    printf("Enter steps taken: ");
    scanf("%d", &newActivity.steps);
    printf("Enter distance (in km): ");
    scanf("%f", &newActivity.distance);
    printf("Enter calories burned: ");
    scanf("%f", &newActivity.calories);

    log->activities[log->count] = newActivity;
    log->count++;
    printf("Activity added successfully!\n");
}

void viewActivities(const ActivityLog *log) {
    if (log->count == 0) {
        printf("No activities recorded yet!\n");
        return;
    }

    printf("\n=== Recorded Activities ===\n");
    for (int i = 0; i < log->count; i++) {
        printf("Activity %d:\n", i + 1);
        printf("Name: %s\n", log->activities[i].name);
        printf("Steps: %d\n", log->activities[i].steps);
        printf("Distance: %.2f km\n", log->activities[i].distance);
        printf("Calories: %.2f kcal\n", log->activities[i].calories);
        printf("----------------------------\n");
    }
}

void totalStatistics(const ActivityLog *log) {
    if (log->count == 0) {
        printf("No activities recorded. Cannot calculate statistics.\n");
        return;
    }

    int totalSteps = 0;
    float totalDistance = 0.0;
    float totalCalories = 0.0;

    for (int i = 0; i < log->count; i++) {
        totalSteps += log->activities[i].steps;
        totalDistance += log->activities[i].distance;
        totalCalories += log->activities[i].calories;
    }

    printf("\n=== Total Statistics ===\n");
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Calories: %.2f kcal\n", totalCalories);
}