//Falcon-180B DATASET v1.0 Category: System event logger ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 1000
#define MAX_EVENT_LENGTH 512

typedef struct {
    char message[MAX_EVENT_LENGTH];
    time_t timestamp;
} Event;

Event events[MAX_EVENTS];
int event_count = 0;

void log_event(char* message) {
    strncpy(events[event_count].message, message, MAX_EVENT_LENGTH);
    events[event_count].timestamp = time(NULL);
    event_count++;
    if (event_count == MAX_EVENTS) {
        event_count = 0;
    }
}

void print_events() {
    int i;
    for (i = 0; i < event_count; i++) {
        printf("%s - %s\n", ctime(&events[i].timestamp), events[i].message);
    }
}

int main() {
    int choice;
    char message[MAX_EVENT_LENGTH];

    do {
        printf("1. Log event\n");
        printf("2. Print events\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter event message: ");
                scanf("%s", message);
                log_event(message);
                break;
            case 2:
                print_events();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}