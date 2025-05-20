//Falcon-180B DATASET v1.0 Category: System event logger ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENT_LENGTH 256
#define MAX_EVENTS 1000
#define EVENT_FILE "events.log"

typedef struct {
    char event[MAX_EVENT_LENGTH];
    time_t timestamp;
} Event;

int main() {
    FILE *event_file;
    char buffer[MAX_EVENT_LENGTH];
    Event events[MAX_EVENTS];
    int num_events = 0;

    // Open the event file for appending
    event_file = fopen(EVENT_FILE, "a");
    if (event_file == NULL) {
        fprintf(stderr, "Could not open event file for writing.\n");
        return 1;
    }

    // Read the existing events from the file
    while (fgets(buffer, MAX_EVENT_LENGTH, event_file)!= NULL) {
        Event event;
        sscanf(buffer, "%s %ld", event.event, &event.timestamp);
        events[num_events++] = event;
    }

    // Log the new events
    while (1) {
        printf("Enter an event (or type 'exit' to quit):\n");
        fgets(buffer, MAX_EVENT_LENGTH, stdin);
        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        Event event;
        strcpy(event.event, buffer);
        time(&event.timestamp);

        // Check if the event is a duplicate
        for (int i = 0; i < num_events; i++) {
            if (strcmp(events[i].event, event.event) == 0) {
                printf("Duplicate event: %s\n", event.event);
                continue;
            }
        }

        // Add the event to the array
        events[num_events++] = event;

        // Write the event to the file
        fprintf(event_file, "%s %ld\n", event.event, event.timestamp);
    }

    // Close the event file
    fclose(event_file);

    return 0;
}