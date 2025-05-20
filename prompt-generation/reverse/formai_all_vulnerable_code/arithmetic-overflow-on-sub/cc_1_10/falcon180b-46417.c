//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIME_TRAVEL_SPEED 1000 // Time travel speed in milliseconds
#define TIME_TRAVEL_DISTANCE 5000 // Time travel distance in milliseconds

int main() {
    struct tm start_time, end_time;
    time_t current_time;

    // Get the current time
    time(&current_time);
    localtime_r(&current_time, &start_time);

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Current time: %s\n", asctime(&start_time));

    // Time travel
    time_t travel_time = current_time - TIME_TRAVEL_DISTANCE;
    localtime_r(&travel_time, &end_time);

    printf("Traveling back in time...\n");
    for (int i = 0; i <= TIME_TRAVEL_DISTANCE; i++) {
        time_t current_travel_time = travel_time + i * TIME_TRAVEL_SPEED;
        localtime_r(&current_travel_time, &start_time);
        printf("%s\r", asctime(&start_time));
        fflush(stdout);
        usleep(TIME_TRAVEL_SPEED * 1000);
    }

    printf("\nYou have arrived at %s.\n", asctime(&end_time));

    // Time travel back
    time_t return_time = current_time + TIME_TRAVEL_DISTANCE;
    localtime_r(&return_time, &end_time);

    printf("Traveling back to the present...\n");
    for (int i = 0; i <= TIME_TRAVEL_DISTANCE; i++) {
        time_t current_return_time = return_time - i * TIME_TRAVEL_SPEED;
        localtime_r(&current_return_time, &start_time);
        printf("%s\r", asctime(&start_time));
        fflush(stdout);
        usleep(TIME_TRAVEL_SPEED * 1000);
    }

    printf("\nYou have returned to %s.\n", asctime(&end_time));

    return 0;
}