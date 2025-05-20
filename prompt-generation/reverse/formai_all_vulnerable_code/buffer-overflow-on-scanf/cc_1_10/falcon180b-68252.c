//Falcon-180B DATASET v1.0 Category: System event logger ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENT_LENGTH 100
#define MAX_LOG_FILE_SIZE 1024*1024*10 // 10 MB

typedef struct {
    char event[MAX_EVENT_LENGTH];
    time_t timestamp;
} Event;

typedef struct {
    FILE *file;
    int num_events;
    Event *events;
} Log;

void log_event(Log *log, const char *event) {
    if (log->num_events >= MAX_LOG_FILE_SIZE) {
        fprintf(stderr, "Log file is full. Discarding event: %s\n", event);
        return;
    }

    strncpy(log->events[log->num_events].event, event, MAX_EVENT_LENGTH);
    log->events[log->num_events].timestamp = time(NULL);
    log->num_events++;
}

void print_log(Log *log) {
    for (int i = 0; i < log->num_events; i++) {
        printf("%s - %s\n", log->events[i].event, ctime(&log->events[i].timestamp));
    }
}

int main() {
    Log log;
    log.file = fopen("event_log.txt", "w");
    if (log.file == NULL) {
        fprintf(stderr, "Failed to open log file.\n");
        exit(1);
    }

    log.num_events = 0;
    log.events = (Event *) malloc(MAX_LOG_FILE_SIZE * sizeof(Event));

    while (1) {
        char event[MAX_EVENT_LENGTH];
        printf("Enter an event (or type 'exit' to quit): ");
        scanf("%s", event);

        if (strcmp(event, "exit") == 0) {
            break;
        }

        log_event(&log, event);
    }

    fclose(log.file);
    print_log(&log);

    return 0;
}