//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seed the random number generator
    char playerMove, computerMove;
    int playerScore, computerScore;

    while (1) {
        printf("Player, choose Rock, Paper, or Scissors: ");
        scanf(" %c", &playerMove);

        if (playerMove == 'R' || playerMove == 'r') {
            playerMove = 0;
        } else if (playerMove == 'P' || playerMove == 'p') {
            playerMove = 1;
        } else if (playerMove == 'S' || playerMove =='s') {
            playerMove = 2;
        } else {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        printf("Computer chooses: ");
        switch (rand() % 3) {
            case 0:
                computerMove = 'R' || 'r';
                break;
            case 1:
                computerMove = 'P' || 'p';
                break;
            case 2:
                computerMove = 'S' ||'s';
                break;
        }

        if (playerMove == 0 && computerMove == 0) {
            printf("Tie.\n");
        } else if (playerMove == 1 && computerMove == 2) {
            printf("Player wins!\n");
        } else if (playerMove == 2 && computerMove == 1) {
            printf("Computer wins!\n");
        } else {
            printf("Invalid move. Please try again.\n");
        }

        playerScore++;
        computerScore++;

        if (playerScore == 3 || computerScore == 3) {
            printf("Player wins!\n");
        } else if (playerScore == 2 && computerScore == 2) {
            printf("Tie.\n");
        } else {
            printf("Computer wins!\n");
        }

        printf("Player score: %d\nComputer score: %d\n\n", playerScore, computerScore);
    }

    return 0;
}