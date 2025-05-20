//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Get the current date and time
    time_t currentTime;
    struct tm *localTime;
    currentTime = time (NULL);
    localTime = localtime (&currentTime);

    int currentYear = localTime->tm_year + 1900;

    // Define the past date and time to travel to
    struct tm targetTime = {0};
    targetTime.tm_year = 1969 - 1900;  // year is 1969
    targetTime.tm_mon = 6 - 1;  // month is June
    targetTime.tm_mday = 20;  // day is 20th
    targetTime.tm_hour = 20;  // hour is 8 pm
    targetTime.tm_min = 17;  // minute is 17
    time_t targetTime_t = mktime(&targetTime);

    // Check if targetTime is after currentTime
    if (targetTime_t > currentTime) {
        printf("Error: Target time is in the future.\n");
        exit(EXIT_FAILURE);
    }

    // Calculate the time difference
    double timeDiff = difftime(currentTime, targetTime_t);

    // Print the time difference in various formats
    printf("Time difference between current time and target time:\n");
    printf("%.0f seconds\n", timeDiff);
    printf("%.2f minutes\n", timeDiff/60);
    printf("%.2f hours\n", timeDiff/3600);
    printf("%.2f days\n", timeDiff/86400);
    printf("%.2f years\n", timeDiff/31536000);

    // Save the current year, month, and day of the target time
    int targetYear = targetTime.tm_year + 1900;
    int targetMonth = targetTime.tm_mon + 1;
    int targetDay = targetTime.tm_mday;

    // Print the travel information
    printf("You have traveled back in time to %d-%02d-%02d %02d:%02d!\n",
           targetYear, targetMonth, targetDay, targetTime.tm_hour, targetTime.tm_min);

    // Time travel loop
    char travelMore;
    do {
        printf("Do you want to travel more? (y/n): ");
        scanf(" %c", &travelMore);
        if (travelMore == 'y' || travelMore == 'Y') {
            int year, month, day, hour, minute;
            printf("Enter the year to travel to (yyyy): ");
            scanf("%d", &year);
            printf("Enter the month to travel to (mm): ");
            scanf("%d", &month);
            printf("Enter the day to travel to (dd): ");
            scanf("%d", &day);
            printf("Enter the hour to travel to (hh): ");
            scanf("%d", &hour);
            printf("Enter the minute to travel to (mm): ");
            scanf("%d", &minute);

            // Create the target time struct
            struct tm targetTime2 = {0};
            targetTime2.tm_year = year - 1900;
            targetTime2.tm_mon = month - 1;
            targetTime2.tm_mday = day;
            targetTime2.tm_hour = hour;
            targetTime2.tm_min = minute;
            time_t targetTime_t2 = mktime(&targetTime2);

            // Check if targetTime is after currentTime
            if (targetTime_t2 > currentTime) {
                printf("Error: Target time is in the future.\n");
                continue;
            }

            // Calculate the time difference
            double timeDiff2 = difftime(currentTime, targetTime_t2);

            // Print the time difference
            int yearsDiff = (int) (timeDiff2/31536000);
            printf("Time difference between current time and target time:\n");
            printf("%.0f seconds\n", timeDiff2);
            printf("%.2f minutes\n", timeDiff2/60);
            printf("%.2f hours\n", timeDiff2/3600);
            printf("%.2f days\n", timeDiff2/86400);
            printf("%.2f years\n", timeDiff2/31536000);

            // Print the travel information
            printf("You have traveled back in time to %d-%02d-%02d %02d:%02d for about %d years!\n",
                   year, month, day, hour, minute, yearsDiff);

            // Adjust the current year
            currentYear -= yearsDiff;

        }
    } while (travelMore == 'y' || travelMore == 'Y');

    printf("You have returned to the present day of %d!\n", currentYear);

    return 0;
}