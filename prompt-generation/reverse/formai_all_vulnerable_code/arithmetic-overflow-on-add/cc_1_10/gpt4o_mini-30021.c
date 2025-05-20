//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define GRID_SIZE 10
#define OBSTACLE '.'
#define EMPTY ' '
#define START 'S'
#define END 'E'
#define PATH '*'

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point point;
    int gCost; // Cost from start to node
    int hCost; // Heuristic cost to end
    int fCost; // Total cost
    struct Node* parent;
} Node;

Node* createNode(int x, int y, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->point.x = x;
    node->point.y = y;
    node->gCost = parent ? parent->gCost + 1 : 0;
    node->hCost = 0;
    node->fCost = 0;
    node->parent = parent;
    return node;
}

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y); // Manhattan distance
}

bool isValid(int x, int y, char grid[GRID_SIZE][GRID_SIZE]) {
    return (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE && grid[x][y] != OBSTACLE);
}

void printGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void reconstructPath(Node* node, char grid[GRID_SIZE][GRID_SIZE]) {
    while (node != NULL) {
        if (grid[node->point.x][node->point.y] == EMPTY) {
            grid[node->point.x][node->point.y] = PATH;
        }
        node = node->parent;
    }
}

int aStar(Point start, Point end, char grid[GRID_SIZE][GRID_SIZE]) {
    Node* openList[GRID_SIZE * GRID_SIZE];
    int openCount = 0;
    Node* closedList[GRID_SIZE * GRID_SIZE];
    int closedCount = 0;

    Node* startNode = createNode(start.x, start.y, NULL);
    startNode->hCost = heuristic(start, end);
    startNode->fCost = startNode->gCost + startNode->hCost;

    openList[openCount++] = startNode;

    while (openCount > 0) {
        int currentIndex = 0;
        for (int i = 1; i < openCount; i++) {
            if (openList[i]->fCost < openList[currentIndex]->fCost) {
                currentIndex = i;
            }
        }
        
        Node* currentNode = openList[currentIndex];

        if (currentNode->point.x == end.x && currentNode->point.y == end.y) {
            reconstructPath(currentNode, grid);
            return 1; // Found path
        }

        // Remove currentNode from open list
        for (int i = currentIndex; i < openCount - 1; i++) {
            openList[i] = openList[i + 1];
        }
        openCount--;

        closedList[closedCount++] = currentNode;

        // Explore neighbors
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        for (int i = 0; i < 4; i++) {
            int newX = currentNode->point.x + dx[i];
            int newY = currentNode->point.y + dy[i];
            if (isValid(newX, newY, grid)) {
                bool inClosedList = false;
                for (int j = 0; j < closedCount; j++) {
                    if (closedList[j]->point.x == newX && closedList[j]->point.y == newY) {
                        inClosedList = true;
                        break;
                    }
                }
                if (inClosedList) {
                    continue;
                }

                Node* neighbor = createNode(newX, newY, currentNode);
                neighbor->hCost = heuristic(neighbor->point, end);
                neighbor->fCost = neighbor->gCost + neighbor->hCost;

                bool inOpenList = false;
                for (int j = 0; j < openCount; j++) {
                    if (openList[j]->point.x == newX && openList[j]->point.y == newY) {
                        inOpenList = true;
                        if (neighbor->gCost < openList[j]->gCost) {
                            openList[j]->gCost = neighbor->gCost;
                            openList[j]->fCost = openList[j]->gCost + openList[j]->hCost;
                            openList[j]->parent = currentNode;
                        }
                        break;
                    }
                }
                if (!inOpenList) {
                    openList[openCount++] = neighbor;
                } else {
                    free(neighbor); // Avoid memory leak
                }
            }
        }
    }

    return 0; // No path found
}

int main() {
    char grid[GRID_SIZE][GRID_SIZE] = {
        { 'S', ' ', ' ', ' ', ' ', OBSTACLE, ' ', ' ', ' ', ' ' },
        { ' ', OBSTACLE, ' ', OBSTACLE, ' ', OBSTACLE, ' ', OBSTACLE, OBSTACLE, OBSTACLE },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { OBSTACLE, OBSTACLE, OBSTACLE, ' ', OBSTACLE, ' ', ' ', ' ', OBSTACLE, ' ' },
        { ' ', ' ', ' ', ' ', ' ', OBSTACLE, ' ', ' ', ' ', ' ' },
        { ' ', OBSTACLE, OBSTACLE, OBSTACLE, ' ', OBSTACLE, ' ', OBSTACLE, ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { OBSTACLE, OBSTACLE, ' ', OBSTACLE, ' ', OBSTACLE, ' ', OBSTACLE, OBSTACLE, OBSTACLE },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'E' },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }
    };

    Point start = {0, 0};
    Point end = {8, 9};
    
    int pathFound = aStar(start, end, grid);

    if (pathFound) {
        printf("Path found:\n");
        printGrid(grid);
    } else {
        printf("No path found.\n");
    }

    return 0;
}