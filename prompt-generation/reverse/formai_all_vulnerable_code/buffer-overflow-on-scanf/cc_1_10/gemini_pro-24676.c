//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Constants
#define BOARD_SIZE 20
#define MAX_GENERATIONS 100

// Cell states
#define DEAD 0
#define ALIVE 1

// Board
int board[BOARD_SIZE][BOARD_SIZE];

// Function to initialize the board
void init_board() {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = DEAD;
        }
    }
}

// Function to print the board
void print_board() {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == DEAD) {
                printf(".");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

// Function to count the number of living neighbors of a cell
int count_neighbors(int x, int y) {
    int i, j;
    int count = 0;

    for (i = x - 1; i <= x + 1; i++) {
        for (j = y - 1; j <= y + 1; j++) {
            if (i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE) {
                if (board[i][j] == ALIVE) {
                    count++;
                }
            }
        }
    }

    if (board[x][y] == ALIVE) {
        count--;
    }

    return count;
}

// Function to update the board to the next generation
void update_board() {
    int i, j;
    int next_board[BOARD_SIZE][BOARD_SIZE];

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            int neighbors = count_neighbors(i, j);

            if (board[i][j] == ALIVE) {
                if (neighbors == 2 || neighbors == 3) {
                    next_board[i][j] = ALIVE;
                } else {
                    next_board[i][j] = DEAD;
                }
            } else {
                if (neighbors == 3) {
                    next_board[i][j] = ALIVE;
                } else {
                    next_board[i][j] = DEAD;
                }
            }
        }
    }

    memcpy(board, next_board, sizeof(board));
}

// Function to run the game of life for a given number of generations
void run_game(int generations) {
    int i;

    for (i = 0; i < generations; i++) {
        printf("Generation %d\n", i);
        print_board();
        update_board();
    }
}

// Main function
int main() {
    int generations;

    printf("Welcome to the Game of Life, Mr. Holmes!\n");
    printf("How many generations would you like to simulate?\n");
    scanf("%d", &generations);

    init_board();
    run_game(generations);

    return 0;
}