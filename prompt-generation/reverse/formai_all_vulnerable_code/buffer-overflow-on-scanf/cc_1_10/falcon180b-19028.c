//Falcon-180B DATASET v1.0 Category: Table Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player1Score = 0;
    int player2Score = 0;
    int roundWinner = 0;
    int gameWinner = 0;
    int choice;
    int dice;
    char playAgain;

    srand(time(NULL));

    do {
        printf("\n\nWelcome to the C Table Game!\n\n");
        printf("Player 1, choose your symbol: ");
        scanf("%c", &choice);
        printf("Player 2, choose your symbol: ");
        scanf("%c", &choice);

        printf("\n\nRound %d\n", ++roundWinner);

        while(1) {
            dice = rand() % 6 + 1;
            printf("Player %d rolled a %d!\n", roundWinner, dice);

            if(dice == 6) {
                printf("Player %d wins the round!\n", roundWinner);
                player1Score++;
                break;
            }
            else if(dice == 1) {
                printf("Player %d loses the round.\n", roundWinner);
                player2Score++;
                break;
            }
        }

        if(player1Score == 3) {
            printf("\n\nPlayer 1 wins the game!\n");
            gameWinner = 1;
            break;
        }
        else if(player2Score == 3) {
            printf("\n\nPlayer 2 wins the game!\n");
            gameWinner = 2;
            break;
        }
        else {
            printf("\n\nTie game, playing again.\n");
        }

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while(playAgain == 'y' || playAgain == 'Y');

    return 0;
}