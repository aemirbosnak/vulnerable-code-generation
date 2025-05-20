//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Struct to hold the bingo card
typedef struct {
    int nums[5][5];
    bool filled;
} BingoCard;

// Function to initialize a bingo card
void initBingoCard(BingoCard *card) {
    srand(time(NULL));

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            card->nums[i][j] = rand() % 75 + 1;
        }
    }
    card->filled = false;
}

// Function to print a bingo card
void printBingoCard(BingoCard card) {
    printf("Bingo Card:\n");

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", card.nums[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a bingo card is filled
bool isBingoCardFilled(BingoCard card) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (!card.filled && card.nums[i][j] == 75) {
                return true;
            }
        }
    }
    return false;
}

// Function to play a game of bingo
void playBingo(BingoCard card) {
    printf("Let's play Bingo!\n");

    while (!isBingoCardFilled(card)) {
        printf("Number called: ");
        scanf("%d", &card.nums[rand() % 5][rand() % 5]);
        printf("Number called: %d\n", card.nums[rand() % 5][rand() % 5]);

        if (card.nums[rand() % 5][rand() % 5] == 75) {
            printf("Bingo!\n");
            card.filled = true;
        }
    }

    if (isBingoCardFilled(card)) {
        printf("Congratulations! You have won the game!\n");
    } else {
        printf("Sorry, no bingo this time.\n");
    }
}

// Main function
int main() {
    BingoCard card;

    initBingoCard(&card);

    printBingoCard(card);

    playBingo(card);

    return 0;
}