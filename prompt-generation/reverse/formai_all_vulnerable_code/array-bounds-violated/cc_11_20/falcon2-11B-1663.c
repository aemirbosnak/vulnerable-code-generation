//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: curious
#include <stdio.h>
#include <stdlib.h>

void printBoard(int board[][3], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int board[3][3] = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    int size = 3;

    printBoard(board, size);

    int newBoard[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int neighbors = 0;

            if (i > 0 && j > 0 && i < size - 1 && j < size - 1) {
                neighbors += board[i - 1][j - 1] && board[i - 1][j] && board[i - 1][j + 1] &&
                           board[i][j - 1] && board[i][j + 1] && board[i + 1][j - 1] &&
                           board[i + 1][j] && board[i + 1][j + 1];
            } else if (i > 0 && j > 0) {
                neighbors += board[i - 1][j - 1] && board[i - 1][j] && board[i - 1][j + 1];
            } else if (i > 0) {
                neighbors += board[i - 1][j - 1] && board[i - 1][j] && board[i - 1][j + 1];
            } else if (j > 0) {
                neighbors += board[i - 1][j - 1] && board[i - 1][j] && board[i - 1][j + 1];
            } else {
                neighbors += board[i - 1][j - 1] && board[i - 1][j] && board[i - 1][j + 1];
            }

            if (board[i][j] == 1 &&!neighbors) {
                newBoard[i][j] = 0;
            } else if (board[i][j] == 0 && neighbors == 3) {
                newBoard[i][j] = 1;
            } else {
                newBoard[i][j] = board[i][j];
            }
        }
    }

    printBoard(newBoard, size);

    return 0;
}