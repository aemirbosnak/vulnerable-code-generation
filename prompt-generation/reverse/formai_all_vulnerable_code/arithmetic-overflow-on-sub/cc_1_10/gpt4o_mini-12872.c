//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define GRID_SIZE 10
#define WALKABLE 0
#define BLOCKED 1

typedef struct {
    int x, y;
} Point;

typedef struct Node {
    Point point;
    int gCost; // Cost from start
    int hCost; // Heuristic cost to end
    int fCost; // Total cost
    struct Node *parent;
} Node;

Node *createNode(int x, int y, Node *parent) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->point.x = x;
    newNode->point.y = y;
    newNode->gCost = 0;
    newNode->hCost = 0;
    newNode->fCost = 0;
    newNode->parent = parent;
    return newNode;
}

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void reconstructPath(Node *node) {
    while (node != NULL) {
        printf("Path: (%d, %d)\n", node->point.x, node->point.y);
        node = node->parent;
    }
}

bool isValid(Point point, int grid[GRID_SIZE][GRID_SIZE]) {
    return point.x >= 0 && point.x < GRID_SIZE && point.y >= 0 && point.y < GRID_SIZE && grid[point.x][point.y] == WALKABLE;
}

void aStar(int grid[GRID_SIZE][GRID_SIZE], Point start, Point end) {
    Node *openList[GRID_SIZE * GRID_SIZE];
    Node *closedList[GRID_SIZE * GRID_SIZE];
    int openCount = 0, closedCount = 0;

    Node *startNode = createNode(start.x, start.y, NULL);
    openList[openCount++] = startNode;

    while (openCount > 0) {
        int currentIndex = 0;
        for (int i = 1; i < openCount; i++) {
            if (openList[i]->fCost < openList[currentIndex]->fCost || 
                (openList[i]->fCost == openList[currentIndex]->fCost && openList[i]->hCost < openList[currentIndex]->hCost)) {
                currentIndex = i;
            }
        }

        Node *currentNode = openList[currentIndex];
        if (currentNode->point.x == end.x && currentNode->point.y == end.y) {
            printf("Path Found:\n");
            reconstructPath(currentNode);
            return;
        }

        // Move current node to closed list
        closedList[closedCount++] = currentNode;
        openCount--;
        for (int i = currentIndex; i < openCount; i++) {
            openList[i] = openList[i + 1];
        }

        // Generate neighbors
        Point neighbors[4] = {{currentNode->point.x + 1, currentNode->point.y},
                               {currentNode->point.x - 1, currentNode->point.y},
                               {currentNode->point.x, currentNode->point.y + 1},
                               {currentNode->point.x, currentNode->point.y - 1}};
        
        for (int i = 0; i < 4; i++) {
            Point neighborPoint = neighbors[i];
            if (!isValid(neighborPoint, grid)) continue;

            int gCost = currentNode->gCost + 1;
            int hCost = heuristic(neighborPoint, end);
            Node *neighborNode = createNode(neighborPoint.x, neighborPoint.y, currentNode);
            neighborNode->gCost = gCost;
            neighborNode->hCost = hCost;
            neighborNode->fCost = gCost + hCost;

            bool inClosedList = false;
            for (int j = 0; j < closedCount; j++) {
                if (closedList[j]->point.x == neighborNode->point.x && closedList[j]->point.y == neighborNode->point.y) {
                    inClosedList = true;
                    break;
                }
            }
            if (inClosedList) {
                free(neighborNode);
                continue;
            }

            bool inOpenList = false;
            for (int j = 0; j < openCount; j++) {
                if (openList[j]->point.x == neighborNode->point.x && openList[j]->point.y == neighborNode->point.y && openList[j]->gCost <= gCost) {
                    inOpenList = true;
                    break;
                }
            }
            if (!inOpenList) {
                openList[openCount++] = neighborNode;
            } else {
                free(neighborNode);
            }
        }
    }
    printf("No Path Found\n");
}

int main() {
    int grid[GRID_SIZE][GRID_SIZE] = {
        {WALKABLE, WALKABLE, BLOCKED, WALKABLE, WALKABLE, BLOCKED, BLOCKED, BLOCKED, WALKABLE, WALKABLE},
        {WALKABLE, BLOCKED, BLOCKED, WALKABLE, BLOCKED, BLOCKED, WALKABLE, WALKABLE, BLOCKED, WALKABLE},
        {BLOCKED, WALKABLE, WALKABLE, WALKABLE, BLOCKED, WALKABLE, BLOCKED, BLOCKED, WALKABLE, BLOCKED},
        {WALKABLE, WALKABLE, BLOCKED, BLOCKED, WALKABLE, BLOCKED, WALKABLE, WALKABLE, WALKABLE, WALKABLE},
        {BLOCKED, BLOCKED, BLOCKED, WALKABLE, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, WALKABLE},
        {WALKABLE, WALKABLE, WALKABLE, WALKABLE, WALKABLE, BLOCKED, BLOCKED, BLOCKED, WALKABLE, WALKABLE},
        {WALKABLE, BLOCKED, BLOCKED, BLOCKED, BLOCKED, WALKABLE, WALKABLE, BLOCKED, BLOCKED, BLOCKED},
        {WALKABLE, BLOCKED, WALKABLE, WALKABLE, WALKABLE, WALKABLE, BLOCKED, WALKABLE, WALKABLE, WALKABLE},
        {BLOCKED, WALKABLE, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, WALKABLE, BLOCKED},
        {WALKABLE, WALKABLE, WALKABLE, BLOCKED, WALKABLE, WALKABLE, WALKABLE, BLOCKED, WALKABLE, WALKABLE}
    };
    
    Point start = {0, 0};
    Point end = {9, 9};
    
    aStar(grid, start, end);
    
    return 0;
}