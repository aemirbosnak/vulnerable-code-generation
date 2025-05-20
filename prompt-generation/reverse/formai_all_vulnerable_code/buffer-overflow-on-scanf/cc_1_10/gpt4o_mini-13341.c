//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGO_ROWS 5
#define BINGO_COLS 5
#define MAX_NUM 75

typedef struct {
    int card[BINGO_ROWS][BINGO_COLS];
    int marked[BINGO_ROWS][BINGO_COLS];
} BingoCard;

void initializeCard(BingoCard *card) {
    int column_ranges[5][2] = {
        {1, 15},   // B: 1-15
        {16, 30},  // I: 16-30
        {31, 45},  // N: 31-45
        {46, 60},  // G: 46-60
        {61, 75}   // O: 61-75
    };
    
    for (int col = 0; col < BINGO_COLS; col++) {
        int numCount = 0;
        int usedNumbers[MAX_NUM + 1] = {0};
        
        while (numCount < BINGO_ROWS) {
            int num = rand() % (column_ranges[col][1] - column_ranges[col][0] + 1) + column_ranges[col][0];
            if (!usedNumbers[num]) {
                card->card[numCount][col] = num;
                usedNumbers[num] = 1;
                numCount++;
            }
        }
    }
    
    // Set the center space as free
    card->card[2][2] = 0;  // Free space
}

void printCard(BingoCard *card) {
    printf("B   I   N   G   O\n");
    for (int row = 0; row < BINGO_ROWS; row++) {
        for (int col = 0; col < BINGO_COLS; col++) {
            if (card->card[row][col] == 0) {
                printf(" *  ");
            } else {
                printf("%-3d ", card->card[row][col]);
            }
        }
        printf("\n");
    }
}

int checkWin(BingoCard *card) {
    // Check rows
    for (int row = 0; row < BINGO_ROWS; row++) {
        int count = 0;
        for (int col = 0; col < BINGO_COLS; col++) {
            if (card->marked[row][col]) count++;
        }
        if (count == BINGO_COLS) return 1; // Win found
    }

    // Check columns
    for (int col = 0; col < BINGO_COLS; col++) {
        int count = 0;
        for (int row = 0; row < BINGO_ROWS; row++) {
            if (card->marked[row][col]) count++;
        }
        if (count == BINGO_ROWS) return 1; // Win found
    }

    // Check diagonals
    int count1 = 0, count2 = 0;
    for (int i = 0; i < BINGO_ROWS; i++) {
        if (card->marked[i][i]) count1++;
        if (card->marked[i][BINGO_ROWS - 1 - i]) count2++;
    }
    if (count1 == BINGO_ROWS || count2 == BINGO_ROWS) return 1; // Win found

    return 0; // No win
}

void markNumber(BingoCard *card, int num) {
    for (int row = 0; row < BINGO_ROWS; row++) {
        for (int col = 0; col < BINGO_COLS; col++) {
            if (card->card[row][col] == num) {
                card->marked[row][col] = 1;
                return;
            }
        }
    }
}

void resetCard(BingoCard *card) {
    for (int row = 0; row < BINGO_ROWS; row++) {
        for (int col = 0; col < BINGO_COLS; col++) {
            card->marked[row][col] = 0;
        }
    }
}

int main() {
    srand(time(0));
    BingoCard card;
    initializeCard(&card);
    resetCard(&card);

    printf("Your Bingo Card:\n");
    printCard(&card);
    
    int gameOn = 1;
    while (gameOn) {
        int drawnNumber = rand() % MAX_NUM + 1;
        printf("\nDrawn Number: %d\n", drawnNumber);
        markNumber(&card, drawnNumber);
        printCard(&card);
        
        if (checkWin(&card)) {
            printf("Bingo! You've won!\n");
            gameOn = 0;
        }
        
        char choice;
        printf("Continue playing? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y') {
            gameOn = 0;
        }
    }

    printf("Thanks for playing Bingo!\n");
    return 0;
}