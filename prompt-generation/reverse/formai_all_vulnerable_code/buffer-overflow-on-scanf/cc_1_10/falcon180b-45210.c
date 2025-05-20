//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 4

int board[ROWS][COLS];

void init_board(void) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = -1;
        }
    }
}

void print_board(void) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return 0;
    }
    if (board[row][col]!= -1) {
        return 0;
    }
    return 1;
}

void flip_card(int row, int col) {
    if (!is_valid_move(row, col)) {
        return;
    }
    int card = 1 + rand() % 13;
    board[row][col] = card;
}

void check_match(int row, int col) {
    int card1 = board[row][col];
    int card2 = board[row][col + 1];
    if (card1 == -1 || card2 == -1) {
        return;
    }
    if (card1 == card2) {
        board[row][col] = -1;
        board[row][col + 1] = -1;
        return;
    }
    board[row][col] = -1;
    board[row][col + 1] = -1;
}

int main(void) {
    srand(time(NULL));
    init_board();
    int moves = 0;
    while (1) {
        print_board();
        int row, col;
        printf("Enter your move (row col): ");
        scanf("%d %d", &row, &col);
        if (!is_valid_move(row, col)) {
            printf("Invalid move.\n");
            continue;
        }
        flip_card(row, col);
        check_match(row, col);
        moves++;
        if (moves == 12) {
            printf("You win!\n");
            break;
        }
    }
    return 0;
}