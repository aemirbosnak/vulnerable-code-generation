//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: grateful
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    time_t t = time(NULL);
    struct tm *now = localtime(&t);
    int year, month, day, hour, minute, second;

    printf("Welcome to the Time Travel Simulator!\n");

    printf("Enter the year you wish to travel to: ");
    scanf("%d", &year);
    while (year < 1900 || year > now->tm_year + 1900) {
        printf("Invalid year. Please enter a year between 1900 and %d: ", now->tm_year + 1900);
        scanf("%d", &year);
    }

    printf("Enter the month you wish to travel to (1-12): ");
    scanf("%d", &month);
    while (month < 1 || month > 12) {
        printf("Invalid month. Please enter a month between 1 and 12: ");
        scanf("%d", &month);
    }

    printf("Enter the day you wish to travel to (1-31): ");
    scanf("%d", &day);
    while (day < 1 || day > 31) {
        printf("Invalid day. Please enter a day between 1 and 31: ");
        scanf("%d", &day);
    }

    printf("Enter the hour you wish to travel to (0-23): ");
    scanf("%d", &hour);
    while (hour < 0 || hour > 23) {
        printf("Invalid hour. Please enter an hour between 0 and 23: ");
        scanf("%d", &hour);
    }

    printf("Enter the minute you wish to travel to (0-59): ");
    scanf("%d", &minute);
    while (minute < 0 || minute > 59) {
        printf("Invalid minute. Please enter a minute between 0 and 59: ");
        scanf("%d", &minute);
    }

    printf("Enter the second you wish to travel to (0-59): ");
    scanf("%d", &second);
    while (second < 0 || second > 59) {
        printf("Invalid second. Please enter a second between 0 and 59: ");
        scanf("%d", &second);
    }

    struct tm time_travel = {0};
    time_travel.tm_year = year - 1900;
    time_travel.tm_mon = month - 1;
    time_travel.tm_mday = day;
    time_travel.tm_hour = hour;
    time_travel.tm_min = minute;
    time_travel.tm_sec = second;

    time_t travel_time = mktime(&time_travel);
    if (travel_time == -1) {
        printf("Error: unable to determine time.\n");
        return 1;
    }

    double time_difference = difftime(travel_time, t);
    if (time_difference < 0) {
        printf("Error: you cannot travel back in time.\n");
        return 1;
    }

    printf("\nBuckle up, we are about to travel through time!\n");
    printf("\nCurrent time: %s", asctime(now));
    printf("Target time: %s", asctime(&time_travel));
    printf("Time difference: %.0lf seconds\n\n", time_difference);

    int countdown = 10;
    while (countdown > 0) {
        printf("%d...\n", countdown);
        sleep(1);
        countdown--;
    }

    printf("\nArrived at destination time: %s", asctime(&time_travel));

    return 0;
}