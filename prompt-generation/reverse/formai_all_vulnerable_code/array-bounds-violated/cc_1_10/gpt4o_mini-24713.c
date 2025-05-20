//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROWS 4
#define COLS 4
#define NUM_CARDS (ROWS * COLS)

void initializeBoard(char board[ROWS][COLS], char symbols[NUM_CARDS]);
void shuffleCards(char symbols[NUM_CARDS]);
void printBoard(char board[ROWS][COLS], int revealed[ROWS][COLS]);
int chooseCard(int *row, int *col);
int checkMatch(int firstRow, int firstCol, int secondRow, int secondCol, char board[ROWS][COLS]);

int main() {
    srand(time(NULL));
    
    char board[ROWS][COLS];
    char symbols[NUM_CARDS] = {
        'A', 'A', 'B', 'B', 
        'C', 'C', 'D', 'D',
        'E', 'E', 'F', 'F',
        'G', 'G', 'H', 'H'
    };

    int revealed[ROWS][COLS] = {0};
    int pairsFound = 0, totalPairs = NUM_CARDS / 2;

    initializeBoard(board, symbols);
    shuffleCards(symbols);

    int turn = 1;
    while (pairsFound < totalPairs) {
        printf("\nTurn %d\n", turn);
        printBoard(board, revealed);
        
        int firstRow, firstCol, secondRow, secondCol;
        
        printf("Choose first card (row col): ");
        if (chooseCard(&firstRow, &firstCol) < 0 || revealed[firstRow][firstCol]) {
            printf("Invalid choice! Try again.\n");
            continue;
        }
        
        revealed[firstRow][firstCol] = 1;
        printBoard(board, revealed);
        
        printf("Choose second card (row col): ");
        if (chooseCard(&secondRow, &secondCol) < 0 || revealed[secondRow][secondCol]) {
            printf("Invalid choice! Try again.\n");
            revealed[firstRow][firstCol] = 0; // Hide the first choice
            continue;
        }
        
        revealed[secondRow][secondCol] = 1;
        printBoard(board, revealed);
        
        if (checkMatch(firstRow, firstCol, secondRow, secondCol, board)) {
            printf("Match found!\n");
            pairsFound++;
        } else {
            printf("No match! Try again.\n");
            revealed[firstRow][firstCol] = 0; // Hide first choice
            revealed[secondRow][secondCol] = 0; // Hide second choice
        }
        
        turn++;
    }

    printf("Congratulations! You've found all pairs!\n");
    return 0;
}

void initializeBoard(char board[ROWS][COLS], char symbols[NUM_CARDS]) {
    int k = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = symbols[k++];
        }
    }
}

void shuffleCards(char symbols[NUM_CARDS]) {
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        char temp = symbols[i];
        symbols[i] = symbols[j];
        symbols[j] = temp;
    }
}

void printBoard(char board[ROWS][COLS], int revealed[ROWS][COLS]) {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (revealed[i][j]) {
                printf("[%c] ", board[i][j]);
            } else {
                printf("[ ] ");
            }
        }
        printf("\n");
    }
}

int chooseCard(int *row, int *col) {
    return scanf("%d %d", row, col) == 2 ? 0 : -1;
}

int checkMatch(int firstRow, int firstCol, int secondRow, int secondCol, char board[ROWS][COLS]) {
    return board[firstRow][firstCol] == board[secondRow][secondCol];
}