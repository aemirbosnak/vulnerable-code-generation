//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int year, month, day, hour, minute, second;
    char time_zone[20];
    struct tm *local_time;
    time_t current_time, target_time;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please enter the current date and time in the format YYYY-MM-DD HH:MM:SS:\n");
    scanf("%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);
    printf("Please enter the target time zone:\n");
    scanf("%s", time_zone);

    // Convert the current time to a time_t object
    local_time = localtime(&current_time);
    local_time->tm_year = year - 1900;
    local_time->tm_mon = month - 1;
    local_time->tm_mday = day;
    local_time->tm_hour = hour;
    local_time->tm_min = minute;
    local_time->tm_sec = second;
    current_time = mktime(local_time);

    // Convert the target time zone to a time_t object
    target_time = strptime(time_zone, "%Y-%m-%d %H:%M:%S", NULL);

    printf("You are currently in the year %d.\n", local_time->tm_year + 1900);
    printf("You are currently in the time zone %s.\n", time_zone);
    printf("Please enter the target year:\n");
    scanf("%d", &year);
    printf("Please enter the target month:\n");
    scanf("%d", &month);
    printf("Please enter the target day:\n");
    scanf("%d", &day);
    printf("Please enter the target hour:\n");
    scanf("%d", &hour);
    printf("Please enter the target minute:\n");
    scanf("%d", &minute);
    printf("Please enter the target second:\n");
    scanf("%d", &second);

    // Convert the target time to a time_t object
    local_time = localtime(&target_time);
    local_time->tm_year = year - 1900;
    local_time->tm_mon = month - 1;
    local_time->tm_mday = day;
    local_time->tm_hour = hour;
    local_time->tm_min = minute;
    local_time->tm_sec = second;
    target_time = mktime(local_time);

    if (current_time > target_time) {
        printf("You cannot travel back in time.\n");
    } else if (current_time == target_time) {
        printf("You are already in the target time.\n");
    } else {
        printf("You have successfully traveled through time!\n");
        printf("You are now in the year %d.\n", local_time->tm_year + 1900);
        printf("You are now in the time zone %s.\n", time_zone);
    }

    return 0;
}