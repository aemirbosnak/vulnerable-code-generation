//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4 // Board size (4x4)
#define TOTAL_CARDS (SIZE * SIZE)
#define MAX_TRIES 10

void initializeBoard(int board[SIZE][SIZE], int cardValues[TOTAL_CARDS]) {
    int index = 0;
    for (int i = 0; i < TOTAL_CARDS / 2; i++) {
        cardValues[index++] = i + 1;
        cardValues[index++] = i + 1;
    }

    // Shuffle the cards
    for (int i = TOTAL_CARDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = cardValues[i];
        cardValues[i] = cardValues[j];
        cardValues[j] = temp;
    }

    // Fill the board
    index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = cardValues[index++];
        }
    }
}

void displayBoard(int board[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("%d\t", board[i][j]);
            } else {
                printf("*\t");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int board[SIZE][SIZE];
    int revealed[SIZE][SIZE] = {0}; // 0 = hidden, 1 = revealed
    int cardValues[TOTAL_CARDS];
    int attempts = 0;
    int pairsFound = 0;

    srand(time(NULL)); // Seed for randomization
    initializeBoard(board, cardValues);

    while (pairsFound < TOTAL_CARDS / 2 && attempts < MAX_TRIES) {
        displayBoard(board, revealed);
        
        int x1, y1, x2, y2;
        printf("Enter coordinates of first card to reveal (row and column): ");
        scanf("%d %d", &x1, &y1);
        printf("Enter coordinates of second card to reveal (row and column): ");
        scanf("%d %d", &x2, &y2);

        if (x1 >= 0 && x1 < SIZE && y1 >= 0 && y1 < SIZE && x2 >= 0 && x2 < SIZE && y2 >= 0 && y2 < SIZE) {
            // Reveal the cards
            revealed[x1][y1] = 1;
            revealed[x2][y2] = 1;
            displayBoard(board, revealed);

            // Check if they match
            if (board[x1][y1] == board[x2][y2]) {
                printf("It's a match!\n");
                pairsFound++;
            } else {
                printf("No match found. Try again!\n");
                // Hide the cards after a brief pause
                getchar(); // To consume the newline character left by previous input
                getchar(); // Wait for user input before hiding again
                revealed[x1][y1] = 0;
                revealed[x2][y2] = 0;
            }
            attempts++;
        } else {
            printf("Invalid coordinates, try again!\n");
        }
    }

    if (pairsFound == TOTAL_CARDS / 2) {
        printf("Congratulations! You've found all pairs in %d attempts!\n", attempts);
    } else {
        printf("Game over! Better luck next time!\n");
    }

    return 0;
}