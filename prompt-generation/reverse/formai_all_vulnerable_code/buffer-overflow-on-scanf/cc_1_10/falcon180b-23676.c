//Falcon-180B DATASET v1.0 Category: System event logger ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100

typedef struct {
    char type[20];
    char description[80];
    time_t timestamp;
} Event;

void log_event(Event *event) {
    FILE *log_file = fopen("event_log.txt", "a");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    fprintf(log_file, "Timestamp: %s\n", ctime(&event->timestamp));
    fprintf(log_file, "Event Type: %s\n", event->type);
    fprintf(log_file, "Description: %s\n\n", event->description);

    fclose(log_file);
}

int main() {
    Event events[MAX_EVENTS];
    int event_count = 0;

    while (1) {
        printf("Enter event type (up to 20 characters): ");
        scanf("%s", events[event_count].type);

        printf("Enter event description (up to 80 characters): ");
        scanf("%[^\n]", events[event_count].description);

        events[event_count].timestamp = time(NULL);
        log_event(&events[event_count]);
        event_count++;

        if (event_count == MAX_EVENTS) {
            printf("Event log is full. Exiting...\n");
            break;
        }
    }

    return 0;
}