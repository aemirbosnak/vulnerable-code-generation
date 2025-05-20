//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGO_SIZE 5

typedef struct {
    int numbers[BINGO_SIZE][BINGO_SIZE];
    int called[BINGO_SIZE][BINGO_SIZE];
} BingoCard;

void print_card(BingoCard *card) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            printf("%2d ", card->numbers[i][j]);
        }
        printf("\n");
    }
}

int check_for_bingo(BingoCard *card) {
    // Check for horizontal bingos
    for (int i = 0; i < BINGO_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card->called[i][j]) {
                count++;
            }
        }
        if (count == BINGO_SIZE) {
            return 1;
        }
    }

    // Check for vertical bingos
    for (int j = 0; j < BINGO_SIZE; j++) {
        int count = 0;
        for (int i = 0; i < BINGO_SIZE; i++) {
            if (card->called[i][j]) {
                count++;
            }
        }
        if (count == BINGO_SIZE) {
            return 1;
        }
    }

    // Check for diagonal bingos
    int count = 0;
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (card->called[i][i]) {
            count++;
        }
    }
    if (count == BINGO_SIZE) {
        return 1;
    }

    count = 0;
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (card->called[i][BINGO_SIZE - 1 - i]) {
            count++;
        }
    }
    if (count == BINGO_SIZE) {
        return 1;
    }

    return 0;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a bingo card
    BingoCard card;
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            card.numbers[i][j] = (i * BINGO_SIZE) + j + 1;
            card.called[i][j] = 0;
        }
    }

    // Shuffle the card
    for (int i = 0; i < BINGO_SIZE * BINGO_SIZE; i++) {
        int r1 = rand() % BINGO_SIZE;
        int r2 = rand() % BINGO_SIZE;
        int temp = card.numbers[r1][r2];
        card.numbers[r1][r2] = card.numbers[i][i];
        card.numbers[i][i] = temp;
    }

    // Print the card
    printf("Your bingo card:\n");
    print_card(&card);

    // Get the called numbers
    int called_numbers[BINGO_SIZE * BINGO_SIZE];
    for (int i = 0; i < BINGO_SIZE * BINGO_SIZE; i++) {
        called_numbers[i] = 0;
    }

    // Play the game
    int number;
    while (1) {
        // Get a random number
        number = rand() % (BINGO_SIZE * BINGO_SIZE) + 1;

        // Check if the number has already been called
        if (called_numbers[number - 1]) {
            continue;
        }

        // Mark the number as called
        called_numbers[number - 1] = 1;

        // Check for bingo
        if (check_for_bingo(&card)) {
            printf("Bingo! You win!\n");
            break;
        }

        // Print the called numbers
        printf("Called numbers: ");
        for (int i = 0; i < BINGO_SIZE * BINGO_SIZE; i++) {
            if (called_numbers[i]) {
                printf("%2d ", i + 1);
            }
        }
        printf("\n");
    }

    return 0;
}