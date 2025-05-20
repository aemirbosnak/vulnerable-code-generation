//FormAI DATASET v1.0 Category: System event logger ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EVENT_TYPES_COUNT 5

typedef enum {
    EVENT_INFO,
    EVENT_WARNING,
    EVENT_ERROR,
    EVENT_SUCCESS,
    EVENT_UNKNOWN
} EventType;

const char* EVENT_TYPE_NAMES[EVENT_TYPES_COUNT] = {
    "INFO",
    "WARNING",
    "ERROR",
    "SUCCESS",
    "UNKNOWN"
};

typedef struct {
    EventType type;
    char* message;
    struct tm* time;
} Event;

Event create_event(EventType type, const char* message) {
    time_t raw_time;
    time(&raw_time);
    struct tm* time_info = localtime(&raw_time);

    Event event = { type, (char*)message, time_info };
    return event;
}

void log_event(Event event) {
    printf("[%04d-%02d-%02d %02d:%02d:%02d] [%s]: %s\n",
        event.time->tm_year + 1900,
        event.time->tm_mon + 1,
        event.time->tm_mday,
        event.time->tm_hour,
        event.time->tm_min,
        event.time->tm_sec,
        EVENT_TYPE_NAMES[event.type],
        event.message
    );
}

void test_event_logging() {
    log_event(create_event(EVENT_INFO, "Test INFO message"));
    log_event(create_event(EVENT_WARNING, "Test WARNING message"));
    log_event(create_event(EVENT_ERROR, "Test ERROR message"));
    log_event(create_event(EVENT_SUCCESS, "Test SUCCESS message"));
    log_event(create_event(EVENT_UNKNOWN, "Test UNKNOWN message"));
}

int main() {
    test_event_logging();

    return 0;
}