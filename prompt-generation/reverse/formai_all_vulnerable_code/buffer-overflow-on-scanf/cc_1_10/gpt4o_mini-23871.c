//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARD_VALUE 13
#define MAX_PLAYERS 4
#define INITIAL_CARDS 2

typedef struct {
    int playerId;
    int score;
    int currentCard;
} Player;

void initializeDeck(int deck[], int size);
void shuffleDeck(int deck[], int size);
void dealCards(int deck[], Player players[], int playerCount);
int drawCard(int deck[], int *deckIndex);
int getNewCard(int deck[], int *deckIndex);
void playGame(Player players[], int playerCount, int deck[], int deckSize);
void printPlayerStatus(Player players[], int playerCount);
void printCard(int cardValue);

int main() {
    srand(time(NULL)); // Seed for random number generation

    int deck[MAX_CARD_VALUE] = {0};
    Player players[MAX_PLAYERS];
    
    int playerCount = 0;
    char input;

    // Get number of players
    while (playerCount < 1 || playerCount > MAX_PLAYERS) {
        printf("Enter number of players (1-%d): ", MAX_PLAYERS);
        scanf(" %d", &playerCount);
    }

    // Initialize and shuffle deck
    initializeDeck(deck, MAX_CARD_VALUE);
    shuffleDeck(deck, MAX_CARD_VALUE);
    
    // Initialize Players
    for (int i = 0; i < playerCount; i++) {
        players[i].playerId = i + 1;
        players[i].score = 0;
        players[i].currentCard = drawCard(deck, &deck[0]);
    }

    // Deal initial cards
    dealCards(deck, players, playerCount);
    
    // Start the game
    do {
        playGame(players, playerCount, deck, MAX_CARD_VALUE);
        printf("Continue playing? (y/n): ");
        scanf(" %c", &input);
    } while (input == 'y');

    // End of game - print final scores
    printf("Final Scores:\n");
    printPlayerStatus(players, playerCount);

    return 0;
}

void initializeDeck(int deck[], int size) {
    for (int i = 0; i < size; i++) {
        deck[i] = (i % 13) + 1; // Assign card values 1-13
    }
}

void shuffleDeck(int deck[], int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards(int deck[], Player players[], int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        players[i].currentCard = getNewCard(deck, &deck[0]);
    }
}

int drawCard(int deck[], int *deckIndex) {
    return deck[(*deckIndex)++];
}

int getNewCard(int deck[], int *deckIndex) {
    return drawCard(deck, deckIndex);
}

void playGame(Player players[], int playerCount, int deck[], int deckSize) {
    for (int i = 0; i < playerCount; i++) {
        printf("Player %d, your current card is: ", players[i].playerId);
        printCard(players[i].currentCard);
        
        char guess; // 'h' for higher, 'l' for lower
        printf("Will the next card be higher (h) or lower (l)? ");
        scanf(" %c", &guess);
        
        int newCard = getNewCard(deck, &deck[0]);
        printf("Next card is: ");
        printCard(newCard);
        
        if ((guess == 'h' && newCard > players[i].currentCard) ||
            (guess == 'l' && newCard < players[i].currentCard)) {
            printf("Correct! You gain 1 point.\n");
            players[i].score++;
        } else {
            printf("Wrong! No points for you.\n");
        }
        
        players[i].currentCard = newCard; // Update current card
    }

    // Print status of players after each round
    printPlayerStatus(players, playerCount);
}

void printPlayerStatus(Player players[], int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        printf("Player %d: Score: %d\n", players[i].playerId, players[i].score);
    }
}

void printCard(int cardValue) {
    switch (cardValue) {
        case 1: printf("Ace\n"); break;
        case 11: printf("Jack\n"); break;
        case 12: printf("Queen\n"); break;
        case 13: printf("King\n"); break;
        default: printf("%d\n", cardValue);
    }
}