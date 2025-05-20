//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of time travel events
#define MAX_EVENTS 100

// Define the structure for a time travel event
typedef struct {
    time_t time;
    char* description;
} TimeTravelEvent;

// Function to compare two time travel events based on their time
int compare_events(const void* a, const void* b) {
    const TimeTravelEvent* event_a = (const TimeTravelEvent*)a;
    const TimeTravelEvent* event_b = (const TimeTravelEvent*)b;

    if (event_a->time < event_b->time) {
        return -1;
    } else if (event_a->time > event_b->time) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print the list of time travel events
void print_events(TimeTravelEvent* events, int num_events) {
    qsort(events, num_events, sizeof(TimeTravelEvent), compare_events);

    for (int i = 0; i < num_events; i++) {
        printf("%s (%ld)\n", events[i].description, events[i].time);
    }
}

// Function to add a new time travel event
void add_event(TimeTravelEvent* events, int* num_events, time_t time, char* description) {
    events[*num_events] = (TimeTravelEvent){
       .time = time,
       .description = description
    };

    (*num_events)++;
}

int main() {
    TimeTravelEvent events[MAX_EVENTS];
    int num_events = 0;

    add_event(events, &num_events, time(NULL), "Traveled back to the 1920s and danced the Charleston");
    add_event(events, &num_events, time(NULL) + 3600, "Went forward in time and saw flying cars");
    add_event(events, &num_events, time(NULL) + 7200, "Visited ancient Rome and watched a gladiator fight");

    print_events(events, num_events);

    return 0;
}