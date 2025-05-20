//FormAI DATASET v1.0 Category: Table Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //initialize random seed
    int playerScore = 0, computerScore = 0;
    char playerName[20];
    printf("Welcome to the C Table Game!\n\n");
    printf("Enter your name: ");
    scanf("%s", playerName);
    printf("Hello %s! Let's begin.\n\n", playerName);
    printf("You will roll a die and try to get as close as possible to 21 without going over.\n");
    printf("If you get closer than the computer, you win!\n\n");

    // Game loop
    while (1)
    {
        printf("Your score: %d | Computer score: %d\n\n", playerScore, computerScore);
        printf("Roll the die? (y/n): ");

        char input;
        fflush(stdin); //flush input buffer
        scanf("%c", &input);

        if (input == 'y')
        {
            int roll = rand() % 6 + 1;
            printf("You rolled: %d\n", roll);
            playerScore += roll;
            if (playerScore > 21)
            {
                printf("Bust! You lose.\n\n");
                break;
            }
        }
        else
        {
            printf("Computer's turn.\n\n");

            while (computerScore < 18)
            {
                int roll = rand() % 6 + 1;
                printf("Computer rolled: %d\n", roll);
                computerScore += roll;
            }

            printf("Your score: %d | Computer score: %d\n\n", playerScore, computerScore);

            if (computerScore > 21)
            {
                printf("Computer bust! You win!\n\n");
                break;
            }
            else if (playerScore == computerScore)
            {
                printf("Tie! Nobody wins.\n\n");
                break;
            }
            else if (playerScore > computerScore)
            {
                printf("You win!\n\n");
                break;
            }
            else
            {
                printf("You lose.\n\n");
                break;
            }
        }
    }

    return 0;
}