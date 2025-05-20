//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    char symbol;
    int color;
} Tile;

typedef struct {
    int width;
    int height;
    Tile* tiles;
} Map;

void generate_map(Map* map) {
    int i, j;
    srand(time(NULL));

    for (i = 0; i < map->height; i++) {
        for (j = 0; j < map->width; j++) {
            map->tiles[i * map->width + j].symbol = rand() % 2? '.' : '#';
            map->tiles[i * map->width + j].color = rand() % 7;
        }
    }
}

void print_map(Map* map) {
    int i, j;

    for (i = 0; i < map->height; i++) {
        for (j = 0; j < map->width; j++) {
            printf("\x1b[38;5;%dm%c\x1b[0m", map->tiles[i * map->width + j].color + 30, map->tiles[i * map->width + j].symbol);
        }
        printf("\n");
    }
}

int main() {
    Map map;
    map.width = 80;
    map.height = 25;
    map.tiles = malloc(map.width * map.height * sizeof(Tile));

    generate_map(&map);
    print_map(&map);

    return 0;
}