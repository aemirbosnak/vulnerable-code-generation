//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define NUM_PAIRS 8

int board[ROWS][COLS];
int pairs[NUM_PAIRS][2];
int num_pairs = 0;
int num_guesses = 0;
int score = 0;
int game_over = 0;

void init_board() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = -1;
        }
    }
}

void init_pairs() {
    int i;
    for (i = 0; i < NUM_PAIRS; i++) {
        pairs[i][0] = rand() % ROWS;
        pairs[i][1] = rand() % COLS;
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

void check_guess(int row, int col) {
    int i;
    for (i = 0; i < num_pairs; i++) {
        if (pairs[i][0] == row && pairs[i][1] == col) {
            board[row][col] = pairs[i][0] * ROWS + pairs[i][1] + 1;
            num_pairs--;
            score += 10;
        } else if (pairs[i][0] == row || pairs[i][1] == col) {
            board[row][col] = pairs[i][0] * ROWS + pairs[i][1] + 1;
            num_pairs--;
            score += 5;
        }
    }
    if (num_pairs == 0) {
        game_over = 1;
    }
}

void play_game() {
    int i, j;
    init_board();
    init_pairs();
    srand(time(NULL));
    int player_row, player_col;
    while (!game_over) {
        draw_board();
        printf("Score: %d\n", score);
        printf("Guesses left: %d\n", NUM_PAIRS - num_pairs);
        scanf("%d%d", &player_row, &player_col);
        check_guess(player_row, player_col);
        num_guesses++;
        if (num_guesses == 8) {
            game_over = 1;
        }
    }
    if (game_over) {
        draw_board();
        printf("Game over! Your score is %d.\n", score);
    }
}

int main() {
    play_game();
    return 0;
}