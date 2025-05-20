//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ACTIVITIES 10
#define MAX_ACTIVITY_NAME_LEN 50

typedef struct {
    char name[MAX_ACTIVITY_NAME_LEN];
    int duration;
    int caloriesBurned;
} Activity;

Activity activities[MAX_ACTIVITIES];
int numActivities = 0;

void addActivity(char* name, int duration, int caloriesBurned) {
    strcpy(activities[numActivities].name, name);
    activities[numActivities].duration = duration;
    activities[numActivities].caloriesBurned = caloriesBurned;
    numActivities++;
}

void printActivities() {
    printf("Activities:\n");
    for (int i = 0; i < numActivities; i++) {
        printf("%s\tDuration: %d minutes\tCalories burned: %d\n", activities[i].name, activities[i].duration, activities[i].caloriesBurned);
    }
}

int main() {
    printf("Welcome to the Fitness Tracker!\n\n");

    char input[100];
    while (1) {
        printf("Enter an activity (type 'quit' to exit): ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        printf("Enter the duration (in minutes): ");
        scanf("%d", &activities[numActivities].duration);

        printf("Enter the calories burned: ");
        scanf("%d", &activities[numActivities].caloriesBurned);

        addActivity(input, activities[numActivities].duration, activities[numActivities].caloriesBurned);
        numActivities++;
    }

    printActivities();

    return 0;
}