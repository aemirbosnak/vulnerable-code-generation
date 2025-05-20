//MISTRAL-7B DATASET v1.0 Category: Bingo Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 100
#define CARD_SIZE 25

typedef struct {
    int numbers[CARD_SIZE];
    int isBingo;
} Card;

void printBingoCard(Card card) {
    printf("Player's Bingo Card:\n");
    for (int i = 0; i < CARD_SIZE; i++) {
        printf("%d ", card.numbers[i]);
        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }
}

void generateRandomCard(Card *card) {
    srand(time(NULL) + (int)card);
    for (int i = 0; i < CARD_SIZE; i++) {
        card->numbers[i] = rand() % 76 + 1;
    }
}

void checkBingo(Card *card) {
    int rowBingo = 0, colBingo = 0, diagonalBingo = 0;
    for (int i = 0; i < CARD_SIZE; i++) {
        if (card->isBingo & (1 << i)) {
            continue;
        }
        if (i % 5 == 0) {
            rowBingo |= (1 << i);
            if (card->isBingo & rowBingo) {
                card->isBingo |= 0x80;
                return;
            }
        } else {
            colBingo |= (1 << (i % 5));
            if (card->isBingo & colBingo) {
                card->isBingo |= 0x80;
                return;
            }
        }
        int diagIndex = i;
        if (diagIndex >= 5) {
            diagIndex -= 5;
        }
        diagonalBingo |= (1 << (diagIndex + i));
        if (card->isBingo & diagonalBingo) {
            card->isBingo |= 0x80;
            return;
        }
    }
}

int main() {
    srand(time(NULL));
    Card players[NUM_PLAYERS];

    printf("Welcome to C Bingo Simulator!\n");
    for (int i = 0; i < NUM_PLAYERS; i++) {
        players[i].isBingo = 0;
        generateRandomCard(&players[i]);
        printf("Player %d's card:\n", i + 1);
        printBingoCard(players[i]);
        printf("\n");
    }

    int calledNumbers[76] = {0};
    int numCalled = 0;
    int winnerIndex = -1;

    while (numCalled < 75) {
        int calledNumber = rand() % 76 + 1;
        calledNumbers[calledNumber - 1] = 1;
        numCalled++;

        for (int i = 0; i < NUM_PLAYERS; i++) {
            if (players[i].isBingo != 0) {
                continue;
            }
            if (players[i].numbers[calledNumber - 1] != -1) {
                players[i].numbers[calledNumber - 1] = -1;
                checkBingo(&players[i]);
                if (players[i].isBingo != 0) {
                    winnerIndex = i;
                    break;
                }
            }
        }
        if (winnerIndex != -1) {
            printf("Player %d wins!\n", winnerIndex + 1);
            break;
        }
    }

    return 0;
}