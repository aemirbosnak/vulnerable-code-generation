//Falcon-180B DATASET v1.0 Category: System event logger ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>

#define MAX_EVENTS 100
#define EVENT_LOG_FILE "event.log"

#define EVENT_TYPE_INFO 0
#define EVENT_TYPE_WARNING 1
#define EVENT_TYPE_ERROR 2

typedef struct {
    int type;
    char message[1024];
    time_t timestamp;
} Event;

FILE *event_log_file;

void init_event_logging() {
    event_log_file = fopen(EVENT_LOG_FILE, "a");
    if (event_log_file == NULL) {
        fprintf(stderr, "Error opening event log file: %s\n", strerror(errno));
        exit(1);
    }
}

void log_event(int type, const char *message) {
    Event event;
    event.type = type;
    strncpy(event.message, message, sizeof(event.message));
    event.timestamp = time(NULL);

    if (fwrite(&event, sizeof(event), 1, event_log_file)!= 1) {
        fprintf(stderr, "Error writing to event log file: %s\n", strerror(errno));
        exit(1);
    }
}

void close_event_logging() {
    if (fclose(event_log_file)!= 0) {
        fprintf(stderr, "Error closing event log file: %s\n", strerror(errno));
        exit(1);
    }
}

int main() {
    init_event_logging();

    int count = 0;
    while (count < MAX_EVENTS) {
        log_event(EVENT_TYPE_INFO, "This is an info message.");
        log_event(EVENT_TYPE_WARNING, "This is a warning message.");
        log_event(EVENT_TYPE_ERROR, "This is an error message.");
        count++;
    }

    close_event_logging();

    return 0;
}