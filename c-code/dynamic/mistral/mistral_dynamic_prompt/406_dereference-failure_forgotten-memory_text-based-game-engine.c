#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct Game {
    char **entities;
    int num_entities;
} Game;

Game game;

void init() {
    game.entities = (char **) malloc(10 * sizeof(char *));
    for (int i = 0; i < 10; i++)
        game.entities[i] = (char *) malloc(20 * sizeof(char));
    game.num_entities = 0;
}

void add_entity(const char *entity) {
    game.entities[game.num_entities] = (char *) malloc(strlen(entity) * sizeof(char));
    strcpy(game.entities[game.num_entities], entity);
    game.num_entities++;
}

void update() {
    for (int i = 0; i < game.num_entities; i++) {
        printf("%s: moves\n", game.entities[i]);
        free(game.entities[i]);
    }
    free(game.entities);
    game.num_entities = 0;
}

int main() {
    init();
    add_entity("Player");
    add_entity("Enemy");
    add_entity("Treasure");

    for (int i = 0; i < 5; i++)
        update();

    return 0;
}
