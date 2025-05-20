//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define N 10 // Size of the grid
#define INF 1000000

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point point;
    int f, g, h;
    struct Node* parent;
} Node;

Node* createNode(Point point, int g, int h, Node* parent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->point = point;
    newNode->g = g; // Cost from start to this node
    newNode->h = h; // Heuristic cost to goal
    newNode->f = g + h; // Total cost
    newNode->parent = parent;
    return newNode;
}

int calculateHeuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool isValid(int grid[N][N], int x, int y) {
    return (x >= 0) && (x < N) && (y >= 0) && (y < N) && (grid[x][y] == 0);
}

void tracePath(Node* node) {
    if (node == NULL) return;
    tracePath(node->parent);
    printf("(%d, %d) ", node->point.x, node->point.y);
}

Node* aStar(int grid[N][N], Point start, Point goal) {
    Node* openList[N * N];
    int openCount = 0;
    bool closedList[N][N] = { false };

    Node* startNode = createNode(start, 0, calculateHeuristic(start, goal), NULL);
    openList[openCount++] = startNode;

    while (openCount > 0) {
        int lowestIndex = 0;
        for (int i = 1; i < openCount; i++) {
            if (openList[i]->f < openList[lowestIndex]->f)
                lowestIndex = i;
        }

        Node* currentNode = openList[lowestIndex];

        if (currentNode->point.x == goal.x && currentNode->point.y == goal.y) {
            return currentNode;
        }

        openCount--;
        openList[lowestIndex] = openList[openCount];

        closedList[currentNode->point.x][currentNode->point.y] = true;

        // Iterate through possible movements (up, down, left, right)
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) == abs(dy)) continue; // Skip diagonals

                int newX = currentNode->point.x + dx;
                int newY = currentNode->point.y + dy;

                if (isValid(grid, newX, newY) && !closedList[newX][newY]) {
                    int gNew = currentNode->g + 1;
                    Point newPoint = { newX, newY };
                    Node* newNode = createNode(newPoint, gNew, calculateHeuristic(newPoint, goal), currentNode);

                    // Check if the new node is already in the open list
                    bool inOpenList = false;
                    for (int i = 0; i < openCount; i++) {
                        if (openList[i]->point.x == newX && openList[i]->point.y == newY && openList[i]->g <= gNew) {
                            inOpenList = true;
                            break;
                        }
                    }

                    if (!inOpenList) {
                        // Add the node to the open list
                        openList[openCount++] = newNode;
                    } else {
                        free(newNode); // Free the new node since it's not used
                    }
                }
            }
        }
    }

    return NULL; // No path was found
}

int main() {
    int grid[N][N] = {
        {0, 1, 0, 0, 0, 0, 1, 1, 0, 0},
        {0, 1, 0, 1, 1, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 1, 1, 0}
    };

    Point start = {0, 0}; // Start position
    Point goal = {9, 9};  // Goal position

    Node* result = aStar(grid, start, goal);

    if (result) {
        printf("Path from start to goal:\n");
        tracePath(result);
        printf("\n");
    } else {
        printf("No path found from start to goal.\n");
    }

    return 0;
}