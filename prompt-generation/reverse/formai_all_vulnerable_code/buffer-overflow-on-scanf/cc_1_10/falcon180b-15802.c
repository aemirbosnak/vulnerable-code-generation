//Falcon-180B DATASET v1.0 Category: System event logger ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_EVENT_LENGTH 256

typedef struct {
    char event[MAX_EVENT_LENGTH];
    time_t timestamp;
} event_t;

event_t events[MAX_EVENTS];
int event_count = 0;

void log_event(char *event) {
    struct tm *tm;
    time_t now;

    now = time(NULL);
    tm = localtime(&now);

    strftime(event, MAX_EVENT_LENGTH, "%Y-%m-%d %H:%M:%S", tm);
    strcat(event, " - ");
    strcat(event, event);

    events[event_count] = (event_t) {
       .event = event,
       .timestamp = now,
    };

    event_count += 1;

    if (event_count >= MAX_EVENTS) {
        event_count = 0;
    }
}

void print_events() {
    int i;

    for (i = 0; i < event_count; i++) {
        printf("%s\n", events[i].event);
    }
}

int main() {
    int choice;

    do {
        printf("1. Log an event\n");
        printf("2. Print events\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the event: ");
                log_event(stdin);
                break;
            case 2:
                print_events();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}