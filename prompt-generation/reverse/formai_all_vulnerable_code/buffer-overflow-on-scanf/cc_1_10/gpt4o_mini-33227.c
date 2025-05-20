//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_CARDS 5

typedef struct {
    char rank;
    char suit;
} Card;

typedef struct {
    char name[50];
    Card hand[MAX_CARDS];
    int bid;
    int isFolded;
} Player;

void shuffleDeck(Card *deck, int size);
void dealCards(Card *deck, Player *players, int numPlayers);
void printHand(Player player);
int calculateHandValue(Player player);
void playRound(Player *players, int numPlayers);
void displayResults(Player *players, int numPlayers);
int compareHands(Player p1, Player p2);

int main() {
    Card deck[52];
    Player players[MAX_PLAYERS];
    int numPlayers;

    // Initialize deck
    char ranks[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    char suits[] = {'H', 'D', 'C', 'S'};
    int index = 0;
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            deck[index].rank = ranks[i];
            deck[index].suit = suits[j];
            index++;
        }
    }

    printf("Enter number of players (2-4): ");
    scanf("%d", &numPlayers);
    if (numPlayers < 2 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players!\n");
        return 1;
    }

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].isFolded = 0;
        players[i].bid = 0;
    }

    shuffleDeck(deck, 52);
    dealCards(deck, players, numPlayers);
    playRound(players, numPlayers);
    displayResults(players, numPlayers);

    return 0;
}

void shuffleDeck(Card *deck, int size) {
    srand(time(NULL));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards(Card *deck, Player *players, int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < MAX_CARDS; j++) {
            players[i].hand[j] = deck[i * MAX_CARDS + j];
        }
    }
}

void printHand(Player player) {
    printf("%s's Hand: ", player.name);
    for (int i = 0; i < MAX_CARDS; i++) {
        printf("%c%c ", player.hand[i].rank, player.hand[i].suit);
    }
    printf("\n");
}

int calculateHandValue(Player player) {
    // Simplistic approach: Just sum the ranks using their face values
    int handValue = 0;
    for (int i = 0; i < MAX_CARDS; i++) {
        switch (player.hand[i].rank) {
            case '2': handValue += 2; break;
            case '3': handValue += 3; break;
            case '4': handValue += 4; break;
            case '5': handValue += 5; break;
            case '6': handValue += 6; break;
            case '7': handValue += 7; break;
            case '8': handValue += 8; break;
            case '9': handValue += 9; break;
            case 'T': handValue += 10; break;
            case 'J': handValue += 11; break;
            case 'Q': handValue += 12; break;
            case 'K': handValue += 13; break;
            case 'A': handValue += 14; break;
        }
    }
    return handValue;
}

void playRound(Player *players, int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        if (!players[i].isFolded) {
            printf("%s, place your bid (Enter 0 to fold): ", players[i].name);
            scanf("%d", &players[i].bid);
            if (players[i].bid <= 0) {
                players[i].isFolded = 1;
                printf("%s has folded.\n", players[i].name);
            } else {
                printf("%s has bid: %d\n", players[i].name, players[i].bid);
            }
        }
    }
}

void displayResults(Player *players, int numPlayers) {
    Player winner = players[0];
    int winnerIndex = 0;

    for (int i = 1; i < numPlayers; i++) {
        if (!players[i].isFolded && compareHands(players[i], winner) > 0) {
            winner = players[i];
            winnerIndex = i;
        }
    }

    printf("The winner is %s with a hand value of %d and bid of %d!\n",
           winner.name, calculateHandValue(winner), winner.bid);
}

int compareHands(Player p1, Player p2) {
    return calculateHandValue(p1) - calculateHandValue(p2);
}