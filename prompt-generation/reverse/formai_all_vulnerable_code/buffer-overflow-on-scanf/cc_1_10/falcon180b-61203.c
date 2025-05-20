//Falcon-180B DATASET v1.0 Category: System event logger ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENT_SIZE 1024
#define EVENT_FILE_NAME "events.log"

typedef struct {
    char event_type[32];
    char message[MAX_EVENT_SIZE];
    time_t timestamp;
} Event;

void log_event(Event *event) {
    FILE *event_file;
    time_t current_time;

    event_file = fopen(EVENT_FILE_NAME, "a");

    if (event_file == NULL) {
        printf("Error opening event file.\n");
        exit(1);
    }

    time(&current_time);
    strftime(event->timestamp, 32, "%Y-%m-%d %H:%M:%S", localtime(&current_time));

    fprintf(event_file, "Event type: %s\nMessage: %s\nTimestamp: %s\n", event->event_type, event->message, event->timestamp);

    fclose(event_file);
}

int main() {
    Event event;

    while (1) {
        printf("Enter event type (up to 32 characters): ");
        scanf("%s", event.event_type);

        printf("Enter event message (up to %d characters): ", MAX_EVENT_SIZE - strlen(event.event_type) - 4);
        scanf("%s", event.message);

        log_event(&event);

        printf("Event logged successfully.\n");
    }

    return 0;
}