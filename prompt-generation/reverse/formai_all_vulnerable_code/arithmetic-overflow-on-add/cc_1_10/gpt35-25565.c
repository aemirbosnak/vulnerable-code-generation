//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);

    int year = tm_now->tm_year + 1900;  // current year
    int month = tm_now->tm_mon + 1;  // current month
    int day = tm_now->tm_mday;  // current day

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Today is %02d/%02d/%d\n\n", month, day, year);

    int future_year, future_month, future_day;
    printf("Enter the future date you would like to visit (YYYY/MM/DD): ");
    scanf("%d/%d/%d", &future_year, &future_month, &future_day);

    time_t future = time(NULL);
    struct tm *tm_future = localtime(&future);
    tm_future->tm_year = future_year - 1900;
    tm_future->tm_mon = future_month - 1;
    tm_future->tm_mday = future_day;

    // calculate the number of seconds between now and the future date
    double seconds_between = difftime(mktime(tm_future), now);

    // travel to the future
    time_t future_time = now + (int)seconds_between;
    struct tm *tm_future_time = localtime(&future_time);

    printf("\nTraveling to %02d/%02d/%d...\n", future_month, future_day, future_year);
    printf("You have arrived at %02d:%02d:%02d on %02d/%02d/%d\n", tm_future_time->tm_hour,
           tm_future_time->tm_min, tm_future_time->tm_sec, future_month, future_day, future_year);

    int past_year, past_month, past_day;
    printf("\nEnter the past date you would like to visit (YYYY/MM/DD): ");
    scanf("%d/%d/%d", &past_year, &past_month, &past_day);

    time_t past = time(NULL);
    struct tm *tm_past = localtime(&past);
    tm_past->tm_year = past_year - 1900;
    tm_past->tm_mon = past_month - 1;
    tm_past->tm_mday = past_day;

    // calculate the number of seconds between now and the past date
    double seconds_past = difftime(mktime(tm_past), now);

    // travel to the past
    time_t past_time = now - (int)seconds_past;
    struct tm *tm_past_time = localtime(&past_time);

    printf("\nTraveling to %02d/%02d/%d...\n", past_month, past_day, past_year);
    printf("You have arrived at %02d:%02d:%02d on %02d/%02d/%d\n", tm_past_time->tm_hour,
           tm_past_time->tm_min, tm_past_time->tm_sec, past_month, past_day, past_year);

    printf("\nThanks for using the Time Travel Simulator!\n");

    return 0;
}