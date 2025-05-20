//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

char maze[HEIGHT][WIDTH];

int main()
{
    srand(time(NULL));

    // Generate maze
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            maze[i][j] = (rand() % 2 == 0) ? ' ' : '#';
        }
    }

    // Print maze
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }

    // Find route through maze
    int x = 0, y = 0;
    while (x != WIDTH - 1 || y != HEIGHT - 1) {
        // Check if we can move right
        if (maze[y][x + 1] == ' ') {
            x++;
        }
        // Check if we can move down
        else if (maze[y + 1][x] == ' ') {
            y++;
        }
        // Check if we can move left
        else if (maze[y][x - 1] == ' ') {
            x--;
        }
        // Check if we can move up
        else if (maze[y - 1][x] == ' ') {
            y--;
        }
        // If we can't move in any direction, we're stuck
        else {
            printf("No route found.\n");
            return 1;
        }
    }

    // Print route through maze
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == y && j == x) {
                printf("X");
            } else {
                printf("%c", maze[i][j]);
            }
        }
        printf("\n");
    }

    printf("Route found!\n");
    return 0;
}