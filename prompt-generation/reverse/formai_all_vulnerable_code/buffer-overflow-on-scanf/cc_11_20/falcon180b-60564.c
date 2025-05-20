//Falcon-180B DATASET v1.0 Category: Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main()
{
    srand(time(NULL));
    int playerScore = 0;
    int computerScore = 0;
    char choice;
    int userChoice;

    do
    {
        system("clear");
        printf("Welcome to the Mind-Bending Game!\n");
        printf("You will play against the computer.\n");
        printf("Choose an option:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        scanf("%c", &choice);

        switch(tolower(choice))
        {
            case '1':
                userChoice = 1;
                break;
            case '2':
                userChoice = 2;
                break;
            case '3':
                userChoice = 3;
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        int computerChoice = rand() % 3 + 1;

        if(userChoice == computerChoice)
        {
            printf("It's a tie!\n");
        }
        else if((userChoice == 1 && computerChoice == 2) ||
                 (userChoice == 2 && computerChoice == 1) ||
                 (userChoice == 3 && computerChoice == 1))
        {
            printf("You win!\n");
            playerScore++;
        }
        else
        {
            printf("You lose!\n");
            computerScore++;
        }

        printf("Score: You - %d, Computer - %d\n", playerScore, computerScore);
        printf("Do you want to play again? (y/n)\n");
        scanf(" %c", &choice);

    }while(tolower(choice) == 'y');

    return 0;
}