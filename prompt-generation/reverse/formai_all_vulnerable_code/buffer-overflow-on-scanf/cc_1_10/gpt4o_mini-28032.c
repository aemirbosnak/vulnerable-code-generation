//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define CARDS_IN_HAND 5
#define DECK_SIZE 52

const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
const char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

typedef struct {
    int rank;
    int suit;
} Card;

typedef struct {
    Card hand[CARDS_IN_HAND];
} Player;

Card deck[DECK_SIZE];
int numberOfPlayers;

void shuffleDeck() {
    for (int i = 0; i < DECK_SIZE; i++) {
        deck[i].rank = i % 13;
        deck[i].suit = i / 13;
    }

    for (int i = 0; i < DECK_SIZE; i++) {
        int r = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

void dealCards(Player players[]) {
    for (int i = 0; i < numberOfPlayers; i++) {
        for (int j = 0; j < CARDS_IN_HAND; j++) {
            players[i].hand[j] = deck[i * CARDS_IN_HAND + j];
        }
    }
}

void printCard(Card card) {
    printf("%s of %s\n", ranks[card.rank], suits[card.suit]);
}

void printPlayerHand(Player player) {
    printf("Player's Hand:\n");
    for (int i = 0; i < CARDS_IN_HAND; i++) {
        printCard(player.hand[i]);
    }
}

void playPoker() {
    Player players[MAX_PLAYERS];
    printf("Enter number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &numberOfPlayers);

    if (numberOfPlayers < 1 || numberOfPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting.\n");
        return;
    }

    shuffleDeck();
    dealCards(players);

    for (int i = 0; i < numberOfPlayers; i++) {
        printf("\nDisplaying cards for Player %d:\n", i + 1);
        printPlayerHand(players[i]);
    }

    // Here we would generally evaluate and determine the winner,
    // but this is a basic implementation just dealing and displaying cards.
}

int main() {
    srand(time(NULL));
    printf("Welcome to the C Poker Game!\n");
    playPoker();
    return 0;
}