//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Time travel simulator!

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get the current time
    time_t now = time(NULL);
    struct tm *now_tm = localtime(&now);

    // Display the current time
    printf("Current time: %s", asctime(now_tm));

    // Get the year, month, and day
    int year = now_tm->tm_year + 1900;
    int month = now_tm->tm_mon + 1;
    int day = now_tm->tm_mday;

    // Get the hour, minute, and second
    int hour = now_tm->tm_hour;
    int minute = now_tm->tm_min;
    int second = now_tm->tm_sec;

    // Get the day of the week
    int day_of_week = now_tm->tm_wday;

    // Convert the day of the week to a string
    char *day_of_week_str;
    switch (day_of_week) {
        case 0:
            day_of_week_str = "Sunday";
            break;
        case 1:
            day_of_week_str = "Monday";
            break;
        case 2:
            day_of_week_str = "Tuesday";
            break;
        case 3:
            day_of_week_str = "Wednesday";
            break;
        case 4:
            day_of_week_str = "Thursday";
            break;
        case 5:
            day_of_week_str = "Friday";
            break;
        case 6:
            day_of_week_str = "Saturday";
            break;
    }

    // Display the day of the week
    printf("Day of the week: %s\n", day_of_week_str);

    // Get a random number for the year
    int random_year = rand() % 10000 + 1;

    // Get a random number for the month
    int random_month = rand() % 12 + 1;

    // Get a random number for the day
    int random_day = rand() % 31 + 1;

    // Get a random number for the hour
    int random_hour = rand() % 24;

    // Get a random number for the minute
    int random_minute = rand() % 60;

    // Get a random number for the second
    int random_second = rand() % 60;

    // Create a new time structure with the random values
    struct tm random_tm = {
        .tm_year = random_year - 1900,
        .tm_mon = random_month - 1,
        .tm_mday = random_day,
        .tm_hour = random_hour,
        .tm_min = random_minute,
        .tm_sec = random_second,
    };

    // Convert the new time structure to a time_t value
    time_t random_time = mktime(&random_tm);

    // Display the random time
    printf("Random time: %s", asctime(&random_tm));

    // Calculate the time difference between the current time and the random time
    time_t time_difference = random_time - now;

    // Display the time difference
    printf("Time difference: %ld seconds\n", time_difference);

    // Convert the time difference to days, hours, minutes, and seconds
    int days = time_difference / (60 * 60 * 24);
    int hours = (time_difference % (60 * 60 * 24)) / (60 * 60);
    int minutes = (time_difference % (60 * 60)) / 60;
    int seconds = time_difference % 60;

    // Display the time difference in days, hours, minutes, and seconds
    printf("Time difference: %d days, %d hours, %d minutes, and %d seconds\n", days, hours, minutes, seconds);

    return 0;
}