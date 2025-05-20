//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACTIVITIES 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int duration;
    int caloriesBurned;
    int stepsCount;
} Activity;

int main() {
    int numActivities, i, choice;
    Activity activities[MAX_ACTIVITIES];

    printf("Welcome to the Fitness Tracker!\n");

    // Initialize all activities
    for (i = 0; i < MAX_ACTIVITIES; i++) {
        strcpy(activities[i].name, "");
        activities[i].duration = 0;
        activities[i].caloriesBurned = 0;
        activities[i].stepsCount = 0;
    }

    numActivities = 0;

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an activity\n");
        printf("2. View activities\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (numActivities >= MAX_ACTIVITIES) {
                printf("Maximum number of activities reached.\n");
            } else {
                printf("Enter the name of the activity:\n");
                scanf("%s", activities[numActivities].name);
                printf("Enter the duration of the activity in minutes:\n");
                scanf("%d", &activities[numActivities].duration);
                printf("Enter the number of calories burned during the activity:\n");
                scanf("%d", &activities[numActivities].caloriesBurned);
                printf("Enter the number of steps taken during the activity:\n");
                scanf("%d", &activities[numActivities].stepsCount);
                numActivities++;
            }
            break;

        case 2:
            if (numActivities == 0) {
                printf("No activities added yet.\n");
            } else {
                printf("\nActivity Name\tDuration (min)\tCalories Burned\tSteps Count\n");
                for (i = 0; i < numActivities; i++) {
                    printf("%s\t\t%d\t\t%d\t\t%d\n", activities[i].name, activities[i].duration, activities[i].caloriesBurned, activities[i].stepsCount);
                }
            }
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}