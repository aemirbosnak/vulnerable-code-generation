//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_EVENTS 1000
#define MAX_TIME 1000

struct event {
    int time;
    void (*function)();
};

int event_count = 0;
struct event *events = NULL;

void add_event(int time, void (*function)()) {
    if (event_count >= MAX_EVENTS) {
        printf("Error: Too many events\n");
        exit(1);
    }
    events = realloc(events, sizeof(struct event) * (event_count + 1));
    events[event_count].time = time;
    events[event_count].function = function;
    event_count++;
}

void run_events() {
    int current_time = 0;
    while (current_time < MAX_TIME) {
        int i;
        for (i = 0; i < event_count; i++) {
            if (events[i].time == current_time) {
                events[i].function();
            }
        }
        current_time++;
    }
}

void travel_backward(int time) {
    printf("Traveling back to %d\n", time);
}

void travel_forward(int time) {
    printf("Traveling forward to %d\n", time);
}

int main() {
    srand(time(NULL));
    int i;
    for (i = 0; i < 10; i++) {
        add_event(rand() % MAX_TIME, travel_backward);
        add_event(rand() % MAX_TIME, travel_forward);
    }
    run_events();
    return 0;
}