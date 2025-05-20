//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t start_time = time(NULL); // get current time
    struct tm *now = localtime(&start_time); // convert to local time
    int current_year = now->tm_year + 1900; // extract current year
    int current_month = now->tm_mon + 1; // extract current month
    int current_day = now->tm_mday; // extract current day
    int current_hour = now->tm_hour; // extract current hour
    
    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("It is currently %02d:%02d on %02d/%02d/%d.\n",current_hour,now->tm_min,current_day,current_month,current_year);

    // prompt user for a year to travel to
    int travel_year;
    printf("Enter a year to travel to: ");
    scanf("%d",&travel_year);

    // check if travel year is valid
    if(travel_year >= current_year)
    {
        printf("\nInvalid year! Time travel is only possible to years before %d.\n", current_year);
    }
    else
    {
        // calculate time difference
        int time_diff = (current_year - travel_year) * 365*24; // assuming 365 days per year and 24 hours per day

        // prompt user for a month to travel to
        int travel_month;
        printf("Enter a month to travel to (1-12): ");
        scanf("%d",&travel_month);

        // check if travel month is valid
        if(travel_month < 1 || travel_month > 12)
        {
            printf("\nInvalid month! Please enter a value between 1 and 12.\n");
        }
        else
        {
            // adjust time difference based on month
            time_diff -= (travel_month - current_month) * 30*24; // assuming 30 days per month and 24 hours per day

            // prompt user for a day to travel to
            int travel_day;
            printf("Enter a day to travel to (1-31): ");
            scanf("%d",&travel_day);

            // check if travel day is valid
            if(travel_day < 1 || travel_day > 31)
            {
                printf("\nInvalid day! Please enter a value between 1 and 31.\n");
            }
            else
            {
                // adjust time difference based on day
                time_diff -= (travel_day - current_day) * 24; // assuming 24 hours per day

                // prompt user for an hour to travel to
                int travel_hour;
                printf("Enter an hour to travel to (0-23): ");
                scanf("%d",&travel_hour);

                // check if travel hour is valid
                if(travel_hour < 0 || travel_hour > 23)
                {
                    printf("\nInvalid hour! Please enter a value between 0 and 23.\n");
                }
                else
                {
                    // adjust time difference based on hour
                    time_diff -= (travel_hour - current_hour);

                    // calculate new time
                    time_t new_time = start_time - (time_diff*3600);
                    struct tm *new_now = localtime(&new_time); // convert to local time

                    // display travel results
                    printf("\nYou have traveled to %02d:%02d on %02d/%02d/%d!\n", travel_hour, new_now->tm_min, travel_day, travel_month, travel_year);
                }
            }
        }
    }

    return 0;
}