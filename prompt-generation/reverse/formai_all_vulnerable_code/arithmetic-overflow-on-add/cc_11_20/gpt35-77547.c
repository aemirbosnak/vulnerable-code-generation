//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year, month, day;   // variables to store the date
    int hour, minute, second; // variables to store the time

    printf("Welcome to the Time Travel Simulator! \n");
    printf("Please enter a date (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &year, &month, &day);

    printf("Please enter a time (HH:MM:SS): ");
    scanf("%d:%d:%d", &hour, &minute, &second);

    printf("\nYou have entered the date and time: %d-%d-%d %d:%d:%d \n", year, month, day, hour, minute, second);

    // check if the date and time are valid
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31 || hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59)
    {
        printf("Invalid date or time entered. Please try again. \n");
        return 0;
    }

    // calculate the total number of seconds since epoch time (Jan 1, 1970)
    long int total_seconds = (year - 1970) * 31536000 + (month - 1) * 2678400 + (day - 1) * 86400 + hour * 3600 + minute * 60 + second;

    // ask the user how many seconds they wish to travel through time
    int time_travel;
    printf("\nHow many seconds would you like to travel through time? ");
    scanf("%d", &time_travel);

    // calculate the new timestamp after traveling through time
    long int new_timestamp = total_seconds + time_travel;

    // calculate the new date and time
    int new_year = 1970 + new_timestamp / 31536000;
    new_timestamp = new_timestamp % 31536000;
    int new_month = new_timestamp / 2678400 + 1;
    new_timestamp = new_timestamp % 2678400;
    int new_day = new_timestamp / 86400 + 1;
    new_timestamp = new_timestamp % 86400;
    int new_hour = new_timestamp / 3600;
    new_timestamp = new_timestamp % 3600;
    int new_minute = new_timestamp / 60;
    int new_second = new_timestamp % 60;

    // display the new date and time
    printf("\nAfter traveling through time, you have arrived at: %d-%d-%d %d:%d:%d \n", new_year, new_month, new_day, new_hour, new_minute, new_second);

    return 0;
}