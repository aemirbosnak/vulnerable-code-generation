//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} Point;

void generate_map(char map[100][100], int width, int height) {
    int i, j;
    for (i = 0; i < height; ++i) {
        for (j = 0; j < width; ++j) {
            map[i][j] = rand() % 2 == 0? '.' : '#';
        }
    }
}

int main() {
    srand(time(0));
    int width, height;
    printf("Enter the width and height of the map: ");
    scanf("%d %d", &width, &height);

    char map[100][100];
    generate_map(map, width, height);

    Point player = {0, 0};
    while (1) {
        system("clear");
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                printf("%c", map[i][j]);
            }
            printf("\n");
        }

        char command;
        scanf(" %c", &command);

        switch (command) {
            case 'w':
                player.y -= 1;
                break;
            case's':
                player.y += 1;
                break;
            case 'a':
                player.x -= 1;
                break;
            case 'd':
                player.x += 1;
                break;
            default:
                continue;
        }

        if (map[player.y][player.x] == '#') {
            printf("You hit a wall!\n");
            continue;
        }

        map[player.y][player.x] = '@';
    }

    return 0;
}