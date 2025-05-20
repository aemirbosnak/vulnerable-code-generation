//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    printf("Welcome to the Date Converter Program!\n\n");

    // User input
    char user_input[50];
    printf("Please enter a date in natural language format (e.g. tomorrow, next Monday): ");
    fgets(user_input, 50, stdin);

    // Time variables
    time_t current_time;
    struct tm *time_info;
    char date_buffer[50];

    // Get current time
    time(&current_time);
    time_info = localtime(&current_time);

    // Add time offset
    int offset = 0;
    if (strstr(user_input, "tomorrow"))
    {
        offset = 86400;
    }
    else if (strstr(user_input, "next week"))
    {
        offset = 604800;
    }
    else if (strstr(user_input, "next month"))
    {
        // Calculate number of days in next month
        int days_in_month;
        if (time_info->tm_mon == 11)
        {
            days_in_month = 31;
        }
        else if (time_info->tm_mon == 1)
        {
            if (((time_info->tm_year + 1900) % 4 == 0 && (time_info->tm_year + 1900) % 100 != 0) || (time_info->tm_year + 1900) % 400 == 0)
            {
                days_in_month = 29;
            }
            else
            {
                days_in_month = 28;
            }
        }
        else if (time_info->tm_mon == 3 || time_info->tm_mon == 5 || time_info->tm_mon == 8 || time_info->tm_mon == 10)
        {
            days_in_month = 30;
        }
        else
        {
            days_in_month = 31;
        }
        offset = days_in_month * 86400;
    }

    // Convert time to epoch time
    current_time = current_time + offset;
    time_info = localtime(&current_time);

    // Format date
    strftime(date_buffer, 50, "%A, %B %d, %Y", time_info);
    printf("The converted date is: %s\n", date_buffer);

    return 0;
}