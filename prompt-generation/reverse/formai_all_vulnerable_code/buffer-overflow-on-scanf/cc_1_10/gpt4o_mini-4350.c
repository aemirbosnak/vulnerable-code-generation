//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4
#define PAIRS (SIZE * SIZE) / 2

void initializeBoard(int board[SIZE][SIZE]);
void shuffleBoard(int board[SIZE][SIZE]);
void printBoard(int board[SIZE][SIZE], bool revealed[SIZE][SIZE]);
bool chooseCell(int *row, int *col);
bool checkMatch(int firstNum, int secondNum);
void playGame(int board[SIZE][SIZE]);

int main() {
    srand(time(NULL)); // Seed for randomness
    int board[SIZE][SIZE];
    
    initializeBoard(board);
    shuffleBoard(board);
    
    playGame(board);
    
    return 0;
}

void initializeBoard(int board[SIZE][SIZE]) {
    int num = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = (num <= PAIRS) ? num : 0; // Fill with pairs
            if (j % 2 != 0) num++;
        }
    }
}

void shuffleBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int randI = rand() % SIZE;
            int randJ = rand() % SIZE;
            // Swap values
            int temp = board[i][j];
            board[i][j] = board[randI][randJ];
            board[randI][randJ] = temp;
        }
    }
}

void printBoard(int board[SIZE][SIZE], bool revealed[SIZE][SIZE]) {
    printf("Memory Game Board:\n");
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
    printf("\n");
}

bool chooseCell(int *row, int *col) {
    printf("Enter row and column (0 to %d): ", SIZE - 1);
    scanf("%d %d", row, col);
    if (*row >= 0 && *row < SIZE && *col >= 0 && *col < SIZE) {
        return true;
    } else {
        printf("Invalid input. Please try again.\n");
        return false;
    }
}

bool checkMatch(int firstNum, int secondNum) {
    return firstNum == secondNum;
}

void playGame(int board[SIZE][SIZE]) {
    bool revealed[SIZE][SIZE] = { false };
    int pairsFound = 0;
    
    while (pairsFound < PAIRS) {
        printBoard(board, revealed);
        
        int firstRow, firstCol, secondRow, secondCol;
        printf("Select first cell:\n");
        while (!chooseCell(&firstRow, &firstCol) || revealed[firstRow][firstCol]) {}
        
        revealed[firstRow][firstCol] = true;
        printBoard(board, revealed);
        
        printf("Select second cell:\n");
        while (!chooseCell(&secondRow, &secondCol) || revealed[secondRow][secondCol]) {}
        
        revealed[secondRow][secondCol] = true;
        printBoard(board, revealed);
        
        if (checkMatch(board[firstRow][firstCol], board[secondRow][secondCol])) {
            printf("It's a match!\n");
            pairsFound++;
        } else {
            printf("Not a match. Try again.\n");
            revealed[firstRow][firstCol] = false;
            revealed[secondRow][secondCol] = false;
        }
    }
    
    printf("Congratulations! You found all pairs!\n");
}