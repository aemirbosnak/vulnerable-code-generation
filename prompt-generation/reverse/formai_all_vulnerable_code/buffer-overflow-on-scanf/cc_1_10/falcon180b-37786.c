//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TIME 1000000
#define MAX_EVENTS 1000

struct event {
    int time;
    int type;
};

int main() {
    int num_events, i;
    struct event* events;

    printf("Enter the number of events: ");
    scanf("%d", &num_events);

    events = malloc(num_events * sizeof(struct event));

    for (i = 0; i < num_events; i++) {
        printf("Enter the time and type of event %d (format: time type): ", i+1);
        scanf("%d %d", &events[i].time, &events[i].type);
    }

    srand(time(NULL));
    int current_time = rand() % MAX_TIME;

    while (current_time < MAX_TIME) {
        int event_index = -1;
        for (i = 0; i < num_events; i++) {
            if (events[i].time == current_time) {
                event_index = i;
                break;
            }
        }

        if (event_index!= -1) {
            switch (events[event_index].type) {
                case 1:
                    printf("Traveling back in time to event %d\n", event_index+1);
                    current_time = events[event_index].time - (rand() % 1000);
                    break;
                case 2:
                    printf("Traveling forward in time to event %d\n", event_index+1);
                    current_time = events[event_index].time + (rand() % 1000);
                    break;
            }
        } else {
            current_time++;
        }
    }

    free(events);

    return 0;
}