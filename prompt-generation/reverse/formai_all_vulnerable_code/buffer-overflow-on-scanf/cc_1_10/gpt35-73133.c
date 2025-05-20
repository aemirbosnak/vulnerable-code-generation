//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int player = 1;
int board[3][3];
char marks[] = {'_', 'X', 'O'};

// Function to display the tic-tac-toe board
void display_board() {
    printf("   1   2   3\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i+1);
        for (int j = 0; j < 3; j++) {
            printf(" %c ", marks[board[i][j]]);
            if (j != 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i != 2) {
            printf("  -----------\n");
        }
    }
    printf("\n");
}

// Function to check for a winner
int check_winner() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    // Check for a tie
    bool is_full = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                is_full = false;
                break;
            }
        }
    }
    if (is_full) {
        return -1;
    }
    return 0;
}

// Function to get the player's move
void get_move() {
    int row, col;
    printf("Player %d's turn. Enter row and column (e.g. 1 2): \n", player);
    scanf("%d %d", &row, &col);
    // Check if the input is valid
    while (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != 0) {
        printf("Invalid input. Enter row and column (e.g. 1 2): \n");
        scanf("%d %d", &row, &col);
    }
    board[row-1][col-1] = player;
}

// Function to run the game
void play_game() {
    int winner = 0;
    while (winner == 0) {
        display_board();
        get_move();
        winner = check_winner();
        if (player == 1) {
            player = 2;
        } else {
            player = 1;
        }
    }
    display_board();
    if (winner == -1) {
        printf("Tie game!\n");
    } else {
        printf("Player %d wins!\n", winner);
    }
}

int main() {
    play_game();
    return 0;
}