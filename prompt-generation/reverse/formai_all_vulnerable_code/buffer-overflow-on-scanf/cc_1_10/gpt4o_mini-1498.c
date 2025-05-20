//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define BOARD_SIZE 10

typedef struct {
    char name[30];
    int position;
} Player;

void initializePlayers(Player players[], int numPlayers);
void printBoard(Player players[], int numPlayers);
void movePlayer(Player *player);
int checkWin(Player player);
void celebrateVictory(Player player);

int main() {
    int numPlayers;
    Player players[MAX_PLAYERS];

    printf("Welcome to the Romantic Journey Game!\n");
    printf("How many players will join in this whimsical adventure (2 to %d)? ", MAX_PLAYERS);
    scanf("%d", &numPlayers);

    while (numPlayers < 2 || numPlayers > MAX_PLAYERS) {
        printf("Please enter a valid number of players (2 to %d): ", MAX_PLAYERS);
        scanf("%d", &numPlayers);
    }

    initializePlayers(players, numPlayers);
    
    int winner = -1;
    while (winner == -1) {
        for (int i = 0; i < numPlayers; i++) {
            movePlayer(&players[i]);
            printBoard(players, numPlayers);
            if (checkWin(players[i])) {
                winner = i;
                break;
            }
        }
    }

    celebrateVictory(players[winner]);
    return 0;
}

void initializePlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].position = 0;
    }
}

void printBoard(Player players[], int numPlayers) {
    printf("\n--- Romantic Journey Board ---\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        int found = 0;
        for (int j = 0; j < numPlayers; j++) {
            if (players[j].position == i) {
                printf("[ %s ]", players[j].name);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("[   ]");
        }
    }
    printf("\n----------------------------\n");
}

void movePlayer(Player *player) {
    int move = rand() % 3 + 1; // Random move between 1 and 3
    player->position += move;

    if (player->position >= BOARD_SIZE) {
        player->position = BOARD_SIZE - 1; // Stay at last position
    }

    printf("%s moves forward by %d steps (to position %d).\n", player->name, move, player->position);
}

int checkWin(Player player) {
    return player.position == BOARD_SIZE - 1;
}

void celebrateVictory(Player player) {
    printf("\n💖🎉 Congratulations, %s! You have traversed the Romantic Journey and claimed your love! 🎉💖\n", player.name);
    printf("You stand at the beautiful garden of victory, where flowers bloom in your honor,\n");
    printf("and birds sing your name. Love has found you, and the world is painted with\n");
    printf("the colors of your triumph!\n");
}