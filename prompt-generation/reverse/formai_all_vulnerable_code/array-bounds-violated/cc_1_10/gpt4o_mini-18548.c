//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ROW 10
#define COL 10

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    int f, g, h;
} Node;

Node* createNode(int x, int y, int g, int h) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->pos.x = x;
    newNode->pos.y = y;
    newNode->g = g;
    newNode->h = h;
    newNode->f = g + h; // Total cost
    return newNode;
}

bool isValid(int row, int col, bool grid[ROW][COL], bool closedList[ROW][COL]) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && grid[row][col] && !closedList[row][col];
}

int heuristic(Position a, Position b) {
    return abs(a.x - b.x) + abs(a.y - b.y); // Manhattan Distance
}

void tracePath(Position parent[ROW][COL], Position start, Position goal) {
    Position path[ROW * COL];
    int pathIndex = 0;

    for (Position pos = goal; pos.x != start.x || pos.y != start.y; ) {
        path[pathIndex++] = pos;
        pos = parent[pos.x][pos.y];
    }
    path[pathIndex++] = start;

    printf("Path found:\n");
    for (int i = pathIndex - 1; i >= 0; i--) {
        printf("(%d, %d) ", path[i].x, path[i].y);
    }
    printf("\n");
}

void aStar(bool grid[ROW][COL], Position start, Position goal) {
    Node* openList[ROW * COL];
    bool closedList[ROW][COL] = {false};
    Position parent[ROW][COL] = {{-1, -1}}; // Store parent positions

    int openSize = 0;
    openList[openSize++] = createNode(start.x, start.y, 0, heuristic(start, goal));

    while (openSize > 0) {
        // Find node with the least f in open list
        int idx = 0;
        for (int i = 1; i < openSize; i++) {
            if (openList[i]->f < openList[idx]->f) idx = i;
        }

        Node* current = openList[idx];

        if (current->pos.x == goal.x && current->pos.y == goal.y) {
            tracePath(parent, start, goal);
            return;
        }

        // Remove current node from open list
        openList[idx] = openList[--openSize];
        closedList[current->pos.x][current->pos.y] = true;

        // Generate neighbors
        Position directions[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; i++) {
            int newX = current->pos.x + directions[i].x;
            int newY = current->pos.y + directions[i].y;

            if (!isValid(newX, newY, grid, closedList)) continue;

            int gNew = current->g + 1;
            int hNew = heuristic((Position){newX, newY}, goal);

            // Check if neighbor is in open list and has lesser g value
            bool updateNode = true;
            for (int j = 0; j < openSize; j++) {
                if (openList[j]->pos.x == newX && openList[j]->pos.y == newY) {
                    if (gNew >= openList[j]->g) {
                        updateNode = false;
                    } else {
                        free(openList[j]);
                        openList[j] = openList[--openSize]; // Removing from open list
                        break;
                    }
                }
            }

            if (updateNode) {
                // Update parent and add to open list
                parent[newX][newY] = current->pos;
                openList[openSize++] = createNode(newX, newY, gNew, hNew);
            }
        }
        free(current); // Free memory used by current node
    }
    
    printf("No path found.\n");
}

int main() {
    bool grid[ROW][COL] = {
        {true, true, true, true, false, true, true, true, true, true},
        {true, false, true, true, false, true, false, false, true, true},
        {true, false, true, true, true, true, true, false, true, true},
        {true, false, false, false, false, true, true, true, true, true},
        {true, true, true, true, true, true, false, false, true, true},
        {true, false, false, false, false, true, true, false, true, true},
        {true, true, true, false, true, true, true, true, true, true},
        {true, false, true, false, false, false, false, false, true, true},
        {true, true, true, true, true, true, true, true, true, true},
        {true, true, true, true, false, false, false, false, false, true}
    };

    Position start = {0, 0};
    Position goal = {9, 9};

    aStar(grid, start, goal);

    return 0;
}