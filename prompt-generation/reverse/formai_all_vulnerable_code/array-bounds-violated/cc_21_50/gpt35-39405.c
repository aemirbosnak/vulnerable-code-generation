//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75

int main() {
    int bingo[ROWS][COLS] = {0};
    int picked[MAX_NUM] = {0};

    srand(time(0));

    // Populate the bingo board with random numbers
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int num;
            do {
                num = (rand() % MAX_NUM) + 1;
            } while(picked[num]); // Pick a new number if it has already been used
            picked[num] = 1;
            bingo[i][j] = num;
        }
    }

    // Display the bingo board
    printf("BINGO BOARD:\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%-3d ", bingo[i][j]);
        }
        printf("\n");
    }

    // Generate 25 random bingo balls and check if they have been picked
    printf("\nBINGO BALLS:\n");
    for(int i = 0; i < MAX_NUM; i++) {
        int ball;
        do {
            ball = (rand() % MAX_NUM) + 1;
        } while(picked[ball]);
        picked[ball] = 1;
        printf("%-3d ", ball);

        // Check if any numbers on the bingo board match the picked ball
        for(int row = 0; row < ROWS; row++) {
            for(int col = 0; col < COLS; col++) {
                if(bingo[row][col] == ball) {
                    bingo[row][col] = 0; // Mark the number as picked
                }
            }
        }

        // Check if anyone has a bingo
        int bingo_row = -1;
        int bingo_col = -1;
        // Check rows
        for(int row = 0; row < ROWS; row++) {
            int bingo_count = 0;
            for(int col = 0; col < COLS; col++) {
                if(bingo[row][col] == 0) {
                    bingo_count++;
                }
            }
            if(bingo_count == COLS) {
                bingo_row = row;
            }
        }
        // Check columns
        for(int col = 0; col < COLS; col++) {
            int bingo_count = 0;
            for(int row = 0; row < ROWS; row++) {
                if(bingo[row][col] == 0) {
                    bingo_count++;
                }
            }
            if(bingo_count == ROWS) {
                bingo_col = col;
            }
        }
        // Check diagonals
        if(bingo[0][0] == 0 && bingo[1][1] == 0 && bingo[2][2] == 0 && bingo[3][3] == 0 && bingo[4][4] == 0) {
            bingo_row = -1;
            bingo_col = -1;
        }
        if(bingo[0][4] == 0 && bingo[1][3] == 0 && bingo[2][2] == 0 && bingo[3][1] == 0 && bingo[4][0] == 0) {
            bingo_row = -1;
            bingo_col = -1;
        }
        if(bingo_row != -1 || bingo_col != -1) {
            printf("\nBINGO! Winning row: %d, Winning column: %d\n", bingo_row, bingo_col);
            break;
        }
        printf("\n");
    }

    return 0;
}