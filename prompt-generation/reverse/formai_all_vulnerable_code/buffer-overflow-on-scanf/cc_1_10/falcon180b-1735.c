//Falcon-180B DATASET v1.0 Category: Procedurally Generated Maze ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

void generateMaze(char maze[10][10], int startX, int startY) {
    int width = 10;
    int height = 10;
    int x, y;
    Point entrance = {startX, startY};

    srand(time(NULL));

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            maze[y][x] = rand() % 2? '.' : '#';
        }
    }

    while (1) {
        int count = 0;
        Point current = entrance;

        while (count < 1000 && current.x < width - 1 && current.y < height - 1) {
            int dx = rand() % 3 - 1;
            int dy = rand() % 3 - 1;

            if (dx == 0 && dy == 0)
                continue;

            int nx = current.x + dx;
            int ny = current.y + dy;

            if (maze[ny][nx] == '#') {
                maze[current.y][current.x] = '.';
                current.x = nx;
                current.y = ny;
            } else {
                maze[ny][nx] = '#';
                current.x = nx;
                current.y = ny;
            }

            count++;
        }

        if (count >= 1000)
            break;
    }
}

void printMaze(char maze[10][10]) {
    int i, j;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char maze[10][10];
    int startX, startY;

    printf("Enter the starting point (x y): ");
    scanf("%d %d", &startX, &startY);

    generateMaze(maze, startX, startY);
    printMaze(maze);

    return 0;
}