//Falcon2-11B DATASET v1.0 Category: Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int currentPlayer = 1;

    while (1) {
        int row, col;

        printf("Player %d's turn.\n", currentPlayer == 1? "X" : "O");

        if (currentPlayer == 1) {
            printf("Enter row (1-3): ");
            scanf("%d", &row);
            printf("Enter column (1-3): ");
            scanf("%d", &col);
            if (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1]!= 0) {
                printf("Invalid move.\n");
                continue;
            }
            board[row-1][col-1] = currentPlayer;
        } else {
            printf("Enter row (1-3): ");
            scanf("%d", &row);
            printf("Enter column (1-3): ");
            scanf("%d", &col);
            if (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1]!= 0) {
                printf("Invalid move.\n");
                continue;
            }
            board[row-1][col-1] = currentPlayer;
        }
        currentPlayer = currentPlayer == 1? 2 : 1;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%3d", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        printf("Do you want to play again? (y/n): ");
        char answer;
        scanf(" %c", &answer);
        if (answer!= 'y' && answer!= 'Y') {
            break;
        }
    }

    return 0;
}