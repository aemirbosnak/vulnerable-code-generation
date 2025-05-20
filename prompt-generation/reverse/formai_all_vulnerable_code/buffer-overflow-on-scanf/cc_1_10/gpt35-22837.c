//FormAI DATASET v1.0 Category: Table Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int player1, player2, score1 = 0, score2 = 0;
    char choice;

    // seed the random number generator
    srand(time(NULL)); 

    printf("Welcome to Table Game!\n");

    do {
        // generate random numbers for each player's turn
        player1 = rand() % 6 + 1;
        player2 = rand() % 6 + 1;
        
        printf("Player 1 rolled: %d\n", player1);
        printf("Player 2 rolled: %d\n", player2);

        // update the scores
        if (player1 > player2) {
            score1++;
            printf("Player 1 wins this round!\n");
        } else if (player2 > player1) {
            score2++;
            printf("Player 2 wins this round!\n");
        } else {
            printf("This round is a tie!\n");
        }

        // print the current scores
        printf("Player 1: %d\n", score1);
        printf("Player 2: %d\n", score2);

        // ask if the players want to play again
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    // print the final scores
    printf("Final Scores:\n");
    printf("Player 1: %d\n", score1);
    printf("Player 2: %d\n", score2);

    // declare the winner or if it's a tie
    if (score1 > score2) {
        printf("Player 1 wins!\n");
    } else if (score2 > score1) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}