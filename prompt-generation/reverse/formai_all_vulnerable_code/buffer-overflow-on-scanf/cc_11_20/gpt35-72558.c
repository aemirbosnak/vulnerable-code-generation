//FormAI DATASET v1.0 Category: Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j;
    char player;
    int board[3][3];
    srand(time(NULL));
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            board[i][j] = rand() % 2;
        }
    }
    
    printf("** Welcome to Tic Tac Toe **\n\n");
    printf("Pick a player (X or O): ");
    scanf("%c", &player);
    printf("\n");

    while (player != 'X' && player != 'O') {
        printf("Invalid player choice, please pick again: ");
        scanf(" %c", &player);
        printf("\n");
    }

    printf("Player %c, let's get started!\n\n", player);

    for(i=0; i<3; i++) {
        printf("\t\t");
        for(j=0; j<3; j++) {
            if (board[i][j] == 0) {
                printf("X ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }

    printf("\n");

    printf("Player %c, enter the row and column where you want to place your mark: ", player);
    
    int row, column;
    scanf("%d %d", &row, &column);

    while (row < 1 || row > 3 || column < 1 || column > 3) {
        printf("Invalid row or column number, please pick again: ");
        scanf("%d %d", &row, &column);
    }

    if (board[row-1][column-1] == 0) {
        board[row-1][column-1] = player == 'X' ? 1 : 2;
    }

    printf("\n");

    for(i=0; i<3; i++) {
        printf("\t\t");
        for(j=0; j<3; j++) {
            if (board[i][j] == 0) {
                printf("X ");
            } else if (board[i][j] == 1) {
                printf("X ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }

    printf("\n");

    return 0;
}