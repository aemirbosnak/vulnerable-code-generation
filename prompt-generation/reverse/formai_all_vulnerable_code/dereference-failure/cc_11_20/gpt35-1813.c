//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t currentTime;
    struct tm *timeInfo;
    char dateString[30];
    
    time(&currentTime);
    timeInfo = localtime(&currentTime);

    printf("Current time: %s\n", asctime(timeInfo));

    printf("Enter the year you want to travel to: ");
    int year;
    scanf("%d", &year);
    if(year < 1970)
    {
        printf("Error: The time machine can only travel to years after 1970.\n");
        return 1;
    }

    int month;
    printf("Enter the month you want to travel to (1-12): ");
    scanf("%d", &month);
    if(month < 1 || month > 12)
    {
        printf("Error: Invalid month.\n");
        return 1;
    }

    int day;
    printf("Enter the day you want to travel to (1-31): ");
    scanf("%d", &day);
    if(day < 1 || day > 31)
    {
        printf("Error: Invalid day.\n");
        return 1;
    }

    int hour;
    printf("Enter the hour you want to travel to (0-23): ");
    scanf("%d", &hour);
    if(hour < 0 || hour > 23)
    {
        printf("Error: Invalid hour.\n");
        return 1;
    }

    int minute;
    printf("Enter the minute you want to travel to (0-59): ");
    scanf("%d", &minute);
    if(minute < 0 || minute > 59)
    {
        printf("Error: Invalid minute.\n");
        return 1;
    }

    int second;
    printf("Enter the second you want to travel to (0-59): ");
    scanf("%d", &second);
    if(second < 0 || second > 59)
    {
        printf("Error: Invalid second.\n");
        return 1;
    }

    timeInfo->tm_year = year - 1900;
    timeInfo->tm_mon = month - 1;
    timeInfo->tm_mday = day;
    timeInfo->tm_hour = hour;
    timeInfo->tm_min = minute;
    timeInfo->tm_sec = second;

    currentTime = mktime(timeInfo);

    printf("Travelling through time...");
    for(int i = 0; i < 10; i++)
    {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("\n");

    timeInfo = localtime(&currentTime);
    strftime(dateString, sizeof(dateString), "%c", timeInfo);
    printf("You have arrived in %s\n", dateString);

    return 0;
}