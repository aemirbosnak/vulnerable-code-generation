//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define CARDS_IN_HAND 5
#define TOTAL_CARDS 52

typedef struct {
    char suit;
    int value;
} Card;

typedef struct {
    Card hand[CARDS_IN_HAND];
    int score;
} Player;

Card deck[TOTAL_CARDS];
int topCardIndex = 0;

void initializeDeck() {
    char suits[] = {'H', 'D', 'C', 'S'};
    int cardIndex = 0;
    for (int suit = 0; suit < 4; suit++) {
        for (int value = 1; value <= 13; value++) {
            deck[cardIndex].suit = suits[suit];
            deck[cardIndex].value = value;
            cardIndex++;
        }
    }
}

void shuffleDeck() {
    srand(time(NULL));
    for (int i = 0; i < TOTAL_CARDS; i++) {
        int r = rand() % TOTAL_CARDS;
        Card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

void dealCards(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < CARDS_IN_HAND; j++) {
            players[i].hand[j] = deck[topCardIndex++];
        }
    }
}

void displayCard(Card card) {
    const char* values[] = {"", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    printf("%s%c ", values[card.value], card.suit);
}

void displayPlayerHand(Player player) {
    printf("Player hand: ");
    for (int i = 0; i < CARDS_IN_HAND; i++) {
        displayCard(player.hand[i]);
    }
    printf("\n");
}

int calculateScore(Player player) {
    int score = 0;
    for (int i = 0; i < CARDS_IN_HAND; i++) {
        if (player.hand[i].value > 10) // Face cards count as 10
            score += 10;
        else
            score += player.hand[i].value;
    }
    return score;
}

void playGame(int numPlayers) {
    Player players[MAX_PLAYERS];

    initializeDeck();
    shuffleDeck();
    topCardIndex = 0;

    dealCards(players, numPlayers);
    
    for (int i = 0; i < numPlayers; i++) {
        players[i].score = calculateScore(players[i]);
        displayPlayerHand(players[i]);
        printf("Player %d score: %d\n", i+1, players[i].score);
    }

    // Determine the winner
    int highestScore = -1;
    int winnerIndex = -1;
    
    for (int i = 0; i < numPlayers; i++) {
        if (players[i].score > highestScore) {
            highestScore = players[i].score;
            winnerIndex = i;
        } else if (players[i].score == highestScore) {
            winnerIndex = -1; // Tie
        }
    }

    if (winnerIndex != -1) {
        printf("Player %d wins with a score of %d!\n", winnerIndex + 1, highestScore);
    } else {
        printf("It's a tie!\n");
    }
}

int main() {
    int numPlayers = 0;

    printf("Enter the number of players (2-4): ");
    scanf("%d", &numPlayers);

    if (numPlayers < 2 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting.\n");
        exit(1);
    }

    playGame(numPlayers);
    
    return 0;
}