//FormAI DATASET v1.0 Category: Date and time ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t currentTime;
    struct tm *localTime;

    time( &currentTime );                   // Get the current time
    localTime = localtime( &currentTime );  // Convert the current time to the local time

    int month, year, j, k, q, h, dayOfWeek, daysInMonth;
    month = localTime->tm_mon + 1;           // Get the current month
    year = localTime->tm_year + 1900;        // Get the current year

    if(month == 1 || month == 2)             // Adjust the month and year for January and February
    {
        month += 12;
        year--;
    }

    j = year / 100;
    k = year % 100;
    q = 13 * (month + 1);
    q = q / 5;
    h = k + k/4 + j/4;
    h = h + (q + localTime->tm_mday + 365 * year);
    dayOfWeek = h % 7;

    printf("Today is ");
    switch(dayOfWeek)
    {
        case 0:
            printf("Sunday");
            break;
        case 1:
            printf("Monday");
            break;
        case 2:
            printf("Tuesday");
            break;
        case 3:
            printf("Wednesday");
            break;
        case 4:
            printf("Thursday");
            break;
        case 5:
            printf("Friday");
            break;
        case 6:
            printf("Saturday");
            break;
    }
    printf(", %d/%d/%d\n\n", localTime->tm_mon + 1, localTime->tm_mday, localTime->tm_year + 1900);

    // Determine the number of days in the current month
    switch(month)
    {
        case 14:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            daysInMonth = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            daysInMonth = 30;
            break;
        case 2:
            // Determine if it is a leap year
            if(year % 4 == 0)
            {
                if(year % 100 == 0)
                {
                    if(year % 400 == 0)
                        daysInMonth = 29;
                    else
                        daysInMonth = 28;
                }
                else
                    daysInMonth = 29;
            }
            else
                daysInMonth = 28;
            break;
    }

    int i, count = 1;
    printf("  S  M  T  W  T  F  S\n");
    for(i = 0; i < dayOfWeek; i++)       // Print empty space before the first day of the month
        printf("   ");
    for(i = 1; i <= daysInMonth; i++)    // Print the days of the month
    {
        if(count % 7 == 0)              // Start a new line every 7 days
            printf("\n");
        printf("%3d", i);
        count++;
    }
    printf("\n");

    return 0;
}