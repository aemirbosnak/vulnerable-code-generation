//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void init_board(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            board[i][j] = '-';
        }
    }
}

void print_board(const char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    init_board(board);

    int player = 1;
    int choice;
    int correct_guesses = 0;

    while (correct_guesses < ROWS * COLS) {
        print_board(board);
        printf("Player %d, choose a position: ", player);
        scanf("%d", &choice);

        int row = choice / COLS;
        int col = choice % COLS;

        if (board[row][col] == '-') {
            board[row][col] = 'X';

            if (player == 1) {
                int value = get_random_number(1, 100);
                printf("You guessed correctly! The value was %d.\n", value);
                ++correct_guesses;
            } else {
                printf("Sorry, that position has already been chosen.\n");
            }
        } else {
            printf("Sorry, that position has already been chosen.\n");
        }

        if (correct_guesses >= ROWS * COLS) {
            printf("Congratulations, you win!\n");
            break;
        }

        player =!player;
    }

    return 0;
}