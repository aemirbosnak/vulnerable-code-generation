//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_EVENTS 1000
#define MAX_TIME 1000

typedef struct {
    int time;
    int type;
    int data;
} Event;

int main() {
    int num_events = 0;
    Event events[MAX_EVENTS];
    double current_time = 0;
    double time_travel_duration = 0;
    int time_travel_start_time = 0;
    int time_travel_end_time = 0;

    printf("Time Travel Simulator\n");
    printf("=====================\n");

    // Initialize random seed
    srand(time(NULL));

    // Add initial event
    events[num_events].time = 0;
    events[num_events].type = 1;
    events[num_events].data = rand() % 100;
    num_events++;

    // Simulate time travel
    printf("Enter start time (in seconds): ");
    scanf("%lf", &time_travel_start_time);
    printf("Enter end time (in seconds): ");
    scanf("%lf", &time_travel_end_time);
    printf("Enter duration (in seconds): ");
    scanf("%lf", &time_travel_duration);

    current_time = time_travel_start_time;
    while (current_time <= time_travel_end_time) {
        // Check for events
        int i;
        for (i = 0; i < num_events; i++) {
            if (events[i].time == current_time) {
                printf("Event at time %.2lf: ", current_time);
                if (events[i].type == 1) {
                    printf("Random number: %d\n", events[i].data);
                } else if (events[i].type == 2) {
                    printf("Time travel started\n");
                } else if (events[i].type == 3) {
                    printf("Time travel ended\n");
                }
            }
        }

        // Update time
        current_time += time_travel_duration;

        // Check for time travel
        if (current_time >= time_travel_start_time && current_time <= time_travel_end_time) {
            // Start time travel
            if (current_time == time_travel_start_time) {
                printf("Time travel started\n");
            }
        } else if (current_time >= time_travel_start_time + time_travel_duration && current_time <= time_travel_end_time) {
            // End time travel
            if (current_time == time_travel_end_time) {
                printf("Time travel ended\n");
            }
        }
    }

    return 0;
}