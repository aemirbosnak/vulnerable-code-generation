//FormAI DATASET v1.0 Category: Table Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

char board[3][3]; // 3x3 Tic Tac Toe Board

int row, col;
char currentPlayer = 'X'; // Player 1 starts the game

void initBoard() {
    // Initialize all board cells to empty space
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    // Print Tic Tac Toe Board
    printf("\n-------------\n");
    for (int i = 0; i < 3; i++) {
        printf("| ");
        for (int j = 0; j < 3; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n-------------\n");
    }
}

int isBoardFull() {
    // Check if the board is full
    int isFull = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                isFull = 0;
                break;
            }
        }
        if (!isFull) {
            break;
        }
    }
    return isFull;
}

int checkForWin() {
    // Check if any player won the game
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ') {
        return 1;
    }
    return 0;
}

int main() {
    int choice;

    printf("TIC TAC TOE GAME\n");
    printf("PLAYER 1 - X\nPLAYER 2 - O\n");
    printf("Press Enter to start the game...");
    getchar(); // Wait for enter key press

    do {
        system("clear"); // Clear console screen
        printBoard(); // Print current board
        printf("PLAYER %c's turn:\n", currentPlayer); 
        printf("Enter row number (1-3): "); 
        scanf("%d", &row);
        printf("Enter column number (1-3): ");
        scanf("%d", &col);

        row--;
        col--;

        // Check if the cell is already occupied or is out of bounds
        if (board[row][col] != ' ' || row < 0 || col < 0 || row > 2 || col > 2) {
            printf("Invalid move, please try again.\n");
            printf("Press Enter to continue...");
            getchar(); // Wait for enter key press
            continue;
        }

        board[row][col] = currentPlayer; // Set current player's symbol on the board

        if (checkForWin()) {
            system("clear");
            printBoard();
            printf("PLAYER %c wins!\n", currentPlayer);
            printf("Press Enter to restart the game...");
            getchar(); // Wait for enter key press
            initBoard();
            continue;
        }

        if (isBoardFull()) {
            system("clear");
            printBoard();
            printf("Game ended in a draw.\n");
            printf("Press Enter to restart the game...");
            getchar(); // Wait for enter key press
            initBoard();
            continue;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch player turns

    } while (1);

    return 0;
}