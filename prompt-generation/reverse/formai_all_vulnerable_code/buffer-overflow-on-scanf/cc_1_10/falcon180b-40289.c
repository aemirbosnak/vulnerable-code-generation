//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100
#define MAX_TIME 1000

typedef struct {
    int time;
    char *event;
} Event;

int main() {
    int num_events = 0;
    Event events[MAX_EVENTS];

    // Read in events from user
    while (num_events < MAX_EVENTS && scanf("%d %s", &events[num_events].time, events[num_events].event) == 2) {
        num_events++;
    }

    // Sort events by time
    for (int i = 0; i < num_events - 1; i++) {
        for (int j = i + 1; j < num_events; j++) {
            if (events[i].time > events[j].time) {
                Event temp = events[i];
                events[i] = events[j];
                events[j] = temp;
            }
        }
    }

    // Simulate time travel
    int current_time = 0;
    int num_changes = 0;
    char *last_event = NULL;
    while (current_time <= MAX_TIME) {
        for (int i = 0; i < num_events; i++) {
            if (events[i].time == current_time && events[i].event!= last_event) {
                printf("At time %d, %s occurred.\n", current_time, events[i].event);
                last_event = events[i].event;
                num_changes++;
            }
        }
        current_time++;
    }

    // Print summary
    printf("Total number of events: %d\n", num_events);
    printf("Number of changes made during time travel: %d\n", num_changes);

    return 0;
}