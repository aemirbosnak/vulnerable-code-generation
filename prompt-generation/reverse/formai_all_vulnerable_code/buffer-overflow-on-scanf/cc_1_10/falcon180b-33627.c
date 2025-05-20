//Falcon-180B DATASET v1.0 Category: Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int playerScore = 0, computerScore = 0;
    int choice, guess;
    char playAgain = 'y';

    srand(time(0));

    while(playAgain == 'y' || playAgain == 'Y')
    {
        printf("Welcome to the guessing game!\n\n");
        printf("You have to guess a number between 1 and 100.\n");
        printf("I will tell you if your guess is too high or too low.\n");
        printf("Let's begin!\n\n");

        int secretNumber = rand() % 100 + 1;

        while(1)
        {
            printf("Guess a number: ");
            scanf("%d", &guess);

            if(guess == secretNumber)
            {
                printf("Congratulations! You guessed the number in %d tries.\n\n", ++playerScore);
                break;
            }
            else if(guess < secretNumber)
            {
                printf("Too low. Try again.\n");
            }
            else
            {
                printf("Too high. Try again.\n");
            }
        }

        computerScore++;

        if(computerScore == 5)
        {
            printf("\nGame over! You lose.\n");
            break;
        }

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    }

    printf("\nThanks for playing! Your final score is: %d\n", playerScore);

    return 0;
}