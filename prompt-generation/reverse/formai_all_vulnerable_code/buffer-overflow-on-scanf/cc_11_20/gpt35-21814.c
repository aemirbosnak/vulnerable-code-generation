//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WALL 1
#define PATH 0

int maze[50][50]; // Maximum maze is 50x50 for this example
int height, width; // Height and Width of X by Y maze
int startX, startY; // Starting position for the player
int endX, endY; // Ending position for the player
int visitedCount = 0; // Keeps track of the number of cells visited
int visited[50][50] = {0}; // Keeps track of cells that have already been visited

// Function to generate the maze
void generateMaze() {
    srand(time(NULL)); // Seed the random number generator with the current time
    int x, y;
    for (x = 0; x < height; x++) {
        for (y = 0; y < width; y++) {
            maze[x][y] = WALL; // Fill the maze with walls
        }
    }

    // Choose a random starting position
    startX = rand() % height;
    startY = rand() % width;
    maze[startX][startY] = PATH;

    // Choose a random ending position
    endX = rand() % height;
    endY = rand() % width;
    maze[endX][endY] = PATH;

    // Start generating paths using randomised DFS traversal
    int stackX[50];
    int stackY[50];
    int stackPointer = -1;
    stackPointer++;
    stackX[stackPointer] = startX;
    stackY[stackPointer] = startY;
    visited[startX][startY] = 1;

    while(stackPointer >= 0) {
        x = stackX[stackPointer];
        y = stackY[stackPointer];
        visitedCount++;
        if ((x == endX) && (y == endY)) {
            break; // Reached the end of the maze, we're done
        }
        // Check for available directions
        int i, dirs[4] = {0}; // Up, Down, Left, Right
        if ((x > 0) && (!visited[x-1][y])) {
            dirs[0] = 1;
        }
        if ((y > 0) && (!visited[x][y-1])) {
            dirs[1] = 1;
        } 
        if ((x < height-1) && (!visited[x+1][y])) {
            dirs[2] = 1;
        }
        if ((y < width-1) && (!visited[x][y+1])) {
            dirs[3] = 1;
        }
        // Randomly choose a direction from the available directions
        int dirPicked = 0;
        for (i = 0; i < 4; i++) {
            if (dirs[i]) {
                dirPicked++;
            }
        }
        if (dirPicked == 0) { // No available directions, backtrack
            stackPointer--;
            continue;
        }
        int dir = rand() % dirPicked;
        for (i = 0; i < 4; i++) {
            if (dirs[i]) {
                if (dir == 0) {
                    switch(i) {
                        case 0: // Up
                            maze[x-1][y] = PATH;
                            stackPointer++;
                            stackX[stackPointer] = x-1;
                            stackY[stackPointer] = y;
                            visited[x-1][y] = 1;
                            break;
                        case 1: // Down
                            maze[x][y-1] = PATH;
                            stackPointer++;
                            stackX[stackPointer] = x;
                            stackY[stackPointer] = y-1;
                            visited[x][y-1] = 1;
                            break;
                        case 2: // Left
                            maze[x+1][y] = PATH;
                            stackPointer++;
                            stackX[stackPointer] = x+1;
                            stackY[stackPointer] = y;
                            visited[x+1][y] = 1;
                            break;
                        case 3: // Right
                            maze[x][y+1] = PATH;
                            stackPointer++;
                            stackX[stackPointer] = x;
                            stackY[stackPointer] = y+1;
                            visited[x][y+1] = 1;
                            break;
                    }
                    break;
                } else {
                    dir--;
                }
            }
        }
    }
}

// Function to print the maze
void printMaze() {
    int x, y;
    for (x = 0; x < height; x++) {
        for (y = 0; y < width; y++) {
            if (maze[x][y] == WALL) {
                printf("#");
            } else if ((x == startX) && (y == startY)) {
                printf("S");
            } else if ((x == endX) && (y == endY)) {
                printf("E");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to the procedurally generated maze!\n");
    printf("Please enter the dimensions of the maze (Height Width): ");
    scanf("%d %d", &height, &width);
    while ((height < 2) || (width < 2) || (height > 50) || (width > 50)) {
        printf("Invalid dimensions, please enter again: ");
        scanf("%d %d", &height, &width);
    }
    generateMaze();
    printf("Maze generated!\n");
    printMaze();
    printf("Number of cells visited: %d\n", visitedCount);
    return 0;
}