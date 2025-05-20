//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 1000
#define MAX_TIME_TRAVEL_DISTANCE 100
#define MAX_TIME_TRAVEL_DURATION 10

struct event {
    int time;
    char *description;
};

int main() {
    int num_events;
    struct event events[MAX_EVENTS];
    char input[100];
    int i, j;
    int current_time = 0;
    int current_index = 0;
    int time_travel_distance;
    int time_travel_duration;
    char *time_machine_name = "Flux Capacitor";

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please enter the number of events you would like to simulate: ");
    scanf("%d", &num_events);

    for (i = 0; i < num_events; i++) {
        printf("Enter the time for event %d (in seconds): ", i);
        scanf("%d", &events[i].time);
        printf("Enter a description for event %d: ", i);
        scanf("%s", events[i].description);
    }

    printf("Enter the name of your time machine: ");
    scanf("%s", time_machine_name);

    while (current_time < MAX_TIME_TRAVEL_DURATION) {
        printf("\nCurrent time: %d seconds\n", current_time);
        printf("Current event: %s\n", events[current_index].description);

        if (current_time >= events[current_index].time) {
            current_time += events[current_index].time;
            current_index++;

            if (current_index >= num_events) {
                printf("\nAll events have been simulated.\n");
                break;
            }
        }

        printf("Do you want to use the time machine? (y/n): ");
        scanf(" %c", &input[0]);

        if (input[0] == 'y') {
            printf("Enter the time travel distance (in seconds): ");
            scanf("%d", &time_travel_distance);

            if (time_travel_distance > MAX_TIME_TRAVEL_DISTANCE) {
                printf("Sorry, the maximum time travel distance is %d seconds.\n", MAX_TIME_TRAVEL_DISTANCE);
            } else {
                printf("Enter the time travel duration (in seconds): ");
                scanf("%d", &time_travel_duration);

                current_time += time_travel_duration;

                printf("\nYou have traveled %d seconds into the future/past.\n", time_travel_distance);
            }
        }
    }

    return 0;
}