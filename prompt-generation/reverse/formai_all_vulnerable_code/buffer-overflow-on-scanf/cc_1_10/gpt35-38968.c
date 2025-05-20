//FormAI DATASET v1.0 Category: Dice Roller ; Style: decentralized
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

//function to roll the dice
int rollDice()
{
    int roll = rand() % 6 + 1; //generates random number between 1 and 6
    return roll;
}

int main()
{
    srand(time(0)); //seeds the random number generator with time

    //declaring variables
    int player1Score = 0, player2Score = 0;
    int numOfGames = 0, numOfRolls = 0;
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y')
    {
        printf("\n Welcome to the Dice Roller Game!\n");
        printf("\n Player 1, please enter your name:\n");
        char player1Name[20];
        scanf(" %s", player1Name);

        printf("\n Player 2, please enter your name:\n");
        char player2Name[20];
        scanf(" %s", player2Name);

        printf("\n How many games would you like to play?\n");
        scanf(" %d", &numOfGames);
        printf("\n Let's start playing!\n");

        //loop for playing multiple games
        for (int i = 1; i <= numOfGames; i++)
        {
            //loop for rolling the dice
            while (player1Score < 100 && player2Score < 100)
            {
                int roll1 = rollDice();
                int roll2 = rollDice();

                numOfRolls++;

                printf("\n %s rolled a %d and %s rolled a %d\n", player1Name, roll1, player2Name, roll2);
                player1Score += roll1;
                player2Score += roll2;

                //checks if any player wins
                if (player1Score >= 100 || player2Score >= 100)
                {
                    break;
                }
            }

            //checks which player won
            if (player1Score >= 100)
            {
                printf("\nCongratulations! %s wins the game\n", player1Name);
            }
            else
            {
                printf("\nCongratulations! %s wins the game\n", player2Name);
            }

            printf("\nNumber of Rolls for Game %d: %d\n", i, numOfRolls);

            //resetting variables for new game
            numOfRolls = 0;
            player1Score = 0;
            player2Score = 0;
        }

        printf("\nWould you like to play again? (y/n)\n");
        scanf(" %c", &playAgain);
    }

    printf("\nThanks for playing Dice Roller Game!\n");
    return 0;
}