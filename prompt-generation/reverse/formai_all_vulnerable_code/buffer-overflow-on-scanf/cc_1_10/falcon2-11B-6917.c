//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random maze
void generateMaze(int width, int height, int * maze) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            maze[i * width + j] = 0;
        }
    }

    srand(time(NULL));
    int r, c;
    for (r = 0; r < height; r++) {
        for (c = 0; c < width; c++) {
            if (r == 0 || r == height - 1 || c == 0 || c == width - 1) {
                maze[r * width + c] = 1;
            } else {
                maze[r * width + c] = rand() % 2;
            }
        }
    }
}

// Function to navigate the maze
void navigateMaze(int width, int height, int * maze, int * x, int * y) {
    int i, j;
    int visited[width * height];
    int count = 0;

    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            visited[i * width + j] = 0;
        }
    }

    visited[0 * width + 0] = 1;
    count++;

    while (count < width * height) {
        int nextX, nextY;
        int nextI, nextJ;

        // Check if current cell is visited
        if (visited[(*x) * width + (*y)] == 1) {
            printf("You have already visited this cell!\n");
            break;
        }

        // Check if current cell is a wall
        if (maze[(*x) * width + (*y)] == 1) {
            printf("You cannot move through this wall!\n");
            break;
        }

        // Check if current cell is the goal
        if (maze[(*x) * width + (*y)] == 2) {
            printf("Congratulations, you have reached the goal!\n");
            break;
        }

        // Check if current cell is an open path
        nextI = (*x);
        nextJ = (*y);
        if (nextI > 0) {
            if (maze[nextI * width + nextJ] == 0) {
                nextX = nextI - 1;
                nextY = nextJ;
            } else if (maze[nextI * width + nextJ] == 1) {
                nextX = nextI + 1;
                nextY = nextJ;
            }
        } else {
            nextI = (*x);
            nextJ = (*y);
            if (nextI < width - 1) {
                if (maze[nextI * width + nextJ] == 0) {
                    nextX = nextI + 1;
                    nextY = nextJ;
                } else if (maze[nextI * width + nextJ] == 1) {
                    nextX = nextI - 1;
                    nextY = nextJ;
                }
            } else {
                nextI = (*x);
                nextJ = (*y);
                if (nextJ > 0) {
                    if (maze[nextI * width + nextJ] == 0) {
                        nextX = nextI;
                        nextY = nextJ - 1;
                    } else if (maze[nextI * width + nextJ] == 1) {
                        nextX = nextI;
                        nextY = nextJ + 1;
                    }
                } else {
                    nextI = (*x);
                    nextJ = (*y);
                    if (nextJ < height - 1) {
                        if (maze[nextI * width + nextJ] == 0) {
                            nextX = nextI;
                            nextY = nextJ + 1;
                        } else if (maze[nextI * width + nextJ] == 1) {
                            nextX = nextI;
                            nextY = nextJ - 1;
                        }
                    }
                }
            }

            // Check if next cell is visited
            if (visited[nextI * width + nextJ] == 1) {
                printf("You cannot move through this wall!\n");
                break;
            }

            // Check if next cell is the goal
            if (maze[nextI * width + nextJ] == 2) {
                printf("Congratulations, you have reached the goal!\n");
                break;
            }

            // Check if next cell is an open path
            if (maze[nextI * width + nextJ] == 0) {
                visited[nextI * width + nextJ] = 1;
                count++;
                (*x) = nextX;
                (*y) = nextY;
            }
        }
    }
}

// Function to initialize the game
void initializeGame() {
    int width, height;
    int maze[width * height];
    int x, y;

    // Prompt user for maze size
    printf("Enter the width of the maze: ");
    scanf("%d", &width);
    printf("Enter the height of the maze: ");
    scanf("%d", &height);

    // Generate random maze
    generateMaze(width, height, maze);

    // Prompt user for starting position
    printf("Enter the starting position (x, y): ");
    scanf("%d%d", &x, &y);

    // Start navigating the maze
    navigateMaze(width, height, maze, &x, &y);
}

int main() {
    initializeGame();
    return 0;
}