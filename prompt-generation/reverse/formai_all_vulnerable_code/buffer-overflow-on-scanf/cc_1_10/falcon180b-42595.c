//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_VIRUSES 10
#define MAX_FILE_SIZE 1000

typedef struct {
    char name[20];
    int score;
    int viruses[MAX_VIRUSES];
} Player;

typedef struct {
    char name[20];
    int strength;
} Virus;

void init_game(Player* players, Virus* viruses) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        strcpy(players[i].name, "Player");
        players[i].score = 0;
        for (int j = 0; j < MAX_VIRUSES; j++) {
            players[i].viruses[j] = 0;
        }
    }

    for (int i = 0; i < MAX_VIRUSES; i++) {
        strcpy(viruses[i].name, "Virus");
        viruses[i].strength = rand() % 100;
    }
}

void print_player_scores(Player* players) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Player %d: %d points\n", i+1, players[i].score);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    Virus viruses[MAX_VIRUSES];

    init_game(players, viruses);

    int num_players = 0;
    while (num_players < MAX_PLAYERS) {
        printf("Enter player name: ");
        scanf("%s", players[num_players].name);
        num_players++;
    }

    int num_viruses = 0;
    while (num_viruses < MAX_VIRUSES) {
        Virus virus;
        strcpy(virus.name, "Virus");
        virus.strength = rand() % 100;
        for (int i = 0; i < num_players; i++) {
            if (players[i].viruses[num_viruses] == 0) {
                players[i].viruses[num_viruses] = virus.strength;
                break;
            }
        }
        num_viruses++;
    }

    int turn = 0;
    while (turn < MAX_PLAYERS) {
        printf("Turn %d\n", turn+1);
        for (int i = 0; i < num_players; i++) {
            printf("Player %d score: %d\n", i+1, players[i].score);
        }
        turn++;
    }

    return 0;
}