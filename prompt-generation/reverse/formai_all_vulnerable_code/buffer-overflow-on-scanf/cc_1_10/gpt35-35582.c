//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int presentYear, futureYear, pastYear, choice, years, randomYear, i;
    time_t presentTime;
    struct tm *localTime;

    // get the present year
    time(&presentTime);
    localTime = localtime(&presentTime);
    presentYear = localTime->tm_year + 1900;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("-------------------------------------\n\n");

    printf("What would you like to do?\n");
    printf("1. Travel to the future\n");
    printf("2. Travel to the past\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("\nEnter the number of years you want to travel into the future: ");
            scanf("%d", &years);

            futureYear = presentYear + years;

            printf("\nYou have traveled %d years into the future!\n", years);
            printf("The current year is %d and the future year is %d.\n", presentYear, futureYear);

            break;

        case 2:
            printf("\nEnter the number of years you want to travel into the past: ");
            scanf("%d", &years);

            pastYear = presentYear - years;

            printf("\nYou have traveled %d years into the past!\n", years);
            printf("The current year is %d and the past year is %d.\n", presentYear, pastYear);

            break;

        default:
            printf("\nInvalid choice!\n");
            exit(1);
    }

    printf("\nWould you like to travel to a random year? (y/n): ");
    char answer;
    scanf(" %c", &answer);

    if(answer == 'y' || answer == 'Y')
    {
        // generate a random year between 1900 and present year
        srand(time(NULL));
        randomYear = rand() % (presentYear - 1900) + 1900;

        printf("\nYou have traveled to a random year: %d\n", randomYear);

        if(randomYear > presentYear)
        {
            printf("You have traveled %d years into the future.\n", randomYear - presentYear);
        }
        else if(randomYear < presentYear)
        {
            printf("You have traveled %d years into the past.\n", presentYear - randomYear);
        }
        else
        {
            printf("You have traveled to the present year!\n");
        }
    }

    printf("\nThank you for using the Time Travel Simulator!\n");

    return 0;
}