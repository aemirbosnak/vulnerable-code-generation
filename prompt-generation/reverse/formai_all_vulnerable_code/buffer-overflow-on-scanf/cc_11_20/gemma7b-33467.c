//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main() {
    system("clear");
    char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    int turn = 0, win = 0;

    // Game loop
    while (!win && board[0] != 'X' && board[1] != 'X' && board[2] != 'X' && board[3] != 'X' && board[4] != 'X' && board[5] != 'X' && board[6] != 'X' && board[7] != 'X' && board[8] != 'X') {
        // Get player input
        int move;
        printf("Enter your move (1-9): ");
        scanf("%d", &move);

        // Validate move
        if (move < 1 || move > 9) {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Place piece
        board[move - 1] = 'X';

        // Check if player won
        win = checkWin(board, turn);

        // Next turn
        turn = (turn == 0) ? 1 : 0;
    }

    // Game over
    system("clear");
    printf("Game over! The winner is: ");
    if (win) {
        printf("You!\n");
    } else {
        printf("The computer.\n");
    }

    return 0;
}

int checkWin(char board[], int turn) {
    // Check rows
    for (int i = 0; i < 9; i++) {
        if (board[i] == board[i + 1] && board[i] == board[i + 2] && board[i] == board[i + 3] && board[i] == 'X') {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[i] == board[i + 3] && board[i] == board[i + 6] && board[i] == board[i + 9] && board[i] == 'X') {
            return 1;
        }
    }

    // Check diagonals
    if (board[0] == board[4] && board[0] == board[8] && board[0] == 'X') {
        return 1;
    }

    // No winner
    return 0;
}