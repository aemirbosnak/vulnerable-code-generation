//MISTRAL-7B DATASET v1.0 Category: System event logger ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 100

typedef struct {
    char event[100];
    time_t timestamp;
} Event;

Event events[MAX_EVENTS];
int current_event = 0;

void log_event(char* event_name) {
    if (current_event >= MAX_EVENTS) {
        printf("Event log is full!\n");
        return;
    }

    strcpy(events[current_event].event, event_name);
    events[current_event].timestamp = time(NULL);
    current_event++;
}

void print_stats() {
    int total_events = current_event;
    double avg_event_interval = 0.0;
    double sum_event_intervals = 0.0;

    for (int i = 0; i < total_events; i++) {
        time_t current_timestamp = events[i].timestamp;
        double event_interval = difftime(current_timestamp, events[i+1].timestamp);
        sum_event_intervals += event_interval;
    }

    avg_event_interval = sum_event_intervals / total_events;

    printf("\nEvent log statistics:\n");
    printf("Total events: %d\n", total_events);
    printf("Average event interval: %.2f seconds\n", avg_event_interval);
}

int main() {
    log_event("Program started");
    log_event("User logged in");
    log_event("File opened");
    log_event("User clicked a button");
    log_event("File saved");
    log_event("Program ended");

    print_stats();

    return 0;
}