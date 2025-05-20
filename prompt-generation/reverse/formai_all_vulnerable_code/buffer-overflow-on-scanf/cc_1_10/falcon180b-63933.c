//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define ROWS 4
#define COLS 5

void init_board(char *board) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i * COLS + j] = '*';
        }
    }
}

void print_board(char *board) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i * COLS + j]);
        }
        printf("\n");
    }
}

int is_valid_move(int row, int col, char *board) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row * COLS + col] == '*') {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    char board[ROWS * COLS];
    init_board(board);
    int player = 1;
    int moves = 0;
    int matches = 0;
    while (matches < ROWS * COLS / 2) {
        printf("Player %d's turn\n", player);
        print_board(board);
        char move;
        int row, col;
        while (1) {
            printf("Enter your move (row,col): ");
            scanf("%d,%d", &row, &col);
            if (is_valid_move(row, col, board)) {
                move = toupper(board[row * COLS + col]);
                board[row * COLS + col] = '*';
                if (player == 1) {
                    printf("You picked %c\n", move);
                } else {
                    printf("CPU picked %c\n", move);
                }
                if (move == '*') {
                    printf("Invalid move. Try again.\n");
                } else if (row == col) {
                    printf("You win!\n");
                    return 0;
                } else if (row + col == COLS - 1) {
                    printf("You lose!\n");
                    return 0;
                } else {
                    matches++;
                    if (matches >= ROWS * COLS / 2) {
                        printf("Tie game.\n");
                        return 0;
                    }
                }
                break;
            } else {
                printf("Invalid move. Try again.\n");
            }
        }
        if (player == 1) {
            player = 2;
        } else {
            player = 1;
        }
        moves++;
    }
    return 0;
}