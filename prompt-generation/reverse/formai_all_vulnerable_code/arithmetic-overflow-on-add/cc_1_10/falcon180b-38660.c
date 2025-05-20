//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100

struct event {
    time_t time;
    void (*function)();
};

void travel_to_past(void) {
    printf("You've traveled back in time!\n");
}

void travel_to_future(void) {
    printf("You've traveled forward in time!\n");
}

int main(void) {
    struct event events[MAX_EVENTS];
    int num_events = 0;

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        events[i].time = time(NULL) + rand() % 86400; // Random time within 24 hours
        events[i].function = (i % 2 == 0)? travel_to_past : travel_to_future;
        num_events++;
    }

    printf("You have %d time travel events:\n", num_events);

    for (int i = 0; i < num_events; i++) {
        printf("%ld: %s\n", events[i].time, (events[i].function == travel_to_past)? "Travel to the past" : "Travel to the future");
    }

    while (1) {
        time_t current_time = time(NULL);

        for (int i = 0; i < num_events; i++) {
            if (events[i].time == current_time) {
                events[i].function();
                num_events--;
                i--;
            }
        }

        sleep(1);
    }

    return 0;
}