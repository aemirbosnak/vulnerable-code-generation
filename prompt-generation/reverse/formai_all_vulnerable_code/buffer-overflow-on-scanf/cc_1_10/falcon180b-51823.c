//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MATCH_PAIRS 4

int board[ROWS][COLS];
int match_pairs[MATCH_PAIRS];

void init_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = -1;
        }
    }
}

void init_match_pairs() {
    for (int i = 0; i < MATCH_PAIRS; i++) {
        match_pairs[i] = rand() % (ROWS * COLS);
    }
}

void print_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_match(int row, int col) {
    if (board[row][col]!= -1) {
        return board[row][col];
    } else {
        return -1;
    }
}

void flip_card(int row, int col) {
    if (check_match(row, col) == -1) {
        board[row][col] = rand() % MATCH_PAIRS;
    } else {
        board[row][col] = -1;
    }
}

int main() {
    srand(time(NULL));
    init_board();
    init_match_pairs();

    int moves = 0;
    int matches = 0;
    int game_over = 0;

    while (!game_over) {
        print_board();
        int row, col;
        printf("Enter your move (row and column): ");
        scanf("%d %d", &row, &col);
        if (row >= ROWS || col >= COLS || row < 0 || col < 0) {
            printf("Invalid move!\n");
            continue;
        }
        if (check_match(row, col) == -1) {
            flip_card(row, col);
            moves++;
        } else {
            matches++;
            flip_card(row, col);
            if (matches == MATCH_PAIRS) {
                game_over = 1;
                printf("Congratulations! You won in %d moves!\n", moves);
            }
        }
    }

    return 0;
}