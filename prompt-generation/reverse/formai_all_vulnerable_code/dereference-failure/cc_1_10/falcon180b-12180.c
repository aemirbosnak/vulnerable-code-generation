//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TIME_MAX 10000
#define EVENT_MAX 1000

typedef struct event {
    int time;
    char *description;
} Event;

void add_event(Event *events, int num_events, int time, char *description) {
    if (num_events >= EVENT_MAX) {
        printf("Error: Too many events.\n");
        exit(1);
    }
    events[num_events].time = time;
    events[num_events].description = strdup(description);
    num_events++;
}

void print_events(Event *events, int num_events) {
    for (int i = 0; i < num_events; i++) {
        printf("%d: %s\n", events[i].time, events[i].description);
    }
}

void time_travel(int start_time, Event *events, int num_events) {
    srand(time(NULL));
    int time = start_time;
    while (time < TIME_MAX) {
        int event_time = rand() % TIME_MAX;
        if (event_time <= time) {
            int event_index = rand() % num_events;
            printf("At %d, you experience %s.\n", time, events[event_index].description);
        }
        time++;
    }
}

int main() {
    Event events[EVENT_MAX];
    int num_events = 0;

    add_event(events, num_events, 0, "You wake up in the year 2050.");
    add_event(events, num_events, 10, "You meet your future self.");
    add_event(events, num_events, 20, "You witness a historic event.");

    print_events(events, num_events);

    int start_time = rand() % TIME_MAX;
    printf("You start your time travel journey at %d.\n", start_time);
    time_travel(start_time, events, num_events);

    return 0;
}