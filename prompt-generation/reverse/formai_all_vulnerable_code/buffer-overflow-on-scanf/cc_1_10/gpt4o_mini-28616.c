//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LEN 20
#define MAX_ITEMS 10

typedef struct Player {
    char name[MAX_NAME_LEN];
    int health;
    int treasures;
} Player;

void initializePlayers(Player players[], int count) {
    for (int i = 0; i < count; ++i) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].health = 100;
        players[i].treasures = 0;
    }
}

void showStatus(Player players[], int count) {
    printf("\nPlayer Status:\n");
    for (int i = 0; i < count; ++i) {
        printf("Name: %s | Health: %d | Treasures: %d\n", players[i].name, players[i].health, players[i].treasures);
    }
}

void encounterDragon(Player *player) {
    printf("%s has encountered a fierce dragon!\n", player->name);
    srand(time(NULL));
    int outcome = rand() % 2;
    if (outcome == 0) {
        printf("The dragon attacks!\n");
        player->health -= 50;
        printf("%s takes damage! Remaining health: %d\n", player->name, player->health);
    } else {
        printf("The dragon is defeated and %s claims the treasures!\n", player->name);
        player->treasures += 20;
    }
}

void explore(Player players[], int count) {
    for (int i = 0; i < count; ++i) {
        char choice;
        printf("\n%s, do you want to explore (e) or check status (s)? ", players[i].name);
        scanf(" %c", &choice);
        if (choice == 'e') {
            encounterDragon(&players[i]);
        } else if (choice == 's') {
            showStatus(players, count);
        } else {
            printf("Invalid choice, skipping turn.\n");
        }
        sleep(1);
    }
}

int main() {
    int numPlayers;

    printf("Welcome to the Dragon's Lair Adventure!\n");
    printf("How many players are there (1 - %d)? ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting the game.\n");
        return 1;
    }

    Player players[MAX_PLAYERS];
    initializePlayers(players, numPlayers);
    int gameOver = 0;

    while (!gameOver) {
        explore(players, numPlayers);
        showStatus(players, numPlayers);

        gameOver = 1;  // Assume game is over after each full round for simplicity
        for (int i = 0; i < numPlayers; ++i) {
            if (players[i].health > 0) {
                gameOver = 0;  // If any player is still alive, keep playing
            }
        }
    }

    printf("\nGame Over! Here are final statuses:\n");
    showStatus(players, numPlayers);
    return 0;
}