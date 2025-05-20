//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4 // 4x4 grid
#define TOTAL_PAIRS (SIZE * SIZE) / 2

void initializeBoard(int board[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    int values[TOTAL_PAIRS];
    for (int i = 0; i < TOTAL_PAIRS; i++) {
        values[i] = i + 1; // Fill values from 1 to TOTAL_PAIRS
    }

    // Duplicate the values for pairs
    for (int i = 0; i < TOTAL_PAIRS; i++) {
        values[TOTAL_PAIRS + i] = values[i];
    }

    // Shuffle the pairs
    for (int i = TOTAL_PAIRS * 2 - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = values[i];
        values[i] = values[j];
        values[j] = temp;
    }

    // Fill the game board with shuffled values
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = values[i * SIZE + j];
            revealed[i][j] = false;
        }
    }
}

void printBoard(int board[SIZE][SIZE], bool revealed[SIZE][SIZE]) {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("%d ", board[i][j]);
            } else {
                printf("X "); // Placeholder for unrevealed cards
            }
        }
        printf("\n");
    }
}

bool isMatch(int first, int second) {
    return first == second;
}

void playGame() {
    int board[SIZE][SIZE];
    bool revealed[SIZE][SIZE];
    initializeBoard(board, revealed);
    int score = 0;
    int moves = 0;

    while (score < TOTAL_PAIRS) {
        printBoard(board, revealed);

        int x1, y1, x2, y2;
        printf("Enter coordinates for the first card (row and column): ");
        scanf("%d %d", &x1, &y1);
        printf("Enter coordinates for the second card (row and column): ");
        scanf("%d %d", &x2, &y2);

        // Validate input
        if (x1 < 0 || x1 >= SIZE || y1 < 0 || y1 >= SIZE ||
            x2 < 0 || x2 >= SIZE || y2 < 0 || y2 >= SIZE ||
            (x1 == x2 && y1 == y2) || revealed[x1][y1] || revealed[x2][y2]) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        revealed[x1][y1] = true;
        revealed[x2][y2] = true;
        printBoard(board, revealed);

        moves++;
        if (isMatch(board[x1][y1], board[x2][y2])) {
            printf("It's a match!\n");
            score++;
        } else {
            printf("Not a match! Try again.\n");
            revealed[x1][y1] = false; // flip back
            revealed[x2][y2] = false; // flip back
        }

        printf("Score: %d | Moves: %d\n", score, moves);
    }

    printf("Congratulations! You've matched all pairs in %d moves!\n", moves);
}

int main() {
    srand(time(NULL)); // Seed random number generator
    printf("Welcome to the Memory Game!\n");
    playGame();
    return 0;
}