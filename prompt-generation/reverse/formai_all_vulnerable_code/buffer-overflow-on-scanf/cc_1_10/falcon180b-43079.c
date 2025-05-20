//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELS 10
#define MAX_TIME_TRAVEL_LENGTH 100

typedef struct {
    int start_time;
    int end_time;
} TimeTravel;

int main() {
    int num_time_travels;
    TimeTravel time_travels[MAX_TIME_TRAVELS];
    int i, j, k;

    printf("Enter the number of time travels: ");
    scanf("%d", &num_time_travels);

    for (i = 0; i < num_time_travels; i++) {
        printf("Enter the start time for time travel %d: ", i+1);
        scanf("%d", &time_travels[i].start_time);

        printf("Enter the end time for time travel %d: ", i+1);
        scanf("%d", &time_travels[i].end_time);

        if (time_travels[i].start_time > time_travels[i].end_time) {
            printf("Error: Start time cannot be greater than end time.\n");
            return 1;
        }
    }

    int current_time = 0;
    while (current_time < MAX_TIME_TRAVEL_LENGTH) {
        for (i = 0; i < num_time_travels; i++) {
            if (current_time >= time_travels[i].start_time && current_time <= time_travels[i].end_time) {
                printf("You are currently in the time period of time travel %d.\n", i+1);
                break;
            }
        }

        if (i == num_time_travels) {
            printf("You are currently in the present time.\n");
        }

        current_time++;
    }

    return 0;
}