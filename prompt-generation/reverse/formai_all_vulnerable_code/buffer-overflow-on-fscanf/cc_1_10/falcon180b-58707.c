//Falcon-180B DATASET v1.0 Category: System event logger ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_EVENTS 100
#define EVENT_FILE "events.log"
#define EVENT_FORMAT "Event %d: %s\n"
#define EVENT_SIZE 1024

typedef struct {
    int id;
    char message[EVENT_SIZE];
} Event;

int main() {
    FILE *event_file;
    Event events[MAX_EVENTS];
    int event_count = 0;
    int event_id = 0;

    // Open or create the event log file
    if ((event_file = fopen(EVENT_FILE, "a")) == NULL) {
        perror("Error opening event log file");
        exit(1);
    }

    // Read existing events from the file
    rewind(event_file);
    while (fscanf(event_file, EVENT_FORMAT, &event_id, events[event_count].message)!= EOF) {
        event_count++;
    }

    // Log new events
    while (1) {
        printf("Enter event message (or type 'quit' to exit): ");
        fgets(events[event_count].message, EVENT_SIZE, stdin);

        if (strcmp(events[event_count].message, "quit") == 0) {
            break;
        }

        event_id++;
        sprintf(events[event_count].message, EVENT_FORMAT, event_id, events[event_count].message);
        event_count++;

        if (event_count >= MAX_EVENTS) {
            printf("Event log is full.\n");
            break;
        }
    }

    // Write events to the file
    fseek(event_file, 0, SEEK_END);
    for (int i = 0; i < event_count; i++) {
        fputs(events[i].message, event_file);
    }

    fclose(event_file);

    return 0;
}