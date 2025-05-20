//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define NUM_CARDS 8

int cards[NUM_CARDS][2] = {{1, 1}, {1, 2}, {1, 3}, {1, 4}, {2, 1}, {2, 2}, {2, 3}, {2, 4}};

void init_cards() {
    int i;
    srand(time(NULL));
    for (i = 0; i < NUM_CARDS; i++) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        cards[i][0] = row;
        cards[i][1] = col;
    }
}

void print_board() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if ((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 1 && j == 0) || (i == 1 && j == 1)) {
                printf(" %c ", (i * 2 + j + 1) % 3 + 'A');
            } else {
                printf(" %c ", '.');
            }
        }
        printf("\n");
    }
}

void flip_card(int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        int card_index = -1;
        for (int i = 0; i < NUM_CARDS; i++) {
            if (cards[i][0] == row && cards[i][1] == col) {
                card_index = i;
                break;
            }
        }
        if (card_index!= -1) {
            cards[card_index][0] = -1;
            cards[card_index][1] = -1;
        }
    }
}

void check_match(int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        int card_index = -1;
        for (int i = 0; i < NUM_CARDS; i++) {
            if (cards[i][0] == row && cards[i][1] == col) {
                card_index = i;
                break;
            }
        }
        if (card_index!= -1) {
            cards[card_index][0] = -1;
            cards[card_index][1] = -1;
            printf("Match!\n");
        } else {
            printf("No match.\n");
            flip_card(row, col);
        }
    }
}

int main() {
    int i, j, match_count = 0;
    init_cards();
    print_board();
    while (match_count < NUM_CARDS) {
        int row, col;
        printf("Enter row and column: ");
        scanf("%d%d", &row, &col);
        flip_card(row, col);
        print_board();
        check_match(row, col);
        match_count += 1;
    }
    return 0;
}