//FormAI DATASET v1.0 Category: Poker Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_PLAYERS 2
#define MAX_PLAYERS 10
#define HAND_SIZE 5
#define NUM_SUITS 4
#define NUM_RANKS 13

typedef enum {Hearts, Diamonds, Clubs, Spades} Suit;
typedef enum {Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace} Rank;

typedef struct {
    Suit suit;
    Rank rank;
} Card;

typedef struct {
    Card cards[HAND_SIZE];
} Hand;

typedef struct {
    Hand hand;
    int chips;
} Player;

Card deck[NUM_SUITS * NUM_RANKS];

void shuffleDeck() {
    srand(time(NULL));
    int i;
    for (i = 0; i < NUM_SUITS * NUM_RANKS; i++) {
        int j = rand() % (NUM_SUITS * NUM_RANKS);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards(Player *players, int numPlayers) {
    int i, j;
    for (i = 0; i < numPlayers; i++) {
        for (j = 0; j < HAND_SIZE; j++) {
            players[i].hand.cards[j] = deck[i * HAND_SIZE + j];
        }
    }
}

void printCard(Card card) {
    switch (card.rank) {
        case Two:
            printf("2");
            break;
        case Three:
            printf("3");
            break;
        case Four:
            printf("4");
            break;
        case Five:
            printf("5");
            break;
        case Six:
            printf("6");
            break;
        case Seven:
            printf("7");
            break;
        case Eight:
            printf("8");
            break;
        case Nine:
            printf("9");
            break;
        case Ten:
            printf("10");
            break;
        case Jack:
            printf("J");
            break;
        case Queen:
            printf("Q");
            break;
        case King:
            printf("K");
            break;
        case Ace:
            printf("A");
            break;
    }
    switch (card.suit) {
        case Hearts:
            printf("H ");
            break;
        case Diamonds:
            printf("D ");
            break;
        case Clubs:
            printf("C ");
            break;
        case Spades:
            printf("S ");
            break;
    }
}

void printHand(Hand hand) {
    int i;
    for (i = 0; i < HAND_SIZE; i++) {
        printCard(hand.cards[i]);
    }
    printf("\n");
}

void printAllHands(Player *players, int numPlayers) {
    int i;
    for (i = 0; i < numPlayers; i++) {
        printf("Player %d's hand: ", i+1);
        printHand(players[i].hand);
    }
}

int main() {
    int numPlayers;
    printf("How many players (2-10)? ");
    scanf("%d", &numPlayers);
    if (numPlayers < MIN_PLAYERS || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }
    int i, j;
    for (i = 0; i < NUM_SUITS; i++) {
        for (j = 0; j < NUM_RANKS; j++) {
            deck[i*NUM_RANKS+j].suit = i;
            deck[i*NUM_RANKS+j].rank = j;
        }
    }
    shuffleDeck();
    Player players[numPlayers];
    for (i = 0; i < numPlayers; i++) {
        players[i].chips = 100;
    }
    dealCards(players, numPlayers);
    printAllHands(players, numPlayers);
    return 0;
}