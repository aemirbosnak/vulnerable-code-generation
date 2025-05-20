//Falcon2-11B DATASET v1.0 Category: File handling ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char email[100];
} Player;

typedef struct {
    Player players[10];
    int numPlayers;
} Game;

void createGame() {
    Game game;
    game.numPlayers = 0;
    game.players[0].name[0] = '\0';
    game.players[0].age = 0;
    game.players[0].email[0] = '\0';
}

void readGame() {
    Game game;
    FILE *fp = fopen("game.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char line[100];
    fgets(line, sizeof(line), fp);
    sscanf(line, "%d", &game.numPlayers);

    for (int i = 0; i < game.numPlayers; i++) {
        fgets(line, sizeof(line), fp);
        sscanf(line, "%s %d %s", game.players[i].name, &game.players[i].age, game.players[i].email);
    }

    fclose(fp);
}

void updateGame() {
    Game game;
    FILE *fp = fopen("game.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char line[100];
    fgets(line, sizeof(line), fp);
    sscanf(line, "%d", &game.numPlayers);

    for (int i = 0; i < game.numPlayers; i++) {
        fgets(line, sizeof(line), fp);
        sscanf(line, "%s %d %s", game.players[i].name, &game.players[i].age, game.players[i].email);
    }

    fclose(fp);
}

void deleteGame() {
    Game game;
    FILE *fp = fopen("game.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    fclose(fp);
}

int main() {
    createGame();
    readGame();
    printf("Game loaded successfully!\n");

    updateGame();
    printf("Game updated successfully!\n");

    deleteGame();
    printf("Game deleted successfully!\n");

    return 0;
}