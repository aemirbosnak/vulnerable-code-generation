//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_TIME 1000

typedef struct {
    int time;
    int event;
} Event;

void addEvent(Event *events, int *numEvents, int time, int event) {
    if (*numEvents >= MAX_EVENTS) {
        printf("Error: Too many events.\n");
        exit(1);
    }
    events[*numEvents].time = time;
    events[*numEvents].event = event;
    (*numEvents)++;
}

int main() {
    int numEvents = 0;
    Event events[MAX_EVENTS];
    int time = 0;
    int event;

    addEvent(events, &numEvents, 0, 1); // Start event

    while (1) {
        printf("Time: %d\n", time);
        event = events[time].event;
        if (event == -1) {
            break;
        }
        switch (event) {
            case 1:
                printf("You start your time travel journey.\n");
                break;
            case 2:
                printf("You arrive in the past.\n");
                break;
            case 3:
                printf("You arrive in the future.\n");
                break;
            default:
                printf("Unknown event: %d\n", event);
        }
        time++;
    }

    return 0;
}