//FormAI DATASET v1.0 Category: Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void displayBoard(char board[3][3]);
int checkWin(char board[3][3]);

int main(void) {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int player = 1, row, col, turn = 0;

    // Seed random number generator for computer's moves
    srand(time(NULL));

    while (checkWin(board) == 0) {
        // Display the board
        printf("Turn %d\n\n", turn + 1);
        displayBoard(board);

        if (player == 1) {
            // Player's turn
            printf("Player's turn (X):\n");
            printf("Enter row number (1-3): ");
            scanf("%d", &row);
            printf("Enter column number (1-3): ");
            scanf("%d", &col);

            // Check for valid move
            if (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ') {
                printf("Invalid move. Please try again.\n\n");
                continue;
            }

            // Make the move
            board[row-1][col-1] = 'X';
        }
        else {
            // Computer's turn
            printf("Computer's turn (O):\n");
            row = rand() % 3;
            col = rand() % 3;

            // Check for valid move
            while (board[row][col] != ' ') {
                row = rand() % 3;
                col = rand() % 3;
            }

            // Make the move
            board[row][col] = 'O';
        }

        // Update turn and player
        turn++;
        player = turn % 2 == 0 ? 2 : 1;
    }

    // Display final board and winner
    displayBoard(board);
    if (checkWin(board) == 1) {
        printf("Player (X) wins!\n");
    }
    else {
        printf("Computer (O) wins!\n");
    }

    return 0;
}

// Display the tic-tac-toe board
void displayBoard(char board[3][3]) {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]);
}

// Check for a win or tie
int checkWin(char board[3][3]) {
    // Check rows
    for (int row = 0; row < 3; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][0] != ' ') {
            return board[row][0] == 'X' ? 1 : 2;
        }
    }

    // Check columns
    for (int col = 0; col < 3; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[0][col] != ' ') {
            return board[0][col] == 'X' ? 1 : 2;
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
            || (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return board[1][1] == 'X' ? 1 : 2;
    }

    // Check for tie
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == ' ') {
                return 0;
            }
        }
    }

    return 3;
}