//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100

typedef struct {
    time_t time;
    char *description;
} Event;

int main() {
    int num_events;
    Event events[MAX_EVENTS];
    char input[100];
    time_t current_time, next_event_time;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please enter the number of events you would like to schedule (up to %d): ", MAX_EVENTS);
    scanf("%d", &num_events);

    for (int i = 0; i < num_events; i++) {
        printf("Event %d description: ", i+1);
        scanf("%s", input);
        events[i].description = strdup(input);
        printf("Event %d time (YYYY-MM-DD HH:MM:SS): ", i+1);
        scanf("%s", input);
        struct tm event_time;
        strptime(input, "%Y-%m-%d %H:%M:%S", &event_time);
        events[i].time = mktime(&event_time);
    }

    current_time = time(NULL);
    for (;;) {
        next_event_time = events[0].time;
        for (int i = 1; i < num_events; i++) {
            if (events[i].time < next_event_time) {
                next_event_time = events[i].time;
            }
        }
        if (next_event_time <= current_time) {
            printf("No more scheduled events.\n");
            break;
        }
        time_t seconds_until_next_event = next_event_time - current_time;
        sleep(seconds_until_next_event);
        current_time = time(NULL);
        printf("Traveling through time to %s for the %s...\n", ctime(&next_event_time), events[0].description);
    }

    return 0;
}