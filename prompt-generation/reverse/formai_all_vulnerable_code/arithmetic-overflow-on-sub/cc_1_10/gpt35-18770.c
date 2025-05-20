//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function to convert date to timestamp
long long dateTimeToTimeStamp(int year, int month, int day, int hour, int minute, int second)
{
    struct tm timeinfo = {0};
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = day;
    timeinfo.tm_hour = hour;
    timeinfo.tm_min = minute;
    timeinfo.tm_sec = second;
    return (long long)mktime(&timeinfo);
}

// function to convert timestamp to date
void timeStampToDateTime(long long timestamp, int *year, int *month, int *day, int *hour, int *minute, int *second)
{
    struct tm *timeinfo = localtime((time_t*)&timestamp);
    *year = timeinfo->tm_year + 1900;
    *month = timeinfo->tm_mon + 1;
    *day = timeinfo->tm_mday;
    *hour = timeinfo->tm_hour;
    *minute = timeinfo->tm_min;
    *second = timeinfo->tm_sec;
}

// main function
int main()
{
    int option, year, month, day, hour, minute, second;
    long long timestamp;
    char buffer[100];
    time_t now = time(NULL);

    // display current time
    strftime(buffer, 100, "%Y-%m-%d %H:%M:%S", localtime(&now));
    printf("Current time is %s\n", buffer);

    // display menu
    printf("\nMENU\n");
    printf("1. Travel Back in Time\n");
    printf("2. Travel Forward in Time\n");
    printf("3. Exit\n");

    while(1)
    {
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("\nEnter date and time to travel back to (yyyy/mm/dd hh:mm:ss): ");
                scanf("%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);
                timestamp = dateTimeToTimeStamp(year, month, day, hour, minute, second);
                if (now >= timestamp)
                {
                    timeStampToDateTime(timestamp, &year, &month, &day, &hour, &minute, &second);
                    strftime(buffer, 100, "%Y-%m-%d %H:%M:%S", localtime(&timestamp));
                    printf("\nTravelling back in time to %s\n", buffer);
                }
                else
                {
                    printf("\nCannot travel back in time to the future!\n");
                }
                break;

            case 2:
                printf("\nEnter date and time to travel forward to (yyyy/mm/dd hh:mm:ss): ");
                scanf("%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);
                timestamp = dateTimeToTimeStamp(year, month, day, hour, minute, second);
                if (now <= timestamp)
                {
                    timeStampToDateTime(timestamp, &year, &month, &day, &hour, &minute, &second);
                    strftime(buffer, 100, "%Y-%m-%d %H:%M:%S", localtime(&timestamp));
                    printf("\nTravelling forward in time to %s\n", buffer);
                }
                else
                {
                    printf("\nCannot travel forward in time to the past!\n");
                }
                break;

            case 3:
                printf("\nThank you for using Time Travel Simulator!\n");
                exit(0);

            default:
                printf("\nInvalid option! Please try again.\n");
        }
    }

    return 0;
}