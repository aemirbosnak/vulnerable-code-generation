//FormAI DATASET v1.0 Category: Table Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the board size
#define ROWS 3
#define COLS 3

// Function to display the board
void displayBoard(int board[][COLS]) {
    printf("\n");

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf(" %d ", board[i][j]);
            if(j != COLS - 1) {
                printf("|");
            }
        }
        printf("\n");
        if(i != ROWS - 1) {
            printf("---|---|---\n");
        }
    }

    printf("\n");
}

// Function to check if a player has won
bool checkWin(int board[][COLS], int player) {
    int row, col;

    for(row = 0; row < ROWS; row++) {
        if(board[row][0] == player && board[row][1] == player && board[row][2] == player) {
            return true;
        }
    }

    for(col = 0; col < COLS; col++) {
        if(board[0][col] == player && board[1][col] == player && board[2][col] == player) {
            return true;
        }
    }

    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }

    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

// Function to check if a move is valid
bool isValidMove(int board[][COLS], int row, int col) {
    if(row < 0 || row > ROWS - 1) {
        return false;
    }

    if(col < 0 || col > COLS - 1) {
        return false;
    }

    if(board[row][col] != 0) {
        return false;
    }

    return true;
}

int main() {
    int board[ROWS][COLS];
    int player = 1;
    int row, col;

    // Set all board locations to 0
    for(row = 0; row < ROWS; row++) {
        for(col = 0; col < COLS; col++) {
            board[row][col] = 0;
        }
    }

    printf("*** Welcome to the Tic Tac Toe Game! ***\n\n");

    // Randomly choose who starts first
    srand(time(NULL));
    player = rand() % 2 + 1;

    printf("Player %d has been randomly chosen to start the game!\n\n", player);

    while(true) {
        displayBoard(board);

        // Get player's move
        printf("Player %d - Enter the row and column where you want to place your %s (e.g. 1 2):\n", player, player == 1 ? "X" : "O");
        scanf("%d %d", &row, &col);

        if(!isValidMove(board, row - 1, col - 1)) {
            printf("\nInvalid move! Please try again.\n\n");
            continue;
        }

        // Place the move on the board
        board[row - 1][col - 1] = player;

        // Check if the player has won
        if(checkWin(board, player)) {
            displayBoard(board);
            printf("Congratulations! Player %d has won the game!\n", player);
            break;
        }

        // Check if the board is full
        bool boardFull = true;
        for(row = 0; row < ROWS; row++) {
            for(col = 0; col < COLS; col++) {
                if(board[row][col] == 0) {
                    boardFull = false;
                    break;
                }
            }
        }

        // If the board is full with no winner, it's a draw
        if(boardFull) {
            displayBoard(board);
            printf("The game has ended in a draw!\n");
            break;
        }

        // Switch to the other player
        player = player == 1 ? 2 : 1;
    }

    printf("\nThank you for playing Tic Tac Toe! Goodbye!\n");

    return 0;
}