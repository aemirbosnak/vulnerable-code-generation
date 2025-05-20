//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Activity {
    char name[50];
    int caloriesBurned;
    int duration;
};

typedef struct Activity Activity;

int main() {
    Activity activities[100];
    int numActivities = 0;
    int totalCalories = 0;
    int totalTime = 0;
    char action[10];

    printf("Welcome to the Fitness Tracker!\n");

    while (1) {
        printf("Enter an action: (add, view, exit):\n");
        scanf("%s", action);

        if (strcmp(action, "add") == 0) {
            Activity activity;
            printf("Enter activity name:\n");
            scanf("%s", activity.name);
            printf("Enter calories burned:\n");
            scanf("%d", &activity.caloriesBurned);
            printf("Enter duration (in minutes):\n");
            scanf("%d", &activity.duration);

            activities[numActivities] = activity;
            numActivities++;
            totalCalories += activity.caloriesBurned;
            totalTime += activity.duration;

            printf("Activity added!\n");
        } else if (strcmp(action, "view") == 0) {
            if (numActivities == 0) {
                printf("No activities added yet.\n");
            } else {
                printf("Activities:\n");
                for (int i = 0; i < numActivities; i++) {
                    printf("%d) %s - %d calories burned - %d minutes\n", i+1, activities[i].name, activities[i].caloriesBurned, activities[i].duration);
                }
                printf("Total calories burned: %d\n", totalCalories);
                printf("Total time spent: %d minutes\n", totalTime);
            }
        } else if (strcmp(action, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid action. Try again.\n");
        }
    }

    return 0;
}