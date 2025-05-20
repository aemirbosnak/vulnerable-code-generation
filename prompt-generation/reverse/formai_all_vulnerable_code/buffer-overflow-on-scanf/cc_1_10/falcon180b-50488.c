//Falcon-180B DATASET v1.0 Category: System event logger ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for event data
typedef struct {
    char* event_name;
    time_t event_time;
} event_t;

// Function to log an event
void log_event(event_t* event) {
    printf("Event logged: %s\n", event->event_name);
    printf("Timestamp: %s\n", ctime(&event->event_time));
}

// Function to sort events by timestamp
int compare_events(const void* a, const void* b) {
    event_t* event_a = (event_t*)a;
    event_t* event_b = (event_t*)b;

    if (event_a->event_time < event_b->event_time)
        return -1;
    else if (event_a->event_time > event_b->event_time)
        return 1;
    else
        return 0;
}

// Main function
int main() {
    // Initialize variables
    event_t* events = NULL;
    int num_events = 0;

    // Prompt user for number of events
    printf("How many events do you want to log? ");
    scanf("%d", &num_events);

    // Allocate memory for events
    events = malloc(num_events * sizeof(event_t));

    // Loop through each event and log it
    for (int i = 0; i < num_events; i++) {
        printf("Enter event name for event %d: ", i+1);
        char* event_name = malloc(100 * sizeof(char));
        scanf("%s", event_name);
        events[i].event_name = event_name;
        time_t event_time = time(NULL);
        events[i].event_time = event_time;
        log_event(&events[i]);
    }

    // Sort events by timestamp
    qsort(events, num_events, sizeof(event_t), compare_events);

    // Loop through sorted events and log them
    for (int i = 0; i < num_events; i++) {
        log_event(&events[i]);
    }

    // Free memory
    for (int i = 0; i < num_events; i++) {
        free(events[i].event_name);
    }
    free(events);

    return 0;
}