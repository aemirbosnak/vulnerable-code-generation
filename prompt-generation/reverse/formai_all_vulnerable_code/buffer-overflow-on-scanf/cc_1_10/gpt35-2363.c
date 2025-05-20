//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

/* Define a macro for ease of use */
#define MAX(x, y) ((x) > (y) ? (x) : (y))

/* Define a struct to hold exercise data */
typedef struct ExerciseData {
    int pushups;
    int squats;
    int lunges;
    int planks;
} ExerciseData;

/* Define a function to print the exercise data */
void printExerciseData(ExerciseData data) {
    printf("Pushups: %d\n", data.pushups);
    printf("Squats: %d\n", data.squats);
    printf("Lunges: %d\n", data.lunges);
    printf("Planks: %d\n", data.planks);
}

/* Define a function to add new exercise data to the tracker */
void addExerciseData(ExerciseData *tracker) {
    int pushups, squats, lunges, planks;
    printf("Enter today's exercise data:\n");
    printf("Pushups: ");
    scanf("%d", &pushups);
    printf("Squats: ");
    scanf("%d", &squats);
    printf("Lunges: ");
    scanf("%d", &lunges);
    printf("Planks: ");
    scanf("%d", &planks);
    tracker->pushups += pushups;
    tracker->squats += squats;
    tracker->lunges += lunges;
    tracker->planks += planks;
}

/* Define a function to display exercise data for a given week */
void displayWeeklySummary(ExerciseData *tracker, int week) {
    int totalPushups = 0, totalSquats = 0, totalLunges = 0, totalPlanks = 0;
    int i;
    printf("Weekly summary for Week %d:\n", week);
    for (i = 1; i <= 7; i++) {
        printf("Day %d:\n", i);
        printf("Pushups: %d\n", tracker[i].pushups);
        printf("Squats: %d\n", tracker[i].squats);
        printf("Lunges: %d\n", tracker[i].lunges);
        printf("Planks: %d\n", tracker[i].planks);
        totalPushups += tracker[i].pushups;
        totalSquats += tracker[i].squats;
        totalLunges += tracker[i].lunges;
        totalPlanks += tracker[i].planks;
    }
    printf("Weekly Totals:\n");
    printf("Pushups: %d\n", totalPushups);
    printf("Squats: %d\n", totalSquats);
    printf("Lunges: %d\n", totalLunges);
    printf("Planks: %d\n", totalPlanks);
}

int main() {
    int i, choice, week = 1;
    ExerciseData tracker[8];
    for (i = 0; i < 8; i++) {
        tracker[i].pushups = 0;
        tracker[i].squats = 0;
        tracker[i].lunges = 0;
        tracker[i].planks = 0;
    }
    printf("Welcome to the Fitness Tracker!\n");
    while (1) {
        printf("What would you like to do?\n");
        printf("1. Add exercise data for today\n");
        printf("2. Display summary for current week\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addExerciseData(&tracker[week]);
                break;
            case 2:
                displayWeeklySummary(tracker, week);
                week++;
                if (week > 7) week = 1;
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    }
    return 0;
}