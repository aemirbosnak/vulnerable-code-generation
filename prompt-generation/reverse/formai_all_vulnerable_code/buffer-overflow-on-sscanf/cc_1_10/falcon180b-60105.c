//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100

struct event {
    time_t timestamp;
    char *description;
};

int main() {
    struct event events[MAX_EVENTS];
    int num_events = 0;
    char input_buffer[1024];
    time_t current_time, target_time, next_event_time;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("You can enter events in the format: '[timestamp] [description]'\n");
    printf("To travel to an event, enter its timestamp.\n");

    while (fgets(input_buffer, sizeof(input_buffer), stdin)!= NULL) {
        if (num_events >= MAX_EVENTS) {
            printf("Error: Maximum number of events reached.\n");
            continue;
        }

        if (sscanf(input_buffer, "%ld %[^\n]", &events[num_events].timestamp, events[num_events].description)!= 2) {
            printf("Error: Invalid event format.\n");
            continue;
        }

        num_events++;
    }

    printf("Enter a target timestamp to travel to (0 for present): ");
    scanf("%ld", &target_time);

    current_time = time(NULL);
    next_event_time = current_time;

    while (next_event_time <= target_time) {
        for (int i = 0; i < num_events; i++) {
            if (events[i].timestamp == next_event_time) {
                printf("You have arrived at the event: %s\n", events[i].description);
            }
        }

        next_event_time = events[num_events - 1].timestamp;
    }

    return 0;
}