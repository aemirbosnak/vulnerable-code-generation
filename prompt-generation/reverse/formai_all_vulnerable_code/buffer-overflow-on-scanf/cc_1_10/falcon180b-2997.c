//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 16

typedef struct {
    int value;
    int matched;
} Card;

void init_cards(Card cards[MAX_CARDS]) {
    for (int i = 0; i < MAX_CARDS; i++) {
        cards[i].value = i + 1;
        cards[i].matched = 0;
    }
}

void shuffle_cards(Card cards[MAX_CARDS]) {
    srand(time(0));
    for (int i = 0; i < MAX_CARDS; i++) {
        int j = rand() % MAX_CARDS;
        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void print_cards(Card cards[MAX_CARDS]) {
    for (int i = 0; i < MAX_CARDS; i++) {
        if (!cards[i].matched)
            printf("%d ", cards[i].value);
        else
            printf("X ");
    }
    printf("\n");
}

int main() {
    Card cards[MAX_CARDS];
    init_cards(cards);
    shuffle_cards(cards);
    printf("Shuffled cards:\n");
    print_cards(cards);

    int num_turns = 0;
    while (num_turns < 10) {
        int choice1, choice2;
        printf("Enter two card numbers (1-%d): ", MAX_CARDS);
        scanf("%d %d", &choice1, &choice2);
        if (choice1 < 1 || choice1 > MAX_CARDS || choice2 < 1 || choice2 > MAX_CARDS) {
            printf("Invalid choice.\n");
            continue;
        }
        if (cards[choice1-1].matched || cards[choice2-1].matched) {
            printf("Card already matched.\n");
            continue;
        }
        if (cards[choice1-1].value == cards[choice2-1].value) {
            cards[choice1-1].matched = 1;
            cards[choice2-1].matched = 1;
            printf("Match found!\n");
            num_turns++;
        } else {
            printf("No match.\n");
            cards[choice1-1].matched = 1;
            cards[choice2-1].matched = 1;
        }
    }

    printf("Game over.\n");
    return 0;
}