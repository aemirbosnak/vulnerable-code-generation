//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} Point;

void generate_map(int width, int height, char **map) {
    srand(time(NULL));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            map[i][j] = rand() % 2? '.' : '#';
        }
    }
}

void print_map(int width, int height, char **map) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int width, height;
    printf("Enter the width and height of the map (separated by a space): ");
    scanf("%d %d", &width, &height);

    char **map = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        map[i] = malloc(width * sizeof(char));
    }

    generate_map(width, height, map);
    print_map(width, height, map);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            free(map[i][j]);
        }
        free(map[i]);
    }
    free(map);

    return 0;
}