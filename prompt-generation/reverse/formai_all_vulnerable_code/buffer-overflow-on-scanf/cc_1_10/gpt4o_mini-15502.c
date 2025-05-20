//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define BOARD_SIZE 10
#define MAX_TURNS 20

typedef struct {
    char name[50];
    int position;
    int score;
} Player;

void initializePlayers(Player players[], int numPlayers);
void displayBoard(int board[], int size);
void takeTurn(Player *player, int board[], int size);
int rollDice();
void configureGame(int *numPlayers, int *maxTurns);
void updateBoard(int board[], int size);

int main() {
    int numPlayers, maxTurns;
    configureGame(&numPlayers, &maxTurns);
    
    Player players[MAX_PLAYERS];
    int board[BOARD_SIZE];
    
    initializePlayers(players, numPlayers);
    updateBoard(board, BOARD_SIZE);

    for (int turn = 0; turn < maxTurns; turn++) {
        printf("\n--- Turn %d ---\n", turn + 1);
        for (int i = 0; i < numPlayers; i++) {
            printf("%s's turn:\n", players[i].name);
            takeTurn(&players[i], board, BOARD_SIZE);
            displayBoard(board, BOARD_SIZE);
        }
    }

    printf("\n--- Game Over ---\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s's final score: %d\n", players[i].name, players[i].score);
    }
    
    return 0;
}

void initializePlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].position = 0;
        players[i].score = 0;
    }
}

void displayBoard(int board[], int size) {
    printf("Board positions:\n");
    for (int i = 0; i < size; i++) {
        printf("Position %2d: %d\n", i, board[i]);
    }
}

void takeTurn(Player *player, int board[], int size) {
    int diceValue = rollDice();
    printf("%s rolled a %d\n", player->name, diceValue);
    
    player->position += diceValue;
    
    if (player->position >= size) {
        player->position = size - 1; // Stay in bounds
    }
    
    player->score += board[player->position];
    printf("%s's current position: %d, Score: %d\n", player->name, player->position, player->score);
}

int rollDice() {
    return (rand() % 6) + 1; // Returns a value between 1 and 6
}

void configureGame(int *numPlayers, int *maxTurns) {
    printf("Enter number of players (1 - %d): ", MAX_PLAYERS);
    scanf("%d", numPlayers);
    
    if (*numPlayers < 1 || *numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players, defaulting to 2.\n");
        *numPlayers = 2;
    }
    
    printf("Enter maximum turns (1 - %d): ", MAX_TURNS);
    scanf("%d", maxTurns);
    
    if (*maxTurns < 1 || *maxTurns > MAX_TURNS) {
        printf("Invalid number of turns, defaulting to 10.\n");
        *maxTurns = 10;
    }
}

void updateBoard(int board[], int size) {
    srand(time(0)); // Seed the random number generator
    for (int i = 0; i < size; i++) {
        board[i] = rand() % 10; // Random score for each position
    }
}