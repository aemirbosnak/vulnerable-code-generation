//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Happy Fitness Tracker

// Define the maximum number of activities that can be tracked
#define MAX_ACTIVITIES 10

// Define the structure for an activity
typedef struct {
    char name[50];
    int duration;
    time_t start_time;
    time_t end_time;
} Activity;

// Function to print the current date and time
void print_date_and_time() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    printf("Current date and time: %s", asctime(t));
}

// Function to get user input for an activity name
char* get_activity_name() {
    char input[50];
    printf("Enter the name of the activity: ");
    scanf("%s", input);

    return strdup(input);
}

// Function to get user input for an activity duration in minutes
int get_activity_duration() {
    int duration;

    do {
        printf("Enter the duration of the activity in minutes: ");
        scanf("%d", &duration);
    } while (duration <= 0);

    return duration;
}

// Function to calculate the duration of an activity in seconds
int calculate_activity_duration(int duration) {
    return duration * 60;
}

// Function to track an activity
void track_activity(Activity* activity) {
    time_t start_time = time(NULL);
    activity->start_time = start_time;

    printf("Starting %s...\n", activity->name);

    sleep(activity->duration);

    time_t end_time = time(NULL);
    activity->end_time = end_time;

    printf("Finished %s. Duration: %d seconds.\n", activity->name, difftime(end_time, start_time));
}

// Function to display the list of tracked activities
void display_activities(Activity activities[MAX_ACTIVITIES], int num_activities) {
    printf("\nList of tracked activities:\n");

    for (int i = 0; i < num_activities; i++) {
        printf("%s: %d seconds\n", activities[i].name, activities[i].duration);
    }
}

int main() {
    print_date_and_time();

    Activity activities[MAX_ACTIVITIES];
    int num_activities = 0;

    while (num_activities < MAX_ACTIVITIES) {
        char* name = get_activity_name();
        int duration = get_activity_duration();

        activities[num_activities] = (Activity){.name = name,.duration = duration};
        num_activities++;
    }

    for (int i = 0; i < num_activities; i++) {
        track_activity(&activities[i]);
    }

    display_activities(activities, num_activities);

    return 0;
}