//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define WIN_NUMBERS 5

typedef struct {
    int number;
    int called;
} BingoCell;

typedef struct {
    BingoCell cells[ROWS][COLS];
    int called_count;
} BingoCard;

void init_card(BingoCard *card) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            card->cells[i][j].number = (i * COLS) + j + 1;
            card->cells[i][j].called = 0;
        }
    }
}

void print_card(BingoCard *card) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", card->cells[i][j].number);
        }
        printf("\n");
    }
}

int call_number(BingoCard *card, int number) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (card->cells[i][j].number == number) {
                card->cells[i][j].called = 1;
                card->called_count++;
                return 1;
            }
        }
    }
    return 0;
}

int check_for_win(BingoCard *card) {
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        int count = 0;
        for (int j = 0; j < COLS; j++) {
            if (card->cells[i][j].called) {
                count++;
            }
        }
        if (count == COLS) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < COLS; j++) {
        int count = 0;
        for (int i = 0; i < ROWS; i++) {
            if (card->cells[i][j].called) {
                count++;
            }
        }
        if (count == ROWS) {
            return 1;
        }
    }

    // Check diagonals
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        if (card->cells[i][i].called) {
            count++;
        }
    }
    if (count == ROWS) {
        return 1;
    }

    count = 0;
    for (int i = 0; i < ROWS; i++) {
        if (card->cells[i][ROWS - i - 1].called) {
            count++;
        }
    }
    if (count == ROWS) {
        return 1;
    }

    return 0;
}

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Create bingo card
    BingoCard card;
    init_card(&card);

    // Print bingo card
    printf("Your bingo card:\n");
    print_card(&card);

    // Generate random numbers
    int numbers[WIN_NUMBERS];
    for (int i = 0; i < WIN_NUMBERS; i++) {
        int number = rand() % (ROWS * COLS) + 1;
        numbers[i] = number;
    }

    // Call numbers and check for win
    int win = 0;
    for (int i = 0; i < WIN_NUMBERS; i++) {
        int number = numbers[i];
        printf("Calling number %d\n", number);
        if (call_number(&card, number)) {
            print_card(&card);
            if (check_for_win(&card)) {
                win = 1;
                break;
            }
        }
    }

    if (win) {
        printf("Congratulations! You won!\n");
    } else {
        printf("Sorry, you lost.\n");
    }

    return 0;
}