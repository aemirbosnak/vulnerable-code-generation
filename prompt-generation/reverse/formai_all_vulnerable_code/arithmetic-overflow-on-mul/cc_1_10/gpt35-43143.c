//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Time Travel Simulator! \n");

    // Getting the current time
    time_t current_time;
    time(&current_time);
    printf("Your current date and time is: %s", ctime(&current_time));

    // Asking the user for a year to travel to
    int year;
    printf("Enter a year to travel to: ");
    scanf("%d", &year);

    if (year < 2021)
    {
        printf("You can't travel to the past! \n");
        exit(0);
    }
    else
    {
        printf("Calculating time travel... \n");

        // Adding the difference of years to the current time
        int year_diff = year - 2021;
        time_t travel_time = current_time + (year_diff * 31556926);

        printf("You have traveled to the year %d! \n", year);
        printf("The date and time in that year is: %s", ctime(&travel_time));

        // Randomizing an event in the future
        if (year > 2021)
        {
            srand(time(NULL));
            int event = rand() % 3;
            switch (event)
            {
                case 0:
                    printf("You have arrived at a peaceful time. Enjoy your trip! \n");
                    break;

                case 1:
                    printf("You have arrived at a time of war. Be careful! \n");
                    break;

                case 2:
                    printf("You have arrived at a time of great technological advancement. \n");
                    break;

                default:
                    printf("Something went wrong with the time-space continuum... \n");
                    break;
            }
        }
    }

    printf("Thank you for using the Time Travel Simulator! \n");
    return 0;
}