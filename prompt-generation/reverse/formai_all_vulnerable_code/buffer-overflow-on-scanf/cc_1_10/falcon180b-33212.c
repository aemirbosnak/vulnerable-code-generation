//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVEL 10
#define TIME_TRAVEL_SPEED 1000 // Time travel speed in milliseconds

int main() {
    int i, j;
    struct tm future_time, past_time;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("You can travel up to %d times.\n", MAX_TIME_TRAVEL);

    for (i = 0; i < MAX_TIME_TRAVEL; i++) {
        printf("Enter the date and time you want to travel to (YYYY-MM-DD HH:MM:SS): ");
        scanf("%d-%d-%d %d:%d:%d", &future_time.tm_year, &future_time.tm_mon, &future_time.tm_mday, &future_time.tm_hour, &future_time.tm_min, &future_time.tm_sec);

        time_t future_timestamp = mktime(&future_time);
        time_t current_timestamp = time(NULL);

        while (difftime(future_timestamp, current_timestamp) > 0) {
            printf("Time traveling...\n");
            sleep(TIME_TRAVEL_SPEED);
            current_timestamp = time(NULL);
        }

        printf("You have arrived in the future!\n");

        for (j = 0; j < i; j++) {
            past_time = future_time;
            future_time.tm_year -= 100;
            future_time.tm_mon -= 6;
            future_time.tm_mday -= 7;
            future_time.tm_hour -= 24;
            future_time.tm_min -= 60;
            future_time.tm_sec -= 60;

            time_t past_timestamp = mktime(&past_time);

            while (difftime(past_timestamp, future_timestamp) > 0) {
                printf("Time traveling...\n");
                sleep(TIME_TRAVEL_SPEED);
                future_timestamp = mktime(&future_time);
            }

            printf("You have arrived in the past!\n");
        }
    }

    return 0;
}