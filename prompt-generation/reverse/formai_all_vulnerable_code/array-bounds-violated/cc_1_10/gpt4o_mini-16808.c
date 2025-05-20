//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 4 // Size of the game grid (4x4)
#define PAIRS (SIZE * SIZE / 2)

char symbols[PAIRS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
char board[SIZE][SIZE];
char revealed[SIZE][SIZE];
int score = 0;

void initializeBoard() {
    int indexes[SIZE * SIZE];
    for (int i = 0; i < SIZE * SIZE; i++) {
        indexes[i] = i / 2; // Each symbol appears twice
    }
    
    // Shuffle the symbols
    for (int i = 0; i < SIZE * SIZE; i++) {
        int j = rand() % (SIZE * SIZE);
        int temp = indexes[i];
        indexes[i] = indexes[j];
        indexes[j] = temp;
    }
    
    // Fill board with shuffled symbols
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = symbols[indexes[i * SIZE + j]];
            revealed[i][j] = ' '; // Initially, all cards are face down
        }
    }
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("[%c] ", revealed[i][j]);
        }
        printf("\n");
    }
}

void revealCard(int row, int col) {
    revealed[row][col] = board[row][col];
}

void hideCard(int row, int col) {
    revealed[row][col] = ' ';
}

int main() {
    srand(time(NULL));
    initializeBoard();
    int pairsFound = 0;
    int totalCards = SIZE * SIZE;
    int firstRow, firstCol, secondRow, secondCol;

    printf("Welcome to the Memory Game!\n");

    while (pairsFound < PAIRS) {
        printBoard();
        printf("Enter the coordinates of the first card (row and column): ");
        scanf("%d %d", &firstRow, &firstCol);
        revealCard(firstRow, firstCol);
        printBoard();
        
        printf("Enter the coordinates of the second card (row and column): ");
        scanf("%d %d", &secondRow, &secondCol);
        revealCard(secondRow, secondCol);
        printBoard();
        
        if (board[firstRow][firstCol] == board[secondRow][secondCol]) {
            printf("You found a pair!\n");
            score += 10;
            pairsFound++;
            hideCard(firstRow, firstCol);
            hideCard(secondRow, secondCol);
        } else {
            printf("Not a match! Try again.\n");
            printf("Score: %d\n", score);
            sleep(2); // Brief pause to observe the revealed cards
            hideCard(firstRow, firstCol);
            hideCard(secondRow, secondCol);
        }
    }

    printf("Congratulations! You've matched all pairs!\n");
    printf("Your score: %d\n", score);
    return 0;
}