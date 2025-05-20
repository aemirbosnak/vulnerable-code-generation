//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100

typedef struct {
    time_t time;
    char *description;
} event_t;

event_t events[MAX_EVENTS];
int num_events = 0;

void add_event(time_t time, char *description) {
    if (num_events >= MAX_EVENTS) {
        printf("Error: Too many events!\n");
        return;
    }
    events[num_events].time = time;
    events[num_events].description = description;
    num_events++;
}

void print_events() {
    printf("Events:\n");
    for (int i = 0; i < num_events; i++) {
        printf("%s - %s\n", ctime(&events[i].time), events[i].description);
    }
}

void time_travel(time_t target_time) {
    printf("Time traveling to %s...\n", ctime(&target_time));
    for (int i = 0; i < num_events; i++) {
        if (events[i].time == target_time) {
            printf("You arrive at the event: %s\n", events[i].description);
        }
    }
}

int main() {
    srand(time(NULL));

    add_event(time(NULL) + 3600, "Lunch with friends");
    add_event(time(NULL) + 7200, "Movie night");

    print_events();

    time_travel(time(NULL) + 3600);

    return 0;
}