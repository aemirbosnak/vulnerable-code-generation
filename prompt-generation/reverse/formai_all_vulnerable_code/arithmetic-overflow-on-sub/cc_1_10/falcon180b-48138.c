//Falcon-180B DATASET v1.0 Category: Memory management ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

void initPlayers(Player players[MAX_PLAYERS]) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        strcpy(players[i].name, "Player ");
        sprintf(&players[i].name[7], "%d", i + 1);
        players[i].score = 0;
    }
}

void printPlayers(Player players[MAX_PLAYERS]) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    initPlayers(players);

    int numPlayers;
    printf("Enter the number of players (1-10): ");
    scanf("%d", &numPlayers);

    while (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Enter the number of players (1-10): ");
        scanf("%d", &numPlayers);
    }

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf(" %s", players[i].name);
    }

    int choice;
    do {
        printf("\nChoose an option:\n");
        printf("1. Print scores\n");
        printf("2. Add points to a player\n");
        printf("3. Subtract points from a player\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printPlayers(players);
                break;
            case 2:
                printf("Enter the player ID to add points: ");
                int playerId;
                scanf("%d", &playerId);
                printf("Enter the number of points to add: ");
                int points;
                scanf("%d", &points);
                players[playerId - 1].score += points;
                break;
            case 3:
                printf("Enter the player ID to subtract points: ");
                int playerId2;
                scanf("%d", &playerId2);
                printf("Enter the number of points to subtract: ");
                int points2;
                scanf("%d", &points2);
                players[playerId2 - 1].score -= points2;
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice!= 4);

    return 0;
}