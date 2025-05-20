//Falcon-180B DATASET v1.0 Category: System event logger ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LOG_EVENTS 1000 // Maximum number of events to log
#define EVENT_LOG_FILE "event_log.txt" // File to store event log

// Struct to hold event information
typedef struct {
    time_t timestamp; // Timestamp of event
    char* message; // Message associated with event
} Event;

// Function to compare two events based on their timestamps
int compare_events(const void* a, const void* b) {
    const Event* event_a = (const Event*)a;
    const Event* event_b = (const Event*)b;

    if (event_a->timestamp < event_b->timestamp) {
        return -1;
    } else if (event_a->timestamp > event_b->timestamp) {
        return 1;
    } else {
        return 0;
    }
}

// Function to log an event
void log_event(const char* message) {
    time_t now = time(NULL);
    Event event = {now, strdup(message)};

    // Open event log file in append mode
    FILE* log_file = fopen(EVENT_LOG_FILE, "a");
    if (log_file == NULL) {
        printf("Error: Could not open event log file.\n");
        exit(EXIT_FAILURE);
    }

    // Write event to log file
    fprintf(log_file, "%s\n", ctime(&now));
    fprintf(log_file, "%s\n", event.message);
    fclose(log_file);

    // Add event to event array
    static Event events[MAX_LOG_EVENTS];
    static int num_events = 0;

    if (num_events >= MAX_LOG_EVENTS) {
        printf("Warning: Event log is full. Oldest event will be overwritten.\n");
        free(events[0].message);
        num_events--;
    }

    events[num_events++] = event;

    // Sort event array by timestamp
    qsort(events, num_events, sizeof(Event), compare_events);
}

int main() {
    log_event("Program started.");

    sleep(1);

    log_event("Something happened.");

    sleep(2);

    log_event("Program ended.");

    return 0;
}