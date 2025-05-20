//FormAI DATASET v1.0 Category: Game ; Style: dynamic
/*
This program simulates a game of rock-paper-scissors between a user and a computer.
The game runs until the user chooses to quit or until one player wins three rounds.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int userScore = 0;
    int compScore = 0;

    while (userScore < 3 && compScore < 3) // game runs until one player wins three rounds
    {
        printf("\nSelect an option:\n1. Rock\n2. Paper\n3. Scissors\n4. Quit game\n");
        int userChoice;
        scanf("%d", &userChoice);

        if (userChoice == 4)
        {
            printf("Game over. You quit.\n");
            return 0;
        }

        srand(time(NULL)); // seed random number generator
        int compChoice = rand() % 3 + 1; // computer selects a random option

        const char *options[4] = { "nothing", "rock", "paper", "scissors" }; // array of option names

        printf("\nYou chose %s and the computer chose %s\n", options[userChoice], options[compChoice]);

        if (userChoice == compChoice)
        {
            printf("It's a tie!\n");
        }
        else if ((userChoice == 1 && compChoice == 3) || (userChoice == 2 && compChoice == 1) || (userChoice == 3 && compChoice == 2))
        {
            printf("You win this round!\n");
            userScore++;
        }
        else
        {
            printf("The computer wins this round.\n");
            compScore++;
        }

        printf("Score: You - %d | Computer - %d\n", userScore, compScore);
    }

    if (userScore == 3)
        printf("\nCongratualations! You won the game!\n");
    else
        printf("\nGame over. The computer won.\n");

    return 0;
}