//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Ken Thompson
/* A C Fitness Tracker Program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function prototypes */
void displayMenu();
void recordWorkout();
void viewProgress();

/* Global variables */
int pushupCount = 0;
int situpCount = 0;
double runningDistance = 0.0;

int main() {
    displayMenu();
    return 0;
}

/**
 * Displays the main menu of the program and reads the user's choice
 */
void displayMenu() {
    int choice;
    printf("Welcome to the C Fitness Tracker!\n");
    printf("1. Record Workout\n");
    printf("2. View Progress\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            recordWorkout();
            break;
        case 2:
            viewProgress();
            break;
        case 3:
            printf("Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            displayMenu();
    }
}

/**
 * Records the user's workout by prompting for the number of pushups, situps, and distance run
 */
void recordWorkout() {
    int pushups, situps;
    double distance;
    printf("Record Workout:\n");
    printf("Enter number of pushups: ");
    scanf("%d", &pushups);
    printf("Enter number of situps: ");
    scanf("%d", &situps);
    printf("Enter distance run (in miles): ");
    scanf("%lf", &distance);

    pushupCount += pushups;
    situpCount += situps;
    runningDistance += distance;

    printf("Workout recorded!\n");
    displayMenu();
}

/**
 * Views the user's progress by displaying current counts of pushups, situps, and distance run
 */
void viewProgress() {
    printf("View Progress:\n");
    printf("Pushups: %d\n", pushupCount);
    printf("Situps: %d\n", situpCount);
    printf("Distance run (in miles): %.2lf\n", runningDistance);
    displayMenu();
}