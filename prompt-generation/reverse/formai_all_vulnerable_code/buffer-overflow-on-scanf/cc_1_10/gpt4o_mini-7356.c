//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 30

typedef struct {
    char name[MAX_NAME_LEN];
    int caloriesBurned;
    int duration; // in minutes
} Activity;

typedef struct {
    Activity activities[MAX_ENTRIES];
    int count;
} FitnessTracker;

// Function prototypes
void addActivity(FitnessTracker *tracker, const char *name, int calories, int duration);
void displayActivities(const FitnessTracker *tracker);
void displayStats(const FitnessTracker *tracker);
int menu();

int main() {
    FitnessTracker tracker = {.count = 0};
    int choice;

    do {
        choice = menu();
        switch (choice) {
            case 1: {
                char name[MAX_NAME_LEN];
                int calories, duration;

                printf("Enter activity name: ");
                scanf("%s", name);
                printf("Enter calories burned: ");
                scanf("%d", &calories);
                printf("Enter duration (in minutes): ");
                scanf("%d", &duration);

                addActivity(&tracker, name, calories, duration);
                break;
            }
            case 2:
                displayActivities(&tracker);
                break;
            case 3:
                displayStats(&tracker);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

void addActivity(FitnessTracker *tracker, const char *name, int calories, int duration) {
    if (tracker->count < MAX_ENTRIES) {
        strcpy(tracker->activities[tracker->count].name, name);
        tracker->activities[tracker->count].caloriesBurned = calories;
        tracker->activities[tracker->count].duration = duration;
        tracker->count++;
        printf("Activity added successfully!\n");
    } else {
        printf("Cannot add more activities. Maximum limit reached.\n");
    }
}

void displayActivities(const FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No activities recorded yet!\n");
        return;
    }

    printf("\n--- Recorded Activities ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Activity %d: %s, Calories Burned: %d, Duration: %d minutes\n",
               i + 1, tracker->activities[i].name,
               tracker->activities[i].caloriesBurned,
               tracker->activities[i].duration);
    }
    printf("--------------------------\n");
}

void displayStats(const FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No activities to display stats for!\n");
        return;
    }

    int totalCalories = 0;
    int totalDuration = 0;

    for (int i = 0; i < tracker->count; i++) {
        totalCalories += tracker->activities[i].caloriesBurned;
        totalDuration += tracker->activities[i].duration;
    }

    printf("\n--- Statistics ---\n");
    printf("Total Activities: %d\n", tracker->count);
    printf("Total Calories Burned: %d\n", totalCalories);
    printf("Total Duration: %d minutes\n", totalDuration);
    printf("-------------------\n");
}

int menu() {
    int choice;

    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Add Activity\n");
    printf("2. Display Activities\n");
    printf("3. Display Stats\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}