//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 4  // Define the grid size (MAX_SIZE x MAX_SIZE)
#define PAIRS (MAX_SIZE * MAX_SIZE / 2)

void initializeBoard(int board[MAX_SIZE][MAX_SIZE]) {
    int pairs[PAIRS];
    for (int i = 0; i < PAIRS; i++) {
        pairs[i] = i + 1;
    }

    // Randomly distribute pairs into the board
    for (int i = 0; i < PAIRS; i++) {
        board[i / (MAX_SIZE / 2)][(i % (MAX_SIZE / 2)) * 2] = pairs[i];
        board[i / (MAX_SIZE / 2)][(i % (MAX_SIZE / 2)) * 2 + 1] = pairs[i];
    }

    // Shuffle the pairs
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            int random_i = rand() % MAX_SIZE;
            int random_j = rand() % MAX_SIZE;

            // Swap elements
            int temp = board[i][j];
            board[i][j] = board[random_i][random_j];
            board[random_i][random_j] = temp;
        }
    }
}

void printBoard(int board[MAX_SIZE][MAX_SIZE], int revealed[MAX_SIZE][MAX_SIZE]) {
    printf("Memory Game Board:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (revealed[i][j]) {
                printf("%2d ", board[i][j]);
            } else {
                printf(" * ");
            }
        }
        printf("\n");
    }
}

int checkMatch(int board[MAX_SIZE][MAX_SIZE], int revealed[MAX_SIZE][MAX_SIZE], int row1, int col1, int row2, int col2) {
    if (board[row1][col1] == board[row2][col2]) {
        revealed[row1][col1] = 1;
        revealed[row2][col2] = 1;
        return 1; // Match found
    }
    return 0; // No match
}

int main() {
    srand(time(NULL));
    int board[MAX_SIZE][MAX_SIZE];
    int revealed[MAX_SIZE][MAX_SIZE] = {0};
    int turns = 0;
    int matches_found = 0;

    initializeBoard(board);

    while (matches_found < PAIRS) {
        printBoard(board, revealed);
        int row1, col1, row2, col2;

        printf("Select first card (row and column): ");
        scanf("%d %d", &row1, &col1);
        printf("Select second card (row and column): ");
        scanf("%d %d", &row2, &col2);

        // Validate input
        if ((row1 < 0 || row1 >= MAX_SIZE || col1 < 0 || col1 >= MAX_SIZE) ||
            (row2 < 0 || row2 >= MAX_SIZE || col2 < 0 || col2 >= MAX_SIZE) ||
            (revealed[row1][col1] || revealed[row2][col2]) ||
            (row1 == row2 && col1 == col2)) {
            printf("Invalid selection. Please try again.\n");
            continue;
        }

        revealed[row1][col1] = 1;  // Temporarily reveal the first card
        revealed[row2][col2] = 1;  // Temporarily reveal the second card
        printBoard(board, revealed);

        turns++;

        if (checkMatch(board, revealed, row1, col1, row2, col2)) {
            matches_found++;
            printf("You found a match!\n");
        } else {
            printf("No match. Try again.\n");
            revealed[row1][col1] = 0;  // Hide first card again
            revealed[row2][col2] = 0;  // Hide second card again
        }
        printf("\n");
    }

    printf("Congratulations! You've matched all cards in %d turns!\n", turns);
    return 0;
}