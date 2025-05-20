//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BINGOS 5
#define BINGO_WIDTH 7
#define BINGO_HEIGHT 5

// Define the bingo board structure
struct bingo_board {
    char board[BINGO_HEIGHT][BINGO_WIDTH];
    char filled_spots[BINGO_HEIGHT][BINGO_WIDTH];
};

struct bingo_board create_bingo_board() {
    struct bingo_board board;
    for (int i = 0; i < BINGO_HEIGHT; i++) {
        for (int j = 0; j < BINGO_WIDTH; j++) {
            board.board[i][j] = '_';
            board.filled_spots[i][j] = 0;
        }
    }
    return board;
}

void print_bingo_board(struct bingo_board board) {
    for (int i = 0; i < BINGO_HEIGHT; i++) {
        for (int j = 0; j < BINGO_WIDTH; j++) {
            printf("%c ", board.board[i][j]);
        }
        printf("\n");
    }
}

void draw_bingo_ball(struct bingo_board board, int ball) {
    if (board.board[ball / 5][ball % 5] == '_') {
        board.filled_spots[ball / 5][ball % 5] = 1;
        printf("Drawing ball %d: ", ball);
        printf(" ");
        for (int i = 0; i < BINGO_HEIGHT; i++) {
            for (int j = 0; j < BINGO_WIDTH; j++) {
                if (board.filled_spots[i][j] == 1) {
                    printf("X");
                } else {
                    printf("_");
                }
            }
            printf("\n");
        }
        printf("Bingo!\n");
    }
}

int main() {
    struct bingo_board board = create_bingo_board();
    srand(time(NULL));

    int ball;
    int num_balls_drawn = 0;
    while (num_balls_drawn < NUM_BINGOS) {
        ball = rand() % 75;
        draw_bingo_ball(board, ball);
        num_balls_drawn++;
    }

    print_bingo_board(board);

    return 0;
}