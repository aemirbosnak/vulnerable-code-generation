//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_TURNS 10
#define MAX_SCORE 100

// Game data structures
typedef struct {
    char name[20];
    int score;
} Player;

typedef struct {
    int turn;
    int currentPlayer;
} GameState;

// Function prototypes
void initializeGame(Player* players);
void startGame(Player* players, GameState* gameState);
void playRound(Player* players, GameState* gameState);
void endGame(Player* players, GameState* gameState);

int main() {
    Player players[MAX_PLAYERS];
    GameState gameState;

    printf("Welcome to the game!\n");

    // Initialize game
    initializeGame(players);

    // Start game
    startGame(players, &gameState);

    // Play game
    playRound(players, &gameState);

    // End game
    endGame(players, &gameState);

    return 0;
}

void initializeGame(Player* players) {
    int i;
    for (i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
}

void startGame(Player* players, GameState* gameState) {
    srand(time(NULL));
    gameState->turn = 0;
    gameState->currentPlayer = rand() % MAX_PLAYERS;
    printf("The game has started!\n");
}

void playRound(Player* players, GameState* gameState) {
    int i;
    for (i = 0; i < MAX_TURNS; i++) {
        if (gameState->currentPlayer == rand() % MAX_PLAYERS) {
            printf("Player %s's turn!\n", players[gameState->currentPlayer].name);
            gameState->currentPlayer = (gameState->currentPlayer + 1) % MAX_PLAYERS;
        }
    }
}

void endGame(Player* players, GameState* gameState) {
    int i;
    for (i = 0; i < MAX_PLAYERS; i++) {
        printf("Player %s's final score: %d\n", players[i].name, players[i].score);
    }
    printf("The game has ended!\n");
}