//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to travel to a random year
void timeTravel()
{
    // get current time
    time_t currentTime;
    time(&currentTime);

    // convert to struct tm format
    struct tm *localTime = localtime(&currentTime);

    // set the minimum and maximum range for time travel
    int minYear = 1800;
    int maxYear = 2200;

    // generate a random year
    int randomYear = rand() % (maxYear - minYear + 1) + minYear;

    // set the new date to the random year and the current month and day
    struct tm newTime = {0};
    newTime.tm_year = randomYear - 1900;
    newTime.tm_mon = localTime->tm_mon;
    newTime.tm_mday = localTime->tm_mday;
  
    // convert back and print new date
    time_t newTime_t = mktime(&newTime);
    printf("You have time traveled to the year %d!\n", randomYear);
    printf("The date is now: %s", ctime(&newTime_t));
}

int main()
{
    printf("Welcome to the Time Travel Simulator!\n\n");

    // seed random number generator
    srand(time(NULL));

    char choice;
    do
    {
        printf("Would you like to travel through time? (Y/N): ");
        scanf(" %c", &choice);

        if (choice == 'Y' || choice == 'y')
        {
            timeTravel();
        }
        else if (choice == 'N' || choice == 'n')
        {
            printf("Thanks for using the Time Travel Simulator!\n");
        }
        else
        {
            printf("Invalid choice, please try again.\n");
        }
    } while (choice != 'N' && choice != 'n');

    return 0;
}