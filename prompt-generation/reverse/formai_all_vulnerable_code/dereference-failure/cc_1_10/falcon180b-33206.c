//Falcon-180B DATASET v1.0 Category: System event logger ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENT_SIZE 1024
#define MAX_EVENTS 100

typedef struct {
    char event[MAX_EVENT_SIZE];
    time_t timestamp;
} Event;

typedef struct {
    Event events[MAX_EVENTS];
    int num_events;
} EventLogger;

EventLogger* create_event_logger() {
    EventLogger* logger = (EventLogger*)malloc(sizeof(EventLogger));
    logger->num_events = 0;
    return logger;
}

void destroy_event_logger(EventLogger* logger) {
    free(logger);
}

void log_event(EventLogger* logger, char* event) {
    if (logger->num_events >= MAX_EVENTS) {
        printf("Event logger is full\n");
        return;
    }

    strncpy(logger->events[logger->num_events].event, event, MAX_EVENT_SIZE);
    logger->events[logger->num_events].timestamp = time(NULL);
    logger->num_events++;
}

void print_event_log(EventLogger* logger) {
    for (int i = 0; i < logger->num_events; i++) {
        printf("Event %d: %s (%ld)\n", i+1, logger->events[i].event, logger->events[i].timestamp);
    }
}

int main() {
    EventLogger* logger = create_event_logger();

    log_event(logger, "Program started");
    log_event(logger, "Some event happened");
    log_event(logger, "Another event occurred");

    print_event_log(logger);

    destroy_event_logger(logger);

    return 0;
}