//FormAI DATASET v1.0 Category: Table Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //Define all necessary variables
    int player1, player2, player3, player4;
    int score1 = 0, score2 = 0, score3 = 0, score4 = 0;
    int i, round;
    char input;

    //Introduction and rules
    printf("Welcome to the C Table Game!\n");
    printf("The game is played with 4 players.\n");
    printf("Each player rolls a dice and the player with the highest score wins the round.\n");
    printf("The winner of the round gets 10 points and the other players get points equal to their rolled score.\n");
    printf("The game consists of 10 rounds and the player with the highest score at the end wins.\n");

    //Game loop
    for (round = 1; round <= 10; round++) {
        printf("\nRound %d:\n", round);

        //Player 1's turn
        printf("Player 1, press any key to roll the dice: ");
        scanf(" %c", &input);
        srand(time(0));
        player1 = rand() % 6 + 1;
        printf("Player 1 rolled a %d.\n", player1);

        //Player 2's turn
        printf("Player 2, press any key to roll the dice: ");
        scanf(" %c", &input);
        srand(time(0));
        player2 = rand() % 6 + 1;
        printf("Player 2 rolled a %d.\n", player2);

        //Player 3's turn
        printf("Player 3, press any key to roll the dice: ");
        scanf(" %c", &input);
        srand(time(0));
        player3 = rand() % 6 + 1;
        printf("Player 3 rolled a %d.\n", player3);

        //Player 4's turn
        printf("Player 4, press any key to roll the dice: ");
        scanf(" %c", &input);
        srand(time(0));
        player4 = rand() % 6 + 1;
        printf("Player 4 rolled a %d.\n", player4);

        //Determine round winner and update scores
        if (player1 > player2 && player1 > player3 && player1 > player4) {
            score1 += 10;
            score2 += player2;
            score3 += player3;
            score4 += player4;
            printf("Player 1 wins the round!\n");
        }
        else if (player2 > player1 && player2 > player3 && player2 > player4) {
            score2 += 10;
            score1 += player1;
            score3 += player3;
            score4 += player4;
            printf("Player 2 wins the round!\n");
        }
        else if (player3 > player1 && player3 > player2 && player3 > player4) {
            score3 += 10;
            score1 += player1;
            score2 += player2;
            score4 += player4;
            printf("Player 3 wins the round!\n");
        }
        else {
            score4 += 10;
            score1 += player1;
            score2 += player2;
            score3 += player3;
            printf("Player 4 wins the round!\n");
        }

        printf("\nScores after Round %d:\n", round);
        printf("Player 1: %d\nPlayer 2: %d\nPlayer 3: %d\nPlayer 4: %d\n", score1, score2, score3, score4);
    }

    //Determine overall winner
    printf("\nGame over!\n");
    if (score1 > score2 && score1 > score3 && score1 > score4) {
        printf("Player 1 wins!");
    }
    else if (score2 > score1 && score2 > score3 && score2 > score4) {
        printf("Player 2 wins!");
    }
    else if (score3 > score1 && score3 > score2 && score3 > score4) {
        printf("Player 3 wins!");
    }
    else {
        printf("Player 4 wins!");
    }

    return 0;
}