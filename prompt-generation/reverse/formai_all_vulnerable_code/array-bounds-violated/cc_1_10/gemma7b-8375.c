//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10

typedef struct BingoCard {
    int numbers[MAX_NUM];
    int marked[MAX_NUM];
    int wins;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
    for (int i = 0; i < MAX_NUM; i++) {
        card->numbers[i] = 0;
        card->marked[i] = 0;
    }
    card->wins = 0;
}

void generateBingoCard(BingoCard *card) {
    for (int i = 0; i < MAX_NUM; i++) {
        card->numbers[i] = rand() % MAX_NUM + 1;
    }
}

int checkBingo(BingoCard *card) {
    for (int i = 0; i < MAX_NUM; i++) {
        if (card->marked[i] && card->numbers[i] == card->wins) {
            return 1;
        }
    }
    return 0;
}

int main() {
    BingoCard card;
    initializeBingoCard(&card);
    generateBingoCard(&card);

    // Play the game
    for (int round = 0; round < 10; round++) {
        // Draw a number
        int number = rand() % MAX_NUM + 1;

        // Mark the number on the card
        card.marked[card.numbers[number]] = 1;

        // Check if the card has won
        if (checkBingo(&card)) {
            card.wins++;
            printf("Congratulations! You have won %d rounds!\n", card.wins);
            break;
        }
    }

    return 0;
}