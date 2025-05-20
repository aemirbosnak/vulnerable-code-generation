//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_TURNS 10
#define BOARD_SIZE 10

typedef struct {
    char name[20];
    int position;
    int score;
} Player;

void initializePlayers(Player players[], int numPlayers);
void displayBoard(Player players[], int numPlayers);
void rollDice(Player *player);
void takeTurn(Player *player);
int checkVictory(Player players[], int numPlayers);
void displayResults(Player players[], int numPlayers);

int main() {
    Player players[MAX_PLAYERS];
    int numPlayers, currentTurn = 0;

    printf("Welcome to the C Table Game!\n");
    printf("Enter the number of players (2-4): ");
    scanf("%d", &numPlayers);

    if(numPlayers < 2 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    initializePlayers(players, numPlayers);

    while(currentTurn < MAX_TURNS) {
        printf("\nTurn %d\n", currentTurn + 1);
        for(int i = 0; i < numPlayers; i++) {
            takeTurn(&players[i]);
            if(checkVictory(players, numPlayers)) {
                printf("\nWe have a winner!\n");
                displayResults(players, numPlayers);
                return 0;
            }
        }
        currentTurn++;
    }

    printf("\nMaximum turns reached. No winner!\n");
    displayResults(players, numPlayers);
    return 0;
}

void initializePlayers(Player players[], int numPlayers) {
    for(int i = 0; i < numPlayers; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].position = 0;
        players[i].score = 0;
    }
}

void displayBoard(Player players[], int numPlayers) {
    printf("\nGame Board:\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < numPlayers; j++) {
            if(players[j].position == i) {
                printf("[%s] ", players[j].name);
            } else {
                printf("[ ] ");
            }
        }
        printf("\n");
    }
}

void rollDice(Player *player) {
    srand(time(NULL));
    int roll = (rand() % 6) + 1; // Roll a number between 1 and 6
    printf("%s rolled a %d!\n", player->name, roll);
    player->position += roll;
    if(player->position >= BOARD_SIZE) {
        player->position = BOARD_SIZE - 1; // Maximum position
    }
}

void takeTurn(Player *player) {
    rollDice(player);
    player->score += player->position; // Add score based on current position
    printf("%s's position: %d, Score: %d\n", player->name, player->position, player->score);
    displayBoard(&player, 1);
}

int checkVictory(Player players[], int numPlayers) {
    for(int i = 0; i < numPlayers; i++) {
        if(players[i].position == BOARD_SIZE - 1) {
            return 1; // A player has reached the end
        }
    }
    return 0;
}

void displayResults(Player players[], int numPlayers) {
    printf("\nFinal Results:\n");
    for(int i = 0; i < numPlayers; i++) {
        printf("Player: %s, Final Position: %d, Final Score: %d\n",
               players[i].name, players[i].position, players[i].score);
    }
}