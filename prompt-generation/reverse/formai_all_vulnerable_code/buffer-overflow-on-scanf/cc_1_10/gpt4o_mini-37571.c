//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_CARDS 52
#define CARDS_PER_HAND 5
#define HANDS 4

typedef enum {
    HEARTS, DIAMONDS, CLUBS, SPADES
} Suit;

typedef struct {
    int value; // 2 to 14, where 11=Jack, 12=Queen, 13=King, 14=Ace
    Suit suit;
} Card;

typedef struct {
    Card hand[CARDS_PER_HAND];
    char name[20];
} Player;

Card deck[MAX_CARDS];
Player players[MAX_PLAYERS];
int numPlayers;

// Function prototypes
void initializeDeck();
void shuffleDeck();
void dealCards();
void printCard(Card card);
void printPlayerHand(Player player);
int calculateHandValue(Player player);
void determineWinner();

int main() {
    srand(time(NULL)); // Seed random number generator

    printf("Welcome to the C Poker Game!\n");
    printf("Enter number of players (2-4): ");
    scanf("%d", &numPlayers);
    if (numPlayers < 2 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting the game.\n");
        return 1;
    }

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
    }

    initializeDeck();
    shuffleDeck();
    dealCards();

    printf("\nPlayer hands:\n");
    for (int i = 0; i < numPlayers; i++) {
        printPlayerHand(players[i]);
    }

    determineWinner();
    return 0;
}

void initializeDeck() {
    int index = 0;
    for (int suit = HEARTS; suit <= SPADES; suit++) {
        for (int value = 2; value <= 14; value++) {
            deck[index].value = value;
            deck[index].suit = suit;
            index++;
        }
    }
}

void shuffleDeck() {
    for (int i = 0; i < MAX_CARDS; i++) {
        int j = rand() % MAX_CARDS;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards() {
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < CARDS_PER_HAND; j++) {
            players[i].hand[j] = deck[i * CARDS_PER_HAND + j];
        }
    }
}

void printCard(Card card) {
    const char *values[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
    const char *suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    printf("%s of %s\n", values[card.value - 2], suits[card.suit]);
}

void printPlayerHand(Player player) {
    printf("%s's Hand:\n", player.name);
    for (int i = 0; i < CARDS_PER_HAND; i++) {
        printCard(player.hand[i]);
    }
}

int calculateHandValue(Player player) {
    int totalValue = 0;
    for (int i = 0; i < CARDS_PER_HAND; i++) {
        totalValue += player.hand[i].value;
    }
    return totalValue;
}

void determineWinner() {
    int highestValue = 0;
    Player *winner = NULL;

    for (int i = 0; i < numPlayers; i++) {
        int handValue = calculateHandValue(players[i]);
        printf("%s's hand value: %d\n", players[i].name, handValue);
        if (handValue > highestValue) {
            highestValue = handValue;
            winner = &players[i];
        }
    }

    if (winner != NULL) {
        printf("The winner is %s with a hand value of %d!\n", winner->name, highestValue);
    }
}