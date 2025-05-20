//MISTRAL-7B DATASET v1.0 Category: System event logger ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 1000
#define MAX_EVENT_SIZE 256

typedef struct {
    char event[MAX_EVENT_SIZE];
    time_t timestamp;
} Event;

Event events[MAX_EVENTS];
int events_count = 0;

void log_event(const char *event) {
    if (events_count >= MAX_EVENTS) {
        printf("Event logger is full. Dropping event: %s\n", event);
        return;
    }

    strncpy(events[events_count].event, event, MAX_EVENT_SIZE - 1);
    events[events_count].timestamp = time(NULL);
    events_count++;
}

void print_events() {
    int i;
    time_t current_time;

    if (events_count == 0) {
        printf("No events logged.\n");
        return;
    }

    printf("\nEvents:\n");
    current_time = time(NULL);

    for (i = 0; i < events_count; i++) {
        printf("%s", ctime(&events[i].timestamp));
        printf("%s - %s\n", events[i].event, ctime(&current_time));
    }
}

int main() {
    char input[100];

    while (1) {
        printf("Enter an event to log (or type 'quit' to exit): ");
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0'; // Remove newline character

        if (strcmp(input, "quit") == 0) {
            break;
        }

        log_event(input);
    }

    print_events();

    return 0;
}