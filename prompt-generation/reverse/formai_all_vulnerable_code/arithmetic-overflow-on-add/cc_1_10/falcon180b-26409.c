//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEAR 9999
#define MAX_MONTH 12
#define MAX_DAY 31
#define MAX_HOUR 23
#define MAX_MINUTE 59
#define MAX_SECOND 59

struct tm travel_time;

void set_time(int year, int month, int day, int hour, int minute, int second) {
    travel_time.tm_year = year - 1900;
    travel_time.tm_mon = month - 1;
    travel_time.tm_mday = day;
    travel_time.tm_hour = hour;
    travel_time.tm_min = minute;
    travel_time.tm_sec = second;
}

int main() {
    int year, month, day, hour, minute, second;

    printf("Enter the year (between 1900 and %d): ", MAX_YEAR);
    scanf("%d", &year);

    printf("Enter the month (between 1 and %d): ", MAX_MONTH);
    scanf("%d", &month);

    printf("Enter the day (between 1 and %d): ", MAX_DAY);
    scanf("%d", &day);

    printf("Enter the hour (between 0 and %d): ", MAX_HOUR);
    scanf("%d", &hour);

    printf("Enter the minute (between 0 and %d): ", MAX_MINUTE);
    scanf("%d", &minute);

    printf("Enter the second (between 0 and %d): ", MAX_SECOND);
    scanf("%d", &second);

    set_time(year, month, day, hour, minute, second);

    time_t now = time(NULL);
    time_t target_time = mktime(&travel_time);

    if (target_time > now) {
        printf("You cannot travel to the future!\n");
        return 1;
    }

    printf("Time travel initiated...\n");

    sleep(5);

    printf("Arrived in the year %d.\n", travel_time.tm_year + 1900);

    return 0;
}