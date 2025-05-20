//FormAI DATASET v1.0 Category: Poker Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_SUITS 4
#define NUM_RANKS 13
#define NUM_CARDS 52
#define HAND_SIZE 5

const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
const char *ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

typedef struct {
    int rank;
    int suit;
} Card;

Card deck[NUM_CARDS];

void shuffle_deck() {
    for (int i = NUM_CARDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_card(Card card) {
    printf("%s of %s\n", ranks[card.rank], suits[card.suit]);
}

void print_hand(Card *hand) {
    for (int i = 0; i < HAND_SIZE; i++) {
        print_card(hand[i]);
    }
}

int is_flush(Card *hand) {
    int suit = hand[0].suit;
    for (int i = 1; i < HAND_SIZE; i++) {
        if (hand[i].suit != suit) {
            return 0;
        }
    }
    return 1;
}

int is_straight(Card *hand) {
    int ranks_seen[NUM_RANKS] = {0};
    for (int i = 0; i < HAND_SIZE; i++) {
        ranks_seen[hand[i].rank] = 1;
    }
    for (int i = 0; i < NUM_RANKS - 4; i++) {
        if (ranks_seen[i] && ranks_seen[i+1] && ranks_seen[i+2] && ranks_seen[i+3] && ranks_seen[i+4]) {
            return 1;
        }
    }
    return 0;
}

int evaluate_hand(Card *hand) {
    if (is_straight(hand) && is_flush(hand)) {
        return 9; // Straight flush
    }
    if (hand[0].rank == hand[3].rank || hand[1].rank == hand[4].rank) {
        return 8; // Four of a kind
    }
    if (hand[0].rank == hand[2].rank && hand[3].rank == hand[4].rank) {
        return 7; // Full house
    }
    if (is_flush(hand)) {
        return 6; // Flush
    }
    if (is_straight(hand)) {
        return 5; // Straight
    }
    if (hand[0].rank == hand[2].rank || hand[1].rank == hand[3].rank || hand[2].rank == hand[4].rank) {
        return 4; // Three of a kind
    }
    int pairs = 0;
    for (int i = 0; i < HAND_SIZE - 1; i++) {
        if (hand[i].rank == hand[i+1].rank) {
            pairs++;
        }
    }
    if (pairs == 2) {
        return 3; // Two pairs
    }
    if (pairs == 1) {
        return 2; // One pair
    }
    return 1; // High card
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < NUM_SUITS; i++) {
        for (int j = 0; j < NUM_RANKS; j++) {
            deck[i*NUM_RANKS+j].suit = i;
            deck[i*NUM_RANKS+j].rank = j;
        }
    }
    int num_players = 0;
    while (num_players < 2 || num_players > 8) {
        printf("Enter the number of players (2-8): ");
        scanf("%d", &num_players);
    }
    shuffle_deck();
    Card hands[num_players][HAND_SIZE];
    for (int i = 0; i < HAND_SIZE; i++) {
        for (int j = 0; j < num_players; j++) {
            hands[j][i] = deck[i*num_players+j];
        }
    }
    for (int i = 0; i < num_players; i++) {
        printf("Player %d's hand:\n", i+1);
        print_hand(hands[i]);
        printf("\n");
    }
    int scores[num_players];
    for (int i = 0; i < num_players; i++) {
        scores[i] = evaluate_hand(hands[i]);
    }
    int max_score = 0;
    int winner = 0;
    for (int i = 0; i < num_players; i++) {
        if (scores[i] > max_score) {
            max_score = scores[i];
            winner = i;
        }
    }
    printf("Player %d wins with %s!\n", winner+1, max_score == 1 ? "a high card" :
                                           max_score == 2 ? "a pair" :
                                           max_score == 3 ? "two pairs" :
                                           max_score == 4 ? "three of a kind" :
                                           max_score == 5 ? "a straight" :
                                           max_score == 6 ? "a flush" :
                                           max_score == 7 ? "a full house" :
                                           max_score == 8 ? "four of a kind" :
                                           "a straight flush");
    return 0;
}