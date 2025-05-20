//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main() {
    int i, j, num, bingo = 0;
    int board[ROWS][COLS] = { 0 };
    int called[ROWS * COLS] = { 0 };
    
    srand(time(NULL));
    
    // Initialize the board
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == ROWS / 2 && j == COLS / 2) {
                board[i][j] = -1;
            } else {
                num = (j * 15) + (rand() % 15) + 1;
                while (called[num]) {
                    num = (j * 15) + (rand() % 15) + 1;
                }
                board[i][j] = num;
                called[num] = 1;
            }
        }
    }
    
    // Play the game
    printf("Welcome to Bingo!\n");
    while (!bingo) {
        // Display the board
        printf("\n--------------------\n");
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                printf("| ");
                if (board[i][j] == -1) {
                    printf("X ");
                } else {
                    printf("%2d ", board[i][j]);
                }
            }
            printf("|\n");
            printf("--------------------\n");
        }
        
        // Get the next number
        num = (rand() % 75) + 1;
        while (called[num]) {
            num = (rand() % 75) + 1;
        }
        called[num] = 1;
        printf("Next number: %d\n", num);
        
        // Check for matches
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (board[i][j] == num) {
                    board[i][j] = -1;
                }
            }
        }
        
        // Check for bingo
        bingo = 1;
        for (i = 0; i < ROWS; i++) {
            if (board[i][0] != -1) {
                continue;
            }
            for (j = 1; j < COLS; j++) {
                if (board[i][j] != -1) {
                    break;
                }
            }
            if (j == COLS) {
                printf("BINGO! Row %d\n", i + 1);
                bingo = 0;
                break;
            }
        }
        if (!bingo) {
            continue;
        }
        for (j = 0; j < COLS; j++) {
            if (board[0][j] != -1) {
                continue;
            }
            for (i = 1; i < ROWS; i++) {
                if (board[i][j] != -1) {
                    break;
                }
            }
            if (i == ROWS) {
                printf("BINGO! Column %d\n", j + 1);
                bingo = 0;
                break;
            }
        }
        if (!bingo) {
            continue;
        }
        if (board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 && board[3][3] == -1 && board[4][4] == -1) {
            printf("BINGO! Diagonal (left to right)\n");
            bingo = 0;
        }
        if (board[0][4] == -1 && board[1][3] == -1 && board[2][2] == -1 && board[3][1] == -1 && board[4][0] == -1) {
            printf("BINGO! Diagonal (right to left)\n");
            bingo = 0;
        }
    }
    
    printf("Congratulations, you win!\n");
    return 0;
}