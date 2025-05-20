//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 4
#define NUM_CARDS (ROWS * COLS)

typedef struct {
    int row;
    int col;
    char symbol;
} card_t;

void init_cards(card_t cards[NUM_CARDS]) {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        cards[i].row = rand() % ROWS;
        cards[i].col = rand() % COLS;
        cards[i].symbol = 'X';
    }
}

void print_card(const card_t *card) {
    int row = card->row;
    int col = card->col;
    printf("(%d,%d): %c\n", row, col, card->symbol);
}

void print_cards(const card_t cards[NUM_CARDS]) {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        print_card(&cards[i]);
    }
}

int main() {
    srand(time(NULL));
    card_t cards[NUM_CARDS];
    init_cards(cards);
    print_cards(cards);

    int choice;
    char input[10];
    while (1) {
        printf("Enter your choice (row,col): ");
        scanf("%s", input);
        sscanf(input, "%d,%d", &choice, &choice);
        if (choice < 0 || choice >= NUM_CARDS) {
            printf("Invalid choice\n");
            continue;
        }
        if (cards[choice].symbol == 'X') {
            printf("Card (%d,%d) has already been revealed\n", cards[choice].row, cards[choice].col);
            continue;
        }
        if (choice == NUM_CARDS - 1) {
            printf("Congratulations! You won the game!\n");
            break;
        }
        cards[choice].symbol = 'X';
        print_cards(cards);
    }

    return 0;
}