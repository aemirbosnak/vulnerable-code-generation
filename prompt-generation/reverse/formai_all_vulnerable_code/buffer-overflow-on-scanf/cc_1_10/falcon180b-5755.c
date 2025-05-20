//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define NUM_CARDS 8
#define MATCH 1
#define NO_MATCH 0
#define FLIP_TIME 1000

int board[ROWS][COLS];
int flipped[ROWS][COLS];
int match_count;

void init_board() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = -1;
            flipped[i][j] = 0;
        }
    }
}

void flip_card(int row, int col) {
    board[row][col] = rand() % NUM_CARDS;
    flipped[row][col] = FLIP_TIME;
}

void draw_board() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (flipped[i][j] > 0) {
                flipped[i][j]--;
            }
            if (board[i][j] >= 0) {
                printf(" %d ", board[i][j]);
            } else {
                printf("? ");
            }
        }
        printf("\n");
    }
}

int check_match(int row1, int col1, int row2, int col2) {
    if (board[row1][col1] == board[row2][col2]) {
        return MATCH;
    } else {
        return NO_MATCH;
    }
}

void play_game() {
    int i, j, match_found;
    init_board();
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            flip_card(i, j);
        }
    }
    while (match_count < NUM_CARDS) {
        draw_board();
        printf("Enter two card positions to flip: ");
        scanf("%d %d", &i, &j);
        if (check_match(i, j, i, j) == MATCH) {
            match_count++;
        } else {
            flip_card(i, j);
            flip_card(i, j);
        }
    }
    printf("Congratulations! You won the game in %d turns.\n", match_count + 2 * ROWS * COLS);
}

int main() {
    play_game();
    return 0;
}