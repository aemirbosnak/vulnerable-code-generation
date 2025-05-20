//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100

typedef struct {
    time_t time;
    int type;
    int data;
} Event;

void add_event(Event* events, int num_events, int type, int data) {
    if (num_events >= MAX_EVENTS) {
        printf("Error: too many events.\n");
        exit(1);
    }
    events[num_events].time = time(NULL) + rand() % 1000;
    events[num_events].type = type;
    events[num_events].data = data;
    num_events++;
}

int main() {
    srand(time(NULL));
    Event events[MAX_EVENTS];
    int num_events = 0;

    // Add some events
    add_event(events, num_events, 1, 42);
    add_event(events, num_events, 2, "Hello, world!");
    add_event(events, num_events, 3, 3.14);

    // Simulate time travel
    time_t target_time = time(NULL) - 1000;
    int i;
    for (i = 0; i < num_events; i++) {
        if (events[i].time > target_time) {
            break;
        }
        switch (events[i].type) {
            case 1:
                printf("Event %d: integer value %d\n", i, events[i].data);
                break;
            case 2:
                printf("Event %d: string value %s\n", i, (char*)events[i].data);
                break;
            case 3:
                printf("Event %d: float value %f\n", i, *(float*)events[i].data);
                break;
            default:
                printf("Event %d: unknown type\n", i);
                break;
        }
    }

    return 0;
}