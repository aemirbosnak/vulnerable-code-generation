//Code Llama-13B DATASET v1.0 Category: Checkers Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void print_board(char board[8][8]);
void place_pieces(char board[8][8], char player);
void move_piece(char board[8][8], char player, int start_row, int start_col, int end_row, int end_col);
void check_win(char board[8][8], char player);

int main() {
    char board[8][8] = {0};
    char player = 'X';
    int start_row, start_col, end_row, end_col;

    // Initialize board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = '.';
        }
    }

    // Place pieces
    place_pieces(board, player);

    // Game loop
    while (1) {
        print_board(board);
        printf("Player %c, enter start position (row, col): ", player);
        scanf("%d %d", &start_row, &start_col);
        printf("Enter end position (row, col): ");
        scanf("%d %d", &end_row, &end_col);

        // Move piece
        move_piece(board, player, start_row, start_col, end_row, end_col);

        // Check for win
        check_win(board, player);

        // Switch player
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}

// Function definitions
void print_board(char board[8][8]) {
    printf("  1 2 3 4 5 6 7 8\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void place_pieces(char board[8][8], char player) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = player;
            }
        }
    }
}

void move_piece(char board[8][8], char player, int start_row, int start_col, int end_row, int end_col) {
    board[end_row][end_col] = player;
    board[start_row][start_col] = '.';
}

void check_win(char board[8][8], char player) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == player) {
                printf("Player %c wins!\n", player);
                exit(0);
            }
        }
    }
}