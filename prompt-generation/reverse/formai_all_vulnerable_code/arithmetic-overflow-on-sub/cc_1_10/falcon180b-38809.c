//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} Point;

void generate_map(int width, int height, char **map) {
    Point start_point = {0, 0};
    map[0][0] = '#';
    for (int i = 1; i < height; i++) {
        map[0][i] = '#';
    }
    for (int i = 1; i < width; i++) {
        map[i][0] = '#';
    }
    Point current_point = start_point;
    while (1) {
        int direction = rand() % 4;
        switch (direction) {
            case 0:
                if (current_point.y > 0 && map[current_point.x][current_point.y - 1] == '.') {
                    map[current_point.x][current_point.y] = '.';
                    current_point.y--;
                }
                break;
            case 1:
                if (current_point.x < width - 1 && map[current_point.x + 1][current_point.y] == '.') {
                    map[current_point.x][current_point.y] = '.';
                    current_point.x++;
                }
                break;
            case 2:
                if (current_point.y < height - 1 && map[current_point.x][current_point.y + 1] == '.') {
                    map[current_point.x][current_point.y] = '.';
                    current_point.y++;
                }
                break;
            case 3:
                if (current_point.x > 0 && map[current_point.x - 1][current_point.y] == '.') {
                    map[current_point.x][current_point.y] = '.';
                    current_point.x--;
                }
                break;
        }
        if (current_point.x < 0 || current_point.x >= width || current_point.y < 0 || current_point.y >= height) {
            break;
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
    srand(time(NULL));
    int width, height;
    printf("Enter the width of the map: ");
    scanf("%d", &width);
    printf("Enter the height of the map: ");
    scanf("%d", &height);
    char **map = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        map[i] = malloc(width * sizeof(char));
    }
    generate_map(width, height, map);
    print_map(width, height, map);
    for (int i = 0; i < height; i++) {
        free(map[i]);
    }
    free(map);
    return 0;
}