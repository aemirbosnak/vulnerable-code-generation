//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of activities that can be tracked
#define MAX_ACTIVITIES 10

// Define the maximum length of a activity name
#define MAX_NAME_LEN 20

// Define a struct to represent a fitness activity
struct Activity {
    char name[MAX_NAME_LEN];
    int minutes;
};

// Define a struct to represent a day's worth of activities
struct DailyActivities {
    int numActivities;
    struct Activity activities[MAX_ACTIVITIES];
};

// Define a function to add an activity to a daily activities object
void addActivity(struct DailyActivities *dailyActivities, char *activityName, int activityTime) {
    if (dailyActivities->numActivities < MAX_ACTIVITIES) {
        struct Activity newActivity;
        strncpy(newActivity.name, activityName, MAX_NAME_LEN - 1);
        newActivity.minutes = activityTime;
        dailyActivities->activities[dailyActivities->numActivities] = newActivity;
        dailyActivities->numActivities++;
    } else {
        printf("Cannot add activity, maximum number of activities reached.\n");
    }
}

// Define a function to calculate the total time spent on all activities for a day
int calculateTotalTime(struct DailyActivities *dailyActivities) {
    int totalTime = 0;
    for (int i = 0; i < dailyActivities->numActivities; i++) {
        totalTime += dailyActivities->activities[i].minutes;
    }
    return totalTime;
}

// Define a function to print out a summary of a day's activities
void printDailySummary(struct DailyActivities *dailyActivities) {
    printf("Summary of Daily Activities:\n");
    printf("---------------------------\n");
    printf("Number of activities: %d\n", dailyActivities->numActivities);
    printf("Total minutes: %d\n", calculateTotalTime(dailyActivities));
    printf("\nList of activities:\n");
    for (int i = 0; i < dailyActivities->numActivities; i++) {
        printf("%d. %s - %d minutes\n", i+1, dailyActivities->activities[i].name, dailyActivities->activities[i].minutes);
    }
}

// Define the main function, where the user can input daily activities and view summaries
int main() {
    printf("Welcome to the C Fitness Tracker!\n");
    printf("---------------------------------\n");

    // Create a daily activities struct and set the number of activities to zero
    struct DailyActivities dailyActivities;
    dailyActivities.numActivities = 0;

    int choice = 0; // Initialize the menu choice variable
    while (choice != 3) { // Keep looping until the user chooses to quit
        printf("\nPlease choose an option:\n");
        printf("1. Add a new activity\n");
        printf("2. View daily activity summary\n");
        printf("3. Quit the program\n");
        printf("> ");
        scanf("%d", &choice);
        printf("\n");

        if (choice == 1) { // Add a new activity
            char activityName[MAX_NAME_LEN];
            int activityTime;

            printf("Enter the name of the activity: ");
            scanf("%s", &activityName);
            printf("Enter the number of minutes spent on the activity: ");
            scanf("%d", &activityTime);

            addActivity(&dailyActivities, activityName, activityTime);

            printf("\nActivity added!\n");
        } else if (choice == 2) { // View daily activity summary
            printDailySummary(&dailyActivities);
        } else if (choice == 3) { // Quit the program
            printf("Thank you for using the C Fitness Tracker!\n");
        } else { // Invalid menu option
            printf("Invalid menu option, please try again.\n");
        }
    }

    return 0;
}