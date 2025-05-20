//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX 100
#define INF 99999

typedef struct Node {
    int x, y;
    int g; // Cost from start
    int h; // Heuristic cost to end
    int f; // Total cost
    struct Node* parent;
} Node;

Node* createNode(int x, int y, int g, int h, Node* parent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->g = g;
    newNode->h = h;
    newNode->f = g + h;
    newNode->parent = parent;
    return newNode;
}

int heuristic(Node* a, Node* b) {
    return abs(a->x - b->x) + abs(a->y - b->y); // Manhattan distance
}

bool isInList(Node** list, int size, int x, int y) {
    for (int i = 0; i < size; i++) {
        if (list[i]->x == x && list[i]->y == y) {
            return true;
        }
    }
    return false;
}

void printPath(Node* target) {
    if (target == NULL) return;
    printPath(target->parent);
    printf(" -> (%d, %d)", target->x, target->y);
}

void astar(int grid[HEIGHT][WIDTH], Node start, Node end) {
    Node* openList[MAX];
    int openCount = 0;
    Node* closedList[MAX];
    int closedCount = 0;

    openList[openCount++] = createNode(start.x, start.y, 0, heuristic(&start, &end), NULL);

    while (openCount > 0) {
        // Find the node with the lowest f cost
        int lowestIndex = 0;
        for (int i = 1; i < openCount; i++) {
            if (openList[i]->f < openList[lowestIndex]->f) {
                lowestIndex = i;
            }
        }

        Node* currentNode = openList[lowestIndex];

        // Check if we reached the goal
        if (currentNode->x == end.x && currentNode->y == end.y) {
            printf("Path found:\n");
            printPath(currentNode);
            printf("\n");
            return;
        }

        // Move current node to closed list
        closedList[closedCount++] = currentNode;
        for (int i = lowestIndex; i < openCount - 1; i++) {
            openList[i] = openList[i + 1];
        }
        openCount--;

        // Check neighbors (4 directions)
        int directions[4][2] = {
            {0, 1},   // Right
            {1, 0},   // Down
            {0, -1},  // Left
            {-1, 0}   // Up
        };

        for (int i = 0; i < 4; i++) {
            int newX = currentNode->x + directions[i][0];
            int newY = currentNode->y + directions[i][1];

            // Check if new position is within bounds
            if (newX < 0 || newX >= WIDTH || newY < 0 || newY >= HEIGHT || grid[newY][newX] == 1) {
                continue; // Skip obstacle and out of bounds
            }

            // Calculate costs
            int newG = currentNode->g + 1; // Cost is always 1 in this grid
            Node* neighborNode = createNode(newX, newY, newG, heuristic(&end, createNode(newX, newY, 0, 0, NULL)), currentNode);
            
            if (isInList(closedList, closedCount, newX, newY)) {
                free(neighborNode); // Don't add to open list if already evaluated
                continue;
            }

            // Check if neighbor is already in open list
            bool inOpenList = isInList(openList, openCount, newX, newY);
            if (!inOpenList || newG < neighborNode->g) {
                if (!inOpenList) {
                    openList[openCount++] = neighborNode;
                } else {
                    free(neighborNode); // Use the existing one
                }
            } else {
                free(neighborNode);
            }
        }
    }
    printf("No path found\n");
}

int main() {
    int grid[HEIGHT][WIDTH] = {
        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 0, 1, 1, 1, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
        {0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 1, 1, 1, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 0}
    };

    Node start = {0, 0};
    Node end = {9, 9};

    astar(grid, start, end);

    // Free memory of lists
    return 0;
}