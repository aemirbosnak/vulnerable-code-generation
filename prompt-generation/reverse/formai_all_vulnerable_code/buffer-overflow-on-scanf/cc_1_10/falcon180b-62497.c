//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100

// Event structure
typedef struct {
    time_t time;
    char *description;
} Event;

// Function prototypes
void add_event(Event *events, int *num_events);
void print_events(Event *events, int num_events);
void time_travel(Event *events, int num_events, time_t target_time);

int main() {
    Event events[MAX_EVENTS];
    int num_events = 0;

    // Add some example events
    add_event(events, &num_events);
    add_event(events, &num_events);
    add_event(events, &num_events);

    // Print the initial timeline
    printf("Initial timeline:\n");
    print_events(events, num_events);

    // Time travel to a specific time
    time_t target_time = 946684800; // January 1, 2000
    time_travel(events, num_events, target_time);

    // Print the updated timeline
    printf("\nTimeline after time travel:\n");
    print_events(events, num_events);

    return 0;
}

void add_event(Event *events, int *num_events) {
    char description[100];
    printf("Enter event description: ");
    scanf("%s", description);

    events[*num_events].time = time(NULL);
    events[*num_events].description = strdup(description);

    (*num_events)++;
}

void print_events(Event *events, int num_events) {
    for (int i = 0; i < num_events; i++) {
        printf("%s - %s\n", ctime(&events[i].time), events[i].description);
    }
}

void time_travel(Event *events, int num_events, time_t target_time) {
    for (int i = 0; i < num_events; i++) {
        if (events[i].time > target_time) {
            events[i].time -= target_time;
        }
    }
}