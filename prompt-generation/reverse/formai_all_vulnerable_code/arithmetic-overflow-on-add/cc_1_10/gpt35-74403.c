//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <time.h>

int main() {
    // set the seed for the random number generator
    srand(time(NULL));

    // generate a random year between 2020 and 2050
    int target_year = rand() % (2050 - 2020 + 1) + 2020;

    // generate a random month, day, and hour
    int target_month = rand() % 12 + 1;
    int target_day = rand() % 31 + 1;
    int target_hour = rand() % 24;

    // print the target date and time
    printf("You wake up in a post-apocalyptic wasteland. You check your time machine and realize you can travel back to: %d-%02d-%02d %02d:00:00\n", target_year, target_month, target_day, target_hour);

    // get the current date and time
    time_t current_time = time(NULL);
    struct tm * current_tm = localtime(&current_time);

    // calculate the difference between the target year and the current year
    int year_diff = target_year - current_tm->tm_year - 1900;

    // calculate the difference between the target month and the current month
    int month_diff = target_month - current_tm->tm_mon - 1;

    // calculate the difference between the target day and the current day
    int day_diff = target_day - current_tm->tm_mday;

    // calculate the difference between the target hour and the current hour
    int hour_diff = target_hour - current_tm->tm_hour;

    // print the time remaining until the target date and time
    printf("Time Remaining:\n");
    printf("%d years\n", year_diff);
    printf("%d months\n", month_diff);
    printf("%d days\n", day_diff);
    printf("%d hours\n", hour_diff);

    // travel through time
    time_t target_time = current_time + (year_diff * 31536000) + (month_diff * 2592000) + (day_diff * 86400) + (hour_diff * 3600);
    struct tm * target_tm = localtime(&target_time);

    // print the new date and time
    printf("You arrive at: %d-%02d-%02d %02d:00:00\n", target_tm->tm_year + 1900, target_tm->tm_mon + 1, target_tm->tm_mday, target_tm->tm_hour);

    return 0;
}