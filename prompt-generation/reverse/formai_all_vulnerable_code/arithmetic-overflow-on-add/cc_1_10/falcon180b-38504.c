//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Define the maximum number of events
#define MAX_EVENTS 100

// Define the event structure
typedef struct {
    time_t timestamp;
    char* description;
} Event;

// Initialize the random number generator
void init_random() {
    srand(time(NULL));
}

// Generate a random integer between min and max (inclusive)
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Generate a random time_t value within the specified range
time_t rand_time(time_t start, time_t end) {
    return start + rand_int(0, end - start);
}

// Print an event
void print_event(Event* event) {
    printf("%s - %s\n", ctime(&event->timestamp), event->description);
}

// Add an event to the timeline
void add_event(Event* timeline, int index, time_t timestamp, char* description) {
    if (index >= MAX_EVENTS) {
        printf("Timeline is full.\n");
        return;
    }
    timeline[index].timestamp = timestamp;
    timeline[index].description = description;
}

// Travel through time
void time_travel(Event* timeline, int num_events, time_t target_time) {
    int i;
    bool found = false;
    for (i = 0; i < num_events; i++) {
        if (timeline[i].timestamp == target_time) {
            print_event(&timeline[i]);
            found = true;
            break;
        }
    }
    if (!found) {
        printf("No event found at that time.\n");
    }
}

int main() {
    Event timeline[MAX_EVENTS];
    int num_events = 0;
    time_t current_time = time(NULL);

    // Initialize the random number generator
    init_random();

    // Add some random events to the timeline
    add_event(timeline, num_events++, current_time - 86400, "Yesterday");
    add_event(timeline, num_events++, current_time - 3600, "One hour ago");
    add_event(timeline, num_events++, current_time + 3600, "One hour from now");
    add_event(timeline, num_events++, current_time + 86400, "Tomorrow");

    // Travel through time
    int target_index;
    printf("Enter the index of the event you want to travel to (0-3): ");
    scanf("%d", &target_index);
    time_travel(timeline, num_events, timeline[target_index].timestamp);

    return 0;
}