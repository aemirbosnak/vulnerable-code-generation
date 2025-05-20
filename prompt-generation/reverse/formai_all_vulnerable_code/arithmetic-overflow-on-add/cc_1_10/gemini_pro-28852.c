//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: happy
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_EVENT_NAME_LENGTH 20

typedef struct _Event {
    char name[MAX_EVENT_NAME_LENGTH];
    time_t timestamp;
} Event;

Event events[MAX_EVENTS];
int num_events = 0;

bool add_event(char *name, time_t timestamp) {
    if (num_events >= MAX_EVENTS) {
        return false;
    }

    strcpy(events[num_events].name, name);
    events[num_events].timestamp = timestamp;
    num_events++;

    return true;
}

Event *find_event(char *name) {
    for (int i = 0; i < num_events; i++) {
        if (strcmp(events[i].name, name) == 0) {
            return &events[i];
        }
    }

    return NULL;
}

void print_events() {
    printf("Time Travel Simulator\n");
    printf("--------------------\n");

    for (int i = 0; i < num_events; i++) {
        printf("%s: %s\n", events[i].name, ctime(&events[i].timestamp));
    }
}

int main() {
    // Add some events to the simulator.
    add_event("Birth", time(NULL));
    add_event("First day of school", time(NULL) + (60 * 60 * 24 * 365));
    add_event("Graduation", time(NULL) + (60 * 60 * 24 * 365 * 18));
    add_event("First job", time(NULL) + (60 * 60 * 24 * 365 * 22));
    add_event("Marriage", time(NULL) + (60 * 60 * 24 * 365 * 28));
    add_event("Retirement", time(NULL) + (60 * 60 * 24 * 365 * 65));

    // Print the events.
    print_events();

    // Get the user's input.
    char input[80];
    printf("Enter an event name to travel to, or 'quit' to exit: ");
    gets(input);

    // Travel to the event.
    while (strcmp(input, "quit") != 0) {
        Event *event = find_event(input);

        if (event != NULL) {
            time_t now = time(NULL);
            if (event->timestamp > now) {
                printf("You cannot travel to the future!\n");
            } else {
                time_t diff = event->timestamp - now;
                printf("Traveling to %s in %ld seconds...\n", event->name, diff);
                sleep(diff);
                printf("You have arrived at %s!\n", event->name);
            }
        } else {
            printf("Event not found.\n");
        }

        // Get the user's input.
        printf("Enter an event name to travel to, or 'quit' to exit: ");
        gets(input);
    }

    return 0;
}