//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Function to print the game board
void print_board(char board[3][3]) {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

// Function to check if a cell is empty
int is_cell_empty(char board[3][3], int row, int col) {
    return (board[row][col] == ' ');
}

// Function to check if a player has won
int evaluate(char board[3][3], char player) {
    int row, col;

    // Check rows
    for (row = 0; row < 3; row++) {
        if (board[row][0] == player && board[row][1] == player && board[row][2] == player)
            return 1;
    }

    // Check columns
    for (col = 0; col < 3; col++) {
        if (board[0][col] == player && board[1][col] == player && board[2][col] == player)
            return 1;
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;

    return 0;
}

// Function to simulate player's move
void simulate_player_move(char board[3][3], int *row, int *col) {
    printf("\nYour turn. Enter row and column numbers separated by a space: ");
    scanf("%d %d", row, col);
    while (!is_cell_empty(board, *row, *col)) {
        printf("\nThat cell is already occupied. Enter row and column numbers separated by a space: ");
        scanf("%d %d", row, col);
    }
    board[*row][*col] = 'X';
}

// Function to simulate AI move
void simulate_ai_move(char board[3][3], int *row, int *col) {
    int i, j, score, best_score = -1000;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (is_cell_empty(board, i, j)) {
                board[i][j] = 'O';
                score = minimax(board, 0, 0);
                board[i][j] = ' ';
                if (score > best_score) {
                    best_score = score;
                    *row = i;
                    *col = j;
                }
            }
        }
    }
    board[*row][*col] = 'O';
}

// Function to evaluate the game state recursively
int minimax(char board[3][3], int depth, int maximizing_player) {
    int i, j, score;

    if (evaluate(board, 'O')) {
        return 10 - depth;
    }

    if (evaluate(board, 'X')) {
        return depth - 10;
    }

    if (!is_moves_left(board)) {
        return 0;
    }

    if (maximizing_player) {
        int best_score = -1000;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (is_cell_empty(board, i, j)) {
                    board[i][j] = 'O';
                    score = minimax(board, depth + 1, 0);
                    board[i][j] = ' ';
                    if (score > best_score) {
                        best_score = score;
                    }
                }
            }
        }
        return best_score;
    } else {
        int best_score = 1000;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (is_cell_empty(board, i, j)) {
                    board[i][j] = 'X';
                    score = minimax(board, depth + 1, 1);
                    board[i][j] = ' ';
                    if (score < best_score) {
                        best_score = score;
                    }
                }
            }
        }
        return best_score;
    }
}

// Function to check if any more moves are available
int is_moves_left(char board[3][3]) {
    int row, col;

    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            if (is_cell_empty(board, row, col)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int row, col;
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    printf("Welcome to Tic Tac Toe!\n");
    printf("You are playing as X and the computer is playing as O\n");
    printf("The first player to get 3 in a row wins.\n");
    printf("The game board is numbered from 0 to 2, as shown below:\n");
    printf(" 0 | 1 | 2 \n");
    printf("---+---+---\n");
    printf(" 3 | 4 | 5 \n");
    printf("---+---+---\n");
    printf(" 6 | 7 | 8 \n");

    while (1) {
        // simulate player move
        print_board(board);
        simulate_player_move(board, &row, &col);
        if (evaluate(board, 'X')) {
            print_board(board);
            printf("\nCongratulations! You have won the game!\n");
            break;
        }
        if (!is_moves_left(board)) {
            print_board(board);
            printf("\nGame over. It's a tie.\n");
            break;
        }

        // simulate AI move
        print_board(board);
        printf("\nComputer is thinking...\n");
        simulate_ai_move(board, &row, &col);
        if (evaluate(board, 'O')) {
            print_board(board);
            printf("\nSorry, you lost. Better luck next time!\n");
            break;
        }
        if (!is_moves_left(board)) {
            print_board(board);
            printf("\nGame over. It's a tie.\n");
            break;
        }
    }

    return 0;
}