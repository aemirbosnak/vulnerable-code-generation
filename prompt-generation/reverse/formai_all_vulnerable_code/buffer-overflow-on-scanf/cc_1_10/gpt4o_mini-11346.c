//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOGS 100

typedef struct {
    int steps;
    float caloriesBurned;
    char workoutType[50];
} ActivityLog;

typedef struct {
    ActivityLog logs[MAX_LOGS];
    int logCount;
} FitnessTracker;

void addLog(FitnessTracker *tracker);
void viewLogs(const FitnessTracker *tracker);
void viewSummary(const FitnessTracker *tracker);
void clearLogs(FitnessTracker *tracker);
void displayMenu();

int main() {
    FitnessTracker tracker;
    tracker.logCount = 0;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addLog(&tracker);
                break;
            case 2:
                viewLogs(&tracker);
                break;
            case 3:
                viewSummary(&tracker);
                break;
            case 4:
                clearLogs(&tracker);
                break;
            case 5:
                printf("Exiting the Fitness Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Add Workout Log\n");
    printf("2. View Workout Logs\n");
    printf("3. View Summary\n");
    printf("4. Clear Logs\n");
    printf("5. Exit\n");
}

void addLog(FitnessTracker *tracker) {
    if (tracker->logCount >= MAX_LOGS) {
        printf("Log limit reached. Cannot add more entries.\n");
        return;
    }

    ActivityLog newLog;

    printf("Enter steps: ");
    scanf("%d", &newLog.steps);
    printf("Enter calories burned: ");
    scanf("%f", &newLog.caloriesBurned);
    printf("Enter workout type: ");
    getchar(); // Consume newline
    fgets(newLog.workoutType, sizeof(newLog.workoutType), stdin);
    newLog.workoutType[strcspn(newLog.workoutType, "\n")] = '\0'; // Remove newline

    tracker->logs[tracker->logCount++] = newLog;
    printf("Log added successfully.\n");
}

void viewLogs(const FitnessTracker *tracker) {
    if (tracker->logCount == 0) {
        printf("No logs available to view.\n");
        return;
    }

    printf("\n--- Workout Logs ---\n");
    for (int i = 0; i < tracker->logCount; i++) {
        printf("Log %d:\n", i + 1);
        printf(" Steps: %d\n", tracker->logs[i].steps);
        printf(" Calories Burned: %.2f\n", tracker->logs[i].caloriesBurned);
        printf(" Workout Type: %s\n", tracker->logs[i].workoutType);
    }
}

void viewSummary(const FitnessTracker *tracker) {
    if (tracker->logCount == 0) {
        printf("No logs available for summary.\n");
        return;
    }

    int totalSteps = 0;
    float totalCalories = 0;

    for (int i = 0; i < tracker->logCount; i++) {
        totalSteps += tracker->logs[i].steps;
        totalCalories += tracker->logs[i].caloriesBurned;
    }

    printf("\n--- Summary ---\n");
    printf(" Total Steps: %d\n", totalSteps);
    printf(" Total Calories Burned: %.2f\n", totalCalories);
    printf(" Total Workouts Logged: %d\n", tracker->logCount);
}

void clearLogs(FitnessTracker *tracker) {
    tracker->logCount = 0;
    printf("All logs cleared successfully.\n");
}