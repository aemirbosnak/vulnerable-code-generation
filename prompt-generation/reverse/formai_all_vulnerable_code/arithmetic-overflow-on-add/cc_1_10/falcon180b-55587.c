//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TIME_TRAVELS 100
#define TIME_TRAVEL_INTERVAL_MS 1000

struct time_travel {
    time_t timestamp;
    double distance;
};

int main() {
    struct time_travel time_travels[MAX_TIME_TRAVELS];
    int num_time_travels = 0;
    time_t current_time;
    double total_distance = 0;

    srand(time(NULL));
    current_time = time(NULL);

    while (num_time_travels < MAX_TIME_TRAVELS) {
        struct time_travel new_time_travel;
        new_time_travel.timestamp = current_time + rand() % (24 * 60 * 60);
        new_time_travel.distance = rand() % 10000;
        total_distance += new_time_travel.distance;

        int i;
        for (i = 0; i < num_time_travels; i++) {
            if (time_travels[i].timestamp > new_time_travel.timestamp) {
                break;
            }
        }

        if (i == num_time_travels) {
            num_time_travels++;
        } else {
            time_travels[i] = new_time_travel;
        }

        current_time = new_time_travel.timestamp;
        printf("Time travel to %s (%d seconds from now). Distance: %.2f km.\n", ctime(&new_time_travel.timestamp), (int)(difftime(new_time_travel.timestamp, current_time) / TIME_TRAVEL_INTERVAL_MS), new_time_travel.distance);
        fflush(stdout);

        usleep(TIME_TRAVEL_INTERVAL_MS * 1000);
    }

    printf("Total distance traveled: %.2f km.\n", total_distance);

    return 0;
}