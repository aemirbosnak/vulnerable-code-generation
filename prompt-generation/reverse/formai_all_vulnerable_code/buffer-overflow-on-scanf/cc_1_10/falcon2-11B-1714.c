//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARDS 5
#define MAX_HAND_SIZE 10

typedef struct Card {
    char suit;
    int value;
} Card;

typedef struct Hand {
    Card cards[MAX_CARDS];
    int num_cards;
    int rank;
} Hand;

typedef struct Game {
    Hand player_hand;
    Hand dealer_hand;
    int winner;
} Game;

int compare_hand(const void* a, const void* b) {
    const Hand* h1 = (const Hand*) a;
    const Hand* h2 = (const Hand*) b;
    if (h1->num_cards!= h2->num_cards) {
        return h1->num_cards - h2->num_cards;
    } else {
        return strcmp(hand_rank(h1), hand_rank(h2));
    }
}

int hand_rank(const Hand* h) {
    if (h->num_cards == 5) {
        if (is_royal_flush(h)) {
            return "Royal Flush";
        } else if (is_straight_flush(h)) {
            return "Straight Flush";
        } else if (is_four_of_a_kind(h)) {
            return "Four of a Kind";
        } else if (is_full_house(h)) {
            return "Full House";
        } else if (is_flush(h)) {
            return "Flush";
        } else if (is_straight(h)) {
            return "Straight";
        } else if (is_three_of_a_kind(h)) {
            return "Three of a Kind";
        } else if (is_two_pair(h)) {
            return "Two Pair";
        } else if (is_one_pair(h)) {
            return "One Pair";
        } else {
            return "High Card";
        }
    } else {
        return "Invalid Hand";
    }
}

int is_royal_flush(const Hand* h) {
    if (is_flush(h) && is_straight(h) && h->cards[0].value == 10 && h->cards[1].value == 11 && h->cards[2].value == 12 && h->cards[3].value == 13 && h->cards[4].value == 14) {
        return 1;
    } else {
        return 0;
    }
}

int is_straight_flush(const Hand* h) {
    if (is_flush(h) && is_straight(h)) {
        return 1;
    } else {
        return 0;
    }
}

int is_four_of_a_kind(const Hand* h) {
    if (h->num_cards == 4 && h->cards[0].value == h->cards[1].value && h->cards[2].value == h->cards[3].value) {
        return 1;
    } else {
        return 0;
    }
}

int is_full_house(const Hand* h) {
    if (h->num_cards == 3 && h->cards[0].value == h->cards[1].value && h->cards[2].value == h->cards[3].value) {
        return 1;
    } else {
        return 0;
    }
}

int is_flush(const Hand* h) {
    for (int i = 0; i < h->num_cards; i++) {
        if (h->cards[i].suit!= h->cards[i + 1].suit) {
            return 0;
        }
    }
    return 1;
}

int is_straight(const Hand* h) {
    if (h->num_cards >= 5) {
        return 0;
    }
    for (int i = 0; i < h->num_cards; i++) {
        if (h->cards[i].value - 1!= h->cards[i + 1].value) {
            return 0;
        }
    }
    return 1;
}

int is_three_of_a_kind(const Hand* h) {
    if (h->num_cards == 3 && h->cards[0].value == h->cards[1].value && h->cards[2].value == h->cards[3].value) {
        return 1;
    } else {
        return 0;
    }
}

int is_two_pair(const Hand* h) {
    if (h->num_cards == 4 && h->cards[0].value == h->cards[1].value && h->cards[2].value == h->cards[3].value) {
        return 1;
    } else {
        return 0;
    }
}

int is_one_pair(const Hand* h) {
    if (h->num_cards == 2 && h->cards[0].value == h->cards[1].value) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Game game;
    int num_hands = 0;
    while (1) {
        printf("Enter number of cards: ");
        scanf("%d", &num_hands);
        if (num_hands == 0) {
            break;
        }
        game.player_hand.num_cards = num_hands;
        game.dealer_hand.num_cards = num_hands;
        for (int i = 0; i < num_hands; i++) {
            printf("Enter card %d (Suit: A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K): ", i);
            scanf(" %c%d", &game.player_hand.cards[i].suit, &game.player_hand.cards[i].value);
            if (game.player_hand.cards[i].suit == 'S' || game.player_hand.cards[i].suit == 'H' || game.player_hand.cards[i].suit == 'D' || game.player_hand.cards[i].suit == 'C') {
                game.dealer_hand.cards[i].suit = game.player_hand.cards[i].suit;
                game.dealer_hand.cards[i].value = game.player_hand.cards[i].value;
            } else {
                printf("Invalid card: %c%d\n", game.player_hand.cards[i].suit, game.player_hand.cards[i].value);
                continue;
            }
        }
        qsort(game.player_hand.cards, game.player_hand.num_cards, sizeof(Card), compare_hand);
        qsort(game.dealer_hand.cards, game.dealer_hand.num_cards, sizeof(Card), compare_hand);
        if (is_royal_flush(&game.player_hand)) {
            printf("Player wins!\n");
        } else if (is_straight_flush(&game.player_hand)) {
            printf("Player wins!\n");
        } else if (is_four_of_a_kind(&game.player_hand)) {
            printf("Player wins!\n");
        } else if (is_full_house(&game.player_hand)) {
            printf("Player wins!\n");
        } else if (is_flush(&game.player_hand)) {
            printf("Player wins!\n");
        } else if (is_straight(&game.player_hand)) {
            printf("Player wins!\n");
        } else if (is_three_of_a_kind(&game.player_hand)) {
            printf("Player wins!\n");
        } else if (is_two_pair(&game.player_hand)) {
            printf("Player wins!\n");
        } else if (is_one_pair(&game.player_hand)) {
            printf("Player wins!\n");
        } else {
            printf("Dealer wins!\n");
        }
        num_hands++;
    }
    return 0;
}