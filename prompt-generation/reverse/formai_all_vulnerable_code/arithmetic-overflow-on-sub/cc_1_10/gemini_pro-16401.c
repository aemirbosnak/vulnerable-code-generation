//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of events to store in the buffer
#define MAX_EVENTS 100

// Define the structure of an event
typedef struct {
    char *name;
    time_t timestamp;
} event;

// Create a buffer to store the events
event buffer[MAX_EVENTS];

// Initialize the buffer index
int buffer_index = 0;

// Add an event to the buffer
void add_event(char *name) {
    // Check if the buffer is full
    if (buffer_index == MAX_EVENTS) {
        // If the buffer is full, shift the events down one
        for (int i = 0; i < MAX_EVENTS - 1; i++) {
            buffer[i] = buffer[i + 1];
        }

        // Decrement the buffer index
        buffer_index--;
    }

    // Add the new event to the buffer
    buffer[buffer_index].name = name;
    buffer[buffer_index].timestamp = time(NULL);

    // Increment the buffer index
    buffer_index++;
}

// Check for suspicious activity
int check_for_suspicious_activity() {
    // Check if there are any events in the buffer
    if (buffer_index == 0) {
        // If there are no events in the buffer, return 0
        return 0;
    }

    // Check if there are any events that occur within a short period of time
    for (int i = 0; i < buffer_index; i++) {
        for (int j = i + 1; j < buffer_index; j++) {
            if (buffer[j].timestamp - buffer[i].timestamp < 10) {
                // If there are two events that occur within a short period of time, return 1
                return 1;
            }
        }
    }

    // If there are no events that occur within a short period of time, return 0
    return 0;
}

// Print the events in the buffer
void print_events() {
    for (int i = 0; i < buffer_index; i++) {
        printf("%s: %ld\n", buffer[i].name, buffer[i].timestamp);
    }
}

// Main function
int main() {
    // Add some events to the buffer
    add_event("login");
    add_event("create_user");
    add_event("delete_user");
    add_event("modify_user");
    add_event("logout");

    // Check for suspicious activity
    int suspicious_activity = check_for_suspicious_activity();

    // Print the events in the buffer
    print_events();

    // If there was suspicious activity, alert the user
    if (suspicious_activity) {
        printf("Suspicious activity detected!\n");
    }

    return 0;
}