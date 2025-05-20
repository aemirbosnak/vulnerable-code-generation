//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random number
int generateRandomNumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}

// function to determine winner
int determineWinner(int player1_choice, int player2_choice)
{
    // return 0 if it's a tie
    if (player1_choice == player2_choice)
        return 0;

    // return 1 if player 1 wins
    if ((player1_choice == 0 && player2_choice == 1) ||
        (player1_choice == 1 && player2_choice == 2) ||
        (player1_choice == 2 && player2_choice == 0))
        return 1;

    // otherwise, player 2 wins
    return 2;
}

int main()
{
    int player1_choice, player2_choice, winner;

    printf("* Welcome to the Rock-Paper-Scissors game! *\n\n");

    while (1)
    {
        printf("Please select your option:\n"
               "1 for Rock\n2 for Paper\n3 for Scissors\n");

        // take input from player 1
        printf("Player 1's turn: ");
        scanf("%d", &player1_choice);

        // generate random input for player 2
        player2_choice = generateRandomNumber(3) + 1;
        printf("Player 2's turn: %d\n\n", player2_choice);

        // determine winner
        winner = determineWinner(player1_choice - 1, player2_choice - 1);

        // print result
        if (winner == 0)
            printf("It's a tie!\n\n");
        else if (winner == 1)
            printf("Player 1 wins!\n\n");
        else
            printf("Player 2 wins!\n\n");

        // ask if players want to play again
        printf("Do you want to play again? (Y/N) ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'N' || choice == 'n')
            break;

        printf("\n");
    }

    printf("*** Thank you for playing! ***\n");

    return 0;
}