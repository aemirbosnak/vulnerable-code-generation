//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX 20
#define INF 99999

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point parent;
    int f, g, h;
    bool isOpen;
    bool isClosed;
} Node;

Node grid[MAX][MAX];
Point start, end;
int rows, cols;

// Function to calculate heuristic (Manhattan distance)
int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// Function to initialize the grid
void initializeGrid(int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            grid[i][j].f = INF;
            grid[i][j].g = INF;
            grid[i][j].h = INF;
            grid[i][j].isOpen = false;
            grid[i][j].isClosed = false;
            grid[i][j].parent.x = -1;
            grid[i][j].parent.y = -1;
        }
    }
}

// Function to check if a point is valid
bool isValid(int r, int c) {
    return r >= 0 && r < rows && c >= 0 && c < cols;
}

// Function to check if a node is in the open list
bool inOpenList(Point p) {
    return grid[p.x][p.y].isOpen;
}

// Function to check if a node is in the closed list
bool inClosedList(Point p) {
    return grid[p.x][p.y].isClosed;
}

// A* algorithm implementation
void aStar(Point start, Point end) {
    grid[start.x][start.y].g = 0;
    grid[start.x][start.y].h = heuristic(start, end);
    grid[start.x][start.y].f = grid[start.x][start.y].g + grid[start.x][start.y].h;
    grid[start.x][start.y].isOpen = true;

    for (int count = 0; count < MAX * MAX; count++) {
        Point current = {-1, -1};
        int lowestF = INF;

        // Find the node with the lowest f in the open list
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j].isOpen && grid[i][j].f < lowestF) {
                    lowestF = grid[i][j].f;
                    current.x = i;
                    current.y = j;
                }
            }
        }

        if (current.x == -1) {
            printf("No path found!\n");
            return; // Return if there's no valid node found
        }

        // If we've reached the end point
        if (current.x == end.x && current.y == end.y) {
            printf("Path found!\n");
            return;
        }

        // Move current node to the closed list
        grid[current.x][current.y].isOpen = false;
        grid[current.x][current.y].isClosed = true;

        // Generate successors
        Point directions[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; i++) {
            Point successor = {current.x + directions[i].x, current.y + directions[i].y};

            // Check if the successor is valid
            if (!isValid(successor.x, successor.y) || inClosedList(successor)) {
                continue; // Skip this successor
            }

            int gNew = grid[current.x][current.y].g + 1;

            // Check if successor is not in Open List or new path is shorter
            if (!inOpenList(successor) || gNew < grid[successor.x][successor.y].g) {
                grid[successor.x][successor.y].g = gNew;
                grid[successor.x][successor.y].h = heuristic(successor, end);
                grid[successor.x][successor.y].f = grid[successor.x][successor.y].g + grid[successor.x][successor.y].h;
                grid[successor.x][successor.y].parent = current;

                if (!inOpenList(successor)) {
                    grid[successor.x][successor.y].isOpen = true;
                }
            }
        }
    }
}

void printPath() {
    Point current = end;
    while (current.x != -1 && current.y != -1) {
        printf("(%d, %d) <- ", current.x, current.y);
        current = grid[current.x][current.y].parent;
    }
    printf("Start\n");
}

int main() {
    printf("Enter grid size (rows and columns): ");
    scanf("%d %d", &rows, &cols);

    printf("Enter starting point (x y): ");
    scanf("%d %d", &start.x, &start.y);

    printf("Enter ending point (x y): ");
    scanf("%d %d", &end.x, &end.y);

    initializeGrid(rows, cols);
    
    // Define obstacles
    grid[1][2].isClosed = true; // Example obstacle
    grid[2][2].isClosed = true; // Example obstacle

    aStar(start, end);
    printPath();

    return 0;
}