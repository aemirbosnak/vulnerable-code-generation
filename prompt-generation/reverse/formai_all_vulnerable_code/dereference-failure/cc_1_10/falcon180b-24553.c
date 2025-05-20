//Falcon-180B DATASET v1.0 Category: System event logger ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 1000
#define EVENT_LOG_FILE "event_log.txt"

typedef struct {
    char *description;
    time_t timestamp;
} Event;

Event events[MAX_EVENTS];
int event_count = 0;

void log_event(const char *description) {
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);

    if (event_count >= MAX_EVENTS) {
        fprintf(stderr, "Event log is full. Cannot log more events.\n");
        return;
    }

    Event event = {
       .description = strdup(description),
       .timestamp = now
    };

    events[event_count++] = event;

    fprintf(stdout, "Logged event: %s at %s\n", description, asctime(tm_now));
}

void write_event_log_to_file() {
    FILE *event_log_file = fopen(EVENT_LOG_FILE, "w");

    if (event_log_file == NULL) {
        fprintf(stderr, "Cannot open event log file for writing: %s\n", EVENT_LOG_FILE);
        return;
    }

    for (int i = 0; i < event_count; i++) {
        fprintf(event_log_file, "%s - %s\n", events[i].description, ctime(&events[i].timestamp));
    }

    fclose(event_log_file);
}

int main() {
    log_event("Program started");

    sleep(1);

    log_event("First event");

    sleep(2);

    log_event("Second event");

    write_event_log_to_file();

    return 0;
}