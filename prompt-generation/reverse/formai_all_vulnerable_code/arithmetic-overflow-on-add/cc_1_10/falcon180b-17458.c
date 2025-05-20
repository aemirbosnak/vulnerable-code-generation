//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100
#define MAX_EVENT_LENGTH 80
#define TIME_TRAVEL_SPEED 1000 // in milliseconds

typedef struct {
    char *event;
    time_t timestamp;
} Event;

int num_events = 0;
Event events[MAX_EVENTS];

void add_event(char *event) {
    if (num_events >= MAX_EVENTS) {
        printf("Error: Maximum number of events reached.\n");
        return;
    }

    events[num_events].event = strdup(event);
    events[num_events].timestamp = time(NULL) + TIME_TRAVEL_SPEED;
    num_events++;
}

void display_events() {
    printf("Current events:\n");
    for (int i = 0; i < num_events; i++) {
        printf("%s - %s\n", events[i].event, ctime(&events[i].timestamp));
    }
}

void time_travel() {
    printf("Entering time travel mode...\n");
    for (int i = 0; i < num_events; i++) {
        sleep(events[i].timestamp - time(NULL));
        printf("%s\n", events[i].event);
    }
}

int main() {
    add_event("First event");
    add_event("Second event");
    add_event("Third event");

    display_events();

    time_travel();

    return 0;
}