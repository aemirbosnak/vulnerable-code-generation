//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_CARDS 52
#define MAX_ROUNDS 5

typedef struct {
    char *name;
    int score;
} Player;

typedef struct {
    int cards[MAX_CARDS];
    int top;
} Deck;

void initializeDeck(Deck *deck) {
    for (int i = 0; i < MAX_CARDS; i++) {
        deck->cards[i] = i + 1;
    }
    deck->top = MAX_CARDS - 1; // end of deck
}

void shuffleDeck(Deck *deck) {
    srand(time(NULL));
    for (int i = 0; i < MAX_CARDS; i++) {
        int j = rand() % MAX_CARDS;
        int temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

int drawCard(Deck *deck) {
    if (deck->top < 0) {
        return -1; // no more cards
    }
    return deck->cards[deck->top--]; // draw the top card
}

void initializePlayers(Player players[], int count) {
    for (int i = 0; i < count; i++) {
        players[i].name = (char *)malloc(20 * sizeof(char));
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
}

void playRound(Deck *deck, Player players[], int count) {
    printf("\n--- New Round ---\n");
    for (int i = 0; i < count; i++) {
        int card = drawCard(deck);
        if (card == -1) {
            printf("No more cards to draw!\n");
            return;
        }
        players[i].score += card; // Players score increases by the value of the card drawn
        printf("%s drew card: %d | Total Score: %d\n", players[i].name, card, players[i].score);
    }
}

void resetScores(Player players[], int count) {
    for (int i = 0; i < count; i++) {
        players[i].score = 0;
    }
}

void announceWinner(Player players[], int count) {
    int highestScore = 0;
    int winnerIndex = -1;

    for (int i = 0; i < count; i++) {
        if (players[i].score > highestScore) {
            highestScore = players[i].score;
            winnerIndex = i;
        }
    }

    if (winnerIndex != -1) {
        printf("\n*** Winner: %s with score: %d ***\n", players[winnerIndex].name, players[winnerIndex].score);
    } else {
        printf("\nIt's a tie!\n");
    }
}

void freePlayers(Player players[], int count) {
    for (int i = 0; i < count; i++) {
        free(players[i].name);
    }
}

int main() {
    int numPlayers;
    printf("Welcome to the Galactic Card Clash!\n");
    
    printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    
    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players!\n");
        return 1;
    }

    Player players[MAX_PLAYERS];
    initializePlayers(players, numPlayers);
    
    Deck deck;
    initializeDeck(&deck);
    shuffleDeck(&deck);

    for (int round = 0; round < MAX_ROUNDS; round++) {
        printf("\n--- Round %d ---\n", round + 1);
        playRound(&deck, players, numPlayers);
    }

    announceWinner(players, numPlayers);
    freePlayers(players, numPlayers);

    printf("Thank you for playing Galactic Card Clash! Until next time.\n");
    return 0;
}