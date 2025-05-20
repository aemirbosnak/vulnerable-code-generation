//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 4
#define NUM_COLS 4
#define NUM_PAIRS 8

int main() {
    int board[NUM_ROWS][NUM_COLS];
    int pairs[NUM_PAIRS][2];
    int i, j, k, x, y, matches = 0;
    char choice;

    // Initialize board with numbers
    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            board[i][j] = rand() % 100;
        }
    }

    // Shuffle the board
    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            x = rand() % NUM_ROWS;
            y = rand() % NUM_COLS;
            board[i][j] = board[x][y];
            board[x][y] = rand() % 100;
        }
    }

    // Initialize pairs with random numbers
    for (k = 0; k < NUM_PAIRS; k++) {
        x = rand() % NUM_ROWS;
        y = rand() % NUM_COLS;
        pairs[k][0] = board[x][y];
        pairs[k][1] = board[x][y];
    }

    // Print the board
    printf("Welcome to the Memory Game!\n");
    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Start the game
    while (matches < NUM_PAIRS) {
        printf("Enter your choice (row and column): ");
        scanf("%d%d", &i, &j);
        if (board[i-1][j-1] == pairs[matches][0]) {
            printf("You found a match!\n");
            matches++;
        } else {
            printf("Sorry, try again.\n");
            board[i-1][j-1] = -1;
        }
        printf("Current board:\n");
        for (i = 0; i < NUM_ROWS; i++) {
            for (j = 0; j < NUM_COLS; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }

    printf("Congratulations! You won the game!\n");

    return 0;
}