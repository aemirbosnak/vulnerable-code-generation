//FormAI DATASET v1.0 Category: Checkers Game ; Style: mind-bending
#include <stdio.h>

#define BOARD_SIZE 8

// Function to print the checker board
void printBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++)
            printf("%c ", board[i][j] ? 'O' : '.');
        printf("\n");
    }
    printf("\n");
}

// Function to move the checkers piece
int movePiece(int board[BOARD_SIZE][BOARD_SIZE], int row1, int col1, int row2, int col2) {
    int i, j;

    // Check if the piece is moving to an empty spot
    if (board[row2][col2] != 0)
        return 0;

    // Check if the piece is moving in the right direction
    if (board[row1][col1] == 1 && row2 <= row1)
        return 0;
    if (board[row1][col1] == 2 && row2 >= row1)
        return 0;

    // Check if the move is a jump
    if (abs(row1 - row2) == 2 && abs(col1 - col2) == 2) {
        i = (row1 + row2) / 2;
        j = (col1 + col2) / 2;
        if (board[i][j] == 0)
            return 0;
        board[i][j] = 0;
    }

    // Move the piece
    board[row2][col2] = board[row1][col1];
    board[row1][col1] = 0;
    return 1;
}

// Main function
int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {
            {0, 1, 0, 1, 0, 1, 0, 1},
            {1, 0, 1, 0, 1, 0, 1, 0},
            {0, 1, 0, 1, 0, 1, 0, 1},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {2, 0, 2, 0, 2, 0, 2, 0},
            {0, 2, 0, 2, 0, 2, 0, 2},
            {2, 0, 2, 0, 2, 0, 2, 0}
    };

    int turn = 1;
    int row1, col1, row2, col2;
    while (1) {
        printf("Player %d turn: \n", turn);

        // Get the piece to move
        printf("Enter row and column of piece to move: ");
        scanf("%d %d", &row1, &col1);

        // Get the destination position
        printf("Enter row and column of destination: ");
        scanf("%d %d", &row2, &col2);

        // Check if the move is valid
        if (movePiece(board, row1, col1, row2, col2)) {
            printBoard(board);
            // Check if the game is over
            int i, j, player1 = 0, player2 = 0;
            for (i = 0; i < BOARD_SIZE; i++) {
                for (j = 0; j < BOARD_SIZE; j++) {
                    if (board[i][j] == 1)
                        player1++;
                    if (board[i][j] == 2)
                        player2++;
                }
            }
            if (player1 == 0 || player2 == 0) {
                printf("Player %d wins!\n", player1 == 0 ? 2 : 1);
                break;
            }
            // Switch turn
            turn = turn == 1 ? 2 : 1;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    return 0;
}