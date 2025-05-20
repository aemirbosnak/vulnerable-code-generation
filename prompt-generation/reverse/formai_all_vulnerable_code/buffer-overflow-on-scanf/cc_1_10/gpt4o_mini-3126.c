//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10
#define INF 99999

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point parent;
    int cost;
    bool visited;
} Node;

Node grid[MAX][MAX];
int rows, cols;

void initializeGrid() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            grid[i][j].cost = INF;
            grid[i][j].visited = false;
            grid[i][j].parent.x = -1;
            grid[i][j].parent.y = -1;
        }
    }
}

bool isValid(int x, int y) {
    return (x >= 0 && x < rows && y >= 0 && y < cols && !grid[x][y].visited);
}

void printPath(Point end) {
    Point path[MAX];
    int pathLength = 0;
    
    while (end.x != -1 && end.y != -1) {
        path[pathLength++] = end;
        end = grid[end.x][end.y].parent;
    }

    printf("Path: ");
    for (int i = pathLength - 1; i >= 0; i--) {
        printf("(%d, %d)", path[i].x, path[i].y);
        if (i != 0) printf(" -> ");
    }
    printf("\n");
}

void dijkstra(Point start, Point end) {
    grid[start.x][start.y].cost = 0;
    
    for (int i = 0; i < rows * cols; i++) {
        int minCost = INF;
        Point current = {-1, -1};
        
        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < cols; y++) {
                if (!grid[x][y].visited && grid[x][y].cost < minCost) {
                    minCost = grid[x][y].cost;
                    current = (Point){x, y};
                }
            }
        }
        
        if (current.x == -1 || current.y == -1) {
            break;  // all reachable nodes are visited
        }
        
        grid[current.x][current.y].visited = true;

        Point neighbors[4] = {
            {current.x - 1, current.y},
            {current.x + 1, current.y},
            {current.x, current.y - 1},
            {current.x, current.y + 1}
        };

        for (int i = 0; i < 4; i++) {
            Point neighbor = neighbors[i];
            if (isValid(neighbor.x, neighbor.y)) {
                int newCost = grid[current.x][current.y].cost + 1;  // Assume equal cost for simplicity
                if (newCost < grid[neighbor.x][neighbor.y].cost) {
                    grid[neighbor.x][neighbor.y].cost = newCost;
                    grid[neighbor.x][neighbor.y].parent = current;
                }
            }
        }
    }

    if (grid[end.x][end.y].cost != INF) {
        printf("Shortest path cost: %d\n", grid[end.x][end.y].cost);
        printPath(end);
    } else {
        printf("No path found from (%d, %d) to (%d, %d).\n", start.x, start.y, end.x, end.y);
    }
}

int main() {
    printf("Enter grid size (rows cols): ");
    scanf("%d %d", &rows, &cols);
    
    if (rows > MAX || cols > MAX || rows <= 0 || cols <= 0) {
        printf("Grid size must be between 1 and %d.\n", MAX);
        return 1;
    }

    initializeGrid();

    printf("Enter blocked cells (x y) with a negative x to stop:\n");
    while (true) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x < 0) break;
        if (isValid(x, y)) {
            grid[x][y].visited = true;  // Mark as blocked
        } else {
            printf("Invalid cell (%d, %d). Try again.\n", x, y);
        }
    }

    Point start, end;
    printf("Enter start point (x y): ");
    scanf("%d %d", &start.x, &start.y);
    printf("Enter end point (x y): ");
    scanf("%d %d", &end.x, &end.y);

    if (isValid(start.x, start.y) && isValid(end.x, end.y)) {
        dijkstra(start, end);
    } else {
        printf("Invalid start or end point.\n");
    }

    return 0;
}