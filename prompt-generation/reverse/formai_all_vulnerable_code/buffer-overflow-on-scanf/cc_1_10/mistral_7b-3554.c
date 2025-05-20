//MISTRAL-7B DATASET v1.0 Category: System event logger ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 50
#define MAX_EVENT_LEN 100

typedef struct {
    char event[MAX_EVENT_LEN];
    time_t timestamp;
} Event;

Event events[MAX_EVENTS];
int event_count = 0;

void log_event(char *event_str) {
    if (event_count >= MAX_EVENTS) {
        printf("Event log is full.\n");
        return;
    }

    strcpy(events[event_count].event, event_str);
    events[event_count].timestamp = time(NULL);
    event_count++;
}

void print_event_log() {
    int i;

    printf("\n--------------------- EVENT LOG ----------------------\n");
    for (i = 0; i < event_count; i++) {
        printf("%s [%s]\n", events[i].event, ctime(&events[i].timestamp));
    }
    printf("------------------------------------------------------\n");
}

int main() {
    char input[MAX_EVENT_LEN];

    while (1) {
        printf("\nRetro Event Logger\n");
        printf("-------------------\n");
        printf("Enter event (or 'quit' to exit): ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        log_event(input);
    }

    print_event_log();

    return 0;
}