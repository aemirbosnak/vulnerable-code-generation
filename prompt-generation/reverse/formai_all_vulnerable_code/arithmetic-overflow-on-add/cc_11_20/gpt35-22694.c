//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t current_time;
    char* c_time_string;
    struct tm* time_info;
    time(&current_time);
    time_info = localtime(&current_time);
    c_time_string = asctime(time_info);
    printf("Current time: %s", c_time_string);
    printf("\n");

    printf("Enter the year you want to travel to (e.g. 2025): ");
    int year;
    scanf("%d", &year);

    if (year < time_info->tm_year + 1900) {
        printf("Sorry, time travel to the past is not possible.\n");
        exit(1);
    }

    printf("Enter the month you want to travel to (e.g. 11 for November): ");
    int month;
    scanf("%d", &month);

    if (month > 12 || month < 1) {
        printf("Invalid month.\n");
        exit(1);
    }

    printf("Enter the day you want to travel to (e.g. 30): ");
    int day;
    scanf("%d", &day);

    if (day > 31 || day < 1) {
        printf("Invalid day.\n");
        exit(1);
    }

    printf("Enter the hour you want to travel to (e.g. 23 for 11 PM): ");
    int hour;
    scanf("%d", &hour);

    if (hour > 24 || hour < 0) {
        printf("Invalid hour.\n");
        exit(1);
    }

    printf("Enter the minute you want to travel to (e.g. 45): ");
    int minute;
    scanf("%d", &minute);

    if (minute > 59 || minute < 0) {
        printf("Invalid minute.\n");
        exit(1);
    }

    printf("Enter the second you want to travel to (e.g. 0): ");
    int second;
    scanf("%d", &second);

    if (second > 59 || second < 0) {
        printf("Invalid second.\n");
        exit(1);
    }
    
    struct tm travel_time = {0};
    travel_time.tm_year = year - 1900;
    travel_time.tm_mon = month - 1;
    travel_time.tm_mday = day;
    travel_time.tm_hour = hour;
    travel_time.tm_min = minute;
    travel_time.tm_sec = second;

    time_t travel_time_t = mktime(&travel_time);
    c_time_string = asctime(localtime(&travel_time_t));
    printf("Time travel successful. You have arrived at %s", c_time_string);

    return 0;
}