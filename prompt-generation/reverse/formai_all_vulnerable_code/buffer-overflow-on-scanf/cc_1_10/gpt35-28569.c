//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 3
#define COLS 3

/* Function prototypes */
void initialize_board(char board[ROWS][COLS]);
void print_board(char board[ROWS][COLS]);
bool is_board_full(char board[ROWS][COLS]);
bool is_winner(char board[ROWS][COLS], char symbol);
void get_player_move(int *row, int *col);
void get_computer_move(char board[ROWS][COLS], int *row, int *col);
void make_move(char board[ROWS][COLS], int row, int col, char symbol);

/* Main function */
int main(void) {
    char board[ROWS][COLS];
    char player_symbol, computer_symbol;
    bool is_player_turn = true;

    initialize_board(board);

    // Ask user to choose a symbol (X or O)
    printf("Choose a symbol (X or O): ");
    scanf(" %c", &player_symbol);
    computer_symbol = (player_symbol == 'X') ? 'O' : 'X';

    // Main game loop
    while (true) {
        // Print current state of board
        print_board(board);

        // Check for winner
        if (is_winner(board, player_symbol)) {
            printf("Congratulations! You win!\n");
            break;
        } else if (is_winner(board, computer_symbol)) {
            printf("Sorry, you lose.\n");
            break;
        }

        // Check if board is full
        if (is_board_full(board)) {
            printf("It's a draw!\n");
            break;
        }

        // Get player/computer move
        int row, col;
        if (is_player_turn) {
            get_player_move(&row, &col);
            make_move(board, row, col, player_symbol);
            is_player_turn = false;
        } else {
            get_computer_move(board, &row, &col);
            printf("Computer moves to (%d, %d)\n", row+1, col+1);
            make_move(board, row, col, computer_symbol);
            is_player_turn = true;
        }
    }

    return 0;
}

/* Function definitions */

void initialize_board(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board(char board[ROWS][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf(" %c | %c | %c \n",
            board[i][0], board[i][1], board[i][2]);
        if (i != ROWS - 1) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

bool is_board_full(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool is_winner(char board[ROWS][COLS], char symbol) {
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return true;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return true;
    }

    return false;
}

void get_player_move(int *row, int *col) {
    // Ask user for row and column
    printf("Enter row number (1-3) and column number (1-3): ");
    scanf("%d %d", row, col);
    (*row)--;
    (*col)--;  // Adjust for 0-based indexing
}

void get_computer_move(char board[ROWS][COLS], int *row, int *col) {
    // Simple AI implementation: randomly choose a valid move
    srand(time(NULL));  // Seed random number generator

    while (true) {
        *row = rand() % ROWS;
        *col = rand() % COLS;
        if (board[*row][*col] == ' ') {
            break;
        }
    }
}

void make_move(char board[ROWS][COLS], int row, int col, char symbol) {
    board[row][col] = symbol;
}