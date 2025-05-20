//FormAI DATASET v1.0 Category: Poker Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_RANKS 13
#define NUM_SUITS 4
#define HAND_SIZE 5
#define MAX_PLAYERS 6

typedef enum {
    CLUBS, DIAMONDS, HEARTS, SPADES
} Suit;

typedef enum {
    TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
} Rank;

typedef struct {
    Rank rank;
    Suit suit;
} Card;

typedef struct {
    Card cards[HAND_SIZE];
    int ranks[NUM_RANKS];
    int suits[NUM_SUITS];
    int score;
} Hand;

typedef struct {
    char name[50];
    Hand hand;
} Player;

void clearScreen() {
    if (system("CLS")) system("clear");
}

void createDeck(Card* deck) {
    int i, j, k = 0;
    for (i = 0; i < NUM_SUITS; i++) {
        for (j = 0; j < NUM_RANKS; j++) {
            deck[k].rank = (Rank)j;
            deck[k].suit = (Suit)i;
            k++;
        }
    }
}

void shuffleDeck(Card* deck) {
    int i, j;
    Card temp;
    srand(time(NULL));
    for (i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards(Player* players, Card* deck, int numPlayers) {
    int i, j, k = 0;
    for (i = 0; i < numPlayers; i++) {
        for (j = 0; j < HAND_SIZE; j++) {
            players[i].hand.cards[j] = deck[k++];
        }
    }
}

void printCard(Card card) {
    char* ranks[NUM_RANKS] = {
        "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"
    };
    char* suits[NUM_SUITS] = {
        "Clubs", "Diamonds", "Hearts", "Spades"
    };
    printf("%s of %s\n", ranks[card.rank], suits[card.suit]);
}

void printHand(Hand hand) {
    int i;
    printf("Cards: ");
    for (i = 0; i < HAND_SIZE; i++) {
        printCard(hand.cards[i]);
    }
}

void calculateRanksSuits(Hand* hand) {
    int i;
    memset(hand->ranks, 0, sizeof(hand->ranks));
    memset(hand->suits, 0, sizeof(hand->suits));
    for (i = 0; i < HAND_SIZE; i++) {
        hand->ranks[hand->cards[i].rank]++;
        hand->suits[hand->cards[i].suit]++;
    }
}

void scoreHand(Hand* hand) {
    int i, j;
    int numPairs = 0, numThreeKinds = 0, numFourKinds = 0, numFlushes = 0, numStraights = 0;
    int pairRank = -1, threeKindRank = -1, fourKindRank = -1, highCardRank = -1, straightRank = -1;
    for (i = 0; i < NUM_RANKS; i++) {
        if (hand->ranks[i] == 2) {
            numPairs++;
            pairRank = i;
        } else if (hand->ranks[i] == 3) {
            numThreeKinds++;
            threeKindRank = i;
        } else if (hand->ranks[i] == 4) {
            numFourKinds++;
            fourKindRank = i;
        }
        if (hand->ranks[i] > 0) {
            highCardRank = i;
        }
    }
    for (i = 0; i < NUM_SUITS; i++) {
        if (hand->suits[i] == HAND_SIZE) {
            numFlushes++;
        }
    }
    for (i = 0; i < NUM_RANKS - 4; i++) {
        if (hand->ranks[i] > 0 && hand->ranks[i + 1] > 0 && hand->ranks[i + 2] > 0 && hand->ranks[i + 3] > 0 && hand->ranks[i + 4] > 0) {
            numStraights++;
            straightRank = i + 4;
        }
    }
    if (numPairs == 1 && numThreeKinds == 0 && numFourKinds == 0) {
        hand->score = 1;
    } else if (numPairs == 2 && numThreeKinds == 0 && numFourKinds == 0) {
        hand->score = 2;
    } else if (numThreeKinds == 1 && numPairs == 0 && numFourKinds == 0) {
        hand->score = 3;
    } else if (numPairs == 1 && numThreeKinds == 1 && numFourKinds == 0) {
        hand->score = 4;
    } else if (numFlushes == 1 && numStraights == 0) {
        hand->score = 5;
    } else if (numFlushes == 0 && numStraights == 1) {
        hand->score = 6;
    } else if (numThreeKinds == 1 && numPairs == 1 && numFourKinds == 0) {
        hand->score = 7;
    } else if (numFourKinds == 1 && numPairs == 0 && numThreeKinds == 0) {
        hand->score = 8;
    } else if (numFlushes == 1 && numStraights == 1) {
        hand->score = 9;
    } else {
        hand->score = 10;
        if (hand->ranks[ACE] == 1 && hand->ranks[KING] == 1 && hand->ranks[QUEEN] == 1 && hand->ranks[JACK] == 1 && hand->ranks[TEN] == 1) {
            hand->score = 0;
        }
    }
}

void printScore(Hand hand) {
    char* scores[] = {
        "High Card", "Pair", "Two Pairs", "Three of a Kind", "Full House", "Flush", "Straight", "Four of a Kind", "Straight Flush", "Royal Flush"
    };
    printf("Score: %s\n", scores[hand.score]);
}

void printPlayer(Player player) {
    printf("\n%s\n", player.name);
    printHand(player.hand);
    calculateRanksSuits(&player.hand);
    scoreHand(&player.hand);
    printScore(player.hand);
}

void printPlayers(Player* players, int numPlayers) {
    int i;
    for (i = 0; i < numPlayers; i++) {
        printPlayer(players[i]);
    }
}

int main() {
    Card deck[NUM_CARDS];
    Player players[MAX_PLAYERS];
    int numPlayers, i;
    printf("Welcome to the C Poker Game!\n\n");
    printf("Enter number of players (1-6): ");
    scanf("%d", &numPlayers);
    clearScreen();
    if (numPlayers > MAX_PLAYERS) {
        printf("Maximum players exceeded.\n");
        return 0;
    }
    createDeck(deck);
    shuffleDeck(deck);
    dealCards(players, deck, numPlayers);
    for (i = 0; i < numPlayers; i++) {
        printf("\nPlayer %d, enter your name: ", i + 1);
        scanf("%s", players[i].name);
    }
    clearScreen();
    printf("Dealing cards...\n\n");
    printPlayers(players, numPlayers);
    return 0;
}