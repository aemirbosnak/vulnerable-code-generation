//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define WINNING_CONDITIONS ((0 == ((board[0][0] ^ board[1][0]) | board[2][0])), \
                              (0 == ((board[0][1] ^ board[1][1]) | board[2][1])), \
                              (0 == ((board[0][2] ^ board[1][2]) | board[2][2])), \
                              (0 == ((board[0][0] ^ board[1][1]) | board[2][2])), \
                              (0 == ((board[0][2] ^ board[1][1]) | board[2][0])))

int board[BOARD_SIZE][BOARD_SIZE];

void initBoard()
{
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void printBoard()
{
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int winner()
{
    return WINNING_CONDITIONS;
}

int main()
{
    srand(time(NULL));
    int player = rand() % 2;
    int i, j, k;

    initBoard();

    while (1) {
        printf("Player %d's turn\n", player + 1);
        printf("Enter row and column: ");
        scanf("%d%d", &i, &j);
        if (player) {
            board[i-1][j-1] = 1;
        } else {
            board[i-1][j-1] = 2;
        }
        printBoard();

        if (winner()) {
            printf("Player %d wins!\n", player + 1);
            break;
        }

        player =!player;
    }

    return 0;
}