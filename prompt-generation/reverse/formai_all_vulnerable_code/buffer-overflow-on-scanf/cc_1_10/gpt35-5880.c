//FormAI DATASET v1.0 Category: System event logger ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 1000
#define MAX_DESC_LENGTH 100
#define MAX_LOG_LENGTH 100

typedef struct event {
    char* name;
    char* desc;
} Event;

Event events[MAX_EVENTS];
int num_events = 0;

void log_event(Event event) {
    FILE* fptr;
    char log[MAX_LOG_LENGTH];

    sprintf(log, "%s: %s\n", event.name, event.desc);
    fptr = fopen("eventlog.txt", "a");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fputs(log, fptr);
    fclose(fptr);
}

void new_event(char* name, char* desc) {
    Event event;

    event.name = name;
    event.desc = desc;

    events[num_events++] = event;
}

int main() {
    char option;
    char name[MAX_DESC_LENGTH];
    char desc[MAX_DESC_LENGTH];

    printf("Welcome to the Event Logger.\n");

    while (1) {
        printf("\nEnter option:\n");
        printf("n - new event\nq - quit\n");

        scanf(" %c", &option);

        switch (option) {
            case 'n':
                printf("Enter event name:\n");
                scanf("%s", name);
                printf("Enter event description:\n");
                scanf("%s", desc);

                new_event(name, desc);
                log_event(events[num_events - 1]);

                printf("Event recorded.\n");
                break;
            case 'q':
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
    }

    return 0;
}