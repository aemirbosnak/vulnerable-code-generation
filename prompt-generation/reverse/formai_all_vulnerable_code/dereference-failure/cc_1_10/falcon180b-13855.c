//Falcon-180B DATASET v1.0 Category: System event logger ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_EVENT_LENGTH 50

typedef struct {
    char* event;
    time_t timestamp;
} Event;

Event events[MAX_EVENTS];
int num_events = 0;

void log_event(char* event) {
    if (num_events >= MAX_EVENTS) {
        printf("Error: event log is full\n");
        return;
    }

    strncpy(events[num_events].event, event, MAX_EVENT_LENGTH);
    events[num_events].timestamp = time(NULL);
    num_events++;
}

void print_events() {
    printf("Event log:\n");
    for (int i = 0; i < num_events; i++) {
        printf("%s - %s\n", events[i].event, ctime(&events[i].timestamp));
    }
}

int main() {
    log_event("Program started");

    int choice;
    while (1) {
        printf("Enter choice:\n");
        printf("1. Log event\n");
        printf("2. Print event log\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char event[MAX_EVENT_LENGTH];
                printf("Enter event: ");
                scanf("%s", event);
                log_event(event);
                break;
            }
            case 2: {
                print_events();
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    }

    return 0;
}