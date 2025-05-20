//FormAI DATASET v1.0 Category: Poker Game ; Style: light-weight
// C Poker Game example program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_SUITS 4
#define NUM_VALUES 13

char* suits[] = {"hearts", "spades", "diamonds", "clubs"};
char* values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

struct card {
    int suit;
    int value;
};

void shuffle(struct card* deck) {
    int i, j;
    struct card temp_card;
    for (i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;
        temp_card = deck[i];
        deck[i] = deck[j];
        deck[j] = temp_card;
    }
}

void print_card(struct card card) {
    printf("%s of %s\n", values[card.value], suits[card.suit]);
}

void print_hand(struct card* hand, int size) {
    int i;
    for (i = 0; i < size; i++) {
        print_card(hand[i]);
    }
}

int score_hand(struct card* hand, int size) {
    int i, score = 0;
    for (i = 0; i < size; i++) {
        if (hand[i].value >= 9 && hand[i].value <= 12) {
            score += 10;
        } else if (hand[i].value == 0) {
            score += 11;
        } else {
            score += hand[i].value + 1;
        }
    }
    return score;
}

int main() {
    srand(time(NULL));
    struct card deck[NUM_CARDS];
    int i, j, num_players, num_cards, num_draws, player_score, dealer_score;
    printf("Welcome to C Poker Game!\n");
    printf("How many players? ");
    scanf("%d", &num_players);
    while (num_players < 1 || num_players > 10) {
        printf("Please enter a number between 1 and 10: ");
        scanf("%d", &num_players);
    }
    printf("How many cards per player? ");
    scanf("%d", &num_cards);
    while (num_cards < 1 || num_cards > NUM_CARDS / num_players) {
        printf("Please enter a number between 1 and %d: ", NUM_CARDS / num_players);
        scanf("%d", &num_cards);
    }
    printf("How many card draws? ");
    scanf("%d", &num_draws);
    while (num_draws < 0 || num_draws > NUM_CARDS - num_players * num_cards) {
        printf("Please enter a number between 0 and %d: ", NUM_CARDS - num_players * num_cards);
        scanf("%d", &num_draws);
    }
    for (i = 0; i < NUM_SUITS; i++) {
        for (j = 0; j < NUM_VALUES; j++) {
            deck[i * NUM_VALUES + j].suit = i;
            deck[i * NUM_VALUES + j].value = j;
        }
    }
    shuffle(deck);
    printf("\n");
    for (i = 0; i < num_players; i++) {
        printf("Player %d's hand:\n", i + 1);
        struct card hand[num_cards + num_draws];
        for (j = 0; j < num_cards; j++) {
            hand[j] = deck[i * num_cards + j];
        }
        for (j = num_cards; j < num_cards + num_draws; j++) {
            hand[j] = deck[NUM_CARDS - (i * num_cards + j - num_cards + 1)];
        }
        print_hand(hand, num_cards + num_draws);
        player_score = score_hand(hand, num_cards + num_draws);
        printf("Player %d's score: %d\n", i + 1, player_score);
        printf("\n");
    }
    printf("Dealer's hand:\n");
    struct card dealer_hand[num_cards + num_draws];
    for (i = 0; i < num_cards; i++) {
        dealer_hand[i] = deck[num_players * num_cards + i];
    }
    for (i = num_cards; i < num_cards + num_draws; i++) {
        dealer_hand[i] = deck[NUM_CARDS - (num_players * num_cards + i - num_cards + 1)];
    }
    print_hand(dealer_hand, num_cards + num_draws);
    dealer_score = score_hand(dealer_hand, num_cards + num_draws);
    printf("Dealer's score: %d\n", dealer_score);
    printf("\n");
    for (i = 0; i < num_players; i++) {
        if (score_hand(dealer_hand, num_cards + num_draws) > 21) {
            printf("Player %d wins!\n", i + 1);
        } else if (score_hand(dealer_hand, num_cards + num_draws) > score_hand(dealer_hand, num_cards + num_draws)) {
            printf("Player %d wins!\n", i + 1);
        } else {
            printf("Player %d loses.\n", i + 1);
        }
    }
    return 0;
}