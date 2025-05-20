#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Game {
    char *name;
    char *description;
    int players;
} Game;

Game* createGame(char *name, char *desc, int numPlayers) {
    Game *newGame = (Game *) malloc(sizeof(Game));
    newGame->name = strdup(name);
    newGame->description = strdup(desc);
    newGame->players = numPlayers;
    return newGame;
}

void freeGame(Game *game) {
    free(game->name);
    free(game->description);
    free(game);
}

int main() {
    Game *myGame = createGame("Test Game", "A simple text-based game", 1);
    Game *yourGame = createGame("Your Game", "Your custom game description", 2);

    printf("Your game: %s\n", yourGame->description);

    free(myGame); // Use after free vulnerability

    printf("Game created for %d player(s).\n", myGame->players); // UAF still in effect

    freeGame(yourGame);

    return 0;
}
