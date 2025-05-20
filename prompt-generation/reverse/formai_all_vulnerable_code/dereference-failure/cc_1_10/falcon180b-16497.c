//Falcon-180B DATASET v1.0 Category: System event logger ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENT_LENGTH 1024
#define MAX_EVENT_NUMBER 1000

typedef struct {
    char event[MAX_EVENT_LENGTH];
    time_t timestamp;
} Event;

static Event events[MAX_EVENT_NUMBER];
static int event_count = 0;

void log_event(const char *event) {
    time_t now = time(NULL);

    if (event_count >= MAX_EVENT_NUMBER) {
        printf("Event buffer full, dropping event\n");
        return;
    }

    strncpy(events[event_count].event, event, MAX_EVENT_LENGTH);
    events[event_count].timestamp = now;

    event_count++;
}

void print_events() {
    printf("=================== Event Log ===================\n");
    printf("Timestamp\tEvent\n");

    for (int i = 0; i < event_count; i++) {
        printf("%ld\t%s\n", events[i].timestamp, events[i].event);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <event>\n", argv[0]);
        return 1;
    }

    log_event(argv[1]);
    print_events();

    return 0;
}