//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ACTIVITIES 10
#define MAX_ACTIVITY_NAME_LENGTH 50

typedef struct {
    char name[MAX_ACTIVITY_NAME_LENGTH];
    int caloriesBurned;
} Activity;

int main() {
    Activity activities[MAX_ACTIVITIES];
    int numActivities = 0;

    printf("Welcome to the Fitness Tracker!\n");

    // prompt user to enter activities
    printf("Please enter the name of an activity followed by the number of calories burned:\n");
    while (numActivities < MAX_ACTIVITIES) {
        printf("Activity %d: ", numActivities + 1);
        scanf("%s %d", activities[numActivities].name, &activities[numActivities].caloriesBurned);
        numActivities++;
    }

    // display activities
    printf("\nActivities:\n");
    for (int i = 0; i < numActivities; i++) {
        printf("Activity %d: %s, %d calories\n", i + 1, activities[i].name, activities[i].caloriesBurned);
    }

    // prompt user to enter number of days
    int numDays;
    printf("\nPlease enter the number of days you want to track your fitness: ");
    scanf("%d", &numDays);

    // track fitness for specified number of days
    printf("\n\nFitness Tracker\n");
    for (int i = 1; i <= numDays; i++) {
        printf("Day %d:\n", i);
        int totalCaloriesBurned = 0;
        printf("Activities:\n");
        for (int j = 0; j < numActivities; j++) {
            printf("Activity %d: %s, %d calories\n", j + 1, activities[j].name, activities[j].caloriesBurned);
            totalCaloriesBurned += activities[j].caloriesBurned;
        }
        printf("\nTotal calories burned: %d\n", totalCaloriesBurned);
        printf("\n");
    }

    return 0;
}