//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_EVENT_LENGTH 100

typedef struct {
    time_t time;
    char message[MAX_EVENT_LENGTH];
} Event;

int main() {
    int num_events = 0;
    Event events[MAX_EVENTS];

    time_t current_time = time(NULL);
    printf("Current time: %s\n", ctime(&current_time));

    while (1) {
        printf("Enter event (or 'q' to quit): ");
        char input[MAX_EVENT_LENGTH];
        fgets(input, MAX_EVENT_LENGTH, stdin);

        if (strcmp(input, "q") == 0) {
            break;
        }

        Event new_event;
        sscanf(input, "%s %ld", new_event.message, &new_event.time);
        events[num_events] = new_event;
        num_events++;

        if (num_events >= MAX_EVENTS) {
            printf("Maximum number of events reached.\n");
            break;
        }
    }

    printf("Traveling through time...\n");
    for (int i = 0; i < num_events; i++) {
        time_t target_time = events[i].time;
        while (difftime(current_time, target_time) > 0) {
            current_time += 60; // Travel one minute at a time
            printf("Traveling to %s...\n", ctime(&target_time));
        }
        printf("%s\n", events[i].message);
    }

    return 0;
}