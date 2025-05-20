//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    time_t current_time;
    struct tm *timeinfo;
    int years;
    int days;
    int months;
    int hours;
    int minutes;
    int seconds;
    int daysOfMonth;
    int newDay;
    int newMonth;
    int newYear;

    // set the current time to the current system time
    time(&current_time);

    // get the current time as a structure in local time
    timeinfo = localtime(&current_time);

    printf("Current date and time: %s", asctime(timeinfo));

    // ask user how many years they want to go back or forward in time
    printf("Enter the number of years you want to go back or forward in time:\n");
    scanf("%d", &years);

    // ask user how many months they want to go back or forward in time
    printf("Enter the number of months you want to go back or forward in time:\n");
    scanf("%d", &months);

    // ask user how many days they want to go back or forward in time
    printf("Enter the number of days you want to go back or forward in time:\n");
    scanf("%d", &days);

    // ask user how many hours they want to go back or forward in time
    printf("Enter the number of hours you want to go back or forward in time:\n");
    scanf("%d", &hours);

    // ask user how many minutes they want to go back or forward in time
    printf("Enter the number of minutes you want to go back or forward in time:\n");
    scanf("%d", &minutes);

    // ask user how many seconds they want to go back or forward in time
    printf("Enter the number of seconds you want to go back or forward in time:\n");
    scanf("%d", &seconds);

    // Calculate the new year, months and days from the given input
    newDay = timeinfo->tm_mday + days;
    newMonth = timeinfo->tm_mon + months;
    newYear = timeinfo->tm_year + years;

    // handle the case when the new month exceeds 12 months in a year
    if(newMonth > 11)
    {
        newYear += (newMonth / 12);
        newMonth = newMonth % 12;
    }

    // get the number of days in the new month
    switch(newMonth)
    {
        case 0:
            daysOfMonth = 31;
            break;
        case 1:
            if(newYear%4 == 0)
                daysOfMonth = 29;
            else
                daysOfMonth = 28;
            break;
        case 2:
            daysOfMonth = 31;
            break;
        case 3:
            daysOfMonth = 30;
            break;
        case 4:
            daysOfMonth = 31;
            break;
        case 5:
            daysOfMonth = 30;
            break;
        case 6:
            daysOfMonth = 31;
            break;
        case 7:
            daysOfMonth = 31;
            break;
        case 8:
            daysOfMonth = 30;
            break;
        case 9:
            daysOfMonth = 31;
            break;
        case 10:
            daysOfMonth = 30;
            break;
        case 11:
            daysOfMonth = 31;
            break;
    }

    // handle the case when the new day exceeds the number of days in the month
    if(newDay > daysOfMonth)
    {
        newDay -= daysOfMonth;
        newMonth++;
    }

    // update the struct tm with the new date and time
    timeinfo->tm_year = newYear;
    timeinfo->tm_mon = newMonth;
    timeinfo->tm_mday = newDay;
    timeinfo->tm_hour += hours;
    timeinfo->tm_min += minutes;
    timeinfo->tm_sec += seconds;

    // normalize the time
    mktime(timeinfo);

    printf("New date and time: %s", asctime(timeinfo));

    return 0;
}