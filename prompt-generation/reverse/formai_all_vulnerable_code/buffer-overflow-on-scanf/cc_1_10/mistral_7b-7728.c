//MISTRAL-7B DATASET v1.0 Category: System event logger ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 1000
#define MAX_EVENT_LEN 256

typedef struct {
    char timestamp[20];
    char event[MAX_EVENT_LEN];
} EventLogEntry;

EventLogEntry event_log[MAX_EVENTS];
int log_index = 0;

void create_timestamp(char timestamp[]) {
    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);
}

void log_event(char * event) {
    if (log_index >= MAX_EVENTS) {
        printf("Event logger is full.\n");
        return;
    }

    create_timestamp(event_log[log_index].timestamp);
    strncpy(event_log[log_index].event, event, MAX_EVENT_LEN);

    printf("Logged event: %s, %s\n", event, event_log[log_index].timestamp);
    log_index++;
}

int main() {
    int i;

    for (i = 0; i < 10; i++) {
        char event[MAX_EVENT_LEN];

        printf("Enter event number %d: ", i+1);
        scanf("%s", event);

        log_event(event);
    }

    return 0;
}