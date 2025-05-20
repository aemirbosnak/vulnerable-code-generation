//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 10
#define MAX_USERNAME_LEN 20
#define MAX_DISK_SPACE 1000 //in MB

typedef struct player {
    char username[MAX_USERNAME_LEN];
    int disk_space;
} Player;

Player players[MAX_PLAYERS];
int num_players = 0;

void init_game() {
    for (int i = 0; i < MAX_PLAYERS; ++i) {
        strcpy(players[i].username, "");
        players[i].disk_space = 0;
    }
    num_players = 0;
}

void add_player() {
    if (num_players >= MAX_PLAYERS) {
        printf("No more players can join.\n");
        return;
    }

    printf("Enter your username (max %d characters): ", MAX_USERNAME_LEN-1);
    scanf("%s", players[num_players].username);

    printf("Enter your disk space in MB: ");
    scanf("%d", &players[num_players].disk_space);

    ++num_players;
}

void print_players() {
    printf("Players:\n");
    for (int i = 0; i < num_players; ++i) {
        printf("#%d %s (%d MB)\n", i+1, players[i].username, players[i].disk_space);
    }
}

int compare_disk_space(const void *a, const void *b) {
    Player *player1 = (Player *)a;
    Player *player2 = (Player *)b;

    if (player1->disk_space > player2->disk_space) {
        return -1;
    } else if (player1->disk_space < player2->disk_space) {
        return 1;
    } else {
        return 0;
    }
}

void sort_players_by_disk_space() {
    qsort(players, num_players, sizeof(Player), compare_disk_space);
}

int main() {
    init_game();

    int choice;
    do {
        printf("1. Add player\n2. Print players\n3. Sort players by disk space\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_player();
            break;
        case 2:
            print_players();
            break;
        case 3:
            sort_players_by_disk_space();
            print_players();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}