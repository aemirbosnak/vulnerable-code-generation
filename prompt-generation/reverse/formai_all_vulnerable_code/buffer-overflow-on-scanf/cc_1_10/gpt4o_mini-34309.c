//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CARDS 52
#define MAX_PLAYERS 4
#define HAND_SIZE 5

typedef struct {
    char *rank;
    char *suit;
} Card;

typedef struct {
    Card hand[HAND_SIZE];
    int score;
} Player;

Card deck[MAX_CARDS];

// Function prototypes
void initializeDeck();
void shuffleDeck();
void dealCards(Player players[], int numPlayers);
void printHand(Player player);
void evaluateScores(Player players[], int numPlayers);
int compareHands(Card hand1[], Card hand2[]);

int main() {
    srand(time(0)); // Initialize random number generator

    Player players[MAX_PLAYERS];
    int numPlayers;

    printf("Welcome to the Curious Poker Game!\n");
    printf("Enter number of players (2-4): ");
    scanf("%d", &numPlayers);

    if (numPlayers < 2 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players!\n");
        return 1;
    }

    initializeDeck();
    shuffleDeck();
    dealCards(players, numPlayers);
    
    printf("\nPlayer Hands:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d: ", i + 1);
        printHand(players[i]);
    }

    evaluateScores(players, numPlayers);

    return 0;
}

// Initialize the deck with cards
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

// Shuffle the deck randomly
void shuffleDeck() {
    for (int i = 0; i < MAX_CARDS; i++) {
        int r = rand() % MAX_CARDS;
        Card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

// Deal cards to each player
void dealCards(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < HAND_SIZE; j++) {
            players[i].hand[j] = deck[i * HAND_SIZE + j];
        }
        players[i].score = 0; // Reset score
    }
}

// Print the player's hand
void printHand(Player player) {
    for (int i = 0; i < HAND_SIZE; i++) {
        printf("%s of %s", player.hand[i].rank, player.hand[i].suit);
        if (i < HAND_SIZE - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

// Evaluate scores for each player and determine the best hand
void evaluateScores(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        // For simplicity, score as the sum of ranks
        for (int j = 0; j < HAND_SIZE; j++) {
            if (players[i].hand[j].rank[0] >= '2' && players[i].hand[j].rank[0] <= '9') {
                players[i].score += players[i].hand[j].rank[0] - '0';
            } else {
                players[i].score += 10; // face cards and aces considered as 10 for simplicity
            }
        }
    }

    int winnerIndex = 0;
    for (int i = 1; i < numPlayers; i++) {
        if (players[i].score > players[winnerIndex].score) {
            winnerIndex = i;
        }
    }

    printf("\nThe winner is Player %d with score: %d\n", winnerIndex + 1, players[winnerIndex].score);
}

// Compare two hands (for future use)
int compareHands(Card hand1[], Card hand2[]) {
    // Placeholder for actual hand comparison logic
    return 0; // Equal for now
}