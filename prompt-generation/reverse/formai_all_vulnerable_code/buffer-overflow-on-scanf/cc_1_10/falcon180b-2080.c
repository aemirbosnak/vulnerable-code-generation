//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_COLOR_CODE_LENGTH 7

typedef struct Player {
    char name[20];
    int score;
} Player;

void initializePlayers(Player players[]) {
    int i;
    for (i = 0; i < MAX_PLAYERS; i++) {
        strcpy(players[i].name, "Player");
        players[i].score = 0;
    }
}

int main() {
    int numPlayers;
    char input[50];
    Player players[MAX_PLAYERS];
    int i, j;

    printf("Enter number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);

    if (numPlayers > MAX_PLAYERS) {
        printf("Error: Too many players.\n");
        return 1;
    }

    initializePlayers(players);

    printf("Enter player names:\n");
    for (i = 0; i < numPlayers; i++) {
        printf("Player %d name: ", i+1);
        scanf("%s", players[i].name);
    }

    while (1) {
        printf("Enter a color code (max %d characters): ", MAX_COLOR_CODE_LENGTH);
        scanf("%s", input);

        int colorCodeLength = strlen(input);
        if (colorCodeLength > MAX_COLOR_CODE_LENGTH) {
            printf("Error: Color code too long.\n");
            continue;
        }

        int red, green, blue;
        if (sscanf(input, "#%02x%02x%02x", &red, &green, &blue)!= 3) {
            printf("Error: Invalid color code.\n");
            continue;
        }

        printf("Color code entered by %s: #%02x%02x%02x\n", players[0].name, red, green, blue);

        int winner = 0;
        for (i = 1; i < numPlayers; i++) {
            if (players[i].score > players[winner].score) {
                winner = i;
            }
        }

        players[winner].score++;

        if (players[winner].score >= numPlayers - 1) {
            printf("Player %s wins!\n", players[winner].name);
            break;
        }
    }

    return 0;
}