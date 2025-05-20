//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 4
#define MATRIX_SIZE (ROWS * COLS)
#define NUM_CARDS (ROWS * COLS / 2)

typedef struct {
    int row;
    int col;
    char value;
    int is_revealed;
} Card;

Card deck[NUM_CARDS];
int num_revealed_cards = 0;

void init_deck(void) {
    int i;
    srand(time(NULL));
    for (i = 0; i < NUM_CARDS; i++) {
        deck[i].row = rand() % ROWS;
        deck[i].col = rand() % COLS;
        deck[i].value = (char)('A' + rand() % 26);
        deck[i].is_revealed = 0;
    }
}

void print_deck(void) {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        if (deck[i].is_revealed) {
            printf(" %c ", deck[i].value);
        } else {
            printf(" X ");
        }
    }
    printf("\n");
}

void reveal_card(int row, int col) {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        if (deck[i].row == row && deck[i].col == col) {
            deck[i].is_revealed = 1;
            num_revealed_cards++;
            break;
        }
    }
}

int check_win(void) {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        if (!deck[i].is_revealed) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int choice;
    int row, col;

    init_deck();

    while (1) {
        print_deck();

        printf("Enter your choice (row and column): ");
        scanf("%d %d", &row, &col);

        if (row >= ROWS || col >= COLS) {
            printf("Invalid choice.\n");
            continue;
        }

        reveal_card(row, col);

        if (check_win()) {
            printf("You win!\n");
            break;
        }
    }

    return 0;
}