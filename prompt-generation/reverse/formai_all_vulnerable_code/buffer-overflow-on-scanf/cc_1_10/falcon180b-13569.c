//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 1000

struct event {
    time_t timestamp;
    char *description;
};

void add_event(struct event *events, int *event_count, time_t timestamp, char *description) {
    if (*event_count >= MAX_EVENTS) {
        printf("Error: Maximum number of events reached.\n");
        exit(1);
    }

    events[*event_count].timestamp = timestamp;
    events[*event_count].description = description;
    (*event_count)++;
}

void print_events(struct event *events, int event_count) {
    printf("Events:\n");
    for (int i = 0; i < event_count; i++) {
        printf("%s - %s\n", ctime(&events[i].timestamp), events[i].description);
    }
}

int main() {
    struct event events[MAX_EVENTS];
    int event_count = 0;

    add_event(events, &event_count, time(NULL), "Program started");

    while (1) {
        char input[100];
        printf("Enter an event (or type 'exit' to quit): ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        add_event(events, &event_count, time(NULL), input);
    }

    print_events(events, event_count);

    return 0;
}