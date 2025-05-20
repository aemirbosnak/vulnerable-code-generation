//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 1000

typedef struct {
    time_t time;
    int type;
    void *data;
} event_t;

int main() {
    event_t events[MAX_EVENTS];
    int num_events = 0;
    time_t current_time = time(NULL);

    while (1) {
        printf("Current time: %ld\n", current_time);
        printf("Enter event (type: 0=set time, 1=travel back, 2=travel forward): ");
        scanf("%d", &events[num_events].type);

        switch (events[num_events].type) {
            case 0:
                printf("Enter new time (in seconds since epoch): ");
                scanf("%ld", &events[num_events].data);
                break;
            case 1:
                printf("Traveling back in time...\n");
                current_time = events[--num_events].time;
                break;
            case 2:
                printf("Traveling forward in time...\n");
                current_time = events[++num_events].time;
                break;
            default:
                printf("Invalid event type.\n");
                break;
        }

        if (num_events >= MAX_EVENTS) {
            printf("Event buffer full. Exiting.\n");
            return 1;
        }

        events[num_events++].time = current_time;
    }

    return 0;
}