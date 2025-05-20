//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 1000

struct event {
    int time;
    int type;
    int data;
};

int main() {
    int num_events;
    printf("Enter the number of events: ");
    scanf("%d", &num_events);

    struct event events[MAX_EVENTS];
    printf("Enter the events (time type data):\n");
    for (int i = 0; i < num_events; i++) {
        scanf("%d %d %d", &events[i].time, &events[i].type, &events[i].data);
    }

    int current_time = 0;
    while (1) {
        printf("\nCurrent time: %d\n", current_time);

        int next_event_time = -1;
        for (int i = 0; i < num_events; i++) {
            if (events[i].time > current_time && (next_event_time == -1 || events[i].time < next_event_time)) {
                next_event_time = events[i].time;
            }
        }

        if (next_event_time == -1) {
            break;
        }

        printf("Next event at time %d:\n", next_event_time);
        for (int i = 0; i < num_events; i++) {
            if (events[i].time == next_event_time) {
                printf("  Type: %d, Data: %d\n", events[i].type, events[i].data);
            }
        }

        current_time = next_event_time;
    }

    return 0;
}