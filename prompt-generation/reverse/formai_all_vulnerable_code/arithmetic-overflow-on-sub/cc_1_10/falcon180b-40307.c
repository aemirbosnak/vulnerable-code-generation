//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 1000
#define MAX_TIME 1000000000

typedef struct {
    int time;
    void (*function)();
} event;

event events[MAX_EVENTS];
int num_events = 0;

void add_event(int time, void (*function)()) {
    if (num_events >= MAX_EVENTS) {
        printf("Error: Too many events!\n");
        exit(1);
    }
    events[num_events] = (event) {.time = time,.function = function };
    num_events++;
}

void run_events() {
    int current_time = 0;
    while (current_time < MAX_TIME) {
        event* event = NULL;
        for (int i = 0; i < num_events; i++) {
            if (events[i].time == current_time) {
                event = &events[i];
                break;
            }
        }
        if (event!= NULL) {
            event->function();
        }
        current_time++;
    }
}

void travel_back_in_time(int seconds) {
    time_t now = time(NULL) - seconds;
    struct tm* time_struct = localtime(&now);
    printf("Travelling back in time to %s", asctime(time_struct));
}

int main() {
    add_event(5, travel_back_in_time);
    run_events();
    return 0;
}