//Falcon-180B DATASET v1.0 Category: System event logger ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100
#define MAX_EVENT_SIZE 256

typedef struct {
    char message[MAX_EVENT_SIZE];
    time_t timestamp;
} Event;

Event events[MAX_EVENTS];
int num_events = 0;

void log_event(const char* message) {
    if (num_events >= MAX_EVENTS) {
        printf("Event buffer is full.\n");
        return;
    }

    time_t now = time(NULL);
    strncpy(events[num_events].message, message, MAX_EVENT_SIZE);
    events[num_events].timestamp = now;
    num_events++;
}

void print_events() {
    printf("=== EVENT LOG ===\n");
    for (int i = 0; i < num_events; i++) {
        printf("%s (%ld)\n", events[i].message, events[i].timestamp);
    }
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("1. Log event\n");
        printf("2. Print event log\n");
        printf("3. Exit\n");
        printf("> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter event message: ");
                char message[MAX_EVENT_SIZE];
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