//FormAI DATASET v1.0 Category: Poker Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52

enum Rank { ACE = 1, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5,
            SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10,
            JACK = 11, QUEEN = 12, KING = 13 };
            
enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };

typedef struct {
    int rank;
    int suit;
} Card;

typedef struct {
    Card cards[DECK_SIZE];
    int size;
} Deck;

// shuffle the deck of cards
void shuffle(Deck* deck) {
    int n = deck->size;
    while (n > 1) {
        int k = rand() % n;
        n--;
        Card temp = deck->cards[n];
        deck->cards[n] = deck->cards[k];
        deck->cards[k] = temp;
    }
}

// deal a single card from the top of the deck
Card deal(Deck* deck) {
    deck->size--;
    return deck->cards[deck->size];
}

// print a card in human-readable format
void print_card(Card card) {
    const char* rank_str;
    switch (card.rank) {
        case ACE: rank_str = "Ace"; break;
        case TWO: rank_str = "Two"; break;
        case THREE: rank_str = "Three"; break;
        case FOUR: rank_str = "Four"; break;
        case FIVE: rank_str = "Five"; break;
        case SIX: rank_str = "Six"; break;
        case SEVEN: rank_str = "Seven"; break;
        case EIGHT: rank_str = "Eight"; break;
        case NINE: rank_str = "Nine"; break;
        case TEN: rank_str = "Ten"; break;
        case JACK: rank_str = "Jack"; break;
        case QUEEN: rank_str = "Queen"; break;
        case KING: rank_str = "King"; break;
    }

    const char* suit_str;
    switch (card.suit) {
        case HEARTS: suit_str = "Hearts"; break;
        case DIAMONDS: suit_str = "Diamonds"; break;
        case CLUBS: suit_str = "Clubs"; break;
        case SPADES: suit_str = "Spades"; break;
    }

    printf("%s of %s", rank_str, suit_str);
}

// create a new deck of cards
Deck new_deck() {
    Deck deck;
    int i, j;
    for (i = ACE; i <= KING; i++) {
        for (j = HEARTS; j <= SPADES; j++) {
            Card card = {i, j};
            deck.cards[deck.size++] = card;
        }
    }
    return deck;
}

int main() {
    srand(time(NULL));
    Deck deck = new_deck();
    shuffle(&deck);

    printf("Dealing five cards:\n");
    int i;
    for (i = 0; i < 5; i++) {
        Card card = deal(&deck);
        print_card(card);
        printf("\n");
    }

    printf("Remaining cards in the deck: %d\n", deck.size);

    return 0;
}