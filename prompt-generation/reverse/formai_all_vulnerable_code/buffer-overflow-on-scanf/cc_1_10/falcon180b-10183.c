//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <assert.h>

#define MAX_TIME_TRAVELS 10000
#define MAX_TIME_TRAVEL_LENGTH 10000

typedef struct {
    int start_time;
    int end_time;
} TimeTravel;

int main() {
    int num_time_travels;
    int i;
    TimeTravel time_travels[MAX_TIME_TRAVELS];

    printf("Enter the number of time travels: ");
    scanf("%d", &num_time_travels);

    for(i = 0; i < num_time_travels; i++) {
        printf("Enter the start time for time travel %d: ", i+1);
        scanf("%d", &time_travels[i].start_time);
        printf("Enter the end time for time travel %d: ", i+1);
        scanf("%d", &time_travels[i].end_time);
    }

    int current_time = 0;
    while(current_time < MAX_TIME_TRAVEL_LENGTH) {
        int next_event_time = INT_MAX;
        int next_event_index = -1;

        for(i = 0; i < num_time_travels; i++) {
            if(time_travels[i].start_time <= current_time && time_travels[i].end_time > current_time) {
                int event_time = time_travels[i].start_time + (current_time - time_travels[i].start_time) % (time_travels[i].end_time - time_travels[i].start_time);
                if(event_time < next_event_time) {
                    next_event_time = event_time;
                    next_event_index = i;
                }
            }
        }

        if(next_event_index!= -1) {
            current_time = next_event_time;
            printf("Time travel event %d occurred at time %d\n", next_event_index+1, current_time);
        } else {
            current_time++;
        }
    }

    return 0;
}