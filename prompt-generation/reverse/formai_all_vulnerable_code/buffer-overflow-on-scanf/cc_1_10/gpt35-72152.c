//FormAI DATASET v1.0 Category: Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
int playRound(int playerChoice, int computerChoice);
void printResults(int playerWins, int computerWins, int draws);

int main()
{
    int playerChoice, computerChoice, playerWins = 0, computerWins = 0, draws = 0, numRounds;
    
    srand(time(NULL)); // initialize random seed
    
    printf("Welcome to this rock-paper-scissors game!\n");
    printf("How many rounds would you like to play? ");
    scanf("%d", &numRounds); // get the number of rounds from the user
    
    for(int i = 0; i < numRounds; i++)
    {
        printf("\nRound %d\n", i+1);
        printf("Please choose:\n 1. Rock\n 2. Paper\n 3. Scissors\n");
        scanf("%d", &playerChoice); // get the player's choice
        
        computerChoice = rand() % 3 + 1; // generate a random choice for the computer
        
        switch(playerChoice)
        {
            case 1:
                printf("You chose Rock.\n");
                break;
            case 2:
                printf("You chose Paper.\n");
                break;
            case 3:
                printf("You chose Scissors.\n");
                break;
            default:
                printf("Invalid choice.\n");
                i--;
                continue;
        }
        
        switch(computerChoice)
        {
            case 1:
                printf("The computer chose Rock.\n");
                break;
            case 2:
                printf("The computer chose Paper.\n");
                break;
            case 3:
                printf("The computer chose Scissors.\n");
                break;
        }
        
        int result = playRound(playerChoice, computerChoice); // play the round and get the result
        
        if(result == 1)
        {
            printf("You win!\n");
            playerWins++;
        }
        else if(result == -1)
        {
            printf("You lose.\n");
            computerWins++;
        }
        else
        {
            printf("It's a draw.\n");
            draws++;
        }
        
        printResults(playerWins, computerWins, draws); // print the current score
    }
    
    printf("\nThank you for playing!\n");
    
    return 0; // indicate successful program termination
}

/*
 * This function plays a single round of rock-paper-scissors.
 * It takes two integers as input: the player's choice and the computer's choice.
 * It returns 1 if the player wins, -1 if the computer wins, and 0 if it's a draw.
 */
int playRound(int playerChoice, int computerChoice)
{
    if(playerChoice == 1) // rock
    {
        if(computerChoice == 1) // rock
            return 0;
        else if(computerChoice == 2) // paper
            return -1;
        else // scissors
            return 1;
    }
    else if(playerChoice == 2) // paper
    {
        if(computerChoice == 1) // rock
            return 1;
        else if(computerChoice == 2) // paper
            return 0;
        else // scissors
            return -1;
    }
    else // scissors
    {
        if(computerChoice == 1) // rock
            return -1;
        else if(computerChoice == 2) // paper
            return 1;
        else // scissors
            return 0;
    }
}

/*
 * This function prints the current score after each round.
 * It takes three integers as input: the number of player wins, computer wins, and draws.
 */
void printResults(int playerWins, int computerWins, int draws)
{
    printf("Current score:\n Player: %d\n Computer: %d\n Draws: %d\n", playerWins, computerWins, draws);
}