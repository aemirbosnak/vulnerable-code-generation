//GEMINI-pro DATASET v1.0 Category: Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_PLAYERS 4
#define NUM_TRICKS 13

typedef struct {
    int rank;
    int suit;
} Card;

typedef struct {
    Card cards[NUM_CARDS];
    int num_cards;
} Deck;

typedef struct {
    Card cards[NUM_CARDS];
    int num_cards;
} Hand;

typedef struct {
    int player;
    Card card;
} Trick;

void shuffle_deck(Deck *deck) {
    for (int i = 0; i < NUM_CARDS; i++) {
        int r = rand() % NUM_CARDS;
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[r];
        deck->cards[r] = temp;
    }
}

void deal_cards(Deck *deck, Hand *hands) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        for (int j = 0; j < NUM_CARDS / NUM_PLAYERS; j++) {
            hands[i].cards[j] = deck->cards[i * (NUM_CARDS / NUM_PLAYERS) + j];
            hands[i].num_cards++;
        }
    }
}

void print_hand(Hand *hand) {
    for (int i = 0; i < hand->num_cards; i++) {
        printf("%d%c ", hand->cards[i].rank, hand->cards[i].suit);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Deck deck;
    for (int i = 0; i < NUM_CARDS; i++) {
        deck.cards[i].rank = i % 13 + 1;
        deck.cards[i].suit = i / 13;
        deck.num_cards++;
    }

    shuffle_deck(&deck);

    Hand hands[NUM_PLAYERS];
    deal_cards(&deck, hands);

    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d's hand: ", i + 1);
        print_hand(&hands[i]);
    }

    Trick tricks[NUM_TRICKS];
    for (int i = 0; i < NUM_TRICKS; i++) {
        for (int j = 0; j < NUM_PLAYERS; j++) {
            int card_index = rand() % hands[j].num_cards;
            tricks[i].player = j;
            tricks[i].card = hands[j].cards[card_index];
            hands[j].num_cards--;
            for (int k = card_index; k < hands[j].num_cards; k++) {
                hands[j].cards[k] = hands[j].cards[k + 1];
            }
        }
    }

    for (int i = 0; i < NUM_TRICKS; i++) {
        printf("Trick %d: ", i + 1);
        for (int j = 0; j < NUM_PLAYERS; j++) {
            printf("%d%c ", tricks[i].card.rank, tricks[i].card.suit);
        }
        printf("\n");
    }

    return 0;
}