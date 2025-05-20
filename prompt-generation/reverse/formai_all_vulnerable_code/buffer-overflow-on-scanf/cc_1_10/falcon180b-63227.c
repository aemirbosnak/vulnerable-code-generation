//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of events that can be stored
#define MAX_EVENTS 100

// Define the structure for storing events
typedef struct {
    time_t timestamp;
    char description[100];
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

    // Simulate time travel by randomly jumping between different points in time
    while (num_events < MAX_EVENTS) {
        time_t current_time = time(NULL);
        time_t target_time = current_time - rand() % (60 * 60 * 24 * 365); // Jump back up to 1 year

        if (target_time < current_time) {
            printf("Time travel successful! You have arrived at %s.\n", ctime(&target_time));
        } else {
            printf("Time travel failed. You are still in the present (%s).\n", ctime(&current_time));
        }

        char input[100];
        printf("Describe your experience: ");
        scanf("%s", input);

        strncpy(events[num_events].description, input, 99);
        events[num_events].timestamp = target_time;
        num_events++;
    }

    // Print the list of events in chronological order
    print_events(events, num_events);

    return 0;
}