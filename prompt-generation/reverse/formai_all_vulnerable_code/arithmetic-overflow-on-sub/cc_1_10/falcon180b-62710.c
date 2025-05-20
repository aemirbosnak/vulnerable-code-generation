//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELS 100
#define TIME_TRAVEL_SUCCESS 0
#define TIME_TRAVEL_FAILURE 1
#define TIME_TRAVEL_ERROR 2

typedef struct {
    int status;
    time_t departure_time;
    time_t arrival_time;
} TimeTravelRecord;

int main() {
    srand(time(NULL));

    TimeTravelRecord time_travel_records[MAX_TIME_TRAVELS];
    int num_time_travels = 0;

    while (num_time_travels < MAX_TIME_TRAVELS) {
        int status = rand() % 3; // 0 = success, 1 = failure, 2 = error

        if (status == TIME_TRAVEL_SUCCESS) {
            time_t departure_time = time(NULL) - 3600; // Travel back 1 hour
            time_t arrival_time = time(NULL);

            time_travel_records[num_time_travels].status = status;
            time_travel_records[num_time_travels].departure_time = departure_time;
            time_travel_records[num_time_travels].arrival_time = arrival_time;

            printf("Time travel attempt %d was successful!\n", num_time_travels + 1);
            printf("You traveled back in time from %s to %s.\n", ctime(&arrival_time), ctime(&departure_time));

            num_time_travels++;
        } else if (status == TIME_TRAVEL_FAILURE) {
            printf("Time travel attempt %d failed.\n", num_time_travels + 1);
        } else {
            printf("Time travel attempt %d encountered an error.\n", num_time_travels + 1);
        }
    }

    printf("\n");
    printf("Time Travel Records:\n");
    printf("---------------------\n");

    for (int i = 0; i < num_time_travels; i++) {
        printf("Attempt %d: ", i + 1);

        if (time_travel_records[i].status == TIME_TRAVEL_SUCCESS) {
            printf("Success\n");
            printf("Departure Time: %s\n", ctime(&time_travel_records[i].departure_time));
            printf("Arrival Time: %s\n", ctime(&time_travel_records[i].arrival_time));
        } else if (time_travel_records[i].status == TIME_TRAVEL_FAILURE) {
            printf("Failure\n");
        } else {
            printf("Error\n");
        }

        printf("\n");
    }

    return 0;
}