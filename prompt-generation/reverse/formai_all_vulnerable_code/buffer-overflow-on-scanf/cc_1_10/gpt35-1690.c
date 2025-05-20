//FormAI DATASET v1.0 Category: Poker Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define DECK_SIZE 52
#define RANK_SIZE 13
#define SUIT_SIZE 4
#define MAX_PLAYERS 6
#define MAX_HAND 7
#define MAX_NAME 20

// Define card struct
typedef struct {
    int rank;
    int suit;
} Card;

// Define player struct
typedef struct {
    Card hand[MAX_HAND];
    int numCards;
    char name[MAX_NAME];
    int chips;
} Player;

// Function prototypes
void initializeDeck(Card *deck);
void shuffleDeck(Card *deck);
void dealCards(Card *deck, Player *players, int numPlayers);
void printCard(Card card);
void printPlayerHand(Player player);
void printAllHands(Player *players, int numPlayers);
void sortByRank(Card *hand, int numCards);
void sortBySuit(Card *hand, int numCards);
int compareRanks(const void *card1, const void *card2);
int compareSuits(const void *card1, const void *card2);
int evaluateHand(Card *hand, int numCards, int *highCard);
int determineWinner(Player *players, int numPlayers);
void displayWinner(Player winner, int pot);

int main() {
    srand(time(NULL)); // Seed random number generator
    char option;
    int pot = 0;
    int numPlayers = 0;
    Player players[MAX_PLAYERS];

    printf("Welcome to Medieval Poker!\n\n");
    printf("Enter the number of players (2-6): ");
    scanf("%d", &numPlayers);

    while (numPlayers < 2 || numPlayers > 6) {
        printf("\nInvalid number of players. Please enter a number between 2 and 6: ");
        scanf("%d", &numPlayers);
    }

    for (int i = 0; i < numPlayers; i++) {
        printf("\nEnter player %d's name: ", i+1);
        scanf("%s", players[i].name);
        players[i].chips = 1000;
        players[i].numCards = 0;
    }

    do {
        Card deck[DECK_SIZE];
        initializeDeck(deck);
        shuffleDeck(deck);
        dealCards(deck, players, numPlayers);

        printf("\n");
        printAllHands(players, numPlayers);

        // Ask each player for their bet
        for (int i = 0; i < numPlayers; i++) {
            printf("\n%s, you have %d chips. Enter your bet: ", players[i].name, players[i].chips);
            int bet;
            scanf("%d", &bet);
            while (bet < 0 || bet > players[i].chips) {
                printf("\nInvalid bet. Please enter a bet between 0 and %d: ", players[i].chips);
                scanf("%d", &bet);
            }
            players[i].chips -= bet;
            pot += bet;
        }

        // Evaluate each player's hand and determine the winner
        int winnerIndex = determineWinner(players, numPlayers);
        displayWinner(players[winnerIndex], pot);
        players[winnerIndex].chips += pot;
        pot = 0;

        // Ask if the players want to play another round
        printf("\n\nDo you want to play another round? (y/n): ");
        scanf(" %c", &option);

    } while (option == 'y');

    return 0;
}

void initializeDeck(Card *deck) {
    int count = 0;
    for (int i = 0; i < RANK_SIZE; i++) {
        for (int j = 0; j < SUIT_SIZE; j++) {
            deck[count].rank = i;
            deck[count].suit = j;
            count++;
        }
    }
}

void shuffleDeck(Card *deck) {
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards(Card *deck, Player *players, int numPlayers) {
    for (int i = 0; i < MAX_HAND; i++) {
        for (int j = 0; j < numPlayers; j++) {
            players[j].hand[i] = deck[i*numPlayers + j];
            players[j].numCards++;
        }
    }
}

void printCard(Card card) {
    if (card.rank == 0) {
        printf("Ace");
    } else if (card.rank == 10) {
        printf("Jack");
    } else if (card.rank == 11) {
        printf("Queen");
    } else if (card.rank == 12) {
        printf("King");
    } else {
        printf("%d", card.rank+1);
    }

    printf(" of ");

    if (card.suit == 0) {
        printf("Hearts");
    } else if (card.suit == 1) {
        printf("Diamonds");
    } else if (card.suit == 2) {
        printf("Clubs");
    } else {
        printf("Spades");
    }
}

void printPlayerHand(Player player) {
    printf("\n%s's hand:\n", player.name);
    for (int i = 0; i < player.numCards; i++) {
        printCard(player.hand[i]);
        printf("\n");
    }
}

void printAllHands(Player *players, int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printPlayerHand(players[i]);
    }
}

void sortByRank(Card *hand, int numCards) {
    qsort(hand, numCards, sizeof(Card), compareRanks);
}

void sortBySuit(Card *hand, int numCards) {
    qsort(hand, numCards, sizeof(Card), compareSuits);
}

int compareRanks(const void *card1, const void *card2) {
    Card c1 = *(Card*)card1;
    Card c2 = *(Card*)card2;

    if (c1.rank > c2.rank) {
        return 1;
    } else if (c1.rank < c2.rank) {
        return -1;
    } else {
        return 0;
    }
}

int compareSuits(const void *card1, const void *card2) {
    Card c1 = *(Card*)card1;
    Card c2 = *(Card*)card2;

    if (c1.suit > c2.suit) {
        return 1;
    } else if (c1.suit < c2.suit) {
        return -1;
    } else {
        return 0;
    }
}

int evaluateHand(Card *hand, int numCards, int *highCard) {
    // Sort hand by rank
    sortByRank(hand, numCards);

    // Check for straight flush
    int straightFlush = 0;
    for (int i = 0; i < numCards-1; i++) {
        if (hand[i].suit == hand[i+1].suit && hand[i].rank + 1 == hand[i+1].rank) {
            straightFlush = 1;
        } else {
            straightFlush = 0;
            break;
        }
    }
    if (straightFlush) {
        *highCard = hand[numCards-1].rank;
        return 9;
    }

    // Check for four of a kind
    if (hand[0].rank == hand[3].rank || hand[1].rank == hand[4].rank) {
        *highCard = hand[3].rank;
        return 8;
    }

    // Check for full house
    if ((hand[0].rank == hand[2].rank && hand[3].rank == hand[4].rank) ||
            (hand[0].rank == hand[1].rank && hand[2].rank == hand[4].rank)) {
        *highCard = hand[2].rank;
        return 7;
    }

    // Check for flush
    int flush = 0;
    for (int i = 0; i < numCards-1; i++) {
        if (hand[i].suit == hand[i+1].suit) {
            flush = 1;
        } else {
            flush = 0;
            break;
        }
    }
    if (flush) {
        *highCard = hand[numCards-1].rank;
        return 6;
    }

    // Check for straight
    int straight = 0;
    for (int i = 0; i < numCards-1; i++) {
        if (hand[i].rank + 1 == hand[i+1].rank) {
            straight = 1;
        } else {
            straight = 0;
            break;
        }
    }
    if (straight) {
        *highCard = hand[numCards-1].rank;
        return 5;
    }

    // Check for three of a kind
    if (hand[0].rank == hand[2].rank || hand[1].rank == hand[3].rank || hand[2].rank == hand[4].rank) {
        *highCard = hand[2].rank;
        return 4;
    }

    // Check for two pairs
    if ((hand[0].rank == hand[1].rank && hand[2].rank == hand[3].rank) ||
            (hand[0].rank == hand[1].rank && hand[3].rank == hand[4].rank) ||
            (hand[1].rank == hand[2].rank && hand[3].rank == hand[4].rank)) {
        *highCard = hand[3].rank;
        return 3;
    }

    // Check for one pair
    for (int i = 0; i < numCards-1; i++) {
        if (hand[i].rank == hand[i+1].rank) {
            *highCard = hand[i].rank;
            return 2;
        }
    }

    // High card
    *highCard = hand[numCards-1].rank;
    return 1;
}

int determineWinner(Player *players, int numPlayers) {
    int winnerIndex = -1;
    int bestHand = 0;
    int handScore = 0;
    int highCard = 0;

    for (int i = 0; i < numPlayers; i++) {
        handScore = evaluateHand(players[i].hand, players[i].numCards, &highCard);
        if (handScore > bestHand) {
            bestHand = handScore;
            winnerIndex = i;
        } else if (handScore == bestHand) {
            if (highCard > players[winnerIndex].hand[players[winnerIndex].numCards-1].rank) {
                winnerIndex = i;
            }
        }
    }
    return winnerIndex;
}

void displayWinner(Player winner, int pot) {
    printf("\n%s has won the pot of %d chips with ", winner.name, pot);
    int highCard = 0;
    int handScore = evaluateHand(winner.hand, winner.numCards, &highCard);
    switch (handScore) {
        case 1:
            printf("High Card %d", highCard+1);
            break;
        case 2:
            printf("One Pair of ");
            printCard((Card){highCard,0});
            printf("s");
            break;
        case 3:
            printf("Two Pairs of ");
            printCard((Card){highCard,0});
            printf("s and ");
            printCard((Card){highCard-1,0});
            printf("s");
            break;
        case 4:
            printf("Three of a Kind of ");
            printCard((Card){highCard,0});
            printf("s");
            break;
        case 5:
            printf("Straight to ");
            printCard((Card){highCard,0});
            printf(" high");
            break;
        case 6:
            printf("Flush of ");
            printCard((Card){highCard,0});
            printf("s");
            break;
        case 7:
            printf("Full House with ");
            printCard((Card){highCard,0});
            printf("s over ");
            printCard((Card){highCard+3,0});
            printf("s");
            break;
        case 8:
            printf("Four of a Kind of ");
            printCard((Card){highCard,0});
            printf("s");
            break;
        case 9:
            printf("Straight Flush to ");
            printCard((Card){highCard,0});
            printf(" high");
            break;
    }
}