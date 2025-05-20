//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: shocked
#include <stdio.h>
#include <time.h>

int main()
{
    time_t currentTime, futureTime;
    int year, month, day, hour, minute, second;

    // Prompt user for their desired future date and time
    printf("Enter desired year (YYYY): ");
    scanf("%d", &year);
    printf("Enter desired month (1-12): ");
    scanf("%d", &month);
    printf("Enter desired day (1-31): ");
    scanf("%d", &day);
    printf("Enter desired hour (0-23): ");
    scanf("%d", &hour);
    printf("Enter desired minute (0-59): ");
    scanf("%d", &minute);
    printf("Enter desired second (0-59): ");
    scanf("%d", &second);

    // Convert user input to a future time_t value
    struct tm future = {0};
    future.tm_year = year - 1900;
    future.tm_mon = month - 1;
    future.tm_mday = day;
    future.tm_hour = hour;
    future.tm_min = minute;
    future.tm_sec = second;
    futureTime = mktime(&future);

    // Get current time
    currentTime = time(NULL);

    // Calculate time difference between current time and future time
    double timeDiff = difftime(futureTime, currentTime);

    if (timeDiff > 0)
    {
        printf("\nTraveling through time... \n");
        printf("You will arrive on %s", ctime(&futureTime));
        printf("\n");

        // Wait for the specified time
        while (difftime(futureTime, time(NULL)) > 0)
        {
            // Do nothing
        }

        printf("Welcome to the future! \n");
        printf("Current time: %s", ctime(&futureTime));
    }
    else if (timeDiff == 0)
    {
        printf("\nYou are already in the future! \n");
        printf("Current time: %s", ctime(&currentTime));
    }
    else
    {
        printf("\nYou missed your chance to travel through time :( \n");
        printf("Current time: %s", ctime(&currentTime));
    }

    return 0;
}