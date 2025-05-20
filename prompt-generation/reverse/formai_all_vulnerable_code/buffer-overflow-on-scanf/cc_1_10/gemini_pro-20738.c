//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGO_SIZE 5

typedef struct {
    int numbers[BINGO_SIZE * BINGO_SIZE];
    int marked[BINGO_SIZE * BINGO_SIZE];
} BingoCard;

void init_card(BingoCard *card) {
    int i, j, k;

    // Fill the card with random numbers
    for (i = 0; i < BINGO_SIZE * BINGO_SIZE; i++) {
        card->numbers[i] = rand() % 100 + 1;
    }

    // Mark all numbers as unmarked
    for (i = 0; i < BINGO_SIZE * BINGO_SIZE; i++) {
        card->marked[i] = 0;
    }
}

void print_card(BingoCard *card) {
    int i, j;

    for (i = 0; i < BINGO_SIZE; i++) {
        for (j = 0; j < BINGO_SIZE; j++) {
            printf("%2d ", card->numbers[i * BINGO_SIZE + j]);
        }
        printf("\n");
    }
}

int check_bingo(BingoCard *card) {
    int i, j, k;

    // Check rows
    for (i = 0; i < BINGO_SIZE; i++) {
        for (j = 0; j < BINGO_SIZE; j++) {
            if (!card->marked[i * BINGO_SIZE + j]) {
                break;
            }
        }
        if (j == BINGO_SIZE) {
            return 1;
        }
    }

    // Check columns
    for (i = 0; i < BINGO_SIZE; i++) {
        for (j = 0; j < BINGO_SIZE; j++) {
            if (!card->marked[j * BINGO_SIZE + i]) {
                break;
            }
        }
        if (j == BINGO_SIZE) {
            return 1;
        }
    }

    // Check diagonals
    for (i = 0; i < BINGO_SIZE; i++) {
        if (!card->marked[i * BINGO_SIZE + i]) {
            break;
        }
    }
    if (i == BINGO_SIZE) {
        return 1;
    }

    for (i = 0; i < BINGO_SIZE; i++) {
        if (!card->marked[(BINGO_SIZE - 1 - i) * BINGO_SIZE + i]) {
            break;
        }
    }
    if (i == BINGO_SIZE) {
        return 1;
    }

    return 0;
}

int main() {
    BingoCard card;
    int i, j, k;

    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the card
    init_card(&card);

    // Print the card
    print_card(&card);

    // Get the numbers to mark
    printf("Enter the numbers to mark (separated by spaces): ");
    for (i = 0; i < BINGO_SIZE * BINGO_SIZE; i++) {
        scanf("%d", &k);
        for (j = 0; j < BINGO_SIZE * BINGO_SIZE; j++) {
            if (card.numbers[j] == k) {
                card.marked[j] = 1;
            }
        }
    }

    // Check if the card is a winner
    if (check_bingo(&card)) {
        printf("BINGO!\n");
    } else {
        printf("No bingo.\n");
    }

    return 0;
}