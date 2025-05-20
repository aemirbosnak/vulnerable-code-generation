//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    int width, height;
    char **tiles;
} Map;

void init_map(Map *map, int width, int height) {
    map->width = width;
    map->height = height;
    map->tiles = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        map->tiles[i] = malloc(width * sizeof(char));
        for (int j = 0; j < width; j++) {
            map->tiles[i][j] = '.';
        }
    }
}

void free_map(Map *map) {
    for (int i = 0; i < map->height; i++) {
        free(map->tiles[i]);
    }
    free(map->tiles);
}

void print_map(Map *map) {
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            printf("%c", map->tiles[i][j]);
        }
        printf("\n");
    }
}

int in_bounds(int x, int y, int width, int height) {
    return x >= 0 && x < width && y >= 0 && y < height;
}

void generate_map(Map *map) {
    srand(time(NULL));
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            if (rand() % 2) {
                map->tiles[i][j] = '#';
            } else {
                map->tiles[i][j] = '.';
            }
        }
    }
}

int main() {
    Map map;
    init_map(&map, 80, 24);
    generate_map(&map);
    print_map(&map);
    free_map(&map);
    return 0;
}