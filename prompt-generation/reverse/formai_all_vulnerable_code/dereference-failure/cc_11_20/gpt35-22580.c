//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define ROW 6 // Define the number of rows in the maze
#define COL 7 // Define the number of columns in the maze

int maze[ROW][COL] = { // Define the maze with 0s and 1s
    {1,1,1,1,1,1,1},
    {1,0,0,0,0,0,1},
    {1,1,1,0,1,0,1},
    {1,0,0,0,1,0,1},
    {1,0,1,1,1,0,1},
    {1,1,1,1,1,1,1}
};

typedef struct { // Define the structure for the coordinates of a point
    int row;
    int col;
} point;

point* findPath(int startX, int startY, int endX, int endY) {
    int i, j;
    int queueStart = 0;
    int queueEnd = 0;
    point* prev[ROW][COL];
    point* queue[ROW*COL];
    int visited[ROW][COL] = {0};
    point start = {startX, startY};
    point end = {endX, endY};

    queue[queueEnd++] = &start;
    visited[start.row][start.col] = 1;

    while (queueStart < queueEnd) { // Loop through the queue until the end point is found
        point* current = queue[queueStart++];
        if (current->row == end.row && current->col == end.col) { // End point has been found
            point* path = (point*) malloc(ROW*COL*sizeof(point)); // Allocate memory for the path
            int count = 0;
            while (current != NULL) { // Trace back from the end point to the start point
                path[count++] = *current;
                current = prev[current->row][current->col];
            }
            return path;
        }

        // Check all four directions and add to queue if it's a valid path
        if (current->row > 0 && maze[current->row-1][current->col] == 0 && visited[current->row-1][current->col] == 0) { // Check up
            point* newPoint = (point*) malloc(sizeof(point));
            newPoint->row = current->row-1;
            newPoint->col = current->col;
            queue[queueEnd++] = newPoint;
            prev[newPoint->row][newPoint->col] = current;
            visited[newPoint->row][newPoint->col] = 1;
        }
        if (current->row < ROW-1 && maze[current->row+1][current->col] == 0 && visited[current->row+1][current->col] == 0) { // Check down
            point* newPoint = (point*) malloc(sizeof(point));
            newPoint->row = current->row+1;
            newPoint->col = current->col;
            queue[queueEnd++] = newPoint;
            prev[newPoint->row][newPoint->col] = current;
            visited[newPoint->row][newPoint->col] = 1;
        }
        if (current->col > 0 && maze[current->row][current->col-1] == 0 && visited[current->row][current->col-1] == 0) { // Check left
            point* newPoint = (point*) malloc(sizeof(point));
            newPoint->row = current->row;
            newPoint->col = current->col-1;
            queue[queueEnd++] = newPoint;
            prev[newPoint->row][newPoint->col] = current;
            visited[newPoint->row][newPoint->col] = 1;
        }
        if (current->col < COL-1 && maze[current->row][current->col+1] == 0 && visited[current->row][current->col+1] == 0) { // Check right
            point* newPoint = (point*) malloc(sizeof(point));
            newPoint->row = current->row;
            newPoint->col = current->col+1;
            queue[queueEnd++] = newPoint;
            prev[newPoint->row][newPoint->col] = current;
            visited[newPoint->row][newPoint->col] = 1;
        }
    }

    // End point was not found, return null
    return NULL;
}

int main() {
    point* path = findPath(1, 1, 4, 5);

    if (path == NULL) {
        printf("No path found!\n");
        return 0;
    }

    printf("Path found: ");
    int i;
    for (i = 0; i < ROW*COL; i++) {
        if (path[i].row == 0 && path[i].col == 0) // End of path
            break;
        printf("(%d,%d)", path[i].row, path[i].col);
        if (i < ROW*COL-1 && path[i+1].row != 0 && path[i+1].col != 0)
            printf(" -> ");
    }

    return 0;
}