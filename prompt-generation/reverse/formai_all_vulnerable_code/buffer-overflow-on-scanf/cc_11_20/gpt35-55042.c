//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    time_t current_time;
    struct tm *time_info;
    char time_string[9];

    time(&current_time);
    time_info = localtime(&current_time);

    strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);

    printf("Current time is %s\n", time_string);
    printf("Welcome to Time Travel Simulator v1.0\n");

    int year, month, day, hour, minute, second;

    printf("Enter the year you want to travel to: ");
    scanf("%d", &year);
    printf("Enter the month (1-12) you want to travel to: ");
    scanf("%d", &month);
    printf("Enter the day (1-31) you want to travel to: ");
    scanf("%d", &day);
    printf("Enter the hour (0-23) you want to travel to: ");
    scanf("%d", &hour);
    printf("Enter the minute (0-59) you want to travel to: ");
    scanf("%d", &minute);
    printf("Enter the second (0-59) you want to travel to: ");
    scanf("%d", &second);

    // Check if the input values are valid
    if (month < 1 || month > 12) {
        printf("Invalid month value!\n");
        return 0;
    }
    if (day < 1 || day > 31) {
        printf("Invalid day value!\n");
        return 0;
    }
    if (hour < 0 || hour > 23) {
        printf("Invalid hour value!\n");
        return 0;
    }
    if (minute < 0 || minute > 59) {
        printf("Invalid minute value!\n");
        return 0;
    }
    if (second < 0 || second > 59) {
        printf("Invalid second value!\n");
        return 0;
    }

    // Set the time to the specified values
    struct tm time_info_new = {0};
    time_info_new.tm_year = year - 1900;
    time_info_new.tm_mon = month - 1;
    time_info_new.tm_mday = day;
    time_info_new.tm_hour = hour;
    time_info_new.tm_min = minute;
    time_info_new.tm_sec = second;

    time_t new_time = mktime(&time_info_new);
    time(&current_time);

    double time_diff = difftime(new_time, current_time);

    // Check if the specified time is in the future or in the past
    if (time_diff > 0) {
        printf("Traveling to the future...\n");
        while (time_diff > 0) {
            time_t new_time2 = time(NULL);
            time_diff = difftime(new_time, new_time2);
        }
    } else {
        printf("Traveling to the past...\n");
        while (time_diff < 0) {
            time_t new_time2 = time(NULL);
            time_diff = difftime(new_time2, new_time);
        }
    }

    printf("Time travel complete!\n");
    printf("Current time is now ");
    strftime(time_string, sizeof(time_string), "%H:%M:%S", localtime(&new_time));
    printf("%s\n", time_string);

    return 0;
}