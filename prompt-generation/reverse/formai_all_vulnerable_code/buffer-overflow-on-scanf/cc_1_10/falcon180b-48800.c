//Falcon-180B DATASET v1.0 Category: Table Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

// Function to print the game board
void print_board(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// Function to initialize the game board
void init_board(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

// Function to check if a player has won
int check_win(char board[ROWS][COLS], char symbol) {
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return 1;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return 1;
    }

    return 0;
}

// Function to get input from the user
char get_input() {
    char input;
    printf("Enter your move: ");
    scanf("%c", &input);
    return input;
}

// Function to check if a move is valid
int is_valid_move(char board[ROWS][COLS], int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == '-') {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    init_board(board);
    int player = 1;
    while (1) {
        print_board(board);
        char input = get_input();
        int row, col;
        for (row = 0; row < ROWS; row++) {
            for (col = 0; col < COLS; col++) {
                if (board[row][col] == input) {
                    board[row][col] = (player % 2 == 0)? 'X' : 'O';
                    if (check_win(board, board[row][col])) {
                        printf("%c wins!\n", board[row][col]);
                        break;
                    }
                    player++;
                    init_board(board);
                }
            }
        }
        if (player % 2 == 0) {
            printf("Player 1's turn.\n");
        } else {
            printf("Player 2's turn.\n");
        }
    }

    return 0;
}