//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Declare variables
    int randNum, month, day;

    // Get current date and time
    time_t currentTime;
    time(&currentTime);

    // Print the date and time
    printf("Current time is %s", ctime(&currentTime));

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random number between 1 and 100
    randNum = rand() % 100 + 1;

    // Get the birth month and day from the user
    printf("Enter your birth month (1-12): ");
    scanf("%d", &month);
    printf("Enter your birth day (1-31): ");
    scanf("%d", &day);

    // Determine the user's fortune based on the random number and birth date
    if (randNum < 25)
    {
        printf("You will find true love this year.\n");
    }
    else if (randNum < 50)
    {
        printf("You will come into a large sum of money.\n");
    }
    else if (randNum < 75)
    {
        if (month == 1 && day >= 20 || month == 2 && day <= 18)
        {
            printf("You will have great success in your career this year.\n");
        }
        else
        {
            printf("You will have great success in your personal life this year.\n");
        }
    }
    else
    {
        printf("You will experience a life-changing event in the near future.\n");
    }

    // Print a goodbye message
    printf("Goodbye! May your fortune be bright.\n");

    return 0;
}