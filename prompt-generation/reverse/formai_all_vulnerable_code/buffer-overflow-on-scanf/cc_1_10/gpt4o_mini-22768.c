//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define DECK_SIZE 52
#define HAND_SIZE 5

typedef struct {
    char suit[10];
    char value[3];
} Card;

typedef struct {
    Card hand[HAND_SIZE];
    int bet;
    int chips;
    char name[20];
} Player;

Card deck[DECK_SIZE];
int deckIndex = 0;

void createDeck() {
    const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *values[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            strcpy(deck[deckIndex].suit, suits[i]);
            strcpy(deck[deckIndex].value, values[j]);
            deckIndex++;
        }
    }
}

void shuffleDeck() {
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCard(Player *player, int index) {
    player->hand[index] = deck[deckIndex++];
}

void printHand(Player player) {
    printf("%s's Hand:\n", player.name);
    for (int i = 0; i < HAND_SIZE; i++) {
        printf("  %s of %s\n", player.hand[i].value, player.hand[i].suit);
    }
}

void initializePlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        players[i].bet = 0;
        players[i].chips = 100; // each player starts with 100 chips
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
    }
}

void bettingRound(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("%s, you have %d chips.\n", players[i].name, players[i].chips);
        printf("Enter your bet (or type 0 to fold): ");
        int bet;
        scanf("%d", &bet);
        if (bet > players[i].chips) {
            printf("You do not have enough chips!\n");
            i--; // ask again
        } else if (bet == 0) {
            printf("%s folds.\n", players[i].name);
            players[i].bet = 0; // folding sets bet to 0
        } else {
            players[i].bet = bet;
            players[i].chips -= bet;
            printf("%s bets %d chips.\n", players[i].name, bet);
        }
    }
}

void showResults(Player players[], int numPlayers) {
    printf("\nFinal Hands:\n");
    for (int i = 0; i < numPlayers; i++) {
        printHand(players[i]);
        printf("%s bet: %d chips\n", players[i].name, players[i].bet);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int numPlayers;

    printf("Welcome to the Royal Poker Tournament!\n");
    printf("Enter the number of players (2 to 4): ");
    scanf("%d", &numPlayers);
    while (numPlayers < 2 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Please enter between 2 and 4: ");
        scanf("%d", &numPlayers);
    }

    initializePlayers(players, numPlayers);
    createDeck();
    shuffleDeck();

    // Dealing cards to players
    for (int i = 0; i < HAND_SIZE; i++) {
        for (int j = 0; j < numPlayers; j++) {
            dealCard(&players[j], i);
        }
    }

    bettingRound(players, numPlayers);
    showResults(players, numPlayers);

    return 0;
}