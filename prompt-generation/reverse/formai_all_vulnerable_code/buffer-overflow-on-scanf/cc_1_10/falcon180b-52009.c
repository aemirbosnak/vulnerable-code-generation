//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 5
#define MAX_DISK_SPACE 1000000000

typedef struct Player {
    char name[20];
    int score;
} Player;

void init_player(Player *player, char *name) {
    strcpy(player->name, name);
    player->score = 0;
}

void print_player(Player player) {
    printf("%s: %d\n", player.name, player.score);
}

int main() {
    int num_players;
    char input[100];
    Player players[MAX_PLAYERS];

    printf("Enter the number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", input);
        init_player(&players[i], input);
    }

    int round = 1;
    while (round <= MAX_ROUNDS) {
        for (int i = 0; i < num_players; i++) {
            printf("Round %d for %s:\n", round, players[i].name);
            char choice;
            int disk_space = rand() % MAX_DISK_SPACE;

            while (disk_space <= 0) {
                disk_space = rand() % MAX_DISK_SPACE;
            }

            printf("You have %d bytes of disk space.\n", disk_space);
            printf("What would you like to do? ");
            scanf(" %c", &choice);

            switch (tolower(choice)) {
                case 'c':
                    printf("Creating a file...\n");
                    disk_space -= 100;
                    break;
                case 'd':
                    printf("Deleting a file...\n");
                    disk_space += 50;
                    break;
                case'm':
                    printf("Moving a file...\n");
                    disk_space -= 50;
                    break;
                case 'r':
                    printf("Renaming a file...\n");
                    disk_space -= 25;
                    break;
                default:
                    printf("Invalid choice.\n");
                    break;
            }

            players[i].score += disk_space;
        }

        round++;
    }

    for (int i = 0; i < num_players; i++) {
        print_player(players[i]);
    }

    return 0;
}