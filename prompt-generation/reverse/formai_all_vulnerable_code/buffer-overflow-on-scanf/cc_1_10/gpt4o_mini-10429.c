//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define DECK_SIZE 52
#define HAND_SIZE 5
#define MAX_PLAYERS 4

typedef enum { HEARTS, DIAMONDS, CLUBS, SPADES } Suit;
typedef struct {
    int rank;
    Suit suit;
} Card;

typedef struct {
    Card hand[HAND_SIZE];
    char name[50];
    int chips;
} Player;

Card deck[DECK_SIZE];
int topCard;

// Function declarations
void initializeDeck();
void shuffleDeck();
void dealCards(Player players[], int playerCount);
void displayHand(Player player);
int bettingRound(Player *player);
void playPoker();

int main() {
    playPoker();
    return 0;
}

void playPoker() {
    Player players[MAX_PLAYERS];
    int playerCount;

    printf("Welcome to the Irregular Poker Game!\n");
    printf("Enter number of players (1-4): ");
    scanf("%d", &playerCount);

    for (int i = 0; i < playerCount; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].chips = 100;  // giving each player some chips
    }

    initializeDeck();
    shuffleDeck();
    dealCards(players, playerCount);

    for (int i = 0; i < playerCount; i++) {
        printf("\n%s's Hand: ", players[i].name);
        displayHand(players[i]);
        if (bettingRound(&players[i]) <= 0) { // If player is out of chips, leave the game 
            printf("%s has no chips left!\n", players[i].name);
            continue; 
        }
    }
}

void initializeDeck() {
    topCard = 0;
    for (int suit = HEARTS; suit <= SPADES; suit++) {
        for (int rank = 1; rank <= 13; rank++) {
            deck[topCard].suit = suit;
            deck[topCard].rank = rank;
            topCard++;
        }
    }
}

void shuffleDeck() {
    srand(time(0)); // Random seed
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards(Player players[], int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        for (int j = 0; j < HAND_SIZE; j++) {
            players[i].hand[j] = deck[topCard++];
        }
    }
}

void displayHand(Player player) {
    for (int i = 0; i < HAND_SIZE; i++) {
        printf("%d of %s, ", player.hand[i].rank,
               player.hand[i].suit == HEARTS ? "Hearts" :
               player.hand[i].suit == DIAMONDS ? "Diamonds" :
               player.hand[i].suit == CLUBS ? "Clubs" : "Spades");
    }
    printf("\n");
}

int bettingRound(Player *player) {
    int bet;
    printf("You have %d chips. Enter your bet: ", player->chips);
    scanf("%d", &bet);

    while (bet < 0 || bet > player->chips) {
        printf("Invalid bet! Enter a valid bet: ");
        scanf("%d", &bet);
    }
    player->chips -= bet;
    printf("%s bets %d chips, remaining chips: %d\n", player->name, bet, player->chips);
    
    return player->chips; // return chips left
}