//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CARDS 52
#define MAX_HAND 5
#define MAX_PLAYERS 6

typedef struct {
    char *rank;
    char *suit;
} Card;

typedef struct {
    Card hand[MAX_HAND];
    int score;
} Player;

Card deck[MAX_CARDS];
Player players[MAX_PLAYERS];
int numPlayers;

void initializeDeck() {
    const char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    int index = 0;

    for (int suit = 0; suit < 4; suit++) {
        for (int rank = 0; rank < 13; rank++) {
            deck[index].rank = (char *)ranks[rank];
            deck[index].suit = (char *)suits[suit];
            index++;
        }
    }
}

void shuffleDeck() {
    for (int i = 0; i < MAX_CARDS; i++) {
        int j = rand() % MAX_CARDS;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards() {
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < MAX_HAND; j++) {
            players[i].hand[j] = deck[i * MAX_HAND + j];
        }
        players[i].score = 0;  // Initialize player score
    }
}

void printCard(Card card) {
    printf("%s of %s\n", card.rank, card.suit);
}

void printPlayerHand(Player player) {
    printf("Player's hand:\n");
    for (int i = 0; i < MAX_HAND; i++) {
        printCard(player.hand[i]);
    }
}

int calculateHandScore(Player player) {
    int score = 0;
    for (int i = 0; i < MAX_HAND; i++) {
        if (strcmp(player.hand[i].rank, "A") == 0) {
            score += 11;
        } else if (strcmp(player.hand[i].rank, "K") == 0 || 
                   strcmp(player.hand[i].rank, "Q") == 0 || 
                   strcmp(player.hand[i].rank, "J") == 0) {
            score += 10;
        } else {
            score += atoi(player.hand[i].rank);
        }
    }
    return score;
}

void determineWinner() {
    int highestScore = 0;
    int winnerIndex = -1;

    for (int i = 0; i < numPlayers; i++) {
        players[i].score = calculateHandScore(players[i]);
        if (players[i].score > highestScore) {
            highestScore = players[i].score;
            winnerIndex = i;
        }
    }

    printf("Player %d wins with a score of %d!\n", winnerIndex + 1, highestScore);
}

int main() {
    srand(time(0));
    printf("Welcome to the Poker Game!\n");
    
    printf("Enter number of players (2-6): ");
    scanf("%d", &numPlayers);
    if (numPlayers < 2 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Please restart the game.\n");
        return 1;
    }

    initializeDeck();
    shuffleDeck();
    dealCards();
    
    for (int i = 0; i < numPlayers; i++) {
        printf("\n");
        printPlayerHand(players[i]);
    }
    
    determineWinner();
    
    return 0;
}