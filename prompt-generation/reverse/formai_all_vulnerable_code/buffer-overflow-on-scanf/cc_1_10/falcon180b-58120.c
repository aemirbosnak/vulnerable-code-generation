//Falcon-180B DATASET v1.0 Category: System event logger ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_EVENT_SIZE 1024
#define MAX_EVENTS 100

typedef struct {
    char event[MAX_EVENT_SIZE];
    int event_id;
} event_t;

event_t events[MAX_EVENTS];
int num_events = 0;

void log_event(char* event, int event_id) {
    if (num_events >= MAX_EVENTS) {
        printf("Event log is full! Can't log event.\n");
        return;
    }

    strncpy(events[num_events].event, event, MAX_EVENT_SIZE);
    events[num_events].event_id = event_id;
    num_events++;

    printf("Event logged: %s (ID %d)\n", event, event_id);
}

void display_events() {
    printf("\nEvent log:\n");
    for (int i = 0; i < num_events; i++) {
        printf("ID %d: %s\n", events[i].event_id, events[i].event);
    }
}

int main() {
    int choice;

    do {
        printf("\nEvent Logger\n");
        printf("1. Log an event\n");
        printf("2. Display event log\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the event: ");
            char event[MAX_EVENT_SIZE];
            scanf("%s", event);

            printf("Enter the event ID: ");
            int event_id;
            scanf("%d", &event_id);

            log_event(event, event_id);
            break;

        case 2:
            display_events();
            break;

        case 3:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
            break;
        }
    } while (choice!= 3);

    return 0;
}