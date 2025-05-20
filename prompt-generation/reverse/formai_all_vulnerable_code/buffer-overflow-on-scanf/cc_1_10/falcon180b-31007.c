//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100

struct event {
    time_t time;
    char *description;
};

int main() {
    int num_events;
    struct event events[MAX_EVENTS];
    char input[100];
    time_t current_time, next_event_time;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please enter the number of events you would like to simulate (up to %d): ", MAX_EVENTS);
    scanf("%d", &num_events);

    for (int i = 0; i < num_events; i++) {
        printf("Enter the time (in seconds since epoch) and description for event %d:\n", i+1);
        scanf("%s %ld", input, &events[i].time);
        events[i].description = strdup(input);
    }

    current_time = time(NULL);
    next_event_time = current_time;

    while (1) {
        sleep(1);
        current_time = time(NULL);

        for (int i = 0; i < num_events; i++) {
            if (events[i].time > current_time && events[i].time < next_event_time) {
                next_event_time = events[i].time;
            }
        }

        if (next_event_time <= current_time) {
            printf("No more events.\n");
            break;
        }

        sleep(next_event_time - current_time);
        printf("Traveling to %s...\n", events[0].description);
        current_time = next_event_time;
    }

    return 0;
}