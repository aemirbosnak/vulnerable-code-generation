//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEAR 9999
#define MIN_YEAR 1900

struct TimeMachine {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

void time_travel(int year, int month, int day, int hour, int minute, int second) {
    struct tm new_time = {0};
    new_time.tm_year = year - 1900;
    new_time.tm_mon = month - 1;
    new_time.tm_mday = day;
    new_time.tm_hour = hour;
    new_time.tm_min = minute;
    new_time.tm_sec = second;

    time_t now = mktime(&new_time);
    if (now == -1) {
        printf("Invalid date/time!\n");
        exit(1);
    }

    printf("Traveling back/forward to %04d-%02d-%02d %02d:%02d:%02d...\n",
           new_time.tm_year + 1900, new_time.tm_mon + 1, new_time.tm_mday,
           new_time.tm_hour, new_time.tm_min, new_time.tm_sec);

    sleep(1);
}

int main() {
    int year, month, day, hour, minute, second;

    printf("Enter the year (between %d and %d): ", MIN_YEAR, MAX_YEAR);
    scanf("%d", &year);

    printf("Enter the month (between 1 and 12): ");
    scanf("%d", &month);

    printf("Enter the day (between 1 and 31): ");
    scanf("%d", &day);

    printf("Enter the hour (between 0 and 23): ");
    scanf("%d", &hour);

    printf("Enter the minute (between 0 and 59): ");
    scanf("%d", &minute);

    printf("Enter the second (between 0 and 59): ");
    scanf("%d", &second);

    time_travel(year, month, day, hour, minute, second);

    return 0;
}