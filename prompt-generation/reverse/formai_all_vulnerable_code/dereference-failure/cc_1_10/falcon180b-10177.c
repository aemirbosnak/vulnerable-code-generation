//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define MAX_EVENTS 100

typedef struct {
    time_t timestamp;
    char *description;
} Event;

void add_event(Event *events, int *num_events, time_t timestamp, char *description) {
    if (*num_events >= MAX_EVENTS) {
        printf("Error: Maximum number of events reached.\n");
        return;
    }

    events[*num_events].timestamp = timestamp;
    events[*num_events].description = strdup(description);
    (*num_events)++;
}

int main() {
    srand(time(NULL));

    int num_events = 0;
    Event events[MAX_EVENTS];

    add_event(events, &num_events, 1582016000, "First event"); // February 18, 2020
    add_event(events, &num_events, 1609459200, "Second event"); // January 1, 2021
    add_event(events, &num_events, 1634020800, "Third event"); // September 22, 2021

    int current_event = 0;
    time_t current_timestamp = time(NULL);

    while (true) {
        if (current_event >= num_events) {
            printf("No more events.\n");
            break;
        }

        if (events[current_event].timestamp > current_timestamp) {
            printf("Waiting for event...\n");
        } else {
            printf("Event at %s\n", ctime(&events[current_event].timestamp));
            current_event++;
        }

        current_timestamp = time(NULL);
    }

    return 0;
}