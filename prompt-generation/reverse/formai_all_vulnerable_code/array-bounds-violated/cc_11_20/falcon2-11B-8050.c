//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {
    int board[3][3];
    int player = 1;

    printf("Welcome to the C Table Game!n");
    printf("Let's play!n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %d | ", i + 1);
            for (int k = 0; k < 3; k++) {
                printf(" %d | ", j + 1);
            }
            printf("\n");
        }
        printf("\n");
    }

    printf("Player %d, it's your turn!\n", player);
    printf("Choose a number from 1 to 9 and enter it below.\n");

    char choice[10];
    scanf("%s", choice);

    if (choice[0] == '1' || choice[0] == '2' || choice[0] == '3') {
        board[0][choice[0] - '0'] = player;
    } else if (choice[0] == '4' || choice[0] == '5' || choice[0] == '6') {
        board[1][choice[0] - '0'] = player;
    } else if (choice[0] == '7' || choice[0] == '8' || choice[0] == '9') {
        board[2][choice[0] - '0'] = player;
    } else {
        printf("Invalid choice. Please try again.\n");
        return 0;
    }

    if (checkWinner(board, player)) {
        printf("Congratulations! Player %d wins!\n", player);
        return 0;
    }

    player = (player + 1) % 2;
    printf("Player %d, it's your turn!\n", player);

    return 0;
}

int checkWinner(int board[3][3], int player) {
    int i, j, k;
    int winner = 0;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == player) {
                for (k = 0; k < 3; k++) {
                    if (board[i][k] == board[k][j] && board[i][k] == board[k][j]) {
                        winner = 1;
                        break;
                    }
                }
                if (winner == 1) {
                    break;
                }
            }
        }
        if (winner == 1) {
            break;
        }
    }

    if (winner == 1) {
        return 1;
    } else {
        return 0;
    }
}