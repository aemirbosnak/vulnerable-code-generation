//FormAI DATASET v1.0 Category: Table Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player1_score = 0, player2_score = 0, round = 0, dice_roll;
    char play_again;

    srand(time(0)); //seed the random number generator with the current time

    printf("Welcome to the C Table Game!\n");

    do {
        round++;
        printf("\n\nRound %d!\n\n", round);

        //player 1's turn
        printf("Player 1, press enter to roll the dice: ");
        getchar();
        dice_roll = rand() % 6 + 1; //generate a random number between 1 and 6
        printf("You rolled a %d!\n", dice_roll);
        player1_score += dice_roll; //add the dice roll to player 1's score
        printf("Your score is now %d.\n", player1_score);

        //player 2's turn
        printf("Player 2, press enter to roll the dice: ");
        getchar();
        dice_roll = rand() % 6 + 1; //generate a random number between 1 and 6
        printf("You rolled a %d!\n", dice_roll);
        player2_score += dice_roll; //add the dice roll to player 2's score
        printf("Your score is now %d.\n", player2_score);

        printf("\n");

        if (player1_score >= 100 || player2_score >= 100) {
            //check if either player has reached 100 points
            break;
        }

        printf("Do you want to play another round? (y/n) ");
        scanf(" %c", &play_again);
    } while (play_again == 'y' || play_again == 'Y');

    printf("\n\nFinal Scores:\n");
    printf("Player 1: %d\n", player1_score);
    printf("Player 2: %d\n", player2_score);

    if (player1_score > player2_score) {
        printf("Player 1 wins!\n");
    }
    else if (player2_score > player1_score) {
        printf("Player 2 wins!\n");
    }
    else {
        printf("It's a tie!\n");
    }

    return 0;
}