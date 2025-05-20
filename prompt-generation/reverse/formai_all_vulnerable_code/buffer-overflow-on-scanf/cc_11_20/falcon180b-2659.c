//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int main() {
    int board[ROWS][COLS];
    int i, j, matches = 0;

    // Initialize the board with random numbers
    srand(time(NULL));
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            board[i][j] = rand() % 100;
        }
    }

    // Print the initial board
    printf("Initial Board:\n");
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Shuffle the board
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            int r = rand() % ROWS;
            int c = rand() % COLS;
            int temp = board[i][j];
            board[i][j] = board[r][c];
            board[r][c] = temp;
        }
    }

    // Print the shuffled board
    printf("\nShuffled Board:\n");
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Prompt the user to play the game
    int choice;
    do {
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);
        if(choice >= 1 && choice <= 4) {
            int x = (choice - 1) / COLS;
            int y = (choice - 1) % COLS;
            if(board[x][y]!= -1) {
                board[x][y] = -1;
                matches++;
            } else {
                printf("Try Again!\n");
            }
        } else {
            printf("Invalid choice!\n");
        }
    } while(matches < ROWS * COLS / 2);

    // Print the final board
    printf("\nFinal Board:\n");
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}