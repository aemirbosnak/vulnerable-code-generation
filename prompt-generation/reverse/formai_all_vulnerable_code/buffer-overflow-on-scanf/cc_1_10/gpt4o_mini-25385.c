//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define CARDS_IN_HAND 5
#define DECK_SIZE 52

const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
const char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

typedef struct {
    char rank[3];
    char suit[10];
} Card;

// Function declarations
void shuffleDeck(Card deck[], int size);
void dealCards(Card deck[], Card playerHands[MAX_PLAYERS][CARDS_IN_HAND], int numPlayers);
void showPlayerCards(Card playerHands[MAX_PLAYERS][CARDS_IN_HAND], int numPlayers);
void displayDeck(Card deck[], int size);
void playPoker();

int main() {
    playPoker(); // Start the poker game
    return 0; 
}

void playPoker() {
    Card deck[DECK_SIZE];
    Card playerHands[MAX_PLAYERS][CARDS_IN_HAND];
    int numPlayers = 0;

    printf("Welcome to C Poker Game!\n");
    printf("Enter number of players (1-4): ");
    scanf("%d", &numPlayers);
    while (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number! Please choose between 1-4 players: ");
        scanf("%d", &numPlayers);
    }

    // Initialize the deck
    int index = 0;
    for(int suit = 0; suit < 4; ++suit) {
        for(int rank = 0; rank < 13; ++rank) {
            sprintf(deck[index].rank, "%s", ranks[rank]);
            sprintf(deck[index].suit, "%s", suits[suit]);
            index++;
        }
    }

    shuffleDeck(deck, DECK_SIZE); // Shuffle the deck
    dealCards(deck, playerHands, numPlayers); // Deal cards
    showPlayerCards(playerHands, numPlayers); // Show player cards
}

void shuffleDeck(Card deck[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int j = rand() % size; 
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp; 
    }
    printf("Deck shuffled!\n");
}

void dealCards(Card deck[], Card playerHands[MAX_PLAYERS][CARDS_IN_HAND], int numPlayers) {
    for (int p = 0; p < numPlayers; p++) {
        for (int c = 0; c < CARDS_IN_HAND; c++) {
            playerHands[p][c] = deck[p * CARDS_IN_HAND + c]; 
        }
    }
    printf("Cards dealt to players!\n");
}

void showPlayerCards(Card playerHands[MAX_PLAYERS][CARDS_IN_HAND], int numPlayers) {
    for (int p = 0; p < numPlayers; p++) {
        printf("Player %d's cards:\n", p + 1);
        for (int c = 0; c < CARDS_IN_HAND; c++) {
            printf("%s of %s\n", playerHands[p][c].rank, playerHands[p][c].suit);
        }
        printf("\n"); 
    }
}

void displayDeck(Card deck[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s of %s\n", deck[i].rank, deck[i].suit);
    }
}