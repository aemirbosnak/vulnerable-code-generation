//Falcon2-11B DATASET v1.0 Category: Maze Route Finder ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 50
#define MOVE_SIZE 3

typedef struct {
    char direction[MOVE_SIZE];
    int move_count;
    bool found;
} maze_t;

int main() {
    maze_t maze = {.direction = {'N', 'N', 'N'},.move_count = 0,.found = false };

    char directions[][MOVE_SIZE] = { "N", "E", "S", "W" };

    maze.found = false;
    maze.move_count = 0;

    for (int i = 0; i < MOVE_SIZE; i++) {
        maze.direction[i] = directions[i % 4];
    }

    int x = 0;
    int y = 0;
    int maze_size = MAX_SIZE;
    int end_x = 0;
    int end_y = 0;

    while (!maze.found) {
        for (int i = 0; i < maze_size; i++) {
            for (int j = 0; j < maze_size; j++) {
                if (i == x && j == y) {
                    continue;
                }
                printf("%c", maze.direction[maze.move_count]);
                maze.move_count++;
                if (i == end_x && j == end_y) {
                    maze.found = true;
                    break;
                }
                printf(" ");
            }
            printf("\n");
            maze.move_count = 0;
        }

        for (int k = 0; k < MOVE_SIZE; k++) {
            maze.direction[k] = directions[k % 4];
        }

        switch (maze.direction[maze.move_count]) {
            case 'N':
                y--;
                break;
            case 'E':
                x++;
                break;
            case 'S':
                y++;
                break;
            case 'W':
                x--;
                break;
        }
    }

    return 0;
}