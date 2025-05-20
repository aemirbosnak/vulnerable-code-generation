//Falcon-180B DATASET v1.0 Category: Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print the game board
void print_board(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if there is a winner
int check_winner(char board[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

// Function to check if the move is valid
int check_move(char board[3][3], int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == '-') {
        return 1;
    }
    return 0;
}

// Function to make a move
void make_move(char board[3][3], int row, int col, char player) {
    if (check_move(board, row, col)) {
        board[row][col] = player;
    }
}

// Function to play the game
void play_game() {
    char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    char player = 'X';
    int row, col;

    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1: X, Player 2: O\n");
    printf("Please enter your move (row and column): ");
    scanf("%d %d", &row, &col);

    while (1) {
        make_move(board, row, col, player);

        if (check_winner(board)) {
            printf("\n%c wins!\n", player);
            break;
        }

        if (check_move(board, row, col)) {
            printf("\nInvalid move, please try again.\n");
            continue;
        }

        if (player == 'X') {
            player = 'O';
        } else {
            player = 'X';
        }

        printf("\nBoard:\n");
        print_board(board);

        printf("\nPlayer %c's turn:\n", player);
        scanf("%d %d", &row, &col);
    }
}

int main() {
    srand(time(NULL));
    play_game();
    return 0;
}