//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SIZE 4
#define PAIRS (SIZE * SIZE) / 2

void shuffle(int board[SIZE][SIZE]) {
    int numbers[PAIRS];
    for (int i = 0; i < PAIRS; i++) {
        numbers[i] = i + 1;
    }
    
    // Create pairs by duplicating values
    for (int i = 0; i < PAIRS; i++) {
        numbers[i + PAIRS] = numbers[i];
    }

    // Shuffle 
    for (int i = 0; i < PAIRS * 2; i++) {
        int randIndex = rand() % (PAIRS * 2);
        int temp = numbers[i];
        numbers[i] = numbers[randIndex];
        numbers[randIndex] = temp;
    }

    // Fill the board
    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = numbers[index++];
        }
    }
}

void printBoard(int board[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    printf("\nMemory Game Board:\n");
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

int checkMatch(int board[SIZE][SIZE], int r1, int c1, int r2, int c2) {
    return board[r1][c1] == board[r2][c2];
}

int allMatched(int revealed[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!revealed[i][j]) {
                return 0; // Not all cards are matched
            }
        }
    }
    return 1; // All cards are matched
}

void clearScreen() {
    // For clearing the screen
    printf("\033[H\033[J");
}

int main() {
    srand(time(NULL));
    int board[SIZE][SIZE], revealed[SIZE][SIZE] = {0};
    int firstRow, firstCol, secondRow, secondCol;
    int attempts = 0, pairsFound = 0;

    shuffle(board);
    clearScreen();

    while (pairsFound < PAIRS) {
        printBoard(board, revealed);
        printf("Choose first card (row col): ");
        scanf("%d %d", &firstRow, &firstCol);
        revealed[firstRow][firstCol] = 1;
        clearScreen();
        printBoard(board, revealed);

        printf("Choose second card (row col): ");
        scanf("%d %d", &secondRow, &secondCol);
        revealed[secondRow][secondCol] = 1;

        clearScreen();
        printBoard(board, revealed);

        attempts++;

        if (checkMatch(board, firstRow, firstCol, secondRow, secondCol)) {
            printf("Match found! You have found %d pairs.\n", ++pairsFound);
        } else {
            printf("No match. Try again!\n");
            sleep(2); // Show this for 2 seconds
            revealed[firstRow][firstCol] = 0;
            revealed[secondRow][secondCol] = 0;
        }

        clearScreen();
        
        if (allMatched(revealed)) {
            printf("Congratulations! You've matched all pairs in %d attempts!\n", attempts);
            break;
        }
    }

    return 0;
}