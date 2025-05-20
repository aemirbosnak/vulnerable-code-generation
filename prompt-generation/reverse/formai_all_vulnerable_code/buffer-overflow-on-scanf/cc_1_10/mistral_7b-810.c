//MISTRAL-7B DATASET v1.0 Category: System event logger ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 100
#define EVENT_SIZE 256

typedef struct {
    char time[20];
    char event[EVENT_SIZE];
} EventLog;

EventLog events[MAX_EVENTS];
int log_index = 0;

void log_event(char *event_str) {
    if (log_index >= MAX_EVENTS) {
        printf("Event log is full!\n");
        return;
    }

    struct tm *current_time;
    time_t current_time_t;

    time(&current_time_t);
    current_time = localtime(&current_time_t);

    strftime(events[log_index].time, sizeof(events[log_index].time), "%Y-%m-%d %H:%M:%S", current_time);

    strcpy(events[log_index].event, event_str);

    log_index++;
}

int main() {
    int choice;

    while (1) {
        printf("\nEvent Logger Menu:\n");
        printf("1. Log an event\n");
        printf("2. Display event log\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char event[EVENT_SIZE];
                printf("Enter event: ");
                scanf("%s", event);
                log_event(event);
                printf("Event logged successfully!\n");
                break;
            }
            case 2: {
                if (log_index == 0) {
                    printf("Event log is empty!\n");
                    break;
                }

                printf("\nEvent Log:\n");
                for (int i = 0; i < log_index; i++) {
                    printf("%s - %s\n", events[i].time, events[i].event);
                }
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid choice! Please try again.\n");
                break;
            }
        }
    }

    return 0;
}