//FormAI DATASET v1.0 Category: Poker Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_RANKS 13
#define NUM_SUITS 4
#define MAX_PLAYERS 6

typedef enum {
    ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
} rank_t;

typedef enum {
    CLUBS, DIAMONDS, HEARTS, SPADES
} suit_t;

typedef struct {
    rank_t rank;
    suit_t suit;
} card_t;

void print_card(card_t c) {
    const char* ranks[NUM_RANKS] = {"Ace", "Two", "Three", "Four", "Five", "Six",
                                    "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    const char* suits[NUM_SUITS] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    printf("%s of %s", ranks[c.rank], suits[c.suit]);
}

void print_hand(card_t hand[], int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        print_card(hand[i]);
        printf("\n");
    }
}

void shuffle_deck(card_t deck[]) {
    srand(time(NULL));
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        card_t temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int compare_cards(const void* c1, const void* c2) {
    const card_t* card1 = (const card_t*) c1;
    const card_t* card2 = (const card_t*) c2;
    return (card1->rank < card2->rank) ? -1 : (card1->rank > card2->rank) ? 1 : 0;
}

int is_flush(card_t hand[], int num_cards) {
    suit_t flush_suit = hand[0].suit;
    for (int i = 1; i < num_cards; i++) {
        if (hand[i].suit != flush_suit) {
            return 0;
        }
    }
    return 1;
}

int is_straight(card_t hand[], int num_cards) {
    qsort(hand, num_cards, sizeof(card_t), compare_cards);
    rank_t current_rank = hand[0].rank;
    for (int i = 1; i < num_cards; i++) {
        if (hand[i].rank != current_rank + 1) {
            return 0;
        }
        current_rank = hand[i].rank;
    }
    return 1;
}

int is_straight_flush(card_t hand[], int num_cards) {
    return is_flush(hand, num_cards) && is_straight(hand, num_cards);
}

int is_royal_flush(card_t hand[], int num_cards) {
    if (!is_straight_flush(hand, num_cards)) {
        return 0;
    }
    qsort(hand, num_cards, sizeof(card_t), compare_cards);
    return (hand[0].rank == TEN && hand[1].rank == JACK && hand[2].rank == QUEEN &&
            hand[3].rank == KING && hand[4].rank == ACE);
}

int is_four_of_a_kind(card_t hand[], int num_cards) {
    qsort(hand, num_cards, sizeof(card_t), compare_cards);
    return ((hand[0].rank == hand[1].rank && hand[1].rank == hand[2].rank &&
            hand[2].rank == hand[3].rank) ||
            (hand[1].rank == hand[2].rank && hand[2].rank == hand[3].rank &&
            hand[3].rank == hand[4].rank));
}

int is_full_house(card_t hand[], int num_cards) {
    qsort(hand, num_cards, sizeof(card_t), compare_cards);
    return ((hand[0].rank == hand[1].rank && hand[1].rank == hand[2].rank &&
            hand[3].rank == hand[4].rank) ||
            (hand[0].rank == hand[1].rank &&
            hand[2].rank == hand[3].rank &&  hand[3].rank == hand[4].rank));
}

int is_three_of_a_kind(card_t hand[], int num_cards) {
    qsort(hand, num_cards, sizeof(card_t), compare_cards);
    return ((hand[0].rank == hand[1].rank && hand[1].rank == hand[2].rank) ||
            (hand[1].rank == hand[2].rank && hand[2].rank == hand[3].rank) ||
            (hand[2].rank == hand[3].rank && hand[3].rank == hand[4].rank));
}

int is_two_pairs(card_t hand[], int num_cards) {
    qsort(hand, num_cards, sizeof(card_t), compare_cards);
    return ((hand[0].rank == hand[1].rank && hand[2].rank == hand[3].rank) ||
            (hand[1].rank == hand[2].rank && hand[3].rank == hand[4].rank) ||
            (hand[0].rank == hand[1].rank && hand[3].rank == hand[4].rank));
}

int is_one_pair(card_t hand[], int num_cards) {
    qsort(hand, num_cards, sizeof(card_t), compare_cards);
    return ((hand[0].rank == hand[1].rank) || (hand[1].rank == hand[2].rank) ||
            (hand[2].rank == hand[3].rank) || (hand[3].rank == hand[4].rank));
}

int rank_hand(card_t hand[], int num_cards) {
    if (is_royal_flush(hand, num_cards)) {
        return 10;
    } else if (is_straight_flush(hand, num_cards)) {
        return 9;
    } else if (is_four_of_a_kind(hand, num_cards)) {
        return 8;
    } else if (is_full_house(hand, num_cards)) {
        return 7;
    } else if (is_flush(hand, num_cards)) {
        return 6;
    } else if (is_straight(hand, num_cards)) {
        return 5;
    } else if (is_three_of_a_kind(hand, num_cards)) {
        return 4;
    } else if (is_two_pairs(hand, num_cards)) {
        return 3;
    } else if (is_one_pair(hand, num_cards)) {
        return 2;
    } else {
        return 1;
    }
}

int main(void) {
    card_t deck[NUM_CARDS];
    int num_players, num_cards_per_player;
    printf("Enter the number of players: ");
    scanf("%d", &num_players);
    printf("Enter the number of cards per player: ");
    scanf("%d", &num_cards_per_player);
    if (num_players > MAX_PLAYERS) {
        printf("Maximum number of players is %d\n", MAX_PLAYERS);
        return 1;
    }
    if (num_cards_per_player > NUM_CARDS / num_players) {
        printf("Maximum number of cards per player is %d\n", NUM_CARDS / num_players);
        return 1;
    }
    for (int i = 0; i < NUM_RANKS; i++) {
        for (int j = 0; j < NUM_SUITS; j++) {
            deck[i * NUM_SUITS + j].rank = i;
            deck[i * NUM_SUITS + j].suit = j;
        }
    }
    shuffle_deck(deck);
    printf("\nDealing cards...\n\n");
    for (int i = 0; i < num_players; i++) {
        printf("Player %d:\n", i + 1);
        card_t hand[num_cards_per_player];
        for (int j = 0; j < num_cards_per_player; j++) {
            hand[j] = deck[i * num_cards_per_player + j];
        }
        print_hand(hand, num_cards_per_player);
        int rank = rank_hand(hand, num_cards_per_player);
        printf("\nHand rank: %d\n\n", rank);
    }
    return 0;
}