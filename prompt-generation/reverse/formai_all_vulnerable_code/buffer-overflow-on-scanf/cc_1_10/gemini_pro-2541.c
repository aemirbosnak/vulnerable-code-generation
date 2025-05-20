//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: genius
// Fitness Tracker Genius Extraordinaire

// Header File Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global Constants
#define MAX_NAME_LENGTH 64
#define MAX_STEPS_PER_DAY 20000

// Structure for User Data
typedef struct {
    char name[MAX_NAME_LENGTH];
    int steps[7];
    int totalSteps;
    int goal;
} UserData;

// Function Prototypes
void initializeTracker(UserData *user);
void updateSteps(UserData *user);
void printReport(UserData *user);

// Main Function
int main() {
    // Local Variables
    UserData user;

    // Initialize Tracker
    initializeTracker(&user);

    // Update Steps
    updateSteps(&user);

    // Print Report
    printReport(&user);

    return 0;
}

// Initialize Tracker Function
void initializeTracker(UserData *user) {
    // Get User Name
    printf("Enter your name: ");
    scanf("%s", user->name);

    // Set Step Goal
    printf("Enter your step goal: ");
    scanf("%d", &user->goal);

    // Initialize Steps
    for (int i = 0; i < 7; i++) {
        user->steps[i] = 0;
        user->totalSteps = 0;
    }
}

// Update Steps Function
void updateSteps(UserData *user) {
    // Local Variables
    int day;
    int steps;

    // Get Steps for Each Day
    for (int i = 0; i < 7; i++) {
        printf("Enter the number of steps you took on day %d: ", i + 1);
        scanf("%d", &user->steps[i]);
    }
}

// Print Report Function
void printReport(UserData *user) {
    // Print Name and Goal
    printf("\nFitness Report for %s\n", user->name);
    printf("Step Goal: %d\n", user->goal);

    // Print Steps for Each Day
    for (int i = 0; i < 7; i++) {
        printf("Day %d: %d steps\n", i + 1, user->steps[i]);
    }

    // Calculate Total Steps
    user->totalSteps = 0;
    for (int i = 0; i < 7; i++) {
        user->totalSteps += user->steps[i];
    }

    // Print Total Steps and Goal Status
    printf("Total Steps: %d\n", user->totalSteps);
    if (user->totalSteps >= user->goal) {
        printf("Congratulations! You reached your goal.\n");
    } else {
        printf("Keep up the good work! You need to take %d more steps to reach your goal.\n", user->goal - user->totalSteps);
    }
}