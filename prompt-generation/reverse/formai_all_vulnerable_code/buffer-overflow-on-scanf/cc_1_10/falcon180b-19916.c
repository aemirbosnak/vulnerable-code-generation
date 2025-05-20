//Falcon-180B DATASET v1.0 Category: Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the game board
void printBoard(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the game is over
int checkWin(int board[3][3], int player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;

    return 0;
}

// Function to check if the game is a tie
int checkTie(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j]!= 1 && board[i][j]!= 2) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to get user input
int getInput(int player) {
    int choice;
    printf("Player %d's turn:\n", player);
    printf("Enter your move (1-9): ");
    scanf("%d", &choice);
    while (choice < 1 || choice > 9) {
        printf("Invalid move. Enter your move (1-9): ");
        scanf("%d", &choice);
    }
    return choice;
}

// Function to update the game board
void updateBoard(int board[3][3], int choice, int player) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                board[i][j] = player;
                if (checkWin(board, player)) {
                    printf("Player %d wins!\n", player);
                    exit(0);
                } else if (checkTie(board)) {
                    printf("Tie game.\n");
                    exit(0);
                }
                break;
            }
        }
    }
}

// Function to play the game
void playGame() {
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1;
    int choice;

    while (1) {
        printBoard(board);
        choice = getInput(player);
        updateBoard(board, choice, player);
        if (player == 1)
            player = 2;
        else
            player = 1;
    }
}

int main() {
    srand(time(NULL));
    playGame();
    return 0;
}