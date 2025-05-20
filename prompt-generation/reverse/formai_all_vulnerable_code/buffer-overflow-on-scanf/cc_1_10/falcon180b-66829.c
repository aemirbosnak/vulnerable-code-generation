//Falcon-180B DATASET v1.0 Category: Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define WINNING_CONDITION (1 << BOARD_SIZE) - 1

// Function to initialize game board
void init_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

// Function to check if a move is valid
int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == '-') {
        return 1;
    }
    return 0;
}

// Function to check if a player has won
int check_win(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

// Function to print the game board
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to get player input
int get_input(char board[BOARD_SIZE][BOARD_SIZE], int player) {
    int row, col;
    printf("Player %d's turn:\n", player + 1);
    printf("Enter row and column (e.g. '0 0'): ");
    scanf("%d %d", &row, &col);
    if (!is_valid_move(board, row, col)) {
        printf("Invalid move.\n");
        return 0;
    }
    board[row][col] = (player == 1)? 'X' : 'O';
    return 1;
}

int main() {
    srand(time(NULL));
    int player = rand() % 2 + 1;
    char board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);

    while (1) {
        printf("Current board:\n");
        print_board(board);
        if (check_win(board, player)) {
            printf("Player %d wins!\n", player);
            break;
        }
        if (!get_input(board, player)) {
            continue;
        }
        if (check_win(board, player)) {
            printf("Player %d wins!\n", player);
            break;
        }
        player =!player;
    }

    return 0;
}