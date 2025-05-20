//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100

typedef struct {
    time_t timestamp;
    char *description;
} event;

event events[MAX_EVENTS];
int num_events = 0;

void add_event(time_t timestamp, char *description) {
    if (num_events == MAX_EVENTS) {
        fprintf(stderr, "Error: too many events\n");
        exit(1);
    }

    events[num_events].timestamp = timestamp;
    events[num_events].description = description;
    num_events++;
}

void print_events() {
    for (int i = 0; i < num_events; i++) {
        printf("%s: %s\n", ctime(&events[i].timestamp), events[i].description);
    }
}

int main() {
    add_event(time(NULL), "Start of program");

    // Simulate some events
    for (int i = 0; i < 10; i++) {
        time_t timestamp = time(NULL) + (i * 60);
        char *description = malloc(100);
        sprintf(description, "Event %d", i);
        add_event(timestamp, description);
    }

    // Travel to the future
    time_t future_timestamp = time(NULL) + (60 * 60 * 24);
    time_t *old_timestamp = malloc(sizeof(time_t));
    *old_timestamp = time(NULL);
    time(old_timestamp);
    time(old_timestamp);

    // Print the events that happened in the future
    print_events();

    // Travel back to the past
    time(old_timestamp);
    time(old_timestamp);
    time(old_timestamp);
    time_t *new_timestamp = malloc(sizeof(time_t));
    *new_timestamp = time(NULL);
    time(new_timestamp);
    time(new_timestamp);

    // Print the events that happened in the past
    print_events();

    return 0;
}