//FormAI DATASET v1.0 Category: Chess engine ; Style: detailed
#include <stdio.h>

#define BOARD_LENGTH 8

// function to display the current state of the board
void displayBoard(int board[][BOARD_LENGTH]) {
    printf("\n");
    for (int i = 0; i < BOARD_LENGTH; i++) {
        for (int j = 0; j < BOARD_LENGTH; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// function to initialize the board
void initBoard(int board[][BOARD_LENGTH]) {
    for (int i = 0; i < BOARD_LENGTH; i++) {
        for (int j = 0; j < BOARD_LENGTH; j++) {
            if (i == 0 && (j == 0 || j == 7))
                board[i][j] = 1; // Rook
            else if (i == 0 && (j == 1 || j == 6))
                board[i][j] = 2; // Knight
            else if (i == 0 && (j == 2 || j == 5))
                board[i][j] = 3; // Bishop
            else if (i == 0 && j == 3)
                board[i][j] = 4; // Queen
            else if (i == 0 && j == 4)
                board[i][j] = 5; // King
            else if (i == 1)
                board[i][j] = 6; // Pawn
            else if (i == 6)
                board[i][j] = -6; // Pawn
            else if (i == 7 && (j == 0 || j == 7))
                board[i][j] = -1; // Rook
            else if (i == 7 && (j == 1 || j == 6))
                board[i][j] = -2; // Knight
            else if (i == 7 && (j == 2 || j == 5))
                board[i][j] = -3; // Bishop
            else if (i == 7 && j == 3)
                board[i][j] = -4; // Queen
            else if (i == 7 && j == 4)
                board[i][j] = -5; // King
            else
                board[i][j] = 0; // Empty cell
        }
    }
}

// function to get the input move from the user
void getInput(int *x1, int *y1, int *x2, int *y2) {
    printf("\nEnter start position (x,y): ");
    scanf("%d%d", x1, y1);
    printf("\nEnter end position (x,y): ");
    scanf("%d%d", x2, y2);
}

int main() {
    int board[BOARD_LENGTH][BOARD_LENGTH];
    int x1, y1, x2, y2;

    // initialize the board
    initBoard(board);

    // display the board
    displayBoard(board);

    // get input from user
    getInput(&x1, &y1, &x2, &y2);

    // move the piece
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = 0;

    // display the updated board
    displayBoard(board);

    return 0;
}