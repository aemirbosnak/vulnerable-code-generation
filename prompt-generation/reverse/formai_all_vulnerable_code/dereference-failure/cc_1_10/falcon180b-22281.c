//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_ROOMS 100
#define MAX_ROWS 20
#define MAX_COLS 30
#define WALL '#'
#define FLOOR '.'
#define DOOR '+'
#define EXIT 'X'
#define ENEMY 'E'
#define PLAYER '@'
#define TREASURE '$'

typedef struct {
    int x, y;
} Vector;

typedef struct {
    char symbol;
    int color;
} Cell;

typedef struct {
    Cell **cells;
    int rows, cols;
} Map;

void generate_map(Map *map) {
    int i, j;
    for (i = 0; i < map->rows; i++) {
        for (j = 0; j < map->cols; j++) {
            map->cells[i][j] = (Cell) {WALL, 0};
        }
    }
    map->cells[0][0] = (Cell) {PLAYER, 1};
    map->cells[map->rows - 1][map->cols - 1] = (Cell) {EXIT, 2};
}

void print_map(Map *map) {
    int i, j;
    for (i = 0; i < map->rows; i++) {
        for (j = 0; j < map->cols; j++) {
            printf("%c", map->cells[i][j].symbol);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    Map map;
    map.rows = rand() % MAX_ROWS + 1;
    map.cols = rand() % MAX_COLS + 1;
    map.cells = (Cell **)malloc(map.rows * sizeof(Cell *));
    for (int i = 0; i < map.rows; i++) {
        map.cells[i] = (Cell *)malloc(map.cols * sizeof(Cell));
    }
    generate_map(&map);
    print_map(&map);
    return 0;
}