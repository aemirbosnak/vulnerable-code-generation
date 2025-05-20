//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 4
#define COLS 4
#define NUM_CARDS 8

typedef struct {
    int row;
    int col;
} Card;

void init_cards(Card cards[NUM_CARDS]) {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        cards[i].row = -1;
        cards[i].col = -1;
    }
}

void shuffle_cards(Card cards[NUM_CARDS]) {
    int i, j;
    for (i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;
        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void place_card(Card cards[NUM_CARDS], int row, int col) {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        if (cards[i].row == -1 && cards[i].col == -1) {
            cards[i].row = row;
            cards[i].col = col;
            return;
        }
    }
}

bool check_match(Card a, Card b) {
    return (a.row == b.row && a.col == b.col);
}

void draw_board(Card cards[NUM_CARDS]) {
    int i;
    for (i = 0; i < ROWS; i++) {
        printf("----+");
    }
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        printf("|   |");
    }
    printf("\n");
}

void draw_card(Card card, int player) {
    if (player == 1) {
        printf("X");
    } else {
        printf("O");
    }
}

int main() {
    srand(time(NULL));
    Card cards[NUM_CARDS];
    init_cards(cards);
    shuffle_cards(cards);
    int player = 1;
    int matches = 0;
    while (matches < NUM_CARDS) {
        draw_board(cards);
        int row, col;
        printf("Player %d, enter row and column: ", player);
        scanf("%d%d", &row, &col);
        place_card(cards, row, col);
        if (check_match(cards[0], cards[1])) {
            printf("Match found!\n");
            matches++;
        } else {
            printf("No match found.\n");
        }
        player++;
        if (player > 2) {
            player = 1;
        }
    }
    return 0;
}