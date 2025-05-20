//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CARDS 52
#define MAX_PLAYERS 4
#define CARDS_PER_PLAYER 5

typedef enum { HEARTS, DIAMONDS, CLUBS, SPADES } Suit;
typedef struct {
    int value; // 1-13 for Ace-King
    Suit suit; // Suit of the card
} Card;

typedef struct {
    Card hand[CARDS_PER_PLAYER];
    char name[20];
} Player;

Card deck[MAX_CARDS];
int topCardIndex = 0; 

void initializeDeck() {
    int index = 0;
    for (int suit = HEARTS; suit <= SPADES; suit++) {
        for (int value = 1; value <= 13; value++) {
            deck[index].value = value;
            deck[index].suit = suit;
            index++;
        }
    }
}

void shuffleDeck() {
    srand(time(NULL));
    for (int i = 0; i < MAX_CARDS; i++) {
        int r = rand() % MAX_CARDS;
        Card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

void dealCards(Player players[], int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        for (int j = 0; j < CARDS_PER_PLAYER; j++) {
            players[i].hand[j] = deck[topCardIndex++];
        }
    }
}

void printCard(Card card) {
    const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    printf("%d of %s\n", card.value, suits[card.suit]);
}

void printPlayerHand(Player player) {
    printf("%s's Hand:\n", player.name);
    for (int i = 0; i < CARDS_PER_PLAYER; i++) {
        printCard(player.hand[i]);
    }
}

void printAllHands(Player players[], int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        printPlayerHand(players[i]);
        printf("\n");
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int playerCount;

    printf("Welcome to the Brave Poker Game!\n");
    printf("Enter the number of players (2-4): ");
    scanf("%d", &playerCount);
    
    if (playerCount < 2 || playerCount > MAX_PLAYERS) {
        printf("Player count must be between 2 and 4.\n");
        return 1;
    }

    for (int i = 0; i < playerCount; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
    }

    printf("Initializing and shuffling the deck...\n");
    initializeDeck();
    shuffleDeck();

    printf("Dealing cards...\n");
    dealCards(players, playerCount);

    printf("All player hands are dealt:\n");
    printAllHands(players, playerCount);

    // Basic Poker game logic could go here...
    
    printf("Thanks for playing Brave Poker! Good luck!\n");
    return 0;
}