//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define ROWS 4
#define COLS 4
#define TOTAL_PAIRS (ROWS * COLS) / 2

typedef struct {
    char symbol;
    int revealed;
} Card;

void initializeDeck(Card deck[ROWS][COLS]);
void shuffleDeck(Card deck[ROWS][COLS]);
void printBoard(Card deck[ROWS][COLS]);
int isGameWon(Card deck[ROWS][COLS]);
void revealCard(Card deck[ROWS][COLS], int row, int col);
void hideCard(Card deck[ROWS][COLS], int row, int col);
void playGame(Card deck[ROWS][COLS]);

int main() {
    Card deck[ROWS][COLS];

    initializeDeck(deck);
    shuffleDeck(deck);
    playGame(deck);
    
    return 0;
}

void initializeDeck(Card deck[ROWS][COLS]) {
    char symbols[TOTAL_PAIRS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    for (int i = 0; i < TOTAL_PAIRS; i++) {
        deck[i / (COLS / 2)][(i % (COLS / 2)) * 2] = (Card){symbols[i], 0};
        deck[i / (COLS / 2)][(i % (COLS / 2)) * 2 + 1] = (Card){symbols[i], 0};
    }
}

void shuffleDeck(Card deck[ROWS][COLS]) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int randRow = rand() % ROWS;
            int randCol = rand() % COLS;
            Card temp = deck[i][j];
            deck[i][j] = deck[randRow][randCol];
            deck[randRow][randCol] = temp;
        }
    }
}

void printBoard(Card deck[ROWS][COLS]) {
    printf("Current Board:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (deck[i][j].revealed) {
                printf("%c ", deck[i][j].symbol);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int isGameWon(Card deck[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (!deck[i][j].revealed) {
                return 0;
            }
        }
    }
    return 1;
}

void revealCard(Card deck[ROWS][COLS], int row, int col) {
    deck[row][col].revealed = 1;
}

void hideCard(Card deck[ROWS][COLS], int row, int col) {
    deck[row][col].revealed = 0;
}

void playGame(Card deck[ROWS][COLS]) {
    int firstRow, firstCol, secondRow, secondCol;
    int firstSelection = 1;
    int pairsFound = 0;

    while (!isGameWon(deck)) {
        printBoard(deck);

        if (firstSelection) {
            printf("Select first card (row and column): ");
            scanf("%d %d", &firstRow, &firstCol);
            revealCard(deck, firstRow, firstCol);
            firstSelection = 0;
        } else {
            printf("Select second card (row and column): ");
            scanf("%d %d", &secondRow, &secondCol);
            revealCard(deck, secondRow, secondCol);
            printBoard(deck);
            
            if (deck[firstRow][firstCol].symbol == deck[secondRow][secondCol].symbol) {
                printf("It's a match!\n");
                pairsFound++;
            } else {
                printf("Not a match!\n");
                sleep(1); // Pause for a moment to show the player
                hideCard(deck, firstRow, firstCol);
                hideCard(deck, secondRow, secondCol);
            }
            firstSelection = 1;
        }
    }

    printf("Congratulations! You've found all pairs in %d turns!\n", pairsFound);
}