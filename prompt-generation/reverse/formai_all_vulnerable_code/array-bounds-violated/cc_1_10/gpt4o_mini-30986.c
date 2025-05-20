//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define BINGO_SIZE 5

typedef struct {
    int number;
    bool marked;
} BingoCell;

typedef struct {
    BingoCell cells[BINGO_SIZE][BINGO_SIZE];
} BingoCard;

void initializeCard(BingoCard* card) {
    int num = 1;
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            card->cells[i][j].number = num++;
            card->cells[i][j].marked = false;
        }
    }
}

void printCard(BingoCard* card) {
    printf("B   I   N   G   O\n");
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card->cells[i][j].marked) {
                printf("[*] ");
            } else {
                printf("[%2d] ", card->cells[i][j].number);
            }
        }
        printf("\n");
    }
}

BingoCard generateBingoCard() {
    BingoCard card;
    int num;

    // Distinct numbers for each column
    for (int j = 0; j < BINGO_SIZE; j++) {
        int columnNumbers[BINGO_SIZE] = {0}; 
        for (int i = 0; i < BINGO_SIZE; i++) {
            do {
                num = rand() % 15 + (j * 15) + 1;
            } while (columnNumbers[num - 1] != 0);
            columnNumbers[num - 1] = 1;
            card.cells[i][j].number = num;
            card.cells[i][j].marked = false;
        }
    }

    card.cells[2][2].marked = true; // Free space in the middle
    return card;
}

void markNumber(BingoCard* card, int number) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card->cells[i][j].number == number) {
                card->cells[i][j].marked = true;
            }
        }
    }
}

bool checkWin(BingoCard* card) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        if ((card->cells[i][0].marked && card->cells[i][1].marked &&
             card->cells[i][2].marked && card->cells[i][3].marked &&
             card->cells[i][4].marked) || 
            (card->cells[0][i].marked && card->cells[1][i].marked &&
             card->cells[2][i].marked && card->cells[3][i].marked &&
             card->cells[4][i].marked)) {
                return true; 
        }
    }
    if ((card->cells[0][0].marked && card->cells[1][1].marked &&
         card->cells[2][2].marked && card->cells[3][3].marked &&
         card->cells[4][4].marked) || 
        (card->cells[0][4].marked && card->cells[1][3].marked &&
         card->cells[2][2].marked && card->cells[3][1].marked &&
         card->cells[4][0].marked)) {
            return true;
    }
    return false;
}

int main() {
    srand(time(NULL));

    BingoCard playerCard = generateBingoCard();
    printCard(&playerCard);

    bool gameWon = false;
    int numberCalled;

    while (!gameWon) {
        printf("Enter a number to call (1-75): ");
        scanf("%d", &numberCalled);

        if (numberCalled < 1 || numberCalled > 75) {
            printf("Number out of range. Try again.\n");
            continue;
        }

        markNumber(&playerCard, numberCalled);
        printCard(&playerCard);
        
        if (checkWin(&playerCard)) {
            printf("Bingo! You've won!\n");
            gameWon = true;
        } else {
            printf("Keep trying!\n");
        }
    }

    return 0;
}