//Falcon-180B DATASET v1.0 Category: System event logger ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENT_LENGTH 100

typedef struct {
    char event[MAX_EVENT_LENGTH];
    time_t timestamp;
} Event;

void log_event(char* event) {
    time_t now = time(NULL);
    Event e = {.event = event,.timestamp = now};
    FILE* log_file = fopen("event_log.txt", "a");
    if (log_file) {
        fprintf(log_file, "%s - %ld\n", e.event, e.timestamp);
        fclose(log_file);
    } else {
        printf("Failed to log event.\n");
    }
}

int main() {
    log_event("Program started.");

    int choice;
    do {
        printf("\nChoose an option:\n");
        printf("1. Log an event\n");
        printf("2. View event log\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char event[MAX_EVENT_LENGTH];
                printf("Enter event to log:\n");
                scanf("%s", event);
                log_event(event);
                break;
            }
            case 2: {
                FILE* log_file = fopen("event_log.txt", "r");
                if (log_file) {
                    char line[MAX_EVENT_LENGTH];
                    while (fgets(line, MAX_EVENT_LENGTH, log_file)) {
                        printf("%s", line);
                    }
                    fclose(log_file);
                } else {
                    printf("Event log is empty.\n");
                }
                break;
            }
            case 3: {
                printf("Exiting program.\n");
                break;
            }
            default: {
                printf("Invalid option.\n");
            }
        }
    } while (choice!= 3);

    return 0;
}