#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 100

typedef struct Player {
    char name[20];
    int health;
    int attack;
} Player;

Player players[MAX_PLAYERS];
int numPlayers = 0;

void createPlayer(char *name) {
    if (numPlayers < MAX_PLAYERS) {
        strcpy(players[numPlayers].name, name);
        players[numPlayers].health = 100;
        players[numPlayers].attack = 10;
        numPlayers++;
    } else {
        printf("Max number of players reached.\n");
    }
}

void attackPlayer(int attackerIndex, int victimIndex) {
    if (attackerIndex >= 0 && attackerIndex < numPlayers && victimIndex >= 0 && victimIndex < numPlayers) {
        players[attackerIndex].health -= players[victimIndex].attack;
        printf("%s attacks %s, causing %d damage.\n", players[attackerIndex].name, players[victimIndex].name, players[attackerIndex].attack);
        if (players[victimIndex].health <= 0) {
            printf("%s has been defeated!\n", players[victimIndex].name);
        } else {
            printf("%s has %d health left.\n", players[victimIndex].name, players[victimIndex].health);
        }
    } else {
        printf("Invalid player indices.\n");
    }
}

int main() {
    createPlayer("Warrior");
    createPlayer("Witch");
    createPlayer("Sorcerer");
    attackPlayer(0, 2); // Attempt to attack an out-of-bounds player, causing a dereference failure
    return 0;
}
