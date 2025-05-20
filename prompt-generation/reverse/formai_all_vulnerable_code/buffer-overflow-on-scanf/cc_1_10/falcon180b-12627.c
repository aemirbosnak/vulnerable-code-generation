//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TIME 1000
#define MAX_EVENTS 1000

typedef struct event {
    int time;
    int action;
} Event;

Event events[MAX_EVENTS];
int num_events;

void add_event(int time, int action) {
    if (num_events >= MAX_EVENTS) {
        printf("Too many events!\n");
        exit(1);
    }
    events[num_events].time = time;
    events[num_events].action = action;
    num_events++;
}

void time_travel(int start_time, int end_time) {
    srand(time(NULL));
    for (int i = 0; i < num_events; i++) {
        events[i].time += rand() % (end_time - start_time) + 1;
    }
}

void print_events() {
    for (int i = 0; i < num_events; i++) {
        printf("%d: %d\n", events[i].time, events[i].action);
    }
}

int main() {
    int start_time, end_time;
    printf("Enter start time: ");
    scanf("%d", &start_time);
    printf("Enter end time: ");
    scanf("%d", &end_time);
    if (start_time >= end_time) {
        printf("Invalid time range!\n");
        exit(1);
    }
    for (int i = 0; i < num_events; i++) {
        printf("%d: %d\n", events[i].time, events[i].action);
    }
    add_event(start_time, 1);
    add_event(end_time, 2);
    time_travel(start_time, end_time);
    print_events();
    return 0;
}