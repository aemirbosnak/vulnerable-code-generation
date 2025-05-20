//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10
#define SITE 0
#define BLOCKED 1
#define PATH 2
#define DROP 3
#define FULL 4

int board[HEIGHT][WIDTH]; // The board where the percolation happens
int n_sites; // The number of open sites

void init_board() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = BLOCKED;
        }
    }
}

void create_path() {
    int x = rand() % WIDTH;
    int y = rand() % HEIGHT;
    board[y][x] = PATH;
    board[y-1][x] = PATH;
    board[y+1][x] = PATH;
    board[y][x-1] = PATH;
    board[y][x+1] = PATH;
}

void percolate() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (board[i][j] == PATH) {
                board[i][j] = DROP;
            }
        }
    }
}

void print_board() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (board[i][j] == BLOCKED) {
                printf("X ");
            } else if (board[i][j] == PATH) {
                printf("- ");
            } else if (board[i][j] == DROP) {
                printf("O ");
            } else if (board[i][j] == FULL) {
                printf("F ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    init_board();
    create_path();
    percolate();
    print_board();
    return 0;
}