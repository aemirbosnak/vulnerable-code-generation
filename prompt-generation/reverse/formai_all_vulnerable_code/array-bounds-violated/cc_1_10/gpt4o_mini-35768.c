//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BINGO_SIZE 5
#define MAX_NUM 75

typedef struct BingoCard {
    int numbers[BINGO_SIZE][BINGO_SIZE];
} BingoCard;

void initialize_card(BingoCard *card) {
    int columns[5][15] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45},
        {46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
        {61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75}
    };

    // Randomizing numbers
    for (int col = 0; col < BINGO_SIZE; col++) {
        int drawn[15] = {0}; // Track drawn numbers for a column
        for (int row = 0; row < BINGO_SIZE; row++) {
            int num;
            do {
                num = columns[col][rand() % 15];
            } while (drawn[num - (col * 15)]); // Check if already drawn
            drawn[num - (col * 15)] = 1; // Mark as drawn
            card->numbers[row][col] = num; // Assign to card
        }
    }
    card->numbers[2][2] = 0; // Free space
}

void print_card(const BingoCard *card) {
    printf(" B   I   N   G   O\n");
    for (int row = 0; row < BINGO_SIZE; row++) {
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (card->numbers[row][col] == 0) {
                printf(" *  ");
            } else {
                printf("%-3d ", card->numbers[row][col]);
            }
        }
        printf("\n");
    }
}

void mark_number(BingoCard *card, int number) {
    for (int row = 0; row < BINGO_SIZE; row++) {
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (card->numbers[row][col] == number) {
                card->numbers[row][col] = 0; // Mark number as drawn
            }
        }
    }
}

int check_bingo(const BingoCard *card) {
    // Check rows and columns for bingo
    for (int i = 0; i < BINGO_SIZE; i++) {
        if ((card->numbers[i][0] == 0 && card->numbers[i][1] == 0 &&
             card->numbers[i][2] == 0 && card->numbers[i][3] == 0 &&
             card->numbers[i][4] == 0) ||  // Check row
            (card->numbers[0][i] == 0 && card->numbers[1][i] == 0 &&
             card->numbers[2][i] == 0 && card->numbers[3][i] == 0 &&
             card->numbers[4][i] == 0)) { // Check column
            return 1; // Bingo!
        }
    }
    // Check diagonals
    if (card->numbers[0][0] == 0 && card->numbers[1][1] == 0 &&
        card->numbers[2][2] == 0 && card->numbers[3][3] == 0 &&
        card->numbers[4][4] == 0) {
        return 1; // Bingo on diagonal
    }
    if (card->numbers[0][4] == 0 && card->numbers[1][3] == 0 &&
        card->numbers[2][2] == 0 && card->numbers[3][1] == 0 &&
        card->numbers[4][0] == 0) {
        return 1; // Bingo on reverse diagonal
    }
    return 0; // No Bingo
}

void simulate_bingo() {
    srand(time(NULL));
    BingoCard card;
    initialize_card(&card);
    print_card(&card);

    int drawn_numbers[MAX_NUM] = {0};
    int current_number;
    while (1) {
        current_number = rand() % MAX_NUM + 1;
        if (drawn_numbers[current_number - 1]) continue; // Skip if already drawn
        drawn_numbers[current_number - 1] = 1; // Mark the drawn number
        printf("Number drawn: %d\n", current_number);
        mark_number(&card, current_number);
        print_card(&card);

        if (check_bingo(&card)) {
            printf("Bingo! You've won!\n");
            break;
        }

        // Optional: Uncomment the next line for a slight delay between draws
        // usleep(1000000);
    }
}

int main() {
    printf("Welcome to Bingo!\n");
    simulate_bingo();
    return 0;
}