//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_TIME_TRAVEL 10

typedef struct {
    time_t time;
    int event_id;
} Event;

int main() {
    int num_events;
    Event events[MAX_EVENTS];
    int num_time_travels;
    time_t time_travel_times[MAX_TIME_TRAVEL];
    int event_ids[MAX_TIME_TRAVEL];

    // Get the number of events
    printf("Enter the number of events: ");
    scanf("%d", &num_events);

    // Get the events
    for (int i = 0; i < num_events; i++) {
        printf("Enter the time and event ID for event %d: ", i+1);
        scanf("%ld %d", &events[i].time, &events[i].event_id);
    }

    // Get the number of time travels
    printf("Enter the number of time travels: ");
    scanf("%d", &num_time_travels);

    // Get the time travel times and event IDs
    for (int i = 0; i < num_time_travels; i++) {
        printf("Enter the time travel time and event ID for time travel %d: ", i+1);
        scanf("%ld %d", &time_travel_times[i], &event_ids[i]);
    }

    // Simulate time travel
    for (int i = 0; i < num_time_travels; i++) {
        for (int j = 0; j < num_events; j++) {
            if (events[j].event_id == event_ids[i]) {
                if (events[j].time > time_travel_times[i]) {
                    printf("Time travel to event %d at time %ld\n", j+1, time_travel_times[i]);
                }
            }
        }
    }

    return 0;
}