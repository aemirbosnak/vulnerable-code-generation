//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 1000
#define MAX_TIME 1000000

typedef struct {
    time_t time;
    char *description;
} Event;

int main(int argc, char *argv[]) {
    int num_events = 0;
    Event events[MAX_EVENTS];
    time_t current_time = 0;
    char input[100];

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Enter events in the format: 'time description'\n");
    printf("Enter 'done' when finished.\n");

    while (fgets(input, sizeof(input), stdin)!= NULL) {
        if (strcmp(input, "done") == 0) {
            break;
        }

        time_t event_time;
        char *event_description;

        if (sscanf(input, "%ld %s", &event_time, event_description)!= 2) {
            printf("Invalid event format.\n");
            continue;
        }

        if (num_events >= MAX_EVENTS) {
            printf("Maximum number of events reached.\n");
            continue;
        }

        events[num_events].time = event_time;
        events[num_events].description = strdup(event_description);
        num_events++;
    }

    printf("Traveling through time...\n");

    for (int i = 0; i < num_events; i++) {
        time_t event_time = events[i].time;
        char *event_description = events[i].description;

        while (current_time < event_time) {
            printf("Waiting for %s...\n", ctime(&event_time));
            current_time = time(NULL);
        }

        printf("Arrived at %s: %s\n", ctime(&event_time), event_description);

        free(event_description);
    }

    return 0;
}