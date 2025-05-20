//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t now = time(NULL); // get the current time
    struct tm *timeinfo = localtime(&now); // convert to local time
    int year = timeinfo->tm_year + 1900; // get current year
    int month = timeinfo->tm_mon + 1; // get current month
    int day = timeinfo->tm_mday; // get current day

    printf("Welcome to the Time Travel Simulator 3000!\n");
    printf("Today is %d/%d/%d\n", day, month, year);

    int travel_year, travel_month, travel_day;

    // prompt user to enter travel date
    printf("Enter the year you want to travel to: ");
    scanf("%d", &travel_year);
    printf("Enter the month you want to travel to: ");
    scanf("%d", &travel_month);
    printf("Enter the day you want to travel to: ");
    scanf("%d", &travel_day);

    time_t travel_time;
    struct tm *travel_timeinfo;
    travel_timeinfo = localtime(&travel_time);
    travel_timeinfo->tm_year = travel_year - 1900;
    travel_timeinfo->tm_mon = travel_month - 1;
    travel_timeinfo->tm_mday = travel_day;
    travel_timeinfo->tm_hour = 0;
    travel_timeinfo->tm_min = 0;
    travel_timeinfo->tm_sec = 0;
    travel_time = mktime(travel_timeinfo);

    // calculate time difference
    double diff = difftime(travel_time, now);

    if (diff < 0) {
        printf("Time travel not possible! You can't travel back in time!\n");
        return 0;
    }

    printf("Preparing for time travel...\n");
    printf("5..\n");
    sleep(1);
    printf("4..\n");
    sleep(1);
    printf("3..\n");
    sleep(1);
    printf("2..\n");
    sleep(1);
    printf("1..\n");
    sleep(1);

    printf("Time travel successful! You have arrived on %d/%d/%d\n", travel_day, travel_month, travel_year);

    return 0;
}