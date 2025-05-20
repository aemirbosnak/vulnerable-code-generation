//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20
#define MAX_COMMANDS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

typedef struct {
    char command[MAX_COMMANDS];
    int length;
} Command;

Player players[MAX_PLAYERS];
int num_players;

void init() {
    num_players = 0;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        strcpy(players[i].name, "Player");
        players[i].score = 0;
    }
}

int main() {
    init();

    char input[MAX_COMMANDS];
    while (1) {
        printf("Enter command: ");
        scanf("%s", input);

        Command command;
        strcpy(command.command, input);
        command.length = strlen(input);

        if (command.length == 5 && strcmp(command.command, "ADD ") == 0) {
            char name[MAX_NAME_LENGTH];
            int score;
            sscanf(input + 5, "%s %d", name, &score);

            for (int i = 0; i < num_players; i++) {
                if (strcmp(players[i].name, name) == 0) {
                    players[i].score += score;
                    printf("%s's score is now %d\n", name, players[i].score);
                    break;
                }
            }
        } else if (command.length == 6 && strcmp(command.command, "REMOV") == 0) {
            char name[MAX_NAME_LENGTH];
            sscanf(input + 6, "%s", name);

            for (int i = 0; i < num_players; i++) {
                if (strcmp(players[i].name, name) == 0) {
                    players[i] = players[num_players - 1];
                    num_players--;
                    printf("%s has been removed from the game\n", name);
                    break;
                }
            }
        } else if (command.length == 8 && strcmp(command.command, "LIST ") == 0) {
            printf("Players:\n");
            for (int i = 0; i < num_players; i++) {
                printf("%s: %d\n", players[i].name, players[i].score);
            }
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}