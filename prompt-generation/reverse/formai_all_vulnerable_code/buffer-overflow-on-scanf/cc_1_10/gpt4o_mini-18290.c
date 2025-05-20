//GPT-4o-mini DATASET v1.0 Category: Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PLAYERS 4
#define MAX_HISTORY 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

typedef struct {
    Player players[MAX_PLAYERS];
    int playerCount;
    int historyCount;
    int scoreHistory[MAX_HISTORY];
} Game;

void initGame(Game *game) {
    game->playerCount = 0;
    game->historyCount = 0;
}

void addPlayer(Game *game, char *name) {
    if (game->playerCount < MAX_PLAYERS) {
        strncpy(game->players[game->playerCount].name, name, MAX_NAME_LENGTH);
        game->players[game->playerCount].score = 0;
        game->playerCount++;
        printf("Player %s added!\n", name);
    } else {
        printf("Maximum player limit reached!\n");
    }
}

void rollDice(Player *player) {
    player->score = (rand() % 6) + 1; // Random number between 1 and 6
    printf("%s rolled: %d\n", player->name, player->score);
}

void saveScoreToHistory(Game *game, int score) {
    if (game->historyCount < MAX_HISTORY) {
        game->scoreHistory[game->historyCount] = score;
        game->historyCount++;
    } else {
        printf("Score history is full!\n");
    }
}

void displayScoreHistory(Game *game) {
    printf("Score History:\n");
    for (int i = 0; i < game->historyCount; i++) {
        printf("%d: %d\n", i + 1, game->scoreHistory[i]);
    }
}

void displayScores(Game *game) {
    printf("Current Scores:\n");
    for (int i = 0; i < game->playerCount; i++) {
        printf("%s: %d\n", game->players[i].name, game->players[i].score);
    }
}

void takeTurn(Game *game) {
    for (int i = 0; i < game->playerCount; i++) {
        rollDice(&game->players[i]);
        saveScoreToHistory(game, game->players[i].score);
    }
}

void findWinner(Game *game) {
    int highestScore = -1;
    Player *winner = NULL;

    for (int i = 0; i < game->playerCount; i++) {
        if (game->players[i].score > highestScore) {
            highestScore = game->players[i].score;
            winner = &game->players[i];
        }
    }
    
    if (winner != NULL) {
        printf("The winner is %s with a score of %d!\n", winner->name, highestScore);
    }
}

int main() {
    Game game;
    char playerName[MAX_NAME_LENGTH];
    int playerCount;

    srand(time(NULL)); // Seed for random number generation
    initGame(&game);

    printf("Enter number of players (1-4): ");
    scanf("%d", &playerCount);
    
    // Limit the number of players
    if (playerCount < 1 || playerCount > MAX_PLAYERS) {
        printf("Invalid number of players!\n");
        return 1;
    }

    // Collect player names
    for (int i = 0; i < playerCount; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", playerName);
        addPlayer(&game, playerName);
    }
    
    // Main game loop
    char choice;
    do {
        takeTurn(&game);
        displayScores(&game);

        printf("Do you want to continue to the next round? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y');

    // Determine the winner
    findWinner(&game);
    
    // Display history
    displayScoreHistory(&game);
    
    return 0;
}