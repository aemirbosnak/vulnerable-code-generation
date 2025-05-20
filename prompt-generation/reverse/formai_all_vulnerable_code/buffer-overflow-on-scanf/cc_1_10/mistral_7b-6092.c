//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 20

struct player {
    char name[MAX_NAME_LENGTH];
    char str[MAX_NAME_LENGTH];
};

int main() {
    struct player players[MAX_PLAYERS];
    int num_players, i, j, len;
    char temp[MAX_NAME_LENGTH];

    printf("Welcome to the String Manipulation Game!\n");
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    if (num_players > MAX_PLAYERS) {
        printf("Sorry, maximum number of players is %d.\n", MAX_PLAYERS);
        return 1;
    }

    printf("Enter the names of the players:\n");

    for (i = 0; i < num_players; i++) {
        scanf("%s", players[i].name);
        strcpy(players[i].str, players[i].name);
    }

    printf("Here are the original strings:\n");

    for (i = 0; i < num_players; i++) {
        printf("Player %s: %s\n", players[i].name, players[i].str);
    }

    printf("\nNow, let's manipulate the strings!\n");

    for (i = 0; i < num_players; i++) {
        for (j = i + 1; j < num_players; j++) {
            if (strlen(players[i].str) > strlen(players[j].str)) {
                strcpy(temp, players[i].str);
                strcpy(players[i].str, players[j].str);
                strcpy(players[j].str, temp);
                printf("Player %s and Player %s strings were swapped.\n",
                       players[i].name, players[j].name);
            }
        }
    }

    printf("\nAnd here are the manipulated strings:\n");

    for (i = 0; i < num_players; i++) {
        printf("Player %s: %s\n", players[i].name, players[i].str);
    }

    return 0;
}