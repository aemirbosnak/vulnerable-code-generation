//Falcon-180B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

void generateMaze(int width, int height, char maze[height][width]) {
    int startX = rand() % height;
    int startY = rand() % width;

    maze[startY][startX] = 'S';

    int dirX = 0;
    int dirY = -1;

    while (1) {
        Point next = {startX, startY};
        int count = 0;

        while (count < 4) {
            next.x += dirX;
            next.y += dirY;

            if (next.x < 0 || next.x >= height || next.y < 0 || next.y >= width) {
                dirX = -dirX;
                dirY = -dirY;
            } else if (maze[next.y][next.x] == '#') {
                dirX = -dirX;
                dirY = -dirY;
            } else if (maze[next.y][next.x] == 'E') {
                break;
            }

            count++;
        }

        if (count == 4) {
            break;
        }

        maze[next.y][next.x] = '.';
        startX = next.x;
        startY = next.y;
    }
}

void printMaze(char maze[100][100]) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int width, height;
    printf("Enter maze width and height: ");
    scanf("%d%d", &width, &height);

    char maze[height][width];

    generateMaze(width, height, maze);

    printf("Generated maze:\n");
    printMaze(maze);

    return 0;
}