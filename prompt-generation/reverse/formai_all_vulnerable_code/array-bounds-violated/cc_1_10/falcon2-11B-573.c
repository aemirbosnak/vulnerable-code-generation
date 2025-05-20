//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_maze(int height, int width) {
    // initialize the maze
    int maze[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze[i][j] = 0;
        }
    }

    // generate the walls
    srand(time(NULL));
    for (int i = 0; i < height - 1; i++) {
        for (int j = 0; j < width - 1; j++) {
            int r = rand() % 2;
            if (r == 0) {
                maze[i][j] = 1;
            }
        }
    }

    // generate the path
    int start = rand() % width;
    int end = rand() % width;
    int path[width * height];
    int i = 0;
    for (int j = 0; j < height; j++) {
        if (maze[j][start] == 0) {
            path[i] = start;
            start++;
        } else if (j == height - 1) {
            path[i] = end;
            break;
        }
        if (maze[j][end] == 0) {
            path[i] = end;
            end++;
        } else if (j == height - 1) {
            path[i] = start;
            break;
        }
        i++;
    }

    // print the maze
    printf("Maze\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (maze[i][j] == 1) {
                printf("X");
            } else if (j == path[i]) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int height = 10;
    int width = 10;
    generate_maze(height, width);
    return 0;
}