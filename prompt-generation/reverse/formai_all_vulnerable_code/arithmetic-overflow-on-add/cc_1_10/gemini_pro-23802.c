//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: interoperable
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
    if (num_events >= MAX_EVENTS) {
        printf("Error: Maximum number of events reached.\n");
        return;
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
    // Initialize the random number generator
    srand(time(NULL));

    // Generate some random events
    for (int i = 0; i < 10; i++) {
        // Generate a random timestamp
        time_t timestamp = time(NULL) + (rand() % 3600);

        // Generate a random description
        char description[100];
        sprintf(description, "Event %d", i+1);

        // Add the event to the list
        add_event(timestamp, description);
    }

    // Print the list of events
    print_events();

    return 0;
}