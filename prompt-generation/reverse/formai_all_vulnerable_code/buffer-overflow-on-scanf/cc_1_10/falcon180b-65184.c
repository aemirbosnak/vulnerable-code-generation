//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define NUM_CARDS 8
#define MATCH 1
#define MISMATCH 0
#define FLIP_DELAY 1000 // milliseconds

int board[ROWS][COLS];
int flipped[ROWS][COLS];
int matches = 0;
int attempts = 0;
int game_over = 0;

void init_board() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = -1;
            flipped[i][j] = 0;
        }
    }
}

void shuffle_board() {
    int i, j, k;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            k = rand() % NUM_CARDS;
            board[i][j] = k;
        }
    }
}

void draw_board() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                printf("_ ");
            } else {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

void flip_card(int row, int col) {
    if (flipped[row][col]) {
        printf("Card is already flipped.\n");
        return;
    }
    int card = board[row][col];
    if (card == -1) {
        printf("Card is already flipped.\n");
        return;
    }
    flipped[row][col] = 1;
    attempts++;
    if (card == matches) {
        matches++;
    } else {
        printf("Mismatch.\n");
        game_over = 1;
    }
    usleep(FLIP_DELAY);
    flipped[row][col] = 0;
}

int main() {
    srand(time(NULL));
    init_board();
    shuffle_board();
    int row, col;
    while (!game_over) {
        draw_board();
        printf("Enter row and column: ");
        scanf("%d%d", &row, &col);
        if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
            flip_card(row, col);
        } else {
            printf("Invalid input.\n");
        }
    }
    printf("Game over.\n");
    printf("Matches: %d\n", matches);
    printf("Attempts: %d\n", attempts);
    return 0;
}