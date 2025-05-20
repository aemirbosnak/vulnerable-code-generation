//FormAI DATASET v1.0 Category: Memory Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 20

int main() {
    int cards[MAX_CARDS] = {0};
    int opened[MAX_CARDS] = {0};
    int num_cards, num_matches;
    int num_opened = 0;
    int first_card, second_card;

    // Get number of cards and matches
    printf("Enter number of cards (up to %d): ", MAX_CARDS);
    scanf("%d", &num_cards);
    if (num_cards > MAX_CARDS) num_cards = MAX_CARDS;
    num_matches = num_cards / 2;

    // Generate random cards
    srand(time(NULL));
    for (int i = 0; i < num_matches; i++) {
        int val = rand() % 100 + 1;
        int pos1, pos2;
        do {
            pos1 = rand() % num_cards;
        } while (cards[pos1] != 0);
        do {
            pos2 = rand() % num_cards;
        } while (cards[pos2] != 0 || pos2 == pos1);
        cards[pos1] = val;
        cards[pos2] = val;
    }

    // Play game
    printf("Memory game start!\n");
    while (num_opened < num_cards) {
        int card_num;
        do {
            printf("Enter the card number to open (1-%d): ", num_cards);
            scanf("%d", &card_num);
            card_num--;
        } while (card_num < 0 || card_num >= num_cards || opened[card_num] == 1);
        opened[card_num] = 1;
        num_opened++;
        if (num_opened % 2 == 1) {
            first_card = card_num;
            printf("First card opened.\n");
        } else {
            second_card = card_num;
            printf("Second card opened.\n");
            if (cards[first_card] == cards[second_card]) {
                printf("Match found!\n");
            } else {
                printf("No match.\n");
                opened[first_card] = 0;
                opened[second_card] = 0;
                num_opened -= 2;
            }
        }
    }
    printf("Congratulations, you won!\n");

    return 0;
}