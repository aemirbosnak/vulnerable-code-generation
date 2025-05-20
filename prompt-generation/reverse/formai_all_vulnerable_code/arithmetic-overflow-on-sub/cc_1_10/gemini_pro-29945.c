//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

struct time_node {
    time_t time;
    char *event;
    struct time_node *next;
};

struct time_traveler {
    struct time_node *history;
    struct time_node *future;
    time_t current_time;
};

void time_travel(struct time_traveler *traveler, time_t destination) {
    if (destination < traveler->current_time) {
        // Travel to the past
        while (traveler->history && traveler->history->time > destination) {
            traveler->future = malloc(sizeof(struct time_node));
            traveler->future->time = traveler->history->time;
            traveler->future->event = traveler->history->event;
            traveler->future->next = traveler->future;
            traveler->history = traveler->history->next;
        }
        traveler->current_time = destination;
    } else {
        // Travel to the future
        while (traveler->future && traveler->future->time < destination) {
            traveler->history = malloc(sizeof(struct time_node));
            traveler->history->time = traveler->future->time;
            traveler->history->event = traveler->future->event;
            traveler->history->next = traveler->history;
            traveler->future = traveler->future->next;
        }
        traveler->current_time = destination;
    }
}

int main() {
    // Create a time traveler
    struct time_traveler traveler;
    traveler.history = NULL;
    traveler.future = NULL;
    traveler.current_time = time(NULL);

    // Add some events to the traveler's history
    struct time_node *event1 = malloc(sizeof(struct time_node));
    event1->time = traveler.current_time - 3600;
    event1->event = "Woke up";
    traveler.history = event1;
    struct time_node *event2 = malloc(sizeof(struct time_node));
    event2->time = traveler.current_time - 1800;
    event2->event = "Ate breakfast";
    event2->next = event1;
    traveler.history = event2;
    struct time_node *event3 = malloc(sizeof(struct time_node));
    event3->time = traveler.current_time - 900;
    event3->event = "Went for a walk";
    event3->next = event2;
    traveler.history = event3;

    // Add some events to the traveler's future
    struct time_node *event4 = malloc(sizeof(struct time_node));
    event4->time = traveler.current_time + 900;
    event4->event = "Meet with friends";
    traveler.future = event4;
    struct time_node *event5 = malloc(sizeof(struct time_node));
    event5->time = traveler.current_time + 1800;
    event5->event = "Go to the movies";
    event5->next = event4;
    traveler.future = event5;
    struct time_node *event6 = malloc(sizeof(struct time_node));
    event6->time = traveler.current_time + 3600;
    event6->event = "Go to bed";
    event6->next = event5;
    traveler.future = event6;

    // Print the traveler's current time
    printf("Current time: %s", ctime(&traveler.current_time));

    // Travel to the past
    time_travel(&traveler, traveler.current_time - 1800);

    // Print the traveler's current time
    printf("Current time after traveling to the past: %s", ctime(&traveler.current_time));

    // Travel to the future
    time_travel(&traveler, traveler.current_time + 3600);

    // Print the traveler's current time
    printf("Current time after traveling to the future: %s", ctime(&traveler.current_time));

    return 0;
}