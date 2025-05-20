//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define CARDS_IN_HAND 2
#define DECK_SIZE 52
#define RANKS 13
#define SUITS 4

typedef struct {
    char *rank;
    char *suit;
} Card;

typedef struct {
    Card hand[CARDS_IN_HAND];
    int totalBet;
} Player;

Card deck[DECK_SIZE];
Player players[MAX_PLAYERS];
int currentPlayer = 0;
int numPlayers = 0;

void initializeDeck() {
    char *ranks[RANKS] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    char *suits[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    int index = 0;
    for (int i = 0; i < SUITS; i++) {
        for (int j = 0; j < RANKS; j++) {
            deck[index].rank = ranks[j];
            deck[index].suit = suits[i];
            index++;
        }
    }
}

void shuffleDeck() {
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++) {
        int r = i + rand() % (DECK_SIZE - i);
        Card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

void dealCards() {
    for (int i = 0; i < numPlayers; i++) {
        players[i].hand[0] = deck[currentPlayer++];
        players[i].hand[1] = deck[currentPlayer++];
        players[i].totalBet = 0;
    }
}

void displayHand(Player player) {
    for (int i = 0; i < CARDS_IN_HAND; i++) {
        printf("%s of %s\n", player.hand[i].rank, player.hand[i].suit);
    }
}

int compareHands(Player player1, Player player2) {
    int rank1 = (strcmp(player1.hand[0].rank, player1.hand[1].rank) == 0) ? 1 : 0;
    int rank2 = (strcmp(player2.hand[0].rank, player2.hand[1].rank) == 0) ? 1 : 0;

    return rank1 - rank2; // 1 if player1 wins, -1 if player2 wins, 0 if tie
}

void displayWinner() {
    Player winner = players[0];
    for (int i = 1; i < numPlayers; i++) {
        if (compareHands(winner, players[i]) < 0) {
            winner = players[i];
        }
    }
    printf("Winner's hand:\n");
    displayHand(winner);
}

void bettingRound() {
    int bet;
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d, enter your bet: ", i + 1);
        scanf("%d", &bet);
        players[i].totalBet += bet;
    }
}

int main() {
    printf("Welcome to the Poker Game!\n");
    
    printf("Enter number of players (2-4): ");
    scanf("%d", &numPlayers);
    if (numPlayers < 2 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    initializeDeck();
    shuffleDeck();
    dealCards();

    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d's hand:\n", i + 1);
        displayHand(players[i]);
    }

    bettingRound();
    displayWinner();

    return 0;
}