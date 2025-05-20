//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100

typedef struct {
    time_t timestamp;
    char *event_description;
} Event;

int main() {
    int num_events = 0;
    Event events[MAX_EVENTS];
    time_t current_time = time(NULL);

    // Initialize first event as current time
    events[num_events].timestamp = current_time;
    events[num_events].event_description = "Program start";
    num_events++;

    // Add example events
    events[num_events].timestamp = current_time + 60;
    events[num_events].event_description = "1 minute has passed";
    num_events++;

    events[num_events].timestamp = current_time + 120;
    events[num_events].event_description = "2 minutes have passed";
    num_events++;

    events[num_events].timestamp = current_time + 180;
    events[num_events].event_description = "3 minutes have passed";
    num_events++;

    // Travel back in time
    time_t target_time = current_time - 60;
    for (int i = num_events - 1; i >= 0; i--) {
        if (events[i].timestamp > target_time) {
            events[i].timestamp -= 60;
            events[i].event_description = "Time travel to 1 minute ago";
        } else {
            break;
        }
    }

    // Travel forward in time
    target_time = current_time + 60;
    for (int i = num_events - 1; i >= 0; i--) {
        if (events[i].timestamp < target_time) {
            events[i].timestamp += 60;
            events[i].event_description = "Time travel to 1 minute in the future";
        } else {
            break;
        }
    }

    // Print events in chronological order
    for (int i = 0; i < num_events; i++) {
        printf("%s at %s\n", events[i].event_description, ctime(&events[i].timestamp));
    }

    return 0;
}