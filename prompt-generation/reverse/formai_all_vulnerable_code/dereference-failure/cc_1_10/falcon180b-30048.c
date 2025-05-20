//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    char ch;
    int color;
} Cell;

typedef struct {
    Cell **cells;
    int width, height;
} Map;

int randint(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generate_map(Map *map) {
    int i, j;
    for (i = 0; i < map->height; ++i) {
        for (j = 0; j < map->width; ++j) {
            map->cells[i][j] = (Cell){' ', randint(0, 7)};
        }
    }
}

void print_map(Map *map) {
    int i, j;
    for (i = 0; i < map->height; ++i) {
        for (j = 0; j < map->width; ++j) {
            printf("%c", map->cells[i][j].ch);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    Map map = {0};
    map.width = 80;
    map.height = 25;
    map.cells = calloc(map.height, sizeof(Cell *));
    for (int i = 0; i < map.height; ++i) {
        map.cells[i] = calloc(map.width, sizeof(Cell));
    }
    generate_map(&map);
    print_map(&map);
    return 0;
}