//FormAI DATASET v1.0 Category: Table Game ; Style: decentralized
/* 
Decentralized C Table Game
Created by: [Your Name]
Date: [Current Date]
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to roll a dice and return the result
int rollDice()
{
    int dice = rand() % 6 + 1;
    printf("\nYou rolled a %d!\n", dice);
    return dice;
}

// Function to check if the player wins or loses based on their roll and the computer's roll
bool checkWinner(int playerRoll, int computerRoll)
{
    if (playerRoll > computerRoll)
    {
        printf("\nYou win!\n");
        return true;
    }
    else if (playerRoll < computerRoll)
    {
        printf("\nThe computer wins!\n");
        return false;
    }
    else
    {
        printf("\nIt's a tie!\n");
        return false;
    }
}

int main()
{
    // Set the seed for random number generation
    srand(time(NULL));
    
    int playerScore = 0;
    int computerScore = 0;
    bool gameOn = true;
    
    // Loop for the game to continue until the player chooses to quit
    while (gameOn)
    {
        printf("\nPlayer score: %d", playerScore);
        printf("\nComputer score: %d", computerScore);
        
        // Prompt the player to roll the dice
        printf("\nDo you want to roll the dice? (y/n): ");
        char choice;
        fflush(stdin);
        scanf(" %c", &choice);
        
        // If the player chooses to roll the dice, roll the dice and check for winner
        if (choice == 'y')
        {
            int playerRoll = rollDice();
            int computerRoll = rollDice();
            
            if (checkWinner(playerRoll, computerRoll))
            {
                playerScore++;
            }
            else
            {
                computerScore++;
            }
        }
        // If the player chooses to quit, end the game
        else if (choice == 'n')
        {
            printf("\nThanks for playing!\n");
            gameOn = false;
        }
        // If the player enters an invalid input, prompt them again
        else
        {
            printf("\nInvalid input. Please try again.\n");
        }
    }
    
    return 0;
}