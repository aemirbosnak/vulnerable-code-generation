//FormAI DATASET v1.0 Category: Table Game ; Style: active
// C Table Game Example Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initializing variables
    int player1_score = 0, player2_score = 0, roll, sum;
    char player1_name[20], player2_name[20];

    // Asking for player's names
    printf("Enter player 1's name: ");
    scanf("%s", player1_name);
    printf("Enter player 2's name: ");
    scanf("%s", player2_name);

    // Making sure random number generator is seeded
    srand(time(NULL));

    // Looping until one player reaches a score of 100
    while(player1_score < 100 && player2_score < 100)
    {
        // Player 1's turn
        printf("\n%s's turn...\n", player1_name);
        do
        {
            // Rolling the dice
            roll = rand() % 6 + 1;
            printf("You rolled a %d.\n", roll);

            // Checking for a score of 1
            if(roll == 1)
            {
                printf("You got a score of 1. Your turn is over.\n");
                break;
            }

            // Adding to the score
            sum += roll;
            printf("Your current score is: %d\n", sum);

            // Asking to roll again or stop
            printf("Roll again? (y/n) ");
            char choice;
            scanf(" %c", &choice);

            // Checking if player wants to stop rolling
            if(choice == 'n')
            {
                player1_score += sum;
                printf("Your turn is over. Your current score is: %d\n", player1_score);
                break;
            }
        } while(roll != 1 && sum + player1_score < 100);

        sum = 0; // Resetting sum for next player

        // Player 2's turn
        printf("\n%s's turn...\n", player2_name);
        do
        {
            // Rolling the dice
            roll = rand() % 6 + 1;
            printf("You rolled a %d.\n", roll);

            // Checking for a score of 1
            if(roll == 1)
            {
                printf("You got a score of 1. Your turn is over.\n");
                break;
            }

            // Adding to the score
            sum += roll;
            printf("Your current score is: %d\n", sum);

            // Asking to roll again or stop
            printf("Roll again? (y/n) ");
            char choice;
            scanf(" %c", &choice);

            // Checking if player wants to stop rolling
            if(choice == 'n')
            {
                player2_score += sum;
                printf("Your turn is over. Your current score is: %d\n", player2_score);
                break;
            }
        } while(roll != 1 && sum + player2_score < 100);

        sum = 0; // Resetting sum for next player
    }

    // Displaying winner
    if(player1_score >= 100)
    {
        printf("\nCONGRATULATIONS, %s! You won with a score of %d!\n", player1_name, player1_score);
    }
    else if(player2_score >= 100)
    {
        printf("\nCONGRATULATIONS, %s! You won with a score of %d!\n", player2_name, player2_score);
    }

    return 0;
}