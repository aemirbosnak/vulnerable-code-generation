//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char activity[50];
    int duration; // in minutes
    int calories; // consumed during the activity
    int steps;    // steps taken during the activity
} Activity;

// Function prototypes
void addActivity(Activity activities[], int *count);
void viewActivities(const Activity activities[], int count);
void deleteActivity(Activity activities[], int *count);
void calculateTotalStats(const Activity activities[], int count);

int main() {
    Activity activities[MAX_ENTRIES];
    int count = 0;
    int choice;

    do {
        printf("\n*** Fitness Tracker Menu ***\n");
        printf("1. Add Activity\n");
        printf("2. View Activities\n");
        printf("3. Delete Activity\n");
        printf("4. Calculate Total Stats\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character after entering choice

        switch (choice) {
            case 1:
                addActivity(activities, &count);
                break;
            case 2:
                viewActivities(activities, count);
                break;
            case 3:
                deleteActivity(activities, &count);
                break;
            case 4:
                calculateTotalStats(activities, count);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addActivity(Activity activities[], int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Activity log is full! Cannot add more activities.\n");
        return;
    }

    printf("Enter activity name: ");
    fgets(activities[*count].activity, 50, stdin);
    activities[*count].activity[strcspn(activities[*count].activity, "\n")] = 0; // Remove newline

    printf("Enter duration in minutes: ");
    scanf("%d", &activities[*count].duration);
    printf("Enter calories burned: ");
    scanf("%d", &activities[*count].calories);
    printf("Enter steps taken: ");
    scanf("%d", &activities[*count].steps);
    getchar(); // Clear newline character

    (*count)++;
    printf("Activity added successfully!\n");
}

void viewActivities(const Activity activities[], int count) {
    if (count == 0) {
        printf("No activities recorded yet.\n");
        return;
    }

    printf("\n*** Recorded Activities ***\n");
    for (int i = 0; i < count; i++) {
        printf("Activity %d: %s | Duration: %d mins | Calories: %d | Steps: %d\n",
            i + 1, activities[i].activity, activities[i].duration, activities[i].calories, activities[i].steps);
    }
}

void deleteActivity(Activity activities[], int *count) {
    if (*count == 0) {
        printf("No activities to delete.\n");
        return;
    }

    viewActivities(activities, *count);
    int index;
    printf("Enter the activity number to delete: ");
    scanf("%d", &index);
    index--; // Adjust for zero-based index

    if (index < 0 || index >= *count) {
        printf("Invalid activity number!\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        activities[i] = activities[i + 1];
    }
    (*count)--;
    printf("Activity deleted successfully!\n");
}

void calculateTotalStats(const Activity activities[], int count) {
    if (count == 0) {
        printf("No activities recorded yet.\n");
        return;
    }

    int totalCalories = 0;
    int totalSteps = 0;

    for (int i = 0; i < count; i++) {
        totalCalories += activities[i].calories;
        totalSteps += activities[i].steps;
    }

    printf("Total Calories Burned: %d\n", totalCalories);
    printf("Total Steps Taken: %d\n", totalSteps);
}