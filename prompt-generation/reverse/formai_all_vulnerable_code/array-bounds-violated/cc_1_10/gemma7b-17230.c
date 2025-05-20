//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_BINGO_CARDS 10

typedef struct BingoCard {
    int numbers[5][5];
    int freeSpaces[25];
    int wins;
} BingoCard;

BingoCard cards[MAX_BINGO_CARDS];

void generateBingoCards() {
    for (int i = 0; i < MAX_BINGO_CARDS; i++) {
        cards[i].wins = 0;
        for (int r = 0; r < 5; r++) {
            for (int c = 0; c < 5; c++) {
                cards[i].numbers[r][c] = rand() % 90 + 1;
            }
        }
        for (int i = 0; i < 25; i++) {
            cards[i].freeSpaces[i] = 1;
        }
    }
}

void playBingo() {
    int drawnNumbers[25];
    int drawnNumberIndex = 0;

    // Draw numbers
    for (int i = 0; i < 25; i++) {
        drawnNumbers[i] = rand() % 90 + 1;
    }

    // Check if someone won
    for (int i = 0; i < MAX_BINGO_CARDS; i++) {
        for (int r = 0; r < 5; r++) {
            for (int c = 0; c < 5; c++) {
                if (cards[i].numbers[r][c] == drawnNumbers[drawnNumberIndex]) {
                    cards[i].freeSpaces[r * 5 + c] = 0;
                }
            }
        }

        if (cards[i].wins == 0 && cards[i].freeSpaces[0] == 0) {
            cards[i].wins = 1;
            printf("Bingo! Card %d won!\n", i + 1);
        }
    }

    // Increment drawn number index
    drawnNumberIndex++;
}

int main() {
    generateBingoCards();
    playBingo();
    return 0;
}