//LLAMA2-13B DATASET v1.0 Category: System event logger ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Define a structure to represent an event
typedef struct {
    int timestamp;  // timestamp in seconds
    char event_type; // 'E' for error, 'I' for info, etc.
    char message[100]; // event message
} event_t;

// Define a global array to store events
event_t events[100];

// Define a function to log an event
void log_event(char event_type, char message[]) {
    // Calculate the timestamp using the current time
    int timestamp = (int)((double)clock() / CLOCKS_PER_SEC) * 1000;

    // Create a new event structure and fill in the details
    event_t new_event = {timestamp, event_type, message};

    // Add the event to the global array
    int i = 0;
    for (i = 0; i < 100; i++) {
        if (events[i].timestamp == 0) {
            events[i] = new_event;
            break;
        }
    }

    // If the array is full, overwrite the oldest event
    if (i == 100) {
        for (i = 0; i < 100; i++) {
            if (events[i].timestamp == 0) {
                events[i] = new_event;
                break;
            }
        }
    }
}

// Define a function to print the events
void print_events() {
    int i = 0;
    for (i = 0; i < 100; i++) {
        if (events[i].timestamp != 0) {
            printf("%d %c %s\n", events[i].timestamp, events[i].event_type, events[i].message);
        }
    }
}

int main() {
    // Log some events
    log_event('E', "Error: Division by zero detected");
    log_event('I', "Info: Program started");
    log_event('W', "Warning: Memory allocation failed");

    // Print the events
    print_events();

    return 0;
}