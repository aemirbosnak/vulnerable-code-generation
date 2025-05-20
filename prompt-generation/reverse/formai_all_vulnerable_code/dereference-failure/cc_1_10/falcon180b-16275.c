//Falcon-180B DATASET v1.0 Category: System event logger ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100
#define EVENT_LOG_FILE "event_log.txt"

typedef struct {
    char event_type[50];
    char event_description[200];
    time_t event_time;
} Event;

FILE *event_log_file;
Event events[MAX_EVENTS];
int num_events = 0;

void log_event(char *event_type, char *event_description) {
    strcpy(events[num_events].event_type, event_type);
    strcpy(events[num_events].event_description, event_description);
    time(&events[num_events].event_time);
    num_events++;

    if (num_events >= MAX_EVENTS) {
        fprintf(stderr, "Event log is full. Discarding new event.\n");
        return;
    }

    event_log_file = fopen(EVENT_LOG_FILE, "a");
    if (event_log_file == NULL) {
        fprintf(stderr, "Could not open event log file for writing.\n");
        return;
    }

    fprintf(event_log_file, "Event Type: %s\n", events[num_events - 1].event_type);
    fprintf(event_log_file, "Event Description: %s\n", events[num_events - 1].event_description);
    fprintf(event_log_file, "Event Time: %s", ctime(&events[num_events - 1].event_time));

    fclose(event_log_file);
}

void display_event_log() {
    event_log_file = fopen(EVENT_LOG_FILE, "r");
    if (event_log_file == NULL) {
        fprintf(stderr, "Could not open event log file for reading.\n");
        return;
    }

    printf("Event Log:\n");
    while (fgets(events[num_events].event_description, sizeof(events[num_events].event_description), event_log_file)!= NULL) {
        printf("%s", events[num_events].event_description);
    }

    fclose(event_log_file);
}

int main() {
    event_log_file = fopen(EVENT_LOG_FILE, "w");
    if (event_log_file == NULL) {
        fprintf(stderr, "Could not open event log file for writing.\n");
        return 1;
    }

    log_event("Program Started", "The program has started.");

    // Your program code goes here

    log_event("Program Ended", "The program has ended.");

    fclose(event_log_file);
    return 0;
}