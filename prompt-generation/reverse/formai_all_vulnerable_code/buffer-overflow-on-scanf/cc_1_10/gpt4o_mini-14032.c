//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define TOTAL_CARDS 52

typedef struct {
    char *name;
    int score;
} Player;

void shuffleDeck(int deck[]) {
    for (int i = TOTAL_CARDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void initializeDeck(int deck[]) {
    for (int i = 0; i < TOTAL_CARDS; i++) {
        deck[i] = i + 1;  // Assign each card a value
    }
}

void printCard(int card) {
    const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    
    printf("%s of %s\n", values[(card - 1) % 13], suits[(card - 1) / 13]);
}

void playGame(Player players[], int numPlayers) {
    int deck[TOTAL_CARDS];
    initializeDeck(deck);
    shuffleDeck(deck);
    
    for (int round = 0; round < 5; round++) { // Each player plays 5 rounds
        printf("\nRound %d:\n", round + 1);
        
        for (int i = 0; i < numPlayers; i++) {
            int cardIndex = round * numPlayers + i; // Ensures each player gets one card per round
            if (cardIndex >= TOTAL_CARDS) {
                printf("No more cards! The deck is officially more exhausted than a cat in a snowstorm!\n");
                return;
            }
            printf("%s plays: ", players[i].name);
            printCard(deck[cardIndex]);
            players[i].score += (deck[cardIndex] % 13); // Adding a straightforward score
            printf("%s's current score: %d\n", players[i].name, players[i].score);
        }
    }
    
    // Determine the winner
    int maxScore = 0;
    char *winnerName = NULL;
    for (int i = 0; i < numPlayers; i++) {
        if (players[i].score > maxScore) {
            maxScore = players[i].score;
            winnerName = players[i].name;
        }
    }
    printf("\nThe winner is %s with a score of %d! Hooraay! 🎉\n", winnerName, maxScore);
}

int main() {
    srand(time(NULL));
    
    Player players[MAX_PLAYERS];
    int numPlayers;
    
    printf("Welcome to the Silly Card Game! 🎊\n");
    printf("How many players will join the madness? (Max %d)\n", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    
    if (numPlayers <= 0 || numPlayers > MAX_PLAYERS) {
        printf("Oops! That number of players is less than one or more than the maximum! Let's try this again.\n");
        return 1;
    }
    
    for (int i = 0; i < numPlayers; i++) {
        players[i].score = 0; // Initialize scores
        printf("Enter player %d's name (be creative, but not too creative!): ", i + 1);
        players[i].name = malloc(50 * sizeof(char)); // Allocate space for the name
        scanf("%s", players[i].name);
    }
    
    playGame(players, numPlayers);
    
    // Freeing the allocated memory
    for (int i = 0; i < numPlayers; i++) {
        free(players[i].name);
    }
    
    printf("Thanks for playing the Silly Card Game! Hope you laughed harder than a clown in a balloon factory!\n");
    return 0;
}