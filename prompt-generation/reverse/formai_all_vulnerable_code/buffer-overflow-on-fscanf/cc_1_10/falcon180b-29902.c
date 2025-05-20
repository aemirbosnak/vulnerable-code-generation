//Falcon-180B DATASET v1.0 Category: System event logger ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define EVENT_SIZE 64

typedef struct {
    char event[EVENT_SIZE];
    time_t timestamp;
} Event;

int main() {
    FILE *log_file;
    Event events[MAX_EVENTS];
    int num_events = 0;
    int i;

    // Open or create the log file
    log_file = fopen("event_log.txt", "a+");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    // Read existing events from the log file
    rewind(log_file);
    while (fscanf(log_file, "%s %ld\n", events[num_events].event, &events[num_events].timestamp) == 2) {
        num_events++;
        if (num_events >= MAX_EVENTS) {
            printf("Warning: Log file contains more than %d events.\n", MAX_EVENTS);
            break;
        }
    }

    // Log user input
    while (1) {
        printf("Enter an event (or type 'quit' to exit): ");
        fgets(events[num_events].event, EVENT_SIZE, stdin);
        events[num_events].timestamp = time(NULL);
        fprintf(log_file, "%s %ld\n", events[num_events].event, events[num_events].timestamp);
        fflush(log_file);

        if (strcmp(events[num_events].event, "quit") == 0) {
            break;
        }

        num_events++;
        if (num_events >= MAX_EVENTS) {
            printf("Warning: Log file contains more than %d events.\n", MAX_EVENTS);
            break;
        }
    }

    // Close the log file
    fclose(log_file);

    return 0;
}