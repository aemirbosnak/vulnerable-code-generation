//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 4
#define COLS 4
#define MAX_PAIRS (ROWS * COLS) / 2

typedef struct {
    char value;
    bool revealed;
} Card;

void initializeDeck(Card deck[ROWS][COLS]);
void shuffleDeck(Card deck[ROWS][COLS]);
void printBoard(Card deck[ROWS][COLS]);
bool checkMatch(Card deck[ROWS][COLS], int r1, int c1, int r2, int c2);
bool allCardsRevealed(Card deck[ROWS][COLS]);
void getPlayerChoice(int *row, int *col);

int main() {
    Card deck[ROWS][COLS];
    initializeDeck(deck);
    shuffleDeck(deck);
    
    int firstRow, firstCol, secondRow, secondCol;
    int moves = 0;
    
    while (!allCardsRevealed(deck)) {
        printBoard(deck);
        printf("Select the first card (row and column): ");
        getPlayerChoice(&firstRow, &firstCol);
        deck[firstRow][firstCol].revealed = true;
        printBoard(deck);
        
        printf("Select the second card (row and column): ");
        getPlayerChoice(&secondRow, &secondCol);
        deck[secondRow][secondCol].revealed = true;
        printBoard(deck);
        
        if (checkMatch(deck, firstRow, firstCol, secondRow, secondCol)) {
            printf("It's a match!\n");
        } else {
            printf("Not a match. Try again.\n");
            deck[firstRow][firstCol].revealed = false;
            deck[secondRow][secondCol].revealed = false;
        }
        moves++;
    }

    printf("Congratulations! You've matched all pairs in %d moves.\n", moves);
    return 0;
}

void initializeDeck(Card deck[ROWS][COLS]) {
    char symbols[MAX_PAIRS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    
    for (int i = 0; i < MAX_PAIRS; i++) {
        deck[i / 2][i % 2].value = symbols[i];
        deck[i / 2][i % 2].revealed = false;
        deck[ROWS - 1 - (i / 2)][COLS - 1 - (i % 2)].value = symbols[i];
        deck[ROWS - 1 - (i / 2)][COLS - 1 - (i % 2)].revealed = false;
    }
}

void shuffleDeck(Card deck[ROWS][COLS]) {
    srand(time(NULL));
    for (int i = 0; i < MAX_PAIRS; i++) {
        int r1 = rand() % ROWS;
        int c1 = rand() % COLS;
        int r2 = rand() % ROWS;
        int c2 = rand() % COLS;
        
        Card temp = deck[r1][c1];
        deck[r1][c1] = deck[r2][c2];
        deck[r2][c2] = temp;
    }
}

void printBoard(Card deck[ROWS][COLS]) {
    printf("\nMemory Game Board:\n");
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (deck[r][c].revealed) {
                printf("[%c] ", deck[r][c].value);
            } else {
                printf("[ ] ");
            }
        }
        printf("\n");
    }
}

bool checkMatch(Card deck[ROWS][COLS], int r1, int c1, int r2, int c2) {
    return deck[r1][c1].value == deck[r2][c2].value;
}

bool allCardsRevealed(Card deck[ROWS][COLS]) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (!deck[r][c].revealed) {
                return false;
            }
        }
    }
    return true;
}

void getPlayerChoice(int *row, int *col) {
    scanf("%d %d", row, col);
    while (*row < 0 || *row >= ROWS || *col < 0 || *col >= COLS) {
        printf("Invalid choice, please select again (row and column): ");
        scanf("%d %d", row, col);
    }
}