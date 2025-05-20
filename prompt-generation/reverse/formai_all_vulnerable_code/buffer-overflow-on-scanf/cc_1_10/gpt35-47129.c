//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); // seed random number generator with the current time

    char user_input;

    printf("Welcome to the Fortune Teller!\n");
    printf("Please enter 'Y' to receive your fortune or 'N' to quit: ");

    scanf(" %c", &user_input);

    while (user_input == 'Y')
    {
        int random_number = rand() % 6; // generate a random number between 0 and 5

        switch (random_number)
        {
            case 0:
                printf("\nYou will have a great day today.\n");
                break;
            case 1:
                printf("\nYou will meet a special someone soon.\n");
                break;
            case 2:
                printf("\nGood news is headed your way.\n");
                break;
            case 3:
                printf("\nMoney is in your future!\n");
                break;
            case 4:
                printf("\nYou will achieve one of your goals soon.\n");
                break;
            case 5:
                printf("\nAn unexpected opportunity will come your way.\n");
                break;
            default:
                printf("\nOops! Something went wrong...\n");
        }

        // ask user if they want another fortune
        printf("\nDo you want another fortune? Enter 'Y' for yes or 'N' for no: ");
        scanf(" %c", &user_input);
    }

    printf("\nThank you for using the Fortune Teller!\n");

    return 0;
}