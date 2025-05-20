//Falcon-180B DATASET v1.0 Category: Table Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player1Score = 0, player2Score = 0;
    int roll, choice;
    char playAgain;

    srand(time(NULL));

    printf("Welcome to the C Table Game!\n");
    printf("Player 1, choose your symbol: 1. X or 2. O\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Player 1, you are X.\n");
        printf("Player 2, you are O.\n");
    } else {
        printf("Player 1, you are O.\n");
        printf("Player 2, you are X.\n");
    }

    while (1) {
        system("clear");
        printf("Score: Player 1 - %d, Player 2 - %d\n", player1Score, player2Score);
        printf("Player %d's turn.\n", (player1Score + player2Score) % 2 + 1);

        printf("Enter your move (1-9): ");
        scanf("%d", &roll);

        if (roll < 1 || roll > 9) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        if (roll == 9) {
            printf("Player %d wins!\n", (player1Score + player2Score) % 2 + 1);
            break;
        }

        if ((roll % 2) == ((player1Score + player2Score) % 2)) {
            printf("Player %d's turn.\n", (player1Score + player2Score) % 2 + 1);
        } else {
            printf("Player %d's turn.\n", 3 - (player1Score + player2Score) % 2);
        }

        player1Score++;
        player2Score++;
    }

    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &playAgain);

    if (playAgain == 'y') {
        main();
    } else {
        printf("Thank you for playing the C Table Game!\n");
        return 0;
    }
}