//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define GRID_SIZE 4
#define TOTAL_PAIRS (GRID_SIZE * GRID_SIZE / 2)

void initializeBoard(int board[GRID_SIZE][GRID_SIZE]);
void shuffleBoard(int board[GRID_SIZE][GRID_SIZE]);
void displayBoard(int board[GRID_SIZE][GRID_SIZE], bool revealed[GRID_SIZE][GRID_SIZE]);
bool checkMatch(int firstRow, int firstCol, int secondRow, int secondCol, int board[GRID_SIZE][GRID_SIZE]);
void playGame(int board[GRID_SIZE][GRID_SIZE]);

int main() {
    srand(time(NULL));

    int board[GRID_SIZE][GRID_SIZE];
    initializeBoard(board);
    
    char playAgain;
    do {
        shuffleBoard(board);
        playGame(board);
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}

void initializeBoard(int board[GRID_SIZE][GRID_SIZE]) {
    int numbers[TOTAL_PAIRS], numCount = 0;
    for (int i = 1; i <= TOTAL_PAIRS; i++) {
        numbers[numCount++] = i;
        numbers[numCount++] = i; // Adding pairs
    }
    
    for (int i = 0; i < TOTAL_PAIRS; i++) {
        int j = rand() % TOTAL_PAIRS;
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    int index = 0;
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            board[i][j] = numbers[index++];
        }
    }
}

void shuffleBoard(int board[GRID_SIZE][GRID_SIZE]) {
    printf("\nRevealing the board for 3 seconds...\n");
    bool revealed[GRID_SIZE][GRID_SIZE] = {false};
    displayBoard(board, revealed);
    sleep(3); // Pause for 3 seconds
}

void displayBoard(int board[GRID_SIZE][GRID_SIZE], bool revealed[GRID_SIZE][GRID_SIZE]) {
    printf("\nMemory Game Board:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (revealed[i][j]) {
                printf("%2d ", board[i][j]);
            } else {
                printf(" * ");
            }
        }
        printf("\n");
    }
}

void playGame(int board[GRID_SIZE][GRID_SIZE]) {
    bool revealed[GRID_SIZE][GRID_SIZE] = {false};
    int pairsFound = 0;
    while (pairsFound < TOTAL_PAIRS) {
        int firstRow, firstCol, secondRow, secondCol;

        // Choose first position
        printf("\nSelect the first position (row column): ");
        scanf("%d %d", &firstRow, &firstCol);
        revealed[firstRow][firstCol] = true;
        displayBoard(board, revealed);

        // Choose second position
        printf("Select the second position (row column): ");
        scanf("%d %d", &secondRow, &secondCol);
        revealed[secondRow][secondCol] = true;
        displayBoard(board, revealed);

        if (checkMatch(firstRow, firstCol, secondRow, secondCol, board)) {
            printf("It's a match!\n");
            pairsFound++;
        } else {
            printf("Not a match. Try again.\n");
            revealed[firstRow][firstCol] = false;
            revealed[secondRow][secondCol] = false;
        }
    }
    printf("Congratulations! You've found all pairs!\n");
}

bool checkMatch(int firstRow, int firstCol, int secondRow, int secondCol, int board[GRID_SIZE][GRID_SIZE]) {
    return board[firstRow][firstCol] == board[secondRow][secondCol];
}