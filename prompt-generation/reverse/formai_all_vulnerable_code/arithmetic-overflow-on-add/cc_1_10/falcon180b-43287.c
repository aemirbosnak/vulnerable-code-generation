//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100

typedef struct {
    time_t time;
    void (*function)();
} Event;

void time_travel(time_t destination) {
    printf("Time travel initiated to %s\n", ctime(&destination));
}

void add_event(Event *events, int count, time_t time, void (*function)()) {
    if (count >= MAX_EVENTS) {
        printf("Event buffer is full!\n");
        return;
    }
    events[count].time = time;
    events[count].function = function;
    count++;
}

void execute_events(Event *events, int count) {
    while (count > 0) {
        if (events[count-1].time <= time(NULL)) {
            events[count-1].function();
            printf("Event executed at %s\n", ctime(&events[count-1].time));
        }
        count--;
    }
}

int main() {
    Event events[MAX_EVENTS];
    int event_count = 0;

    add_event(events, event_count, time(NULL) + 60, time_travel);
    add_event(events, event_count, time(NULL) + 120, time_travel);

    while (1) {
        time_t current_time = time(NULL);
        execute_events(events, event_count);
        sleep(1);
    }

    return 0;
}