//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_TIME_TRAVEL_DISTANCE 100

typedef struct {
    int time;
    int event;
} Event;

int main() {
    int num_events;
    int num_time_travels;
    int i, j;

    printf("Enter the number of events: ");
    scanf("%d", &num_events);

    Event events[MAX_EVENTS];
    for (i = 0; i < num_events; i++) {
        printf("Enter event %d time: ", i+1);
        scanf("%d", &events[i].time);
    }

    printf("Enter the number of time travels: ");
    scanf("%d", &num_time_travels);

    for (i = 0; i < num_time_travels; i++) {
        printf("Enter time travel %d distance (in seconds): ", i+1);
        scanf("%d", &events[num_events+i].time);
    }

    for (i = 0; i < num_events; i++) {
        printf("Event %d occurs at time %d\n", i+1, events[i].time);
    }

    for (i = 0; i < num_time_travels; i++) {
        printf("Time travel %d occurs at time %d\n", i+1, events[num_events+i].time);
    }

    for (i = 0; i < num_events; i++) {
        if (events[i].time > events[num_events+i].time) {
            printf("Time travel %d is invalid\n", i+1);
        }
    }

    return 0;
}