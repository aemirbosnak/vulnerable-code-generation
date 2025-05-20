//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    int current_year = tm->tm_year + 1900;
    int current_month = tm->tm_mon + 1;
    int current_day = tm->tm_mday;

    int travel_year, travel_month, travel_day;
    printf("Enter the year you want to travel to: ");
    scanf("%d", &travel_year);
    printf("Enter the month you want to travel to: ");
    scanf("%d", &travel_month);
    printf("Enter the day you want to travel to: ");
    scanf("%d", &travel_day);

    if (travel_year > current_year) {
        printf("Time travel not possible! You can't travel to the future.\n");
    } else if ((travel_year == current_year) && (travel_month > current_month)) {
        printf("Time travel not possible! You can't travel to the future.\n");
    } else if ((travel_year == current_year) && (travel_month == current_month) && (travel_day > current_day)) {
        printf("Time travel not possible! You can't travel to the future.\n");
    } else {
        printf("Time travel successful!\n");

        struct tm travel_time = {
            .tm_year = travel_year - 1900,
            .tm_mon = travel_month - 1,
            .tm_mday = travel_day,
            .tm_hour = tm->tm_hour,
            .tm_min = tm->tm_min,
            .tm_sec = tm->tm_sec
        };

        time_t travel_t = mktime(&travel_time);
        printf("You have successfully travelled to %s", asctime(&travel_time));

        // Perform some time travel actions here

        // And then return back to the current time
        printf("Returning back to current time.\n");

        time_t return_t = time(NULL);
        struct tm *return_tm = localtime(&return_t);
        printf("You have returned to %s", asctime(return_tm));
    }

    return 0;
}