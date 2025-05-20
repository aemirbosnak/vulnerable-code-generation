//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of events that can be stored
#define MAX_EVENTS 100

// Define the structure of an event
typedef struct {
    time_t timestamp;
    char description[80];
} Event;

// Function to compare two events based on their timestamps
int compare_events(const void *a, const void *b) {
    const Event *event_a = (const Event *)a;
    const Event *event_b = (const Event *)b;

    if (event_a->timestamp < event_b->timestamp) {
        return -1;
    } else if (event_a->timestamp > event_b->timestamp) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print the list of events in chronological order
void print_events(Event events[], int num_events) {
    qsort(events, num_events, sizeof(Event), compare_events);

    printf("Chronological list of events:\n");
    for (int i = 0; i < num_events; i++) {
        printf("%s - %s\n", ctime(&events[i].timestamp), events[i].description);
    }
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the list of events
    Event events[MAX_EVENTS];
    int num_events = 0;

    // Simulate time travel by randomly adding events to the list
    for (int i = 0; i < 10; i++) {
        time_t timestamp = rand() % (time(NULL) - 86400) + time(NULL) - 86400; // Generate a random timestamp within the last 24 hours
        char description[80];
        sprintf(description, "Event %d at %s", i + 1, ctime(&timestamp));
        events[num_events++] = (Event){timestamp, description};
    }

    // Print the initial list of events
    printf("Initial list of events:\n");
    for (int i = 0; i < num_events; i++) {
        printf("%s - %s\n", ctime(&events[i].timestamp), events[i].description);
    }

    // Simulate time travel by randomly removing events from the list
    for (int i = 0; i < 5; i++) {
        int index = rand() % num_events;
        events[index] = events[--num_events];
    }

    // Print the final list of events
    printf("\nFinal list of events:\n");
    print_events(events, num_events);

    return 0;
}