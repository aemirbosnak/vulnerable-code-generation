//Falcon2-11B DATASET v1.0 Category: Checkers Game ; Style: synchronous
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Define constants for board size and piece colors
#define BOARD_SIZE 8
#define BLACK 0
#define WHITE 1

// Define a structure for each piece on the board
typedef struct {
    int x;
    int y;
    int color;
} Piece;

// Define a 2D array to represent the board
Piece board[BOARD_SIZE][BOARD_SIZE];

// Define a function to initialize the board
void initBoard() {
    // Initialize each piece on the board to have an empty position and color
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].x = -1;
            board[i][j].y = -1;
            board[i][j].color = 0;
        }
    }
}

// Define a function to print the board
void printBoard() {
    // Print the board in a nice format
    printf("+-------+-------+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("| ");
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].color == BLACK) {
                printf("b ");
            } else if (board[i][j].color == WHITE) {
                printf("w ");
            } else {
                printf(" ");
            }
        }
        printf("| ");
        printf("+-------+-------+\n");
    }
}

// Define a function to check if a move is legal
bool isLegalMove(int x, int y, int color) {
    // Check if the move is in bounds and not already occupied
    if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y].color == 0) {
        // Check if the move is a capture or a jump
        int dx = abs(x - board[x][y].x);
        int dy = abs(y - board[x][y].y);
        if (board[x][y].color == color && dx > 1 && dy > 1) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

// Define a function to make a move
void makeMove(int x, int y, int color) {
    // Check if the move is legal
    if (isLegalMove(x, y, color)) {
        // Update the board with the new position
        board[x][y].x = x;
        board[x][y].y = y;
        board[x][y].color = color;
    } else {
        printf("Illegal move!\n");
    }
}

// Define a function to determine the winner
bool isWinner(int color) {
    // Check if the player has a row of pieces
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0].color == color && board[i][1].color == color && board[i][2].color == color &&
            board[i][3].color == color && board[i][4].color == color && board[i][5].color == color &&
            board[i][6].color == color && board[i][7].color == color) {
            return true;
        }
    }

    // Check if the player has a column of pieces
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i].color == color && board[1][i].color == color && board[2][i].color == color &&
            board[3][i].color == color && board[4][i].color == color && board[5][i].color == color &&
            board[6][i].color == color && board[7][i].color == color) {
            return true;
        }
    }

    // Check if the player has a diagonal of pieces
    if (board[0][0].color == color && board[1][1].color == color && board[2][2].color == color &&
        board[3][3].color == color && board[4][4].color == color && board[5][5].color == color &&
        board[6][6].color == color && board[7][7].color == color) {
        return true;
    }

    // Check if the player has a diagonal of pieces
    if (board[0][7].color == color && board[1][6].color == color && board[2][5].color == color &&
        board[3][4].color == color && board[4][3].color == color && board[5][2].color == color &&
        board[6][1].color == color && board[7][0].color == color) {
        return true;
    }

    // Check if it's a draw
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].color == 0) {
                return false;
            }
        }
    }
    return true;
}

// Define a function to play the game
void playGame() {
    initBoard();
    int turn = BLACK;

    while (true) {
        printf("Player %d's turn:\n", turn == BLACK? 1 : 2);
        printf("1. Move\n");
        printf("2. End turn\n");
        printf("3. Quit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter coordinates of piece to move: ");
                int x, y;
                scanf("%d %d", &x, &y);

                if (board[x][y].color == turn) {
                    printf("Enter coordinates of destination: ");
                    int dx, dy;
                    scanf("%d %d", &dx, &dy);

                    if (isLegalMove(dx, dy, turn)) {
                        makeMove(dx, dy, turn);
                    } else {
                        printf("Illegal move!\n");
                    }
                } else {
                    printf("Invalid move!\n");
                }
                break;
            case 2:
                turn = (turn == BLACK? WHITE : BLACK);
                break;
            case 3:
                printf("Game over!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}

int main() {
    playGame();
    return 0;
}