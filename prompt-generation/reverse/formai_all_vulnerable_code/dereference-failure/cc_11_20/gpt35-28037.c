//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    struct tm current_time = {0};
    time_t now = time(NULL);
    current_time = *localtime(&now);
    int year, month, day;

    printf("Welcome to the Time Travel Simulator.\n\n");
    printf("Enter your desired travel year (1900 to 2200): ");
    scanf("%d", &year);
    printf("Enter your desired travel month (1 to 12): ");
    scanf("%d", &month);
    printf("Enter your desired travel day (1 to 31): ");
    scanf("%d", &day);

    if (year < 1900 || year > 2200 || month < 1 || month > 12 || day < 1 || day > 31)
    {
        printf("Invalid input. Please try again.\n");
        return 1;
    }

    struct tm travel_time = {0};
    travel_time.tm_year = year - 1900;
    travel_time.tm_mon = month - 1;
    travel_time.tm_mday = day;

    time_t current_unix_time = mktime(&current_time);
    time_t travel_unix_time = mktime(&travel_time);

    if (travel_unix_time < current_unix_time)
    {
        printf("You cannot travel back in time. Please select a future date.\n");
        return 1;
    }

    long time_difference = difftime(travel_unix_time, current_unix_time);

    printf("You have selected to travel to %d-%02d-%02d.\n", year, month, day);
    printf("Time travel initiated. Please wait...\n\n");

    for (int i = 10; i >= 0; i--)
    {
        printf("%d...\n", i);
        sleep(1);
    }

    printf("\nYou have arrived at %d-%02d-%02d!\n", year, month, day);
    printf("Time difference: ");

    if (time_difference / 60 / 60 / 24 > 365)
    {
        printf("%ld years, ", time_difference / 60 / 60 / 24 / 365);
        time_difference %= 60 * 60 * 24 * 365;
    }

    if (time_difference / 60 / 60 / 24 <= 365 && time_difference / 60 / 60 / 24 > 0)
    {
        printf("%ld days, ", time_difference / 60 / 60 / 24);
        time_difference %= 60 * 60 * 24;
    }

    if (time_difference / 60 / 60 > 0)
    {
        printf("%ld hours, ", time_difference / 60 / 60);
        time_difference %= 60 * 60;
    }

    if (time_difference / 60 > 0)
    {
        printf("%ld minutes, and ", time_difference / 60);
        time_difference %= 60;
    }

    printf("%ld seconds.\n", time_difference);

    return 0;
}