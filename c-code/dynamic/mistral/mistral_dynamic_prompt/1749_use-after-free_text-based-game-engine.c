#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct GameMap {
    char **grid;
    int width, height;
} GameMap;

GameMap* create_map(int width, int height) {
    GameMap* map = malloc(sizeof(GameMap));
    map->width = width;
    map->height = height;
    map->grid = calloc(height, sizeof(char*));
    for (int i = 0; i < height; i++) {
        map->grid[i] = calloc(width, sizeof(char));
    }
    return map;
}

void free_map(GameMap* map) {
    for (int i = 0; i < map->height; i++) {
        free(map->grid[i]);
    }
    free(map->grid);
    free(map);
}

void print_map(GameMap* map) {
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            printf("%c ", map->grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    GameMap* gameMap = create_map(20, 20);
    // Fill the map with some data
    // ...

    // Perform some game logic and free the memory that should not be freed here
    free_map(gameMap);

    // Continue with the game or show the map
    print_map(gameMap); // UAF Vulnerability

    return 0;
}
