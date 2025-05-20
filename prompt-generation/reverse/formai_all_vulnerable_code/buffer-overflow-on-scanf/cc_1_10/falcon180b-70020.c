//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 6
#define NUM_PAIRS 10

int board[MAX_ROWS][MAX_COLS] = {{0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}};
int pair[NUM_PAIRS][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}, {11, 12}, {13, 14}, {15, 16}, {17, 18}, {19, 20}};
int num_pairs = 0;
int num_moves = 0;
int player = 1;

void init_board() {
    srand(time(NULL));
    for (int i = 0; i < NUM_PAIRS; i++) {
        int row = rand() % MAX_ROWS;
        int col = rand() % MAX_COLS;
        board[row][col] = i + 1;
        pair[i][0] = row;
        pair[i][1] = col;
    }
}

void print_board() {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (board[i][j] == 0) {
                printf("_ ");
            } else {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

int check_win() {
    for (int i = 0; i < NUM_PAIRS; i++) {
        int row1 = pair[i][0];
        int col1 = pair[i][1];
        int row2 = pair[i+1][0];
        int col2 = pair[i+1][1];
        if (row1 == row2 && col1 == col2) {
            return 0;
        }
    }
    return 1;
}

int main() {
    init_board();
    print_board();
    while (num_pairs < NUM_PAIRS) {
        int row, col;
        printf("Player %d's turn. Enter row and column: ", player);
        scanf("%d%d", &row, &col);
        if (row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS && board[row][col] == 0) {
            board[row][col] = player;
            num_moves++;
            if (check_win()) {
                printf("Player %d wins!\n", player);
                break;
            } else {
                player =!player;
            }
        } else {
            printf("Invalid move.\n");
        }
    }
    printf("Number of moves: %d\n", num_moves);
    return 0;
}