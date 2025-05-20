//Falcon-180B DATASET v1.0 Category: System event logger ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENT_COUNT 100
#define EVENT_LOG_FILE "event_log.txt"

typedef struct {
    char event_type[50];
    char event_message[200];
    time_t event_time;
} Event;

void log_event(Event* event) {
    FILE* log_file = fopen(EVENT_LOG_FILE, "a");

    if (log_file == NULL) {
        printf("Error: Could not open event log file.\n");
        return;
    }

    fprintf(log_file, "Event Type: %s\nEvent Message: %s\nEvent Time: %s\n",
            event->event_type, event->event_message, ctime(&event->event_time));

    fclose(log_file);
}

int main() {
    Event event_log[MAX_EVENT_COUNT];
    int event_count = 0;

    while (1) {
        char input[200];
        printf("Enter event type (max 50 characters): ");
        scanf("%s", input);

        strncpy(event_log[event_count].event_type, input, 50);
        event_log[event_count].event_type[50] = '\0';

        printf("Enter event message (max 200 characters): ");
        scanf("%[^\n]", event_log[event_count].event_message);

        event_log[event_count].event_time = time(NULL);
        log_event(&event_log[event_count]);

        event_count++;

        if (event_count == MAX_EVENT_COUNT) {
            printf("Event log is full. Exiting program.\n");
            break;
        }
    }

    return 0;
}