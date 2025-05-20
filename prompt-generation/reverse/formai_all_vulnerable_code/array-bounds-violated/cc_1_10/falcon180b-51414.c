//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define NUM_CARDS 8

typedef struct {
    char value;
    int is_revealed;
} Card;

void init_deck(Card deck[NUM_CARDS]) {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        deck[i].value = '2' + i;
        deck[i].is_revealed = 0;
    }
}

void print_deck(Card deck[NUM_CARDS]) {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        if (deck[i].is_revealed) {
            printf("%c ", deck[i].value);
        } else {
            printf("? ");
        }
    }
    printf("\n");
}

int match_cards(Card card1, Card card2) {
    return card1.value == card2.value;
}

void reveal_card(Card *card) {
    if (!(*card).is_revealed) {
        (*card).is_revealed = 1;
    }
}

void hide_card(Card *card) {
    (*card).is_revealed = 0;
}

int main() {
    srand(time(NULL));

    Card deck[NUM_CARDS];
    init_deck(deck);

    int selected_row, selected_col;
    int num_matches = 0;

    while (num_matches < NUM_CARDS / 2) {
        system("clear");
        print_deck(deck);

        printf("Enter row and column of card to reveal: ");
        scanf("%d %d", &selected_row, &selected_col);

        if (selected_row >= 0 && selected_row < ROWS &&
            selected_col >= 0 && selected_col < COLS) {
            int card_index = selected_row * COLS + selected_col;
            if (!deck[card_index].is_revealed) {
                reveal_card(&deck[card_index]);
                num_matches += 1;
            } else {
                hide_card(&deck[card_index]);
            }
        } else {
            printf("Invalid selection.\n");
        }

        if (num_matches >= NUM_CARDS / 2) {
            printf("Congratulations! You won the game.\n");
            break;
        }

        if (num_matches + 1 >= NUM_CARDS) {
            printf("Game over. Try again.\n");
            break;
        }
    }

    return 0;
}