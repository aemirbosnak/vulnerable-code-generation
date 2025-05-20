//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

typedef struct {
    int alive;
    int dead;
} cell;

int width, height, num_generations;
cell **board;

int is_alive(cell c) {
    return c.alive == 1;
}

void init_board(int width, int height) {
    num_generations = 0;
    srand(time(NULL));

    board = (cell **)malloc(width * sizeof(cell *));
    for (int i = 0; i < width; i++) {
        board[i] = (cell *)malloc(height * sizeof(cell));
    }

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            board[i][j].alive = rand() % 2 == 0;
            board[i][j].dead =!board[i][j].alive;
        }
    }
}

void print_board() {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (is_alive(board[i][j])) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void step() {
    num_generations++;

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int neighbors = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int new_i = i + dx;
                    int new_j = j + dy;
                    if (new_i >= 0 && new_i < width && new_j >= 0 && new_j < height) {
                        if (is_alive(board[new_i][new_j])) {
                            neighbors++;
                        }
                    }
                }
            }

            if (board[i][j].alive) {
                if (neighbors < 2 || neighbors > 3) {
                    board[i][j].alive = 0;
                } else {
                    board[i][j].alive = 1;
                }
            } else {
                if (neighbors == 3) {
                    board[i][j].alive = 1;
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int width, height;
    printf("Enter width: ");
    scanf("%d", &width);
    printf("Enter height: ");
    scanf("%d", &height);

    init_board(width, height);

    while (num_generations < 100) {
        step();
        print_board();
    }

    return 0;
}