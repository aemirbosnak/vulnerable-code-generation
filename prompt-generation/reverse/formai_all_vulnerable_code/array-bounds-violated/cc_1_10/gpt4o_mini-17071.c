//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define SIZE 4

void initializeBoard(int board[SIZE][SIZE]) {
    int numbers[SIZE * SIZE / 2];
    for (int i = 0; i < SIZE * SIZE / 2; i++) {
        numbers[i] = i + 1;
    }
    
    // Duplicate the numbers for pairs
    for (int i = 0; i < SIZE * SIZE / 2; i++) {
        numbers[i + SIZE * SIZE / 2] = numbers[i];
    }

    // Shuffle the numbers
    for (int i = 0; i < SIZE * SIZE; i++) {
        int j = rand() % (SIZE * SIZE);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // Fill the board with the shuffled numbers
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = numbers[i * SIZE + j];
        }
    }
}

void displayBoard(int board[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    printf("Current Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("%2d ", board[i][j]);
            } else {
                printf(" * ");
            }
        }
        printf("\n");
    }
}

int checkMatch(int board[SIZE][SIZE], int revealed[SIZE][SIZE], int x1, int y1, int x2, int y2) {
    return board[x1][y1] == board[x2][y2];
}

int main() {
    srand(time(NULL));
    int board[SIZE][SIZE];
    int revealed[SIZE][SIZE] = {0}; // 0 = hidden, 1 = revealed
    int totalPairs = (SIZE * SIZE) / 2;
    int pairsFound = 0;
    int x1, y1, x2, y2;

    initializeBoard(board);

    printf("Welcome to the Memory Game!\n");
    while (pairsFound < totalPairs) {
        displayBoard(board, revealed);

        // First pick
        printf("Pick the first card (row and column): ");
        scanf("%d %d", &x1, &y1);
        if (revealed[x1][y1]) {
            printf("Card already revealed! Try again.\n");
            continue;
        }
        revealed[x1][y1] = 1;

        // Second pick
        displayBoard(board, revealed);
        printf("Pick the second card (row and column): ");
        scanf("%d %d", &x2, &y2);
        if (revealed[x2][y2]) {
            printf("Card already revealed! Try again.\n");
            revealed[x1][y1] = 0; // Hide the first card again
            continue;
        }
        revealed[x2][y2] = 1;

        // Check for a match
        if (checkMatch(board, revealed, x1, y1, x2, y2)) {
            printf("It's a match!\n");
            pairsFound++;
        } else {
            printf("Not a match. Try again.\n");
            // Hide the cards again after a short delay
            sleep(1);
            revealed[x1][y1] = 0;
            revealed[x2][y2] = 0;
        }
    }

    printf("Congratulations! You've found all pairs!\n");
    return 0;
}