//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_TIME_DELTA 1000

struct event {
    time_t time;
    char *description;
};

void add_event(struct event *events, int num_events, time_t time, char *description) {
    if (num_events >= MAX_EVENTS) {
        fprintf(stderr, "Error: Too many events.\n");
        exit(1);
    }
    events[num_events].time = time;
    events[num_events].description = description;
    num_events++;
}

void print_events(struct event *events, int num_events) {
    for (int i = 0; i < num_events; i++) {
        printf("%s (%ld)\n", events[i].description, events[i].time);
    }
}

int main() {
    struct event events[MAX_EVENTS];
    int num_events = 0;
    time_t current_time = time(NULL);
    char input[100];

    add_event(events, num_events, current_time + 10, "Go back 10 seconds");
    add_event(events, num_events, current_time + 20, "Go forward 20 seconds");
    add_event(events, num_events, current_time + 30, "Go back 30 seconds");

    while (1) {
        printf("Current time: %ld\n", current_time);
        printf("Enter an event number to trigger or 'q' to quit: ");
        scanf("%s", input);

        if (strcmp(input, "q") == 0) {
            break;
        }

        int event_num = atoi(input);
        if (event_num >= 0 && event_num < num_events) {
            struct event *event = &events[event_num];
            time_t event_time = event->time;

            if (event_time > current_time) {
                time_t delta = event_time - current_time;
                if (delta > MAX_TIME_DELTA) {
                    fprintf(stderr, "Error: Time travel too far in the future.\n");
                    exit(1);
                }
                sleep(delta);
            } else {
                fprintf(stderr, "Error: Time travel to the past.\n");
                exit(1);
            }

            current_time = event_time;
            printf("Time travel successful.\n");
        } else {
            fprintf(stderr, "Invalid event number.\n");
        }
    }

    return 0;
}