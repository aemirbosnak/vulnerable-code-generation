//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4

typedef struct {
    char name[20];
    int score;
    int checksum;
} Player;

void generate_checksum(Player *player) {
    int i, sum = 0;
    for (i = 0; i < strlen(player->name); i++) {
        sum += player->name[i];
    }
    player->checksum = sum % 100;
}

int main() {
    Player players[MAX_PLAYERS];
    int num_players, i;

    printf("Enter the number of players (up to %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    for (i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
        generate_checksum(&players[i]);
        printf("Player %d's checksum is %d\n", i + 1, players[i].checksum);
    }

    int choice, player_index;
    while (1) {
        printf("Choose an option:\n");
        printf("1. Add a player\n");
        printf("2. Remove a player\n");
        printf("3. Display scores\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_players >= MAX_PLAYERS) {
                    printf("Maximum number of players reached.\n");
                } else {
                    printf("Enter player name: ");
                    scanf("%s", players[num_players].name);
                    players[num_players].score = 0;
                    generate_checksum(&players[num_players]);
                    num_players++;
                    printf("Player %d added.\n", num_players);
                }
                break;
            case 2:
                printf("Enter player index to remove: ");
                scanf("%d", &player_index);
                if (player_index >= 0 && player_index < num_players) {
                    num_players--;
                    printf("Player %d removed.\n", player_index + 1);
                } else {
                    printf("Invalid player index.\n");
                }
                break;
            case 3:
                printf("Scores:\n");
                for (i = 0; i < num_players; i++) {
                    printf("%s: %d\n", players[i].name, players[i].score);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}