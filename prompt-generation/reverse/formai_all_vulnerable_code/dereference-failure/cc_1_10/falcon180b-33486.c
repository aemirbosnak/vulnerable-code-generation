//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: romantic
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
    Point position;
    int health;
    int attack;
} Enemy;

typedef struct {
    Point position;
    int health;
    int attack;
    int defense;
} Player;

void generate_map(int width, int height, char **map) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            map[i][j] = rand() % 2? '.' : '#';
        }
    }
}

int main() {
    srand(time(NULL));

    int width = 20;
    int height = 10;

    char **map = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        map[i] = malloc(width * sizeof(char));
    }

    generate_map(width, height, map);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}