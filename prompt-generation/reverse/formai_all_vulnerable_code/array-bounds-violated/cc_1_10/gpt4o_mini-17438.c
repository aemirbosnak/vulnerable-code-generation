//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGO_SIZE 5
#define MAX_NUMBER 75

typedef struct {
    int numbers[BINGO_SIZE][BINGO_SIZE];
    int marked[BINGO_SIZE][BINGO_SIZE];
} BingoCard;

void printBingoCard(BingoCard card) {
    printf("  B   I   N   G   O\n");
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card.marked[i][j]) {
                printf(" *  ");
            } else {
                printf("%-3d ", card.numbers[i][j]);
            }
        }
        printf("\n");
    }
}

void generateBingoCard(BingoCard *card) {
    int range[BINGO_SIZE][2] = { {1, 15}, {16, 30}, {31, 45}, {46, 60}, {61, 75} };
    for (int j = 0; j < BINGO_SIZE; j++) {
        int numbers[BINGO_SIZE] = {0};
        for (int i = 0; i < BINGO_SIZE; i++) {
            int number;
            do {
                number = rand() % (range[j][1] - range[j][0] + 1) + range[j][0];
            } while (numbers[number - range[j][0]] != 0);
            numbers[number - range[j][0]] = 1;
            card->numbers[i][j] = number;
            card->marked[i][j] = 0;
        }
    }
    card->marked[2][2] = 1; // Free space
}

void markNumber(BingoCard *card, int drawnNumber) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card->numbers[i][j] == drawnNumber) {
                card->marked[i][j] = 1;
            }
        }
    }
}

int checkBingo(BingoCard card) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (card.marked[i][0] && card.marked[i][1] && card.marked[i][2] && card.marked[i][3] && card.marked[i][4]) {
            return 1; // Row Bingo
        }
    }
    for (int j = 0; j < BINGO_SIZE; j++) {
        if (card.marked[0][j] && card.marked[1][j] && card.marked[2][j] && card.marked[3][j] && card.marked[4][j]) {
            return 1; // Column Bingo
        }
    }
    if (card.marked[0][0] && card.marked[1][1] && card.marked[2][2] && card.marked[3][3] && card.marked[4][4]) {
        return 1; // Diagonal Bingo
    }
    if (card.marked[0][4] && card.marked[1][3] && card.marked[2][2] && card.marked[3][1] && card.marked[4][0]) {
        return 1; // Anti-Diagonal Bingo
    }
    return 0; // No Bingo
}

int main() {
    srand(time(NULL)); // Seed for randomness
    BingoCard card;
    generateBingoCard(&card);
    
    printf("A Bingo card dost thou possess:\n");
    printBingoCard(card);

    int drawnNumbers[100] = {0};
    int count = 0;
    
    while (count < 100) {
        int number = rand() % MAX_NUMBER + 1;
        if (drawnNumbers[number] == 0) {
            drawnNumbers[number] = 1;
            count++;
            printf("\nThe number drawn is: %d\n", number);
            markNumber(&card, number);
            printBingoCard(card);
            if (checkBingo(card)) {
                printf("Hark! Bingo hath been achieved!\n");
                break;
            }
        }
    }

    if (count >= 100) {
        printf("No Bingo achieved, alas! The fates were cruel and unkind.\n");
    }

    return 0;
}