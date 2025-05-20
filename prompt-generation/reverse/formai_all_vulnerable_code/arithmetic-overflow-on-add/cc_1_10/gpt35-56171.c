//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

// Define the size of maze and initial position of the robot
#define ROW 10
#define COL 10
int posX = 1, posY = 1;

// Define a struct to represent each cell in the maze
struct Cell {
    int x, y;
    int distance;
    int visited;
    struct Cell* parent;
};

// Define a function to create a new cell with given coordinates and parent
struct Cell* newCell(int x, int y, struct Cell* parent) {
    struct Cell* cell = (struct Cell*) malloc(sizeof(struct Cell));
    cell->x = x;
    cell->y = y;
    cell->distance = 0;
    cell->visited = 0;
    cell->parent = parent;
    return cell;
}

// Define a function to check if given coordinates are valid
int isValidCell(int x, int y) {
    return (x >= 0 && x < ROW && y >= 0 && y < COL);
}

// Define a function to find the shortest path between two cells in the maze
struct Cell* findPath(int maze[][COL], int startX, int startY, int endX, int endY) {
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    struct Cell* startCell = newCell(startX, startY, NULL);
    startCell->visited = 1;

    struct Cell* queue[ROW*COL];
    int front = 0, rear = 0;
    queue[rear++] = startCell;

    while (front != rear) {
        struct Cell* curr = queue[front++];

        if (curr->x == endX && curr->y == endY) {
            return curr;
        }

        for (int i = 0; i < 4; i++) {
            int nextX = curr->x + dx[i];
            int nextY = curr->y + dy[i];

            if (isValidCell(nextX, nextY) && maze[nextX][nextY] == 0) {
                struct Cell* nextCell = newCell(nextX, nextY, curr);
                nextCell->distance = curr->distance + 1;
                nextCell->visited = 1;
                queue[rear++] = nextCell;
            }
        }
    }

    return NULL;
}

// Define a function to print the shortest path found by the algorithm
void printPath(struct Cell* endCell) {
    if (endCell == NULL) {
        printf("No path found.\n");
        return;
    }

    int pathLength = endCell->distance;
    struct Cell* path[pathLength];
    struct Cell* curr = endCell;

    for (int i = 0; i < pathLength; i++) {
        path[i] = curr;
        curr = curr->parent;
    }

    printf("Shortest path:\n");
    for (int i = pathLength-1; i >= 0; i--) {
        printf("(%d, %d) -> ", path[i]->x, path[i]->y);
    }

    printf("Arrived at the destination (%d, %d) successfully!\n", endCell->x, endCell->y);
}

// Define the main function
int main() {

    int maze[ROW][COL] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
        {0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 0, 1, 1, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 1, 1, 0, 0, 0, 1, 1, 0},
        {0, 1, 0, 1, 1, 1, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    int startX = 1, startY = 1;
    int endX = 8, endY = 8;

    // Find the shortest path between start and end
    struct Cell* endCell = findPath(maze, startX, startY, endX, endY);

    // Print the path
    printPath(endCell);

    return 0;

}