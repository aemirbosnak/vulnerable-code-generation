//FormAI DATASET v1.0 Category: Poker Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 6
#define MAX_NAME_LENGTH 20

typedef enum {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
} Suit;

typedef enum {
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
} Rank;

typedef struct {
    Rank rank;
    Suit suit;
} Card;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int chips;
    Card hand[2];
} Player;

Card deck[52];
int deckIndex = 0;

void shuffleDeck()
{
    srand(time(NULL));
    int n = 52;
    while (n > 1) {
        int k = rand() % n;
        n--;
        Card temp = deck[n];
        deck[n] = deck[k];
        deck[k] = temp;
    }
}

Card dealCard()
{
    if (deckIndex == 52) {
        shuffleDeck();
        deckIndex = 0;
    }
    return deck[deckIndex++];
}

void dealCards(Player *players, int numPlayers)
{
    for (int i = 0; i < numPlayers; i++) {
        players[i].hand[0] = dealCard();
        players[i].hand[1] = dealCard();
    }
}

void printCard(Card card)
{
    switch (card.rank) {
        case ACE:
            printf("Ace");
            break;
        case TWO:
            printf("2");
            break;
        case THREE:
            printf("3");
            break;
        case FOUR:
            printf("4");
            break;
        case FIVE:
            printf("5");
            break;
        case SIX:
            printf("6");
            break;
        case SEVEN:
            printf("7");
            break;
        case EIGHT:
            printf("8");
            break;
        case NINE:
            printf("9");
            break;
        case TEN:
            printf("10");
            break;
        case JACK:
            printf("Jack");
            break;
        case QUEEN:
            printf("Queen");
            break;
        case KING:
            printf("King");
            break;
    }
    printf(" of ");
    switch (card.suit) {
        case CLUBS:
            printf("Clubs");
            break;
        case DIAMONDS:
            printf("Diamonds");
            break;
        case HEARTS:
            printf("Hearts");
            break;
        case SPADES:
            printf("Spades");
            break;
    }
    printf("\n");
}

void printHand(Card hand[], int size)
{
    for (int i = 0; i < size; i++) {
        printCard(hand[i]);
    }
}

int main()
{
    Player players[MAX_PLAYERS];
    int numPlayers = 0;
    int numChips = 0;
    int numCards = 2;
    
    printf("Welcome to paranoid poker! How many players will be playing? ");
    scanf("%d", &numPlayers);
    if (numPlayers < 2 || numPlayers > 6) {
        printf("Invalid number of players. Must be between 2 and 6.\n");
        return 1;
    }
    
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d, enter your name: ", i+1);
        scanf("%s", players[i].name);
        players[i].chips = 1000;
    }
    
    printf("\n%s has begun dealing cards...\n\n", players[rand() % numPlayers].name);
    shuffleDeck();
    dealCards(players, numPlayers);
    
    for (int i = 0; i < numPlayers; i++) {
        printf("%s's hand:\n", players[i].name);
        printHand(players[i].hand, numCards);
        printf("\n");
    }
    
    return 0;
}