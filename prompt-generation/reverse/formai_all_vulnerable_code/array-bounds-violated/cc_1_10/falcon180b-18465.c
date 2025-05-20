//Falcon-180B DATASET v1.0 Category: Table Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
    char symbol;
} Cell;

void printBoard(Cell board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j].symbol);
        }
        printf("\n");
    }
}

int checkWin(Cell board[3][3]) {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0].symbol == board[i][1].symbol && board[i][1].symbol == board[i][2].symbol) {
            return 1;
        }
    }

    // check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j].symbol == board[1][j].symbol && board[1][j].symbol == board[2][j].symbol) {
            return 1;
        }
    }

    // check diagonals
    if (board[0][0].symbol == board[1][1].symbol && board[1][1].symbol == board[2][2].symbol) {
        return 1;
    }
    if (board[0][2].symbol == board[1][1].symbol && board[1][1].symbol == board[2][0].symbol) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(0));

    Cell board[3][3];

    // initialize board with empty cells
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j].symbol = '-';
        }
    }

    // start game loop
    int player = 1;
    int winner = 0;
    while (!winner) {
        printBoard(board);
        printf("Player %d's turn\n", player);
        int x, y;
        scanf("%d %d", &x, &y);
        if (board[x][y].symbol!= '-') {
            printf("Invalid move!\n");
            continue;
        }
        board[x][y].symbol = (player == 1)? 'X' : 'O';
        winner = checkWin(board);
        if (winner == 0) {
            player = (player == 1)? 2 : 1;
        }
    }

    printf("Player %d wins!\n", winner);

    return 0;
}