//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 25
#define MAX_ROOMS 50
#define MAX_ENEMIES 50
#define MAX_ITEMS 50

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point top_left;
    Point bottom_right;
} Rectangle;

typedef enum {
    WALL,
    FLOOR,
    DOOR,
    ITEM,
    ENEMY
} Tile;

Tile map[HEIGHT][WIDTH];

void generate_map() {
    int num_rooms = rand() % MAX_ROOMS + 1;
    for (int i = 0; i < num_rooms; i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        int w = rand() % 10 + 4;
        int h = rand() % 10 + 4;
        for (int j = x; j < x + w; j++) {
            for (int k = y; k < y + h; k++) {
                map[k][j] = FLOOR;
            }
        }
    }

    for (int i = 0; i < MAX_ENEMIES; i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        while (map[y][x]!= FLOOR) {
            x = rand() % WIDTH;
            y = rand() % HEIGHT;
        }
        map[y][x] = ENEMY;
    }

    for (int i = 0; i < MAX_ITEMS; i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        while (map[y][x]!= FLOOR) {
            x = rand() % WIDTH;
            y = rand() % HEIGHT;
        }
        map[y][x] = ITEM;
    }
}

void print_map() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            switch (map[i][j]) {
                case WALL:
                    printf("#");
                    break;
                case FLOOR:
                    printf(".");
                    break;
                case DOOR:
                    printf("+");
                    break;
                case ITEM:
                    printf("*");
                    break;
                case ENEMY:
                    printf("E");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    generate_map();
    print_map();

    return 0;
}