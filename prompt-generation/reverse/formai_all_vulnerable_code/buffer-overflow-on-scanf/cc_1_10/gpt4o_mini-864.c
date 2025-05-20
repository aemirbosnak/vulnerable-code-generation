//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ACTIVITIES 100

typedef struct {
    char name[30];
    float duration; // duration in minutes
    int caloriesBurned; // calories burned
    time_t date; // date of the activity
} Activity;

typedef struct {
    Activity activities[MAX_ACTIVITIES];
    int count;
} FitnessTracker;

// Function prototypes
void addActivity(FitnessTracker *tracker);
void viewActivities(const FitnessTracker *tracker);
void viewSummary(const FitnessTracker *tracker);
void clearActivities(FitnessTracker *tracker);
void displayMenu();

int main() {
    FitnessTracker tracker;
    tracker.count = 0;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addActivity(&tracker);
                break;
            case 2:
                viewActivities(&tracker);
                break;
            case 3:
                viewSummary(&tracker);
                break;
            case 4:
                clearActivities(&tracker);
                break;
            case 0:
                printf("Exiting the fitness tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Add Activity\n");
    printf("2. View Activities\n");
    printf("3. View Summary\n");
    printf("4. Clear Activities\n");
    printf("0. Exit\n");
}

void addActivity(FitnessTracker *tracker) {
    if (tracker->count >= MAX_ACTIVITIES) {
        printf("Activity limit reached! Unable to add more activities.\n");
        return;
    }

    Activity newActivity;
    printf("Enter activity name: ");
    scanf("%s", newActivity.name);

    printf("Enter duration (in minutes): ");
    scanf("%f", &newActivity.duration);

    printf("Enter calories burned: ");
    scanf("%d", &newActivity.caloriesBurned);

    newActivity.date = time(NULL); // Automatically sets date to current time
    tracker->activities[tracker->count] = newActivity;
    tracker->count++;

    printf("Activity added successfully!\n");
}

void viewActivities(const FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No activities recorded yet.\n");
        return;
    }

    printf("\n--- Your Activities ---\n");
    for (int i = 0; i < tracker->count; i++) {
        struct tm *activityDate = localtime(&tracker->activities[i].date);
        printf("Activity %d: %s | Duration: %.2f mins | Calories Burned: %d | Date: %02d-%02d-%d\n",
               i + 1,
               tracker->activities[i].name,
               tracker->activities[i].duration,
               tracker->activities[i].caloriesBurned,
               activityDate->tm_mday,
               activityDate->tm_mon + 1,
               activityDate->tm_year + 1900);
    }
}

void viewSummary(const FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No activities recorded yet.\n");
        return;
    }

    float totalDuration = 0;
    int totalCalories = 0;

    for (int i = 0; i < tracker->count; i++) {
        totalDuration += tracker->activities[i].duration;
        totalCalories += tracker->activities[i].caloriesBurned;
    }

    printf("\n--- Summary ---\n");
    printf("Total Activities: %d\n", tracker->count);
    printf("Total Duration: %.2f minutes\n", totalDuration);
    printf("Total Calories Burned: %d\n", totalCalories);
}

void clearActivities(FitnessTracker *tracker) {
    tracker->count = 0;
    printf("All activities have been cleared.\n");
}