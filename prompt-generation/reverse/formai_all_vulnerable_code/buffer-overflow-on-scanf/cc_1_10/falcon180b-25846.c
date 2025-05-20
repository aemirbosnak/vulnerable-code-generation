//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_TIME 1000
#define MAX_EVENTS 100

typedef struct {
    int time;
    char event[50];
} Event;

void add_event(Event* events, int num_events, char* event_str) {
    if (num_events >= MAX_EVENTS) {
        printf("Error: Too many events!\n");
        exit(1);
    }
    strcpy(events[num_events].event, event_str);
    events[num_events].time = num_events + 1;
    num_events++;
}

void time_travel(int time, Event* events, int num_events) {
    if (time < 1 || time > MAX_TIME) {
        printf("Error: Invalid time!\n");
        exit(1);
    }
    if (time == 1) {
        printf("You arrive at the beginning of time.\n");
    } else if (time == MAX_TIME) {
        printf("You arrive at the end of time.\n");
    } else {
        int i;
        for (i = 0; i < num_events; i++) {
            if (events[i].time == time) {
                printf("You witness the %s.\n", events[i].event);
            }
        }
    }
}

int main() {
    int num_events = 0;
    Event events[MAX_EVENTS];
    add_event(events, num_events, "Big Bang");
    add_event(events, num_events, "Formation of Earth");
    add_event(events, num_events, "Extinction of Dinosaurs");
    add_event(events, num_events, "Invention of Time Travel");
    int time = 0;
    while (1) {
        printf("Enter time to travel to (1-%d): ", MAX_TIME);
        scanf("%d", &time);
        time_travel(time, events, num_events);
        if (time == MAX_TIME) {
            break;
        }
    }
    return 0;
}