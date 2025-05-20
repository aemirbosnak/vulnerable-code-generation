//FormAI DATASET v1.0 Category: Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to initialize the game board with random numbers
void initializeBoard(int board[3][3]) {
    srand(time(NULL));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = rand() % 10;
        }
    }
}

// function to display the game board
void displayBoard(int board[3][3]) {
    printf("\nTIC TAC TOE\n\n");
    for (int i = 0; i < 3; i++) {
        printf("-------------\n");
        printf("| %d | %d | %d |\n", board[i][0], board[i][1], board[i][2]);
    }
    printf("-------------\n");
}

// function to check if there is a winner
int checkWinner(int board[3][3]) {
    int winner = 0;
    // checking rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            winner = board[i][0];
        }
    }
    // checking columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            winner = board[0][i];
        }
    }
    // checking diagonal
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        winner = board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        winner = board[0][2];
    }
    return winner;
}

// function to play the game
void playGame() {
    int board[3][3];
    int currentPlayer = 1;
    int winner = 0;
    initializeBoard(board);
    while (winner == 0) {
        displayBoard(board);
        int row, col;
        printf("Player %d's turn\n", currentPlayer);
        printf("Enter row (0-2): ");
        scanf("%d", &row);
        printf("Enter column (0-2): ");
        scanf("%d", &col);
        if (board[row][col] == 0) {
            board[row][col] = currentPlayer;
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
            winner = checkWinner(board);
        } else {
            printf("Invalid move\n");
        }
    }
    displayBoard(board);
    printf("Player %d wins!\n", winner);
}

// main function
int main() {
    playGame();
    return 0;
}