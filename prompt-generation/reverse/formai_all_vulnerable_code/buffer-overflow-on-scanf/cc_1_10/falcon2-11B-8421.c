//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 10
#define MAX_NUMBERS 100

typedef struct {
    int card[MAX_NUMBERS];
    int drawn[MAX_NUMBERS];
    int num_drawn;
    int num_bings;
} card_t;

void print_card(card_t *card) {
    printf("Card: ");
    for (int i = 0; i < MAX_NUMBERS; i++) {
        if (card->drawn[i])
            printf("%d ", i);
        else
            printf("- ");
    }
    printf("\n");
}

void draw_numbers(card_t *cards, int num_cards, int num_drawn) {
    for (int i = 0; i < num_cards; i++) {
        int num;
        do {
            num = rand() % MAX_NUMBERS;
        } while (cards[i].drawn[num]);
        cards[i].drawn[num] = 1;
        num_drawn++;
    }
}

void print_results(card_t *cards, int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        printf("Card %d:\n", i + 1);
        print_card(&cards[i]);
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int num_cards = 0;
    card_t *cards = malloc(num_cards * sizeof(card_t));

    printf("Enter number of cards to generate: ");
    int num_cards_input;
    scanf("%d", &num_cards_input);

    for (int i = 0; i < num_cards_input; i++) {
        int num_drawn = 0;
        card_t *card = &cards[i];
        for (int j = 0; j < MAX_NUMBERS; j++) {
            card->drawn[j] = 0;
            card->card[j] = j + 1;
        }
        draw_numbers(cards, num_cards, num_drawn);
        num_cards++;
    }

    print_results(cards, num_cards);

    return 0;
}