//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 10

typedef struct {
    char name[20];
    int score;
} Player;

Player players[MAX_PLAYERS];
int num_players = 0;

void add_player(char* name) {
    if (num_players == MAX_PLAYERS) {
        printf("Error: Too many players\n");
        return;
    }
    strcpy(players[num_players].name, name);
    players[num_players].score = 0;
    num_players++;
}

void remove_player(char* name) {
    int i;
    for (i = 0; i < num_players; i++) {
        if (strcmp(players[i].name, name) == 0) {
            memmove(&players[i], &players[i+1], sizeof(Player) * (num_players - i - 1));
            num_players--;
            break;
        }
    }
}

void display_players() {
    int i;
    for (i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

void add_score(char* name, int score) {
    int i;
    for (i = 0; i < num_players; i++) {
        if (strcmp(players[i].name, name) == 0) {
            players[i].score += score;
            break;
        }
    }
}

int main() {
    char command[100];
    while (1) {
        printf("Enter command: ");
        scanf("%s", command);
        if (strcmp(command, "add_player") == 0) {
            char name[20];
            printf("Enter player name: ");
            scanf("%s", name);
            add_player(name);
        } else if (strcmp(command, "remove_player") == 0) {
            char name[20];
            printf("Enter player name: ");
            scanf("%s", name);
            remove_player(name);
        } else if (strcmp(command, "display_players") == 0) {
            display_players();
        } else if (strcmp(command, "add_score") == 0) {
            char name[20];
            int score;
            printf("Enter player name: ");
            scanf("%s", name);
            printf("Enter score: ");
            scanf("%d", &score);
            add_score(name, score);
        } else {
            printf("Invalid command\n");
        }
    }
    return 0;
}