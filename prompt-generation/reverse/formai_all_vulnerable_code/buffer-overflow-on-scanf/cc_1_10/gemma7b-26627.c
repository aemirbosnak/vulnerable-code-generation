//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_Players 4

typedef struct Player {
    char name[20];
    int units;
    int convertedUnits;
} Player;

void calculateConvertedUnits(Player *player) {
    switch (player->units) {
        case 1:
            player->convertedUnits = 10;
            break;
        case 2:
            player->convertedUnits = 20;
            break;
        case 3:
            player->convertedUnits = 30;
            break;
        default:
            printf("Error: Invalid units.\n");
            exit(1);
    }
}

void displayConvertedUnits(Player *player) {
    printf("%s has converted %d units to %d converted units.\n", player->name, player->units, player->convertedUnits);
}

int main() {
    Player players[MAX_Players];

    // Initialize players
    for (int i = 0; i < MAX_Players; i++) {
        players[i].name[0] = '\0';
        players[i].units = 0;
        players[i].convertedUnits = 0;
    }

    // Get player information
    for (int i = 0; i < MAX_Players; i++) {
        printf("Enter your name: ");
        scanf("%s", players[i].name);

        printf("Enter the number of units you want to convert: ");
        scanf("%d", &players[i].units);

        calculateConvertedUnits(&players[i]);

        displayConvertedUnits(&players[i]);
    }

    return 0;
}