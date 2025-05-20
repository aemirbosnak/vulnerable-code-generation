//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_ROWS 5
#define NUM_COLS 5
#define MAX_BALLS 25
int main() {
    int board[NUM_ROWS][NUM_COLS];
    int balls[MAX_BALLS];
    int row, col, ball;
    int n;

    // Initialize board
    for (row = 0; row < NUM_ROWS; row++) {
        for (col = 0; col < NUM_COLS; col++) {
            board[row][col] = 0;
        }
    }

    // Randomly fill board with numbers from 1 to 25
    srand(time(NULL));
    for (n = 0; n < NUM_ROWS * NUM_COLS; n++) {
        ball = rand() % 25 + 1;
        while (board[ball / NUM_COLS][ball % NUM_COLS]!= 0) {
            ball = rand() % 25 + 1;
        }
        board[ball / NUM_COLS][ball % NUM_COLS] = 1;
    }

    // Print board
    printf("Bingo board:\n");
    for (row = 0; row < NUM_ROWS; row++) {
        for (col = 0; col < NUM_COLS; col++) {
            if (board[row][col]!= 0) {
                printf("X ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    // Print randomly selected balls
    printf("Balls drawn:\n");
    for (n = 0; n < MAX_BALLS; n++) {
        ball = rand() % 25 + 1;
        printf("%d ", ball);
        board[ball / NUM_COLS][ball % NUM_COLS] = 0;
    }
    printf("\n");

    // Check for Bingo
    int bingos = 0;
    for (row = 0; row < NUM_ROWS; row++) {
        for (col = 0; col < NUM_COLS; col++) {
            if (board[row][col] == 0) {
                continue;
            }
            for (int i = row; i < NUM_ROWS; i++) {
                for (int j = col; j < NUM_COLS; j++) {
                    if (board[i][j]!= 0) {
                        board[i][j] = 0;
                    }
                }
            }
            bingos++;
            break;
        }
        if (bingos > 0) {
            break;
        }
    }
    printf("Bingo!\n");
    return 0;
}