//FormAI DATASET v1.0 Category: Table Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the game board
void printBoard(int board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf("-------------\n");
        printf("| %d | %d | %d |\n", board[i][0], board[i][1], board[i][2]);
    }
    printf("-------------\n");
}

// Function to check if a player has won the game
int checkWin(int board[3][3], int player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

// Function to choose the computer's move
void computerMove(int board[3][3], int computer) {
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != 0);
    board[row][col] = computer;
}

int main() {
    srand(time(NULL));

    // Initialize game variables
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1, computer = 2;
    int turn = 1, maxTurns = 9;
    int winner = 0;

    // Loop for the game
    while (turn <= maxTurns && winner == 0) {
        // Print board
        printBoard(board);

        // Determine whose turn it is
        if (turn % 2 == 1) {
            printf("\nPlayer's turn:\n");
            int row, col;
            printf("Enter row (1-3): ");
            scanf("%d", &row);
            printf("Enter column (1-3): ");
            scanf("%d", &col);
            while (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != 0) {
                printf("Invalid move. Enter row (1-3): ");
                scanf("%d", &row);
                printf("Invalid move. Enter column (1-3): ");
                scanf("%d", &col);
            }
            board[row-1][col-1] = player;
        } else {
            printf("\nComputer's turn:\n");
            computerMove(board, computer);
        }

        // Check for a win
        if (checkWin(board, player)) {
            printBoard(board);
            printf("\nPlayer wins!\n");
            winner = 1;
        } else if (checkWin(board, computer)) {
            printBoard(board);
            printf("\nComputer wins!\n");
            winner = 2;
        }

        turn++;
    }

    // Check for a tie
    if (winner == 0) {
        printBoard(board);
        printf("\nTie game!\n");
    }

    return 0;
}