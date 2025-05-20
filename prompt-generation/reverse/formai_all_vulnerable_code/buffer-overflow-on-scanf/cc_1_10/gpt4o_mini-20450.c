//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 50
#define BOARD_SIZE 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

typedef struct {
    Player players[MAX_PLAYERS];
    int playerCount;
} Game;

void initGame(Game *game) {
    game->playerCount = 0;
}

void addPlayer(Game *game, const char *name) {
    if (game->playerCount < MAX_PLAYERS) {
        strncpy(game->players[game->playerCount].name, name, MAX_NAME_LENGTH);
        game->players[game->playerCount].score = 0;
        game->playerCount++;
    } else {
        printf("Maximum number of players reached!\n");
    }
}

void displayPlayers(Game *game) {
    printf("Current Players:\n");
    for (int i = 0; i < game->playerCount; i++) {
        printf("%d: %s - Score: %d\n", i + 1, game->players[i].name, game->players[i].score);
    }
}

int rollDice() {
    return rand() % 6 + 1; // Rolls a number between 1 and 6
}

void playRound(Game *game) {
    for (int i = 0; i < game->playerCount; i++) {
        printf("%s's turn:\n", game->players[i].name);
        int roll = rollDice();
        printf("Rolled: %d\n", roll);
        game->players[i].score += roll;
    }
}

void displayBoard(Game *game) {
    printf("\nGame Board:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("|---");
    }
    printf("|\n");
    
    for (int i = 0; i < game->playerCount; i++) {
        int position = game->players[i].score >= BOARD_SIZE ? BOARD_SIZE - 1 : game->players[i].score;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (j == position) {
                printf("| %s ", game->players[i].name);
            } else {
                printf("|   ");
            }
        }
        printf("|\n");
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("|---");
        }
        printf("|\n");
    }
}

int checkWinner(Game *game) {
    for (int i = 0; i < game->playerCount; i++) {
        if (game->players[i].score >= BOARD_SIZE) {
            printf("Congratulations %s! You have won the game!\n", game->players[i].name);
            return 1;
        }
    }
    return 0;
}

void playGame(Game *game) {
    while (1) {
        playRound(game);
        displayBoard(game);
        if (checkWinner(game)) {
            break;
        }
    }
}

int main() {
    Game game;
    initGame(&game);
    
    srand(time(NULL));  // Seed for random number generation

    char name[MAX_NAME_LENGTH];
    int numPlayers;

    printf("Enter number of players (1 to %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", name);
        addPlayer(&game, name);
    }

    displayPlayers(&game);
    playGame(&game);

    return 0;
}