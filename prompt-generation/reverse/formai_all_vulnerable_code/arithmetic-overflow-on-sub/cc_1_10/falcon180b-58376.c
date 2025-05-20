//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100

// Event structure to store timestamp and description
struct event {
    time_t timestamp;
    char description[100];
};

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Initialize event list
    struct event events[MAX_EVENTS];
    int num_events = 0;

    // Prompt user for number of events
    printf("Enter the number of events (maximum %d): ", MAX_EVENTS);
    scanf("%d", &num_events);

    // Fill event list with user input
    for (int i = 0; i < num_events; i++) {
        printf("Enter event #%d (timestamp in YYYY-MM-DD HH:MM:SS format followed by description): ", i+1);
        scanf("%s", events[i].description);
        strptime(events[i].description, "%Y-%m-%d %H:%M:%S", &events[i].timestamp);
    }

    // Shuffle event list
    for (int i = 0; i < num_events; i++) {
        int j = rand() % num_events;
        struct event temp = events[i];
        events[i] = events[j];
        events[j] = temp;
    }

    // Simulate time travel
    int current_event = 0;
    while (1) {
        time_t current_time = time(NULL);

        // Check if it's time to travel
        if (difftime(current_time, events[current_event].timestamp) <= 0) {
            // Print event description and travel to next event
            printf("%s\n", events[current_event].description);
            current_event = (current_event + 1) % num_events;
        }

        // Wait for next event
        time_t wait_time = events[current_event].timestamp - current_time;
        sleep(wait_time);
    }

    return 0;
}