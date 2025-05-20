//Falcon-180B DATASET v1.0 Category: System event logger ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 1000
#define EVENT_SIZE 64

typedef struct {
    char event[EVENT_SIZE];
    time_t timestamp;
} Event;

Event events[MAX_EVENTS];
int event_count = 0;

void log_event(char* event) {
    strncpy(events[event_count].event, event, EVENT_SIZE);
    events[event_count].timestamp = time(NULL);
    event_count++;
}

void print_events() {
    for (int i = 0; i < event_count; i++) {
        printf("%s %ld\n", events[i].event, events[i].timestamp);
    }
}

int main() {
    srand(time(NULL));

    int choice;
    char event[EVENT_SIZE];

    do {
        printf("Enter an event (up to %d characters): ", EVENT_SIZE - 1);
        scanf("%s", event);

        log_event(event);

        printf("Event logged.\n");

        printf("1. Print events\n2. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_events();
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

    } while (1);

    return 0;
}