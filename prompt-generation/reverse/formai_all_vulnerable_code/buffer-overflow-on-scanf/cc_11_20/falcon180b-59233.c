//Falcon-180B DATASET v1.0 Category: Memory management ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LEN 20
#define MAX_SCORE 100

typedef struct player {
    char name[MAX_NAME_LEN];
    int score;
} player_t;

int main() {
    int num_players;
    player_t players[MAX_PLAYERS];
    int i, j, choice;

    printf("Enter the number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    for (i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    while (1) {
        printf("\nCurrent scores:\n");
        for (i = 0; i < num_players; i++) {
            printf("%d. %s - %d\n", i+1, players[i].name, players[i].score);
        }

        printf("\nChoose an option:\n");
        printf("1. Add a player\n2. Remove a player\n3. Update a player's score\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_players >= MAX_PLAYERS) {
                printf("Maximum number of players reached.\n");
            } else {
                printf("Enter player %d's name: ", num_players+1);
                scanf("%s", players[num_players].name);
                players[num_players].score = 0;
                num_players++;
            }
            break;
        case 2:
            printf("Enter the player number to remove: ");
            scanf("%d", &i);
            if (i >= 0 && i < num_players) {
                for (j = i; j < num_players-1; j++) {
                    strcpy(players[j].name, players[j+1].name);
                    players[j].score = players[j+1].score;
                }
                num_players--;
            } else {
                printf("Invalid player number.\n");
            }
            break;
        case 3:
            printf("Enter the player number to update: ");
            scanf("%d", &i);
            if (i >= 0 && i < num_players) {
                printf("Enter the new score: ");
                scanf("%d", &players[i].score);
            } else {
                printf("Invalid player number.\n");
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}