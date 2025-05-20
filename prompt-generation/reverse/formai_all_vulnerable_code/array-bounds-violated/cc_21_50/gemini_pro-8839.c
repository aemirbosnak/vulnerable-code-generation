//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point start;
    Point end;
} Path;

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Define the maze dimensions
    int width = 20;
    int height = 20;

    // Create the maze
    char maze[width][height];
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            maze[i][j] = '#';
        }
    }

    // Create the starting and ending points
    Point start = {0, 0};
    Point end = {width - 1, height - 1};

    // Create the path
    Path path = {start, end};

    // Generate the maze
    while (path.start.x != path.end.x || path.start.y != path.end.y) {
        // Get the current position
        int x = path.start.x;
        int y = path.start.y;

        // Get the possible directions
        int directions[4] = {0, 1, 2, 3};
        for (int i = 0; i < 4; i++) {
            int direction = directions[i];

            // Check if the direction is valid
            bool valid = false;
            switch (direction) {
                case 0:
                    valid = (x - 1 >= 0 && maze[x - 1][y] == '#');
                    break;
                case 1:
                    valid = (y + 1 < height && maze[x][y + 1] == '#');
                    break;
                case 2:
                    valid = (x + 1 < width && maze[x + 1][y] == '#');
                    break;
                case 3:
                    valid = (y - 1 >= 0 && maze[x][y - 1] == '#');
                    break;
            }

            // If the direction is valid, add it to the list of possible directions
            if (valid) {
                directions[i] = direction;
            }
        }

        // Choose a random direction
        int direction = directions[rand() % 4];

        // Move in the chosen direction
        switch (direction) {
            case 0:
                path.start.x--;
                break;
            case 1:
                path.start.y++;
                break;
            case 2:
                path.start.x++;
                break;
            case 3:
                path.start.y--;
                break;
        }

        // Mark the cell as visited
        maze[x][y] = '.';
    }

    // Print the maze
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}