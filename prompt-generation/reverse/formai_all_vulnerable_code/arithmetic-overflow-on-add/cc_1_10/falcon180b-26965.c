//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_EVENTS 100
#define MAX_EVENT_SIZE 100

typedef struct {
    time_t time;
    char message[MAX_EVENT_SIZE];
} Event;

Event events[MAX_EVENTS];
int num_events = 0;

void add_event(time_t time, char* message) {
    if (num_events >= MAX_EVENTS) {
        printf("Error: Maximum number of events reached.\n");
        return;
    }

    events[num_events].time = time;
    strcpy(events[num_events].message, message);
    num_events++;
}

void time_travel(time_t destination_time) {
    printf("Time traveling to %s...\n", ctime(&destination_time));

    // Reset num_events to 0
    num_events = 0;

    // Add new event
    add_event(destination_time, "Arrived in the future/past!");
}

void print_events() {
    if (num_events == 0) {
        printf("No events yet.\n");
        return;
    }

    printf("Events:\n");
    for (int i = 0; i < num_events; i++) {
        printf("%s: %s\n", ctime(&events[i].time), events[i].message);
    }
}

int main() {
    srand(time(NULL));

    // Add some example events
    add_event(time(NULL) + 60, "Traveled 1 minute into the future!");
    add_event(time(NULL) - 3600, "Traveled 1 hour into the past!");

    // Time travel to a random destination
    time_t destination_time = time(NULL) + rand() % 3600;
    time_travel(destination_time);

    // Print events
    print_events();

    return 0;
}