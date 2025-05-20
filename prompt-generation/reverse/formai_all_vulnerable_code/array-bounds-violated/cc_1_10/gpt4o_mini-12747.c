//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4 // Define the size of the grid
#define NUM_PAIRS (SIZE * SIZE) / 2 // Calculate the number of pairs

void initializeBoard(int board[SIZE][SIZE]) {
    int nums[NUM_PAIRS];
    for (int i = 0; i < NUM_PAIRS; i++) {
        nums[i] = i + 1;
    }
    
    // Create pairs
    for (int i = 0; i < NUM_PAIRS; i++) {
        nums[NUM_PAIRS + i] = nums[i];
    }

    // Shuffle
    for (int i = NUM_PAIRS * 2 - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // Fill the board
    int idx = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = nums[idx++];
        }
    }
}

void printBoard(int board[SIZE][SIZE], bool revealed[SIZE][SIZE]) {
    printf("    0  1  2  3\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf(" %d ", board[i][j]);
            } else {
                printf(" * ");
            }
        }
        printf("\n");
    }
}

bool selectCells(int board[SIZE][SIZE], bool revealed[SIZE][SIZE]) {
    int x1, y1, x2, y2;

    // Get first selection
    printf("Select first cell (row col): ");
    scanf("%d %d", &x1, &y1);
    if (revealed[x1][y1]) {
        printf("Cell already revealed! Choose again.\n");
        return false;
    }
    revealed[x1][y1] = true;
    printBoard(board, revealed);

    // Get second selection
    printf("Select second cell (row col): ");
    scanf("%d %d", &x2, &y2);
    if (revealed[x2][y2]) {
        printf("Cell already revealed! Choose again.\n");
        revealed[x1][y1] = false; // Undo first selection
        return false;
    }
    revealed[x2][y2] = true;
    printBoard(board, revealed);

    // Check if they match
    if (board[x1][y1] == board[x2][y2]) {
        printf("Match found!\n");
        return true;
    } else {
        printf("No match! Try again.\n");
        revealed[x1][y1] = false; // Hide them again
        revealed[x2][y2] = false; // Hide them again
        return false;
    }
}

bool isGameWon(bool revealed[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!revealed[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int board[SIZE][SIZE];
    bool revealed[SIZE][SIZE] = {false};
    int turns = 0;

    srand(time(NULL)); // Seed the random number generator
    initializeBoard(board);

    printf("Welcome to the Memory Game!\n");

    while (true) {
        printBoard(board, revealed);
        if (selectCells(board, revealed)) {
            turns++;
        }
        if (isGameWon(revealed)) {
            printf("Congratulations! You've matched all pairs in %d turns!\n", turns);
            break;
        }
    }

    return 0;
}