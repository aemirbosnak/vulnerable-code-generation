//Falcon-180B DATASET v1.0 Category: Game of Life ; Style: brave
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50
#define BOARD_SIZE (WIDTH * HEIGHT)
#define NEIGHBOR_COUNT 8

int board[BOARD_SIZE];

void initializeBoard(int seed) {
    srand(seed);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = rand() % 2;
    }
}

void printBoard() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d", board[i * WIDTH + j]);
        }
        printf("\n");
    }
}

void nextGeneration() {
    int newBoard[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        int count = 0;
        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                int index = (i + j * WIDTH + k * HEIGHT) % BOARD_SIZE;
                if (index >= 0 && index < BOARD_SIZE) {
                    count += board[index];
                }
            }
        }
        newBoard[i] = count == 3 || (count == 2 && board[i]);
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = newBoard[i];
    }
}

int main(int argc, char *argv[]) {
    int seed;
    if (argc > 1) {
        seed = atoi(argv[1]);
    } else {
        seed = time(NULL);
    }
    initializeBoard(seed);
    printBoard();
    for (int i = 0; i < 10; i++) {
        nextGeneration();
        printBoard();
        usleep(100000);
    }
    return 0;
}