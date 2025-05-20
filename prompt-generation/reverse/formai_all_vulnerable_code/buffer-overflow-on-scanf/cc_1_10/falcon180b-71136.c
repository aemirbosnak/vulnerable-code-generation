//Falcon-180B DATASET v1.0 Category: System event logger ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100
#define MAX_EVENT_LENGTH 100

typedef struct {
    char event_type[MAX_EVENT_LENGTH];
    char event_data[MAX_EVENT_LENGTH];
    time_t timestamp;
} Event;

void log_event(Event event) {
    FILE *log_file = fopen("event_log.txt", "a");

    if(log_file == NULL) {
        printf("Error: could not open event log file.\n");
        return;
    }

    fprintf(log_file, "Timestamp: %s\nEvent Type: %s\nEvent Data: %s\n\n", ctime(&event.timestamp), event.event_type, event.event_data);

    fclose(log_file);
}

int main() {
    Event events[MAX_EVENTS];
    int num_events = 0;

    while(1) {
        printf("Enter event type (up to %d characters): ", MAX_EVENT_LENGTH - 1);
        scanf("%s", events[num_events].event_type);

        printf("Enter event data (up to %d characters): ", MAX_EVENT_LENGTH - 1);
        scanf("%s", events[num_events].event_data);

        events[num_events].timestamp = time(NULL);
        log_event(events[num_events]);

        num_events++;

        if(num_events == MAX_EVENTS) {
            printf("Event log is full. Please delete some events to log more.\n");
            break;
        }
    }

    return 0;
}