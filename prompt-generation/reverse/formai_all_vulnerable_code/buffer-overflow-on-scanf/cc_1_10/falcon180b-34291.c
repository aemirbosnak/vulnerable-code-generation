//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100

// Event structure
typedef struct event {
    time_t time;
    char *description;
} Event;

// Function prototypes
void add_event(Event *events, int *num_events);
void print_events(Event events[], int num_events);
void travel_time(Event events[], int num_events, time_t target_time);

int main() {
    Event events[MAX_EVENTS];
    int num_events = 0;

    // Add some sample events
    add_event(events, &num_events);
    add_event(events, &num_events);
    add_event(events, &num_events);

    // Print the initial timeline
    printf("Initial Timeline:\n");
    print_events(events, num_events);

    // Travel back in time
    time_t target_time = time(NULL) - 3600; // 1 hour ago
    travel_time(events, num_events, target_time);

    // Print the updated timeline
    printf("\nTimeline after traveling back 1 hour:\n");
    print_events(events, num_events);

    return 0;
}

void add_event(Event *events, int *num_events) {
    char input[100];
    printf("Enter an event (format: MM/DD/YYYY HH:MM:SS Event Description): ");
    scanf("%s", input);

    struct tm tm;
    strptime(input, "%m/%d/%Y %H:%M:%S", &tm);

    events[*num_events].time = mktime(&tm);
    events[*num_events].description = strdup(input);

    (*num_events)++;
}

void print_events(Event events[], int num_events) {
    for (int i = 0; i < num_events; i++) {
        printf("%s - %s\n", ctime(&events[i].time), events[i].description);
    }
}

void travel_time(Event events[], int num_events, time_t target_time) {
    for (int i = 0; i < num_events; i++) {
        if (events[i].time > target_time) {
            events[i].time -= target_time - events[i].time;
        }
    }
}