//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // initialize variables
    int current_year, target_year, increment, travel_time;
    int i, j;
    char choice;
    time_t timer;

    // get current year
    time(&timer);
    struct tm* current_time = localtime(&timer);
    current_year = current_time->tm_year + 1900;

    // display the current year
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Today's year is %d.\n\n", current_year);

    // get target year
    printf("Enter the year you want to travel to: ");
    scanf("%d", &target_year);

    // calculate travel time
    if (target_year > current_year)
    {
        printf("\nTraveling to the future...\n");
        travel_time = target_year - current_year;
        increment = 1;
    }
    else if (target_year < current_year)
    {
        printf("\nTraveling to the past...\n");
        travel_time = current_year - target_year;
        increment = -1;
    }
    else
    {
        printf("\nYou are already in the target year!\n");
        return 0;
    }

    // time travel animation
    for (i = 0; i < travel_time; i++)
    {
        printf("\nYear %d\n", current_year);

        // display animation (only for fun!)
        for (j = 0; j <= i*2; j++)
            printf("*");

        // update current year
        current_year += increment;

        // delay for 1 second (only for fun!)
        printf("\n");
        clock_t delay = 1000000;
        while (delay)
            delay--;
    }

    // time travel complete
    printf("\n\nWelcome to the year %d!\n", current_year);

    // ask for another trip
    printf("\nDo you want to travel again? (Y/N): ");
    getchar();
    scanf("%c", &choice);

    if (choice == 'Y' || choice == 'y')
        main();

    return 0;
}