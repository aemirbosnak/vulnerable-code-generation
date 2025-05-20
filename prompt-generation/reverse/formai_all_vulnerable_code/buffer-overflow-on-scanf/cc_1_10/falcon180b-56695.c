//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 10

typedef struct {
    char name[20];
    int score;
    char binary[33];
} Player;

void init_player(Player *player, char *name) {
    strcpy(player->name, name);
    player->score = 0;
    memset(player->binary, '0', sizeof(player->binary));
}

void print_player(Player *player) {
    printf("Name: %s\n", player->name);
    printf("Score: %d\n", player->score);
    printf("Binary: %s\n", player->binary);
}

int main() {
    Player players[MAX_PLAYERS];
    char name[20];
    int num_players, i;

    printf("Enter number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    for (i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", name);
        init_player(&players[i], name);
    }

    while (1) {
        int choice, player_index;

        printf("\n");
        printf("1. Convert decimal to binary\n");
        printf("2. Convert binary to decimal\n");
        printf("3. Display scores\n");
        printf("4. Quit\n");
        printf("\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                if (scanf("%d", &player_index)!= 1) {
                    printf("Invalid input.\n");
                    break;
                }
                if (player_index >= 0 && player_index < num_players) {
                    printf("Enter a decimal number: ");
                    if (scanf("%d", &players[player_index].score)!= 1) {
                        printf("Invalid input.\n");
                        break;
                    }
                    sprintf(players[player_index].binary, "%032b", players[player_index].score);
                } else {
                    printf("Invalid player index.\n");
                }
                break;
            case 2:
                printf("Enter a binary number: ");
                if (scanf("%s", players[0].binary)!= 1) {
                    printf("Invalid input.\n");
                    break;
                }
                players[0].score = strtol(players[0].binary, NULL, 2);
                break;
            case 3:
                for (i = 0; i < num_players; i++) {
                    print_player(&players[i]);
                }
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}