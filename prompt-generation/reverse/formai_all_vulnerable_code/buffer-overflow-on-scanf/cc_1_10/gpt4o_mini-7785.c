//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_CARDS 52
#define CARDS_IN_HAND 5

typedef struct {
    char suit[10];
    char rank[3];
} Card;

typedef struct {
    char name[30];
    Card hand[CARDS_IN_HAND];
    int score;
} Player;

Card deck[MAX_CARDS];
Player players[MAX_PLAYERS];
int numPlayers;

// Function prototypes
void initializeDeck();
void shuffleDeck();
void dealCards();
void displayPlayerHands();
void calculateScores();
void determineWinner();
void playGame();

int main() {
    printf("Welcome to the Exciting C Poker Game!\n\n");
    printf("How many players (max %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);

    if(numPlayers < 2 || numPlayers > MAX_PLAYERS) {
        printf("Please enter a valid number of players between 2 and %d.\n", MAX_PLAYERS);
        return 1;
    }
    
    printf("Enter the names of the players:\n");
    for(int i = 0; i < numPlayers; i++) {
        printf("Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0; // Initialize scores to 0
    }
    
    playGame();

    return 0;
}

void initializeDeck() {
    const char* suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char* ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

    int index = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 13; j++) {
            strcpy(deck[index].suit, suits[i]);
            strcpy(deck[index].rank, ranks[j]);
            index++;
        }
    }
}

void shuffleDeck() {
    srand(time(NULL)); // Seed for random number generator
    for(int i = 0; i < MAX_CARDS; i++) {
        int r = rand() % MAX_CARDS;
        Card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

void dealCards() {
    for(int i = 0; i < numPlayers; i++) {
        printf("\nDealing cards to %s...\n", players[i].name);
        for(int j = 0; j < CARDS_IN_HAND; j++) {
            players[i].hand[j] = deck[i * CARDS_IN_HAND + j];
            printf("\t%s of %s\n", players[i].hand[j].rank, players[i].hand[j].suit);
        }
    }
}

void displayPlayerHands() {
    for(int i = 0; i < numPlayers; i++) {
        printf("%s's Hand: ", players[i].name);
        for(int j = 0; j < CARDS_IN_HAND; j++) {
            printf("[%s of %s] ", players[i].hand[j].rank, players[i].hand[j].suit);
        }
        printf("\n");
    }
}

void calculateScores() {
    // Simplistic scoring: Count number of Aces, Kings, Queens, and Jacks
    for(int i = 0; i < numPlayers; i++) {
        for(int j = 0; j < CARDS_IN_HAND; j++) {
            if(strcmp(players[i].hand[j].rank, "A") == 0) players[i].score += 4;
            else if(strcmp(players[i].hand[j].rank, "K") == 0) players[i].score += 3;
            else if(strcmp(players[i].hand[j].rank, "Q") == 0) players[i].score += 2;
            else if(strcmp(players[i].hand[j].rank, "J") == 0) players[i].score += 1;
        }
    }
}

void determineWinner() {
    int maxScore = 0;
    char winner[30];
    
    for(int i = 0; i < numPlayers; i++) {
        if(players[i].score > maxScore) {
            maxScore = players[i].score;
            strcpy(winner, players[i].name);
        }
    }
    printf("\nThe winner is %s with a score of %d!\n", winner, maxScore);
}

void playGame() {
    initializeDeck();
    shuffleDeck();
    dealCards();
    displayPlayerHands();
    calculateScores();
    determineWinner();
}