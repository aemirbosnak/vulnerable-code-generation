//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: happy
#include <stdio.h>
#include <time.h>

void travel(int year, int month, int day, int hour, int min, int sec)
{
    struct tm epoch = {0}; // Set all elements of struct tm to zero
    epoch.tm_year = year - 1900;  // Year since 1900
    epoch.tm_mon = month - 1; // Month (0-11)
    epoch.tm_mday = day; // Day of the month (1-31)
    epoch.tm_hour = hour; // Hour since midnight (0-23)
    epoch.tm_min = min; // Minutes after the hour (0-59)
    epoch.tm_sec = sec; // Seconds after the minute (0-60)

    time_t epochTime = mktime(&epoch); // Convert struct tm to time_t

    time_t currentTime = time(NULL); // Get current time in seconds since 1970

    if (epochTime < currentTime) // Check if travel time is in the past
    {
        printf("Sorry, you cannot travel back in time.\n");
        return;
    }

    printf("You have just traveled to %s", ctime(&epochTime)); // Print new date and time
}

int main()
{
    printf("Welcome to the time travel simulator!\n\n");

    int year, month, day, hour, min, sec;

    printf("Enter the year you want to travel to: ");
    scanf("%d", &year); // Get year

    printf("Enter the month you want to travel to (1-12): ");
    scanf("%d", &month); // Get month

    printf("Enter the day you want to travel to (1-31): ");
    scanf("%d", &day); // Get day

    printf("Enter the hour you want to travel to (0-23): ");
    scanf("%d", &hour); // Get hour

    printf("Enter the minute you want to travel to (0-59): ");
    scanf("%d", &min); // Get minute

    printf("Enter the second you want to travel to (0-60): ");
    scanf("%d", &sec); // Get second

    printf("\nTraveling through time...\n\n");

    travel(year, month, day, hour, min, sec); // Travel to selected time

    printf("\nThank you for using the time travel simulator, come back anytime!\n");

    return 0;
}