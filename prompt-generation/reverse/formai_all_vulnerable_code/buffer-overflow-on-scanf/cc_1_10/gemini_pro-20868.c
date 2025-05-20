//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGO_SIZE 5
#define BINGO_NUMBERS 75

typedef struct {
    int numbers[BINGO_SIZE][BINGO_SIZE];
    int marked[BINGO_SIZE][BINGO_SIZE];
} BingoCard;

void init_bingo_card(BingoCard *card) {
    int i, j, num;

    // Fill the card with random numbers
    for (i = 0; i < BINGO_SIZE; i++) {
        for (j = 0; j < BINGO_SIZE; j++) {
            do {
                num = rand() % BINGO_NUMBERS + 1;
            } while (card->numbers[i][j] == num);
            card->numbers[i][j] = num;
        }
    }

    // Mark all numbers as unmarked
    for (i = 0; i < BINGO_SIZE; i++) {
        for (j = 0; j < BINGO_SIZE; j++) {
            card->marked[i][j] = 0;
        }
    }
}

void print_bingo_card(BingoCard *card) {
    int i, j;

    for (i = 0; i < BINGO_SIZE; i++) {
        for (j = 0; j < BINGO_SIZE; j++) {
            printf("%2d ", card->numbers[i][j]);
        }
        printf("\n");
    }
}

int check_bingo(BingoCard *card) {
    int i, j, bingo = 1;

    // Check rows
    for (i = 0; i < BINGO_SIZE; i++) {
        bingo = 1;
        for (j = 0; j < BINGO_SIZE; j++) {
            if (!card->marked[i][j]) {
                bingo = 0;
                break;
            }
        }
        if (bingo) {
            return 1;
        }
    }

    // Check columns
    for (j = 0; j < BINGO_SIZE; j++) {
        bingo = 1;
        for (i = 0; i < BINGO_SIZE; i++) {
            if (!card->marked[i][j]) {
                bingo = 0;
                break;
            }
        }
        if (bingo) {
            return 1;
        }
    }

    // Check diagonals
    bingo = 1;
    for (i = 0; i < BINGO_SIZE; i++) {
        if (!card->marked[i][i]) {
            bingo = 0;
            break;
        }
    }
    if (bingo) {
        return 1;
    }

    bingo = 1;
    for (i = 0; i < BINGO_SIZE; i++) {
        if (!card->marked[i][BINGO_SIZE - 1 - i]) {
            bingo = 0;
            break;
        }
    }
    if (bingo) {
        return 1;
    }

    return 0;
}

int main() {
    BingoCard card;
    int num, i, j;

    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the bingo card
    init_bingo_card(&card);

    // Print the bingo card
    printf("Your bingo card:\n");
    print_bingo_card(&card);

    // Get the numbers from the user
    printf("\nEnter the numbers one by one:\n");
    for (i = 0; i < BINGO_NUMBERS; i++) {
        scanf("%d", &num);

        // Mark the number on the card
        for (j = 0; j < BINGO_SIZE; j++) {
            for (i = 0; i < BINGO_SIZE; i++) {
                if (card.numbers[i][j] == num) {
                    card.marked[i][j] = 1;
                    break;
                }
            }
        }

        // Check for bingo
        if (check_bingo(&card)) {
            printf("You won!\n");
            break;
        }
    }

    if (!check_bingo(&card)) {
        printf("You lost!\n");
    }

    return 0;
}