//FormAI DATASET v1.0 Category: Table Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Declare variables
    char playerName[20];
    int playerScore = 0, computerScore = 0;
    int computerChoice, playerChoice;
    int round = 1;
    
    // Get the player's name
    printf("What's your name?\n");
    scanf("%s", playerName);
    
    printf("Welcome to the C Table Game, %s!\n", playerName);
    
    // Play the game until one player wins three rounds
    while (playerScore < 3 && computerScore < 3)
    {
        // Display round number
        printf("\n*** Round %d ***\n", round);
        
        // Get player's choice
        printf("Choose your move:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        scanf("%d", &playerChoice);
        
        // Generate computer's choice
        srand(time(NULL));
        computerChoice = rand() % 3 + 1;
        
        // Determine winner of round and update scores
        if (playerChoice == computerChoice)
        {
            printf("It's a tie!\n");
        }
        else if (playerChoice == 1 && computerChoice == 3)
        {
            printf("You win the round!\n");
            playerScore++;
        }
        else if (playerChoice == 2 && computerChoice == 1)
        {
            printf("You win the round!\n");
            playerScore++;
        }
        else if (playerChoice == 3 && computerChoice == 2)
        {
            printf("You win the round!\n");
            playerScore++;
        }
        else
        {
            printf("Computer wins the round!\n");
            computerScore++;
        }
        
        // Display current scores
        printf("Your score: %d\n", playerScore);
        printf("Computer's score: %d\n", computerScore);
        
        round++; // Increment the round number
    }
    
    // Determine the winner of the game
    printf("\n*** Game Over ***\n");
    
    if (playerScore > computerScore)
    {
        printf("Congratulations, %s! You win!\n", playerName);
    }
    else
    {
        printf("Sorry, %s. Computer wins.\n", playerName);
    }
    
    return 0;
}