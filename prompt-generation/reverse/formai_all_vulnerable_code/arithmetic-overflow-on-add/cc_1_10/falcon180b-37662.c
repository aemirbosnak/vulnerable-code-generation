//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_EVENTS 1000
#define MAX_EVENT_LENGTH 100

struct event {
    time_t time;
    int type;
    char message[MAX_EVENT_LENGTH];
};

void add_event(struct event *events, int num_events, time_t time, int type, char *message) {
    if (num_events >= MAX_EVENTS) {
        printf("Error: Too many events!\n");
        exit(1);
    }
    events[num_events].time = time;
    events[num_events].type = type;
    strncpy(events[num_events].message, message, MAX_EVENT_LENGTH);
    num_events++;
}

void print_event(struct event event) {
    printf("%s - %s\n", ctime(&event.time), event.message);
}

int main() {
    struct event events[MAX_EVENTS];
    int num_events = 0;
    time_t current_time = time(NULL);

    // Set the initial event
    add_event(events, num_events, current_time + 60, 1, "You wake up in the morning.");
    current_time += 60;

    // Add events throughout the day
    add_event(events, num_events, current_time + 1800, 2, "You have breakfast.");
    add_event(events, num_events, current_time + 3600, 3, "You go to work.");
    add_event(events, num_events, current_time + 5400, 4, "You have lunch.");
    add_event(events, num_events, current_time + 7200, 5, "You finish work.");
    add_event(events, num_events, current_time + 9000, 6, "You have dinner.");
    add_event(events, num_events, current_time + 10800, 7, "You go to bed.");

    // Simulate time travel
    time_t target_time = current_time + 3600; // 1 hour into the future
    while (current_time < target_time) {
        for (int i = 0; i < num_events; i++) {
            if (events[i].time == current_time) {
                print_event(events[i]);
            }
        }
        current_time += 60; // Advance time by 1 minute
    }

    // Print remaining events
    for (int i = num_events - 1; i >= 0; i--) {
        if (events[i].time > current_time) {
            print_event(events[i]);
        }
    }

    return 0;
}