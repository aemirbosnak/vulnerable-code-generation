//FormAI DATASET v1.0 Category: Table Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display the Tic-Tac-Toe board
void display_board(char board[]) {
    printf("\n");
    printf(" %c | %c | %c  \n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c  \n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c  \n\n", board[6], board[7], board[8]);
}

// Function to check if there is a winner
int winner(char board[]) {
    // Check if there is a row win
    for (int i = 0; i < 9; i += 3) {
        if (board[i] != '-' && board[i] == board[i + 1] && board[i + 1] == board[i + 2]) {
            return 1;
        }
    }
    // Check if there is a column win
    for (int i = 0; i < 3; i++) {
        if (board[i] != '-' && board[i] == board[i + 3] && board[i + 3] == board[i + 6]) {
            return 1;
        }
    }
    // Check if there is a diagonal win
    if (board[0] != '-' && board[0] == board[4] && board[4] == board[8]) {
        return 1;
    }
    if (board[2] != '-' && board[2] == board[4] && board[4] == board[6]) {
        return 1;
    }
    // Check if the board is full
    for (int i = 0; i < 9; i++) {
        if (board[i] == '-') {
            return 0;
        }
    }
    // If no winner and the board is full, it's a tie game
    return -1;
}

int main() {
    char board[9] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
    int player = 1;
    int position = 0;
    int result = 0;

    printf("Welcome to the Happy Tic-Tac-Toe Game!\n");
    printf("Player 1: X\n");
    printf("Player 2: O\n");
    display_board(board);

    while (result == 0) {
        printf("Player %d, enter a position (1-9): ", player);
        scanf("%d", &position);
        fflush(stdin);

        if (position < 1 || position > 9) {
            printf("Invalid input, please enter a number between 1 and 9.\n");
        }
        else if (board[position - 1] != '-') {
            printf("That position is already taken, please try a different one.\n");
        }
        else {
            if (player == 1) {
                board[position - 1] = 'X';
                player = 2;
            }
            else {
                board[position - 1] = 'O';
                player = 1;
            }
            display_board(board);
            result = winner(board);
        }
    }

    if (result == 1) {
        printf("Congratulations Player %d, you won!\n", player);
    }
    else {
        printf("It's a tie game!\n");
    }

    return 0;
}