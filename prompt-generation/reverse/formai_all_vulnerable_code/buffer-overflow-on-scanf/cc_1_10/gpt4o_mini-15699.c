//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_CARDS 52
#define NUM_PLAYERS 2
#define CARDS_IN_HAND 5

typedef struct {
    int rank;
    char suit;
} Card;

typedef struct {
    Card hand[CARDS_IN_HAND];
    char name[20];
} Player;

Card deck[NUM_CARDS];
int topCardIndex = 0;

void createDeck() {
    char suits[] = {'H', 'D', 'S', 'C'};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deck[i * 13 + j].rank = j + 1;
            deck[i * 13 + j].suit = suits[i];
        }
    }
}

void shuffleDeck() {
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards(Player players[]) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        for (int j = 0; j < CARDS_IN_HAND; j++) {
            players[i].hand[j] = deck[topCardIndex++];
        }
    }
}

void printCard(Card card) {
    const char* ranks[] = {"", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    printf("%s%c ", ranks[card.rank], card.suit);
}

void printPlayerHand(Player player) {
    printf("%s's Hand: ", player.name);
    for (int i = 0; i < CARDS_IN_HAND; i++) {
        printCard(player.hand[i]);
    }
    printf("\n");
}

int compareCards(const void* a, const void* b) {
    Card* cardA = (Card*)a;
    Card* cardB = (Card*)b;
    return cardA->rank - cardB->rank;
}

void sortHand(Player* player) {
    qsort(player->hand, CARDS_IN_HAND, sizeof(Card), compareCards);
}

int main() {
    srand(time(NULL));
    Player players[NUM_PLAYERS];
    
    printf("Welcome to the Poker Game!\n");
    
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
    }

    createDeck();
    shuffleDeck();
    
    dealCards(players);
    
    for (int i = 0; i < NUM_PLAYERS; i++) {
        sortHand(&players[i]);
        printPlayerHand(players[i]);
    }
    
    printf("Game Over!\n");
    return 0;
}