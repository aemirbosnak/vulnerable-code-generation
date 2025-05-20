//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point start;
    Point end;
} Line;

typedef struct {
    int x;
    int y;
    char symbol;
    int color;
} Cell;

Cell *generateMap(int width, int height) {
    Cell *map = (Cell *) malloc(width * height * sizeof(Cell));
    if (map == NULL) {
        printf("Error: Failed to allocate memory for the map.\n");
        exit(1);
    }

    srand(time(NULL));

    for (int i = 0; i < width * height; i++) {
        map[i].x = rand() % width;
        map[i].y = rand() % height;
        map[i].symbol = rand() % 10 + '0';
        map[i].color = rand() % 7;
    }

    return map;
}

void printMap(Cell *map, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        printf("%c", map[i].symbol);
        printf("\033[38;5;%dm ", map[i].color);
    }
}

int main() {
    int width, height;

    printf("Enter the width of the map: ");
    scanf("%d", &width);

    printf("Enter the height of the map: ");
    scanf("%d", &height);

    Cell *map = generateMap(width, height);
    printMap(map, width, height);

    free(map);

    return 0;
}