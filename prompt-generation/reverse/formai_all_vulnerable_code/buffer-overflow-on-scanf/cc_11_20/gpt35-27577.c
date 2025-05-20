//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int playerChoice, computerChoice, rounds, playerScore=0, computerScore=0, tieScore=0;
    srand(time(0)); // Initializing random number generator

    printf("Welcome to Rock Paper Scissors!\n");
    printf("Enter the number of rounds you want to play: ");
    scanf("%d", &rounds);

    // Loop for running the game for desired number of rounds
    for(int i=1; i<=rounds; i++)
    {
        printf("\nRound %d\n", i);
        printf("Choose your move:\n");
        printf("1. Rock\n2. Paper\n3. Scissors\n");
        scanf("%d", &playerChoice);

        // Generating random number for computer's move
        computerChoice = (rand() % 3) + 1;

        // Checking the winner of the round and updating the scores
        if(playerChoice == computerChoice)
        {
            printf("It's a tie!\n");
            tieScore++;
        }
        else if((playerChoice == 1 && computerChoice == 3) || (playerChoice == 2 && computerChoice == 1) 
                || (playerChoice == 3 && computerChoice == 2))
        {
            printf("You won the round!\n");
            playerScore++;
        }
        else
        {
            printf("Computer won the round!\n");
            computerScore++;
        }
        printf("Your move: %d\nComputer's move: %d\n", playerChoice, computerChoice);
    }

    // Displaying final scores and winner of the game
    printf("\nGame over!\n");
    printf("Your score: %d\nComputer's score: %d\nTie score: %d\n", playerScore, computerScore, tieScore);
    if(playerScore == computerScore)
        printf("It's a tie!\n");
    else if(playerScore > computerScore)
        printf("You win the game!\n");
    else
        printf("Computer wins the game!\n");

    return 0;
}