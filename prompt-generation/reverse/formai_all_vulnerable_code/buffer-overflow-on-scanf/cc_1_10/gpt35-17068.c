//FormAI DATASET v1.0 Category: Poker Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define cards struct
typedef struct {
    int rank;
    int suit;
} Card;

// function prototypes
void initializeDeck(Card[]);
void shuffleDeck(Card[]);
void printCard(Card);
void printDeck(Card[], int);

int main(void) {
    // initialize variables
    int numPlayers, numCards;
    Card deck[52], hand[7];

    // prompt user for number of players and cards per hand
    printf("Enter number of players (2-5): ");
    scanf("%d", &numPlayers);
    printf("Enter number of cards per hand (1-7): ");
    scanf("%d", &numCards);

    // validate user input
    if (numPlayers < 2 || numPlayers > 5 || numCards < 1 || numCards > 7) {
        printf("Invalid input!\n");
        return 1;
    }

    // initialize deck and shuffle cards
    initializeDeck(deck);
    shuffleDeck(deck);

    // deal hands to each player
    for (int i = 0; i < numPlayers; i++) {
        printf("\nPlayer %d's hand:\n", i+1);
        for (int j = 0; j < numCards; j++) {
            hand[j] = deck[(i*numCards)+j];
            printCard(hand[j]);
        }
    }

    // print remaining deck
    printf("\n\nRemaining deck:\n");
    printDeck(deck, 52-(numPlayers*numCards));

    return 0;
}

// initialize deck of cards
void initializeDeck(Card deck[]) {
    int index = 0;
    for (int i = 1; i <= 13; i++) {
        for (int j = 1; j <= 4; j++) {
            deck[index].rank = i;
            deck[index].suit = j;
            index++;
        }
    }
}

// shuffle deck of cards
void shuffleDeck(Card deck[]) {
    srand(time(0));
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// print card
void printCard(Card card) {
    if (card.rank == 1) {
        printf("Ace");
    } else if (card.rank == 11) {
        printf("Jack");
    } else if (card.rank == 12) {
        printf("Queen");
    } else if (card.rank == 13) {
        printf("King");
    } else {
        printf("%d", card.rank);
    }

    printf(" of ");

    if (card.suit == 1) {
        printf("Clubs");
    } else if (card.suit == 2) {
        printf("Diamonds");
    } else if (card.suit == 3) {
        printf("Hearts");
    } else {
        printf("Spades");
    }

    printf("\n");
}

// print deck of cards
void printDeck(Card deck[], int numCards) {
    for (int i = 0; i < numCards; i++) {
        printCard(deck[i]);
    }
}