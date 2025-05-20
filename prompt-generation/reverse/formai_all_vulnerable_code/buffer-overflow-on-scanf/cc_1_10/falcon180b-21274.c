//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} Point;

void generateMap(int **map, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            map[i][j] = rand() % 2;
        }
    }
}

int countAdjacentWalls(int **map, int x, int y) {
    int count = 0;
    if (map[y - 1][x] == 1) count++;
    if (map[y][x - 1] == 1) count++;
    if (map[y + 1][x] == 1) count++;
    if (map[y][x + 1] == 1) count++;
    return count;
}

void carvePassages(int **map, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (map[i][j] == 1 && countAdjacentWalls(map, i, j) > 1) {
                map[i][j] = 0;
            }
        }
    }
}

void printMap(int **map, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (map[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));

    int width, height;
    printf("Enter the width of the map: ");
    scanf("%d", &width);
    printf("Enter the height of the map: ");
    scanf("%d", &height);

    int **map = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        map[i] = (int *)malloc(width * sizeof(int));
    }

    generateMap(map, width, height);
    carvePassages(map, width, height);

    printf("The generated map:\n");
    printMap(map, width, height);

    for (int i = 0; i < height; i++) {
        free(map[i]);
    }
    free(map);

    return 0;
}