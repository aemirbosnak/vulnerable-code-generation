//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define BOARD_SIZE_SQUARED (BOARD_SIZE * BOARD_SIZE)
#define FLIPPED_CARD_CHAR 'X'

typedef struct {
    int value;
    int flipped;
} card_t;

card_t board[BOARD_SIZE_SQUARED];

void shuffle_board() {
    int i, j, k;
    card_t temp;

    for (i = 0; i < BOARD_SIZE_SQUARED; i++) {
        board[i].value = i / 2;
        board[i].flipped = 0;
    }

    for (i = 0; i < BOARD_SIZE_SQUARED; i++) {
        j = rand() % BOARD_SIZE_SQUARED;
        temp = board[i];
        board[i] = board[j];
        board[j] = temp;
    }
}

void print_board() {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i * BOARD_SIZE + j].flipped) {
                printf("%d ", board[i * BOARD_SIZE + j].value);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int check_for_match(int card1, int card2) {
    return board[card1].value == board[card2].value;
}

void flip_card(int card) {
    board[card].flipped = 1;
}

int main() {
    int card1, card2, matches_found = 0;
    char input;

    srand(time(NULL));
    shuffle_board();

    while (matches_found < BOARD_SIZE_SQUARED / 2) {
        printf("\n\n");
        print_board();

        printf("Enter two cards to flip (e.g., 1 3): ");
        scanf("%d %d", &card1, &card2);

        flip_card(card1);
        flip_card(card2);

        if (check_for_match(card1, card2)) {
            printf("Match found!\n");
            matches_found++;
        } else {
            printf("No match found.\n");
            flip_card(card1);
            flip_card(card2);
        }

        printf("Press any key to continue: ");
        scanf(" %c", &input);
    }

    printf("\n\nCongratulations! You found all the matches.\n");

    return 0;
}