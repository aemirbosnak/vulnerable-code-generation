//Falcon-180B DATASET v1.0 Category: System event logger ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENT_SIZE 512

typedef struct {
    char event[MAX_EVENT_SIZE];
    time_t timestamp;
} Event;

typedef struct {
    Event *events;
    int size;
    int capacity;
} EventLog;

void init_event_log(EventLog *log, int capacity) {
    log->events = (Event *)malloc(capacity * sizeof(Event));
    log->size = 0;
    log->capacity = capacity;
}

void add_event(EventLog *log, const char *event) {
    if (log->size >= log->capacity) {
        printf("Event log is full!\n");
        return;
    }

    strncpy(log->events[log->size].event, event, MAX_EVENT_SIZE);
    log->events[log->size].timestamp = time(NULL);
    log->size++;
}

void print_event_log(EventLog *log) {
    for (int i = 0; i < log->size; i++) {
        printf("%s - %s\n", ctime(&log->events[i].timestamp), log->events[i].event);
    }
}

int main() {
    EventLog log;
    init_event_log(&log, 10);

    add_event(&log, "Program started");
    add_event(&log, "Variable initialized");
    add_event(&log, "Function called");

    print_event_log(&log);

    return 0;
}