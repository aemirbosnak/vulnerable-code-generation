//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 4
#define NUM_PAIRS 8

typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    char value;
    int is_flipped;
} Card;

Card board[BOARD_SIZE][BOARD_SIZE];
Position flipped_cards[2];
int num_flipped_cards;
int num_matches;

void create_board() {
    int i, j, k;
    char values[NUM_PAIRS];

    // Generate a list of unique values for the cards.
    for (i = 0; i < NUM_PAIRS; i++) {
        values[i] = 'A' + i;
    }

    // Shuffle the values.
    for (i = 0; i < NUM_PAIRS; i++) {
        int r = rand() % (NUM_PAIRS - i);
        char temp = values[i];
        values[i] = values[r];
        values[r] = temp;
    }

    // Place the cards on the board.
    k = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j].value = values[k];
            board[i][j].is_flipped = 0;
            k++;
        }
    }
}

void print_board() {
    int i, j;

    printf("  ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");

    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].is_flipped) {
                printf("%c ", board[i][j].value);
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }
}

void flip_card(int row, int col) {
    if (board[row][col].is_flipped) {
        return;
    }

    board[row][col].is_flipped = 1;
    flipped_cards[num_flipped_cards].row = row;
    flipped_cards[num_flipped_cards].col = col;
    num_flipped_cards++;

    if (num_flipped_cards == 2) {
        if (board[flipped_cards[0].row][flipped_cards[0].col].value == board[flipped_cards[1].row][flipped_cards[1].col].value) {
            num_matches++;
            printf("Match!\n");
        } else {
            printf("No match.\n");
            board[flipped_cards[0].row][flipped_cards[0].col].is_flipped = 0;
            board[flipped_cards[1].row][flipped_cards[1].col].is_flipped = 0;
        }

        num_flipped_cards = 0;
    }
}

int main() {
    int row, col;

    srand(time(NULL));
    create_board();

    while (num_matches < NUM_PAIRS) {
        print_board();

        printf("Enter the row and column of the card you want to flip (e.g. 1 2): ");
        scanf("%d %d", &row, &col);

        flip_card(row - 1, col - 1);
    }

    printf("Congratulations! You found all the matches.\n");

    return 0;
}