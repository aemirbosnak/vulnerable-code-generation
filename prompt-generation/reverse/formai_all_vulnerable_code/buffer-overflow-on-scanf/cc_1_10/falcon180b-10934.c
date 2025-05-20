//Falcon-180B DATASET v1.0 Category: System event logger ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_EVENT_SIZE 100
#define MAX_EVENTS 10000

typedef struct {
    int event_id;
    char event_message[MAX_EVENT_SIZE];
    time_t event_timestamp;
} event_t;

event_t events[MAX_EVENTS];
int num_events = 0;

void log_event(int event_id, char* message) {
    if (num_events >= MAX_EVENTS) {
        printf("Event buffer full, cannot log event.\n");
        return;
    }

    event_t* new_event = &events[num_events];
    new_event->event_id = event_id;
    strncpy(new_event->event_message, message, MAX_EVENT_SIZE);
    new_event->event_timestamp = time(NULL);
    num_events++;
}

void print_event(event_t* event) {
    printf("Event ID: %d\n", event->event_id);
    printf("Event Message: %s\n", event->event_message);
    printf("Event Timestamp: %s\n", ctime(&event->event_timestamp));
}

void print_events() {
    if (num_events == 0) {
        printf("No events to display.\n");
        return;
    }

    for (int i = 0; i < num_events; i++) {
        print_event(&events[i]);
    }
}

int main() {
    int choice;
    do {
        printf("1. Log event\n");
        printf("2. Print events\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter event ID: ");
                int event_id;
                scanf("%d", &event_id);
                printf("Enter event message: ");
                char event_message[MAX_EVENT_SIZE];
                scanf("%s", event_message);
                log_event(event_id, event_message);
                break;
            case 2:
                print_events();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}