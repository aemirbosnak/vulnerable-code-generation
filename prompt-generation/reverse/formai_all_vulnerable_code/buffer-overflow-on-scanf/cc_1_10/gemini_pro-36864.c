//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

typedef struct {
    int value;
    int flipped;
} Card;

void init_game(Card deck[SIZE][SIZE]) {
    int values[] = {1, 1, 2, 2, 3, 3, 4, 4};
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int index = rand() % 8;
            deck[i][j].value = values[index];
            deck[i][j].flipped = 0;
        }
    }
}

void print_game(Card deck[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (deck[i][j].flipped) {
                printf("%d ", deck[i][j].value);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Card deck[SIZE][SIZE];
    init_game(deck);

    int flips = 0;
    int first_card_i, first_card_j, second_card_i, second_card_j;
    int first_card_flipped = 0;

    while (flips < 8) {
        print_game(deck);

        printf("Enter the first card coordinates (i, j): ");
        scanf(" %d %d", &first_card_i, &first_card_j);

        if (first_card_i < 0 || first_card_i >= SIZE || first_card_j < 0 || first_card_j >= SIZE) {
            printf("Invalid coordinates!\n");
            continue;
        }

        if (deck[first_card_i][first_card_j].flipped) {
            printf("Card already flipped!\n");
            continue;
        }

        deck[first_card_i][first_card_j].flipped = 1;
        flips++;

        if (!first_card_flipped) {
            first_card_i = first_card_i;
            first_card_j = first_card_j;
            first_card_flipped = 1;
        } else {
            second_card_i = first_card_i;
            second_card_j = first_card_j;
            first_card_flipped = 0;

            if (deck[first_card_i][first_card_j].value == deck[second_card_i][second_card_j].value) {
                printf("Match found!\n");
            } else {
                printf("No match found!\n");
                deck[first_card_i][first_card_j].flipped = 0;
                deck[second_card_i][second_card_j].flipped = 0;
            }
        }
    }

    printf("Game over!\n");

    return 0;
}