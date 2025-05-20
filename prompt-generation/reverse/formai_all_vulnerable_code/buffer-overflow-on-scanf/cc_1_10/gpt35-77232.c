//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Welcome message
    printf("Welcome to the Automated Fortune Teller!\n");

    // Declare variables
    int randomNumber;
    char playAgain = 'y';

    // Seed the random number generator
    srand(time(NULL));

    while (playAgain == 'y')
    {
        // Generate a random number between 1 and 5
        randomNumber = rand() % 5 + 1;

        // Use random number to display a fortune
        switch (randomNumber)
        {
            case 1:
                printf("Your future looks bright!\n");
                break;
            case 2:
                printf("You will encounter a great opportunity soon.\n");
                break;
            case 3:
                printf("Your hard work will pay off in the near future.\n");
                break;
            case 4:
                printf("Take time to reflect on recent events, it will help you move forward.\n");
                break;
            case 5:
                printf("Be careful of those around you, some may not have your best interest at heart.\n");
                break;
            default:
                printf("Error: Invalid random number.\n");
        }

        // Ask if the user wants to play again
        printf("Would you like to play again? (y/n)\n");
        scanf(" %c", &playAgain);
    }

    // Goodbye message
    printf("Thank you for playing the Automated Fortune Teller. Goodbye!\n");

    return 0;
}