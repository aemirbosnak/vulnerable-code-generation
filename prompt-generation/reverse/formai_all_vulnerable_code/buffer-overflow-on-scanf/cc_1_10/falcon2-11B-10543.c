//Falcon2-11B DATASET v1.0 Category: System event logger ; Style: Ada Lovelace
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_EVENTS 100
#define MAX_EVENT_SIZE 100

typedef struct event {
    char event_type[MAX_EVENT_SIZE];
    char event_message[MAX_EVENT_SIZE];
    int timestamp;
} event_t;

event_t events[MAX_EVENTS];
int num_events = 0;

void log_event(char *event_type, char *event_message) {
    event_t new_event;
    strcpy(new_event.event_type, event_type);
    strcpy(new_event.event_message, event_message);
    new_event.timestamp = time(NULL);

    if (num_events >= MAX_EVENTS) {
        printf("Event log is full, please delete old events to continue logging.\n");
        return;
    }

    events[num_events++] = new_event;
    printf("Event logged: %s, %s at %s.\n", new_event.event_type, new_event.event_message, ctime(&new_event.timestamp));
}

int main() {
    int choice;

    printf("Welcome to the Ada Lovelace Event Logger!\n");
    printf("1. Log an event\n");
    printf("2. View event log\n");
    printf("3. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the event type: ");
                scanf("%s", events[num_events].event_type);
                printf("Enter the event message: ");
                scanf("%s", events[num_events].event_message);
                log_event(events[num_events].event_type, events[num_events].event_message);
                break;
            case 2:
                printf("Event log:\n");
                for (int i = 0; i < num_events; i++) {
                    printf("Event %d: %s, %s at %s.\n", i+1, events[i].event_type, events[i].event_message, ctime(&events[i].timestamp));
                }
                break;
            case 3:
                printf("Exiting the program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please enter a valid number.\n");
                break;
        }
    }

    return 0;
}