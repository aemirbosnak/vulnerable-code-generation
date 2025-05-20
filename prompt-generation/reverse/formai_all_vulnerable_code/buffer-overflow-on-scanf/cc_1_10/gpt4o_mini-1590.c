//GPT-4o-mini DATASET v1.0 Category: Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 10
#define BOARD_SIZE 10

typedef struct {
    char name[30];
    int position;
} Player;

typedef struct {
    Player players[MAX_PLAYERS];
    int playerCount;
} GameState;

void initGameState(GameState *gameState) {
    gameState->playerCount = 0;
}

void addPlayer(GameState *gameState, const char *playerName) {
    if (gameState->playerCount < MAX_PLAYERS) {
        strncpy(gameState->players[gameState->playerCount].name, playerName, 30);
        gameState->players[gameState->playerCount].position = 0;
        gameState->playerCount++;
    } else {
        printf("Maximum player limit reached.\n");
    }
}

void displayBoard(GameState *gameState) {
    printf("\nGame Board:\n");
    for (int i = 0; i < gameState->playerCount; i++) {
        printf("%s is at position %d\n", gameState->players[i].name, gameState->players[i].position);
    }
}

void movePlayer(Player *player) {
    int roll = rand() % 6 + 1;
    player->position += roll;
    if (player->position >= BOARD_SIZE) {
        player->position = BOARD_SIZE;
        printf("%s has finished the game!\n", player->name);
    } else {
        printf("%s rolled a %d and moved to position %d\n", player->name, roll, player->position);
    }
}

int allPlayersFinished(GameState *gameState) {
    for (int i = 0; i < gameState->playerCount; i++) {
        if (gameState->players[i].position < BOARD_SIZE) {
            return 0; // Not all players have finished
        }
    }
    return 1; // All players finished
}

void playGame(GameState *gameState) {
    while (!allPlayersFinished(gameState)) {
        for (int i = 0; i < gameState->playerCount; i++) {
            if (gameState->players[i].position < BOARD_SIZE) {
                movePlayer(&gameState->players[i]);
                displayBoard(gameState);
                printf("\n");
            }
        }
    }
    printf("Game Over!\n");
}

int main() {
    GameState gameState;
    initGameState(&gameState);

    srand(time(NULL));
    
    char playerName[30];

    printf("Enter the number of players (max %d): ", MAX_PLAYERS);
    int numPlayers;
    scanf("%d", &numPlayers);

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", playerName);
        addPlayer(&gameState, playerName);
    }

    displayBoard(&gameState);
    playGame(&gameState);
    
    return 0;
}