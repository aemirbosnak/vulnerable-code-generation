//FormAI DATASET v1.0 Category: Table Game ; Style: creative
#include <stdio.h>

char board[3][3]; // The game board

void initBoard() { // Initialize the game board
    for(int r = 0; r < 3; r++) {
        for(int c = 0; c < 3; c++) {
            board[r][c] = '_';
        }
    }
}

void printBoard() { // Print the game board
    for(int r = 0; r < 3; r++) {
        printf(" %c | %c | %c \n", board[r][0], board[r][1], board[r][2]);
        if(r < 2) {
            printf("---|---|---\n");
        }
    }
}

char checkForWinner() { // Check if there is a winner
    for(int i = 0; i < 3; i++) {
        // Check rows for winner
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0];
        }
        // Check columns for winner
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return board[0][i];
        }
    }
    // Check diagonals for winner
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return board[0][0];
    }
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return board[0][2];
    }
    return '_'; // No winner
}

void playGame() { // Play the game
    int row, col;
    char currentPlayer = 'X';
    while(checkForWinner() == '_') { // Game continues if no winner yet
        printBoard();
        printf("\nPlayer %c's turn. Enter row and column numbers (1-3) separated by a space: ", currentPlayer);
        scanf("%d %d", &row, &col);
        row--;
        col--;
        if(board[row][col] == '_') { // Make sure spot is available
            board[row][col] = currentPlayer;
            if(currentPlayer == 'X') {
                currentPlayer = 'O';
            } else {
                currentPlayer = 'X';
            }
        } else {
            printf("That spot is already taken. Try again.\n");
        }
    }
    printBoard();
    printf("\nPlayer %c wins!\n", checkForWinner());
}

int main() {
    printf("Welcome to Tic-Tac-Toe!\n\n");
    initBoard();
    playGame();
    return 0;
}