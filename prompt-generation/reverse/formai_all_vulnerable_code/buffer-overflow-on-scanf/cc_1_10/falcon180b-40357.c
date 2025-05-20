//Falcon-180B DATASET v1.0 Category: System event logger ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 100
#define MAX_EVENT_LENGTH 50
#define MAX_LOG_LENGTH 10000

typedef struct {
    char event[MAX_EVENT_LENGTH];
    int event_id;
    int event_type;
    char log[MAX_LOG_LENGTH];
} Event;

void init_event_logger() {
    FILE *log_file = fopen("event_log.txt", "w");
    if (log_file == NULL) {
        printf("Error: could not open event log file!\n");
        exit(1);
    }
    fprintf(log_file, "Event Type\tEvent ID\tEvent\n");
    fclose(log_file);
}

int get_next_event_id() {
    static int event_id = 1;
    return event_id++;
}

void log_event(Event *event) {
    FILE *log_file = fopen("event_log.txt", "a");
    if (log_file == NULL) {
        printf("Error: could not open event log file!\n");
        exit(1);
    }
    fprintf(log_file, "%d\t%d\t%s\n", event->event_type, event->event_id, event->log);
    fclose(log_file);
}

int main() {
    init_event_logger();

    Event events[MAX_EVENTS];
    int num_events = 0;

    while (1) {
        Event new_event;
        strcpy(new_event.event, "");
        new_event.event_id = get_next_event_id();
        new_event.event_type = 1; // default event type is 1

        printf("Enter event type (1-10): ");
        scanf("%d", &new_event.event_type);

        printf("Enter event ID: ");
        scanf("%d", &new_event.event_id);

        printf("Enter event description: ");
        scanf("%s", new_event.event);

        if (num_events >= MAX_EVENTS) {
            printf("Event log is full! Cannot log more events.\n");
            continue;
        }

        events[num_events] = new_event;
        num_events++;
        log_event(&new_event);
    }

    return 0;
}