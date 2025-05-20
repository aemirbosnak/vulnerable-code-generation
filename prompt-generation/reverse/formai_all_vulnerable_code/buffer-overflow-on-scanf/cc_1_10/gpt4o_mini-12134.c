//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define CARDS_PER_PLAYER 5
#define DECK_SIZE 52

typedef struct {
    char *suit;
    char *rank;
} Card;

typedef struct {
    Card hand[CARDS_PER_PLAYER];
    char *name;
} Player;

Card deck[DECK_SIZE];
int top_card = 0;

void initializeDeck() {
    char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

    top_card = 0;
    for (int s = 0; s < 4; s++) {
        for (int r = 0; r < 13; r++) {
            deck[top_card].suit = suits[s];
            deck[top_card].rank = ranks[r];
            top_card++;
        }
    }
}

void shuffleDeck() {
    for (int i = 0; i < DECK_SIZE; i++) {
        int r = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

void dealCards(Player players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        for (int j = 0; j < CARDS_PER_PLAYER; j++) {
            players[i].hand[j] = deck[top_card++];
        }
    }
}

void printHand(Player p) {
    printf("%s's hand: ", p.name);
    for (int i = 0; i < CARDS_PER_PLAYER; i++) {
        printf("%s of %s ", p.hand[i].rank, p.hand[i].suit);
    }
    printf("\n");
}

void declareWinner(Player players[], int num_players) {
    // For simplicity, the winner is chosen randomly.
    srand(time(NULL));
    int winner_index = rand() % num_players;
    printf("The winner is %s!\n", players[winner_index].name);
}

int main() {
    srand(time(NULL));
    int num_players;

    printf("Welcome to the C Poker Game!\n");
    printf("Enter the number of players (1 to %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting game.\n");
        return 1;
    }

    Player players[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        players[i].name = (char *)malloc(50);
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
    }

    initializeDeck();
    shuffleDeck();
    dealCards(players, num_players);

    for (int i = 0; i < num_players; i++) {
        printHand(players[i]);
    }

    declareWinner(players, num_players);

    for (int i = 0; i < num_players; i++) {
        free(players[i].name);
    }

    return 0;
}