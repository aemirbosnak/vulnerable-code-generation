//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 50
#define MAX_MESSAGE_LENGTH 100

struct player {
    char name[MAX_NAME_LENGTH];
    int score;
};

void sanitize_input(char *input) {
    int i, j;
    for (i = 0, j = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            input[j++] = tolower(input[i]);
        }
    }
    input[j] = '\0';
}

int main() {
    char input[100];
    int num_players, i;
    struct player players[MAX_PLAYERS];

    printf("Enter number of players (1-4): ");
    scanf("%d", &num_players);

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    for (i = 0; i < num_players; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", input);
        sanitize_input(input);
        strcpy(players[i].name, input);
        players[i].score = 0;
    }

    printf("Enter your message (max %d characters): ", MAX_MESSAGE_LENGTH - 1);
    scanf("%s", input);
    sanitize_input(input);

    printf("Player %s: %s\n", players[0].name, input);

    return 0;
}