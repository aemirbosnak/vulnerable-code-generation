//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Enter the year you wish to travel to: ");
    int targetYear;
    scanf("%d", &targetYear);

    time_t currTime;
    struct tm *currentTimeInfo;
    time(&currTime);
    currentTimeInfo = localtime(&currTime);

    int currYear = currentTimeInfo->tm_year + 1900;
    int currMonth = currentTimeInfo->tm_mon + 1;
    int currDay = currentTimeInfo->tm_mday;
    int currHour = currentTimeInfo->tm_hour;
    int currMinute = currentTimeInfo->tm_min;
    int currSecond = currentTimeInfo->tm_sec;

    if (targetYear > currYear)
    {
        printf("Sorry, time travel to the future is not possible.\n");
        printf("Please enter a year in the past: ");
        scanf("%d", &targetYear);
    }

    printf("Traveling to the year %d...\n\n", targetYear);

    while (currYear > targetYear)
    {
        currYear--;
        printf("%d\n", currYear);
        printf("One year has passed.\n");
    }

    printf("\nArrived in the year %d.\n\n", targetYear);

    printf("Current date and time is: %d/%d/%d %d:%02d:%02d.\n", currDay, currMonth, currYear, currHour, currMinute, currSecond);
    printf("Do you want to change the date and time? (y/n): ");

    char input;
    fflush(stdin);
    scanf("%c", &input);

    if (input == 'y' || input == 'Y')
    {
        printf("Please enter the new date and time in the following format: yyyy-mm-dd HH:MM:SS.\n");
        printf("Example: 1969-07-20 20:17:40 for the moon landing.\n");

        char datetimeStr[20];
        scanf("%s", datetimeStr);

        struct tm newTimeInfo;
        strptime(datetimeStr, "%Y-%m-%d %H:%M:%S", &newTimeInfo);

        currYear = newTimeInfo.tm_year + 1900;
        currMonth = newTimeInfo.tm_mon + 1;
        currDay = newTimeInfo.tm_mday;
        currHour = newTimeInfo.tm_hour;
        currMinute = newTimeInfo.tm_min;
        currSecond = newTimeInfo.tm_sec;

        printf("Date and time has been updated to: %d/%d/%d %d:%02d:%02d.\n", currDay, currMonth, currYear, currHour, currMinute, currSecond);
    }

    printf("Thank you for using the Time Travel Simulator!\n");

    return 0;
}