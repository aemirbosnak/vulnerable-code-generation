//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ACTIVITIES 10
#define MAX_ACTIVITY_NAME_LENGTH 50
#define MAX_ACTIVITY_DURATION 24*60*60

typedef struct {
    char name[MAX_ACTIVITY_NAME_LENGTH];
    int duration;
} Activity;

int main() {
    Activity activities[MAX_ACTIVITIES];
    int num_activities = 0;
    char input_buffer[100];
    time_t current_time;
    struct tm *current_tm;
    int activity_index = -1;

    printf("Welcome to the Fitness Tracker!\n");

    while(1) {
        printf("Enter an activity (or type 'quit' to exit): ");
        fgets(input_buffer, 100, stdin);

        if(strcmp(input_buffer, "quit") == 0) {
            break;
        }

        if(num_activities >= MAX_ACTIVITIES) {
            printf("Sorry, you can only have %d activities.\n", MAX_ACTIVITIES);
            continue;
        }

        activity_index++;
        if(activity_index >= num_activities) {
            num_activities++;
        }

        activities[activity_index].duration = 0;
        printf("Enter the name of the activity: ");
        fgets(activities[activity_index].name, MAX_ACTIVITY_NAME_LENGTH, stdin);

        printf("Enter the duration of the activity in seconds: ");
        scanf("%d", &activities[activity_index].duration);

        if(activities[activity_index].duration > MAX_ACTIVITY_DURATION) {
            printf("Sorry, the duration of an activity cannot be longer than %d seconds.\n", MAX_ACTIVITY_DURATION);
            num_activities--;
            continue;
        }

        printf("Activity %s added.\n", activities[activity_index].name);
    }

    printf("Activities:\n");
    for(int i = 0; i < num_activities; i++) {
        printf("%s: %d seconds\n", activities[i].name, activities[i].duration);
    }

    return 0;
}