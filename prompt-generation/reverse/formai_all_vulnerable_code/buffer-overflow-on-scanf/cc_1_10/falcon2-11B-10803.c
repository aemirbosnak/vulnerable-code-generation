//Falcon2-11B DATASET v1.0 Category: Checkers Game ; Style: minimalist
#include <stdio.h>

void movePiece(int board[8][8], int row, int col, int dir) {
    int nextRow = row + dir;
    int nextCol = col + (dir > 0? 1 : -1);

    if (nextRow >= 0 && nextRow < 8 && nextCol >= 0 && nextCol < 8 && board[nextRow][nextCol] == 0) {
        board[row][col] = 0;
        board[nextRow][nextCol] = 1 - board[row][col];
        return;
    }
}

void displayBoard(int board[8][8]) {
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int board[8][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    printf("Please choose a piece to move:\n");
    int row, col;
    scanf("%d %d", &row, &col);
    if (row < 0 || row >= 8 || col < 0 || col >= 8) {
        printf("Invalid input.\n");
        return 0;
    }

    int dir = 0;
    do {
        printf("Choose a direction to move (0 = right, 1 = down, 2 = left, 3 = up):\n");
        scanf("%d", &dir);
        if (dir < 0 || dir > 3) {
            printf("Invalid input.\n");
        }
    } while (dir < 0 || dir > 3);

    movePiece(board, row, col, dir);
    displayBoard(board);

    int winner = -1;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (board[i][j] == 0) {
                winner = i;
                break;
            }
        }
        if (winner!= -1) {
            break;
        }
    }

    if (winner == -1) {
        printf("Game ended in a draw.\n");
    } else {
        printf("Player %d wins!\n", winner + 1);
    }

    return 0;
}