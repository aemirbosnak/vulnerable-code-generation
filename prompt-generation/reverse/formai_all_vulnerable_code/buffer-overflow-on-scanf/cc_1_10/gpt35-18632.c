//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// function to convert a given time to seconds
int convertToSeconds(int hr, int min, int sec)
{
    return hr * 3600 + min * 60 + sec;
}

// function to convert a given seconds to time(hh:mm:ss)
void convertToTime(int seconds)
{
    int hr, min, sec;
    hr = seconds / 3600;
    seconds %= 3600;
    min = seconds / 60;
    sec = seconds % 60;
    printf("%.2d:%.2d:%.2d\n", hr, min, sec);
}

// function to simulate time travel
void timeTravel(int day, int month, int year, int hr, int min, int sec, int years)
{
    time_t now;
    time(&now); // get current time
    struct tm *local = localtime(&now);
    int current_year = local->tm_year + 1900; // get current year

    // calculate time difference
    int time_diff, current_time_in_sec, travel_time_in_sec;
    int travel_seconds = convertToSeconds(hr, min, sec);
    if (current_year < year + years)
    {
        time_diff = (year + years - current_year) * 31536000; // leap year not considered
        current_time_in_sec = convertToSeconds(local->tm_hour, local->tm_min, local->tm_sec);
        travel_time_in_sec = convertToSeconds(0, 0, 0) + convertToSeconds(24, 0, 0) - travel_seconds; // seconds left in the day
        time_diff += travel_time_in_sec - current_time_in_sec; // add remaining seconds of current day
    }
    else
        time_diff = 0; // time travel not possible
    
    // calculate new date and time
    time_t new_time = now + time_diff;
    struct tm *new_local = localtime(&new_time);
    printf("You have traveled %d years into the past or future and your new date and time is:\n", years);
    printf("%.2d-%.2d-%d ", day, month, year + years);
    convertToTime(travel_seconds);
}

int main()
{
    int day, month, year, hr, min, sec, years;
    printf("Enter the date and time you want to time travel to (dd-mm-yyyy hh:mm:ss): ");
    scanf("%d-%d-%d %d:%d:%d", &day, &month, &year, &hr, &min, &sec);
    printf("Enter the number of years you want to time travel: ");
    scanf("%d", &years);
    timeTravel(day, month, year, hr, min, sec, years);
    return 0;
}