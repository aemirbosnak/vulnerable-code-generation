//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    events[*num_events].description = description;
    (*num_events)++;
}

void print_events(Event *events, int num_events) {
    for (int i = 0; i < num_events; i++) {
        printf("%s - %s\n", ctime(&events[i].timestamp), events[i].description);
    }
}

int main() {
    Event events[MAX_EVENTS];
    int num_events = 0;

    add_event(events, &num_events, 1609459200, "First event");
    add_event(events, &num_events, 1610364800, "Second event");
    add_event(events, &num_events, 1611270400, "Third event");

    printf("Original timeline:\n");
    print_events(events, num_events);

    time_t current_time = time(NULL);
    time_t target_time = 1610364800; // Target the second event

    while (difftime(current_time, target_time) > 0) {
        current_time -= 60; // Travel back in time by one minute
    }

    printf("\nTraveling back in time to %s...\n", ctime(&current_time));

    for (int i = 0; i < num_events; i++) {
        if (events[i].timestamp > current_time) {
            events[i].timestamp -= difftime(current_time, target_time);
        }
    }

    printf("Timeline after time travel:\n");
    print_events(events, num_events);

    return 0;
}