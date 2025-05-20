//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MATCH 1
#define NOT_MATCH 0

void init_board(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_match(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == '-') {
                return NOT_MATCH;
            }
        }
    }
    return MATCH;
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    init_board(board);
    int matches = 0;
    int turns = 0;
    while (1) {
        print_board(board);
        int row, col;
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == '-') {
            board[row][col] = 'X';
            if (check_match(board) == MATCH) {
                matches++;
            } else {
                board[row][col] = '-';
            }
        } else {
            printf("Invalid move.\n");
        }
        turns++;
        if (matches == COLS * ROWS / 2) {
            printf("Congratulations! You win in %d turns.\n", turns);
            break;
        } else if (turns == COLS * ROWS) {
            printf("Game over. You lose.\n");
            break;
        }
    }
    return 0;
}