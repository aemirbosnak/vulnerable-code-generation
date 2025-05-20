//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIME_TRAVEL_SUCCESS 0
#define TIME_TRAVEL_FAILURE 1

int time_travel(int target_year, int *result_year) {
    struct tm target_tm, result_tm;
    time_t target_time, result_time;

    target_tm.tm_year = target_year - 1900;
    target_tm.tm_mon = 0;
    target_tm.tm_mday = 1;
    target_tm.tm_hour = 0;
    target_tm.tm_min = 0;
    target_tm.tm_sec = 0;

    target_time = mktime(&target_tm);

    if (target_time == -1) {
        printf("Invalid target year.\n");
        return TIME_TRAVEL_FAILURE;
    }

    result_tm.tm_year = *result_year - 1900;
    result_tm.tm_mon = 0;
    result_tm.tm_mday = 1;
    result_tm.tm_hour = 0;
    result_tm.tm_min = 0;
    result_tm.tm_sec = 0;

    result_time = mktime(&result_tm);

    if (result_time == -1) {
        printf("Invalid result year.\n");
        return TIME_TRAVEL_FAILURE;
    }

    *result_year = result_tm.tm_year + 1900;
    return TIME_TRAVEL_SUCCESS;
}

int main() {
    int target_year, result_year;

    printf("Enter target year: ");
    scanf("%d", &target_year);

    int status = time_travel(target_year, &result_year);

    if (status == TIME_TRAVEL_SUCCESS) {
        printf("You have successfully traveled to the year %d.\n", result_year);
    } else {
        printf("Time travel failed.\n");
    }

    return 0;
}