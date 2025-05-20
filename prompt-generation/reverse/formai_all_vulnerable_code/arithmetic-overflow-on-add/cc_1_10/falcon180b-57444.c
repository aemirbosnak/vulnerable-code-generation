//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    struct tm start_time, end_time;
    time_t start_t, end_t;

    // Set the start time
    start_time.tm_sec = 0;
    start_time.tm_min = 0;
    start_time.tm_hour = 12;
    start_time.tm_mday = 1;
    start_time.tm_mon = 0;
    start_time.tm_year = 2022 - 1900; // 1900 is the base year for tm_year
    start_time.tm_isdst = 0;

    // Convert the start time to Unix timestamp
    start_t = mktime(&start_time);

    // Set the end time
    end_time.tm_sec = 0;
    end_time.tm_min = 0;
    end_time.tm_hour = 12;
    end_time.tm_mday = 1;
    end_time.tm_mon = 0;
    end_time.tm_year = 2022 - 1900; // 1900 is the base year for tm_year
    end_time.tm_isdst = 0;

    // Convert the end time to Unix timestamp
    end_t = mktime(&end_time);

    // Calculate the duration between the start and end times
    int duration = (int)difftime(end_t, start_t);

    // Travel back in time
    printf("Traveling back in time...\n");
    for (int i = duration; i >= 0; i--) {
        time_t current_t = start_t + i;
        struct tm current_time;
        localtime_r(&current_t, &current_time);
        printf("%d seconds left...\n", i);
        printf("Current time: %d:%d:%d\n", current_time.tm_hour, current_time.tm_min, current_time.tm_sec);
        sleep(1);
    }

    // Travel forward in time
    printf("Traveling forward in time...\n");
    for (int i = 0; i <= duration; i++) {
        time_t current_t = start_t + i;
        struct tm current_time;
        localtime_r(&current_t, &current_time);
        printf("%d seconds passed...\n", i);
        printf("Current time: %d:%d:%d\n", current_time.tm_hour, current_time.tm_min, current_time.tm_sec);
        sleep(1);
    }

    return 0;
}