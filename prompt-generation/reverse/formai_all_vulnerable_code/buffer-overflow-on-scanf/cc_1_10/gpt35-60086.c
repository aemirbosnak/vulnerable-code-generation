//FormAI DATASET v1.0 Category: Data recovery tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20
#define MAX_SCORE_LENGTH 10

typedef struct player {
    char name[MAX_NAME_LENGTH];
    int scores[MAX_SCORE_LENGTH];
    int num_scores;
} Player;

Player players[MAX_PLAYERS];
int num_players = 0;

void printPlayers() {
    printf("Players:\n");
    for (int i=0; i<num_players; i++) {
        printf("%d. %s\n", i+1, players[i].name);
    }
}

void addPlayer(char *name) {
    if (num_players >= MAX_PLAYERS) {
        printf("Error: Maximum number of players reached.");
        return;
    }
    Player p;
    strcpy(p.name, name);
    p.num_scores = 0;
    players[num_players] = p;
    num_players++;
    printf("Player added successfully.\n");
}

void addScore(char *name, int score) {
    int player_index = -1;
    for (int i=0; i<num_players; i++) {
        if (strcmp(players[i].name, name) == 0) {
            player_index = i;
            break;
        }
    }
    if (player_index == -1) {
        printf("Error: Player not found.\n");
        return;
    }
    if (players[player_index].num_scores >= MAX_SCORE_LENGTH) {
        printf("Error: Maximum number of scores reached for player.\n");
        return;
    }
    players[player_index].scores[players[player_index].num_scores] = score;
    players[player_index].num_scores++;
    printf("Score added successfully.\n");
}

void printScores(char *name) {
    int player_index = -1;
    for (int i=0; i<num_players; i++) {
        if (strcmp(players[i].name, name) == 0) {
            player_index = i;
            break;
        }
    }
    if (player_index == -1) {
        printf("Error: Player not found.\n");
        return;
    }
    printf("Scores for %s:", name);
    for (int i=0; i<players[player_index].num_scores; i++) {
        printf(" %d", players[player_index].scores[i]);
    }
    printf("\n");
}

int main() {
    char command[MAX_NAME_LENGTH];
    while (1) {
        printf("Enter command (addPlayer, addScore, printPlayers, printScores, quit):");
        scanf("%s", command);
        if (strcmp(command, "addPlayer") == 0) {
            char name[MAX_NAME_LENGTH];
            printf("Enter name:");
            scanf("%s", name);
            addPlayer(name);
        }
        else if (strcmp(command, "addScore") == 0) {
            char name[MAX_NAME_LENGTH];
            int score;
            printf("Enter name:");
            scanf("%s", name);
            printf("Enter score:");
            scanf("%d", &score);
            addScore(name, score);
        }
        else if (strcmp(command, "printPlayers") == 0) {
            printPlayers();
        }
        else if (strcmp(command, "printScores") == 0) {
            char name[MAX_NAME_LENGTH];
            printf("Enter name:");
            scanf("%s", name);
            printScores(name);
        }
        else if (strcmp(command, "quit") == 0) {
            break;
        }
        else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}