//Falcon-180B DATASET v1.0 Category: File handling ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20
#define MAX_COMMAND_LENGTH 80

typedef struct {
    char name[MAX_NAME_LENGTH];
    FILE *input_file;
    FILE *output_file;
} Player;

void initialize_player(Player *player, char *name) {
    strncpy(player->name, name, MAX_NAME_LENGTH);
    player->input_file = stdin;
    player->output_file = stdout;
}

int main() {
    char host_name[MAX_NAME_LENGTH];
    int num_players;
    Player players[MAX_PLAYERS];

    printf("Enter your name: ");
    scanf("%s", host_name);

    printf("Enter number of players (1 to %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", players[i].name);
        initialize_player(&players[i], players[i].name);
    }

    char command[MAX_COMMAND_LENGTH];
    while (1) {
        printf("\n%s: ", host_name);
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = '\0'; // remove newline character

        for (int i = 0; i < num_players; i++) {
            if (strcmp(players[i].name, host_name) == 0) {
                continue;
            }
            fprintf(players[i].output_file, "%s: %s\n", host_name, command);
        }
    }

    return 0;
}