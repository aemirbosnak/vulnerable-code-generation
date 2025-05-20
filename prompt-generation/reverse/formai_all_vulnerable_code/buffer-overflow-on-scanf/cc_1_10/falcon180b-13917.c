//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20
#define MAX_MESSAGE_LENGTH 80

typedef struct {
    char name[MAX_NAME_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} Player;

int main() {
    int numPlayers;
    char input[MAX_MESSAGE_LENGTH];
    Player players[MAX_PLAYERS];
    int i;

    printf("How many players are there? ");
    scanf("%d", &numPlayers);

    for (i = 0; i < numPlayers; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        strcpy(players[i].message, "");
    }

    while (1) {
        printf("\n");
        for (i = 0; i < numPlayers; i++) {
            printf("Player %d: %s\n", i + 1, players[i].message);
        }

        printf("Enter your message: ");
        scanf("%s", input);

        if (strlen(input) == 0) {
            continue;
        }

        for (i = 0; i < numPlayers; i++) {
            if (strcmp(players[i].name, input) == 0) {
                strcat(players[i].message, " ");
                strcat(players[i].message, input);
                strcat(players[i].message, ": ");
                strcat(players[i].message, &input[strlen(input)]);
                strcat(players[i].message, "\n");
                break;
            }
        }
    }

    return 0;
}