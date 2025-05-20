//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: post-apocalyptic
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
            if (rand() % 2 == 0) {
                map[i][j] = '.';
            } else {
                map[i][j] = '#';
            }
        }
    }
}

int count_survivors(char **map, int width, int height, Point start) {
    int count = 0;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};

    for (int i = 0; i < 4; i++) {
        int nx = start.x + dx[i];
        int ny = start.y + dy[i];

        if (nx >= 0 && nx < width && ny >= 0 && ny < height && map[ny][nx] == '.') {
            count++;
        }
    }

    return count;
}

void print_map(char **map, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int width, height;
    printf("Enter the width and height of the map: ");
    scanf("%d %d", &width, &height);

    char **map = (char **)malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        map[i] = (char *)malloc(width * sizeof(char));
    }

    generate_map(width, height, map);

    Point start;
    printf("Enter the starting position (x y): ");
    scanf("%d %d", &start.x, &start.y);

    int survivors = count_survivors(map, width, height, start);

    printf("There are %d survivors within a 2-block radius.\n", survivors);

    print_map(map, width, height);

    for (int i = 0; i < height; i++) {
        free(map[i]);
    }
    free(map);

    return 0;
}