//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_TIME 1000000

typedef struct {
    int time;
    int type;
    int data;
} Event;

int compare(const void *a, const void *b) {
    const Event *eventA = (const Event *) a;
    const Event *eventB = (const Event *) b;

    if (eventA->time < eventB->time) {
        return -1;
    } else if (eventA->time > eventB->time) {
        return 1;
    } else {
        return 0;
    }
}

void time_travel(Event events[], int num_events) {
    qsort(events, num_events, sizeof(Event), compare);

    int current_time = 0;
    for (int i = 0; i < num_events; i++) {
        if (events[i].type == 1) {
            current_time += events[i].data;
        } else if (events[i].type == 2) {
            printf("At time %d, you traveled back in time by %d seconds.\n", current_time, events[i].data);
            current_time -= events[i].data;
        } else if (events[i].type == 3) {
            printf("At time %d, you traveled forward in time by %d seconds.\n", current_time, events[i].data);
            current_time += events[i].data;
        }
    }
}

int main() {
    Event events[MAX_EVENTS];
    int num_events = 0;

    printf("Enter the number of events: ");
    scanf("%d", &num_events);

    for (int i = 0; i < num_events; i++) {
        printf("Enter the type of event (1 = go back in time, 2 = go forward in time): ");
        scanf("%d", &events[i].type);

        if (events[i].type == 1 || events[i].type == 2) {
            printf("Enter the amount of time to travel: ");
            scanf("%d", &events[i].data);
        }
    }

    time_travel(events, num_events);

    return 0;
}