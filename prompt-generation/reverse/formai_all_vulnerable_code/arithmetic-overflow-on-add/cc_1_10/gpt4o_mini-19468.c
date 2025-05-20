//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_NODES (WIDTH * HEIGHT)

typedef struct {
    int x, y;
} Node;

typedef struct {
    Node nodes[MAX_NODES];
    int count;
} NodeList;

typedef struct {
    Node node;
    int gCost;  // Cost from the start node
    int hCost;  // Heuristic cost to the end node
    int fCost;  // Total cost
    Node* parent;
} PathNode;

NodeList openList;
NodeList closedList;

bool isInList(NodeList* list, Node node) {
    for (int i = 0; i < list->count; i++) {
        if (list->nodes[i].x == node.x && list->nodes[i].y == node.y) {
            return true;
        }
    }
    return false;
}

int calculateHeuristic(Node a, Node b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void addNode(NodeList* list, Node node) {
    list->nodes[list->count++] = node;
}

void clearList(NodeList* list) {
    list->count = 0;
}

bool isWalkable(int grid[HEIGHT][WIDTH], Node node) {
    return node.x >= 0 && node.x < WIDTH && node.y >= 0 && node.y < HEIGHT && grid[node.y][node.x] == 0;
}

void generateNeighbors(Node current, Node neighbors[4]) {
    neighbors[0] = (Node){current.x + 1, current.y}; // Right
    neighbors[1] = (Node){current.x - 1, current.y}; // Left
    neighbors[2] = (Node){current.x, current.y + 1}; // Down
    neighbors[3] = (Node){current.x, current.y - 1}; // Up
}

void printGrid(int grid[HEIGHT][WIDTH], Node path[], int pathLength) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            bool inPath = false;
            for (int p = 0; p < pathLength; p++) {
                if (path[p].x == x && path[p].y == y) {
                    inPath = true;
                    break;
                }
            }
            if (inPath) {
                printf(" * ");
            } else if (grid[y][x] == 1) {
                printf(" X ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

Node* findPath(int grid[HEIGHT][WIDTH], Node start, Node end, Node path[], int* pathLength) {
    clearList(&openList);
    clearList(&closedList);
    
    PathNode pathNodes[MAX_NODES];
    int pathNodeCount = 0;

    addNode(&openList, start);

    while (openList.count > 0) {
        int lowestIndex = 0;
        for (int i = 1; i < openList.count; i++) {
            if (pathNodes[openList.nodes[i].y * WIDTH + openList.nodes[i].x].fCost < pathNodes[openList.nodes[lowestIndex].y * WIDTH + openList.nodes[lowestIndex].x].fCost) {
                lowestIndex = i;
            }
        }

        Node current = openList.nodes[lowestIndex];

        if (current.x == end.x && current.y == end.y) {
            Node* currentNode = &current;
            *pathLength = 0;

            while (currentNode != NULL) {
                path[(*pathLength)++] = *currentNode;
                currentNode = pathNodes[currentNode->y * WIDTH + currentNode->x].parent;
            }

            return path;
        }

        openList.nodes[lowestIndex] = openList.nodes[--openList.count];
        addNode(&closedList, current);

        Node neighbors[4];
        generateNeighbors(current, neighbors);

        for (int i = 0; i < 4; i++) {
            if (!isWalkable(grid, neighbors[i]) || isInList(&closedList, neighbors[i])) {
                continue;
            }

            int newGCost = pathNodes[current.y * WIDTH + current.x].gCost + 1;
            if (!isInList(&openList, neighbors[i])) {
                addNode(&openList, neighbors[i]);
                pathNodes[neighbors[i].y * WIDTH + neighbors[i].x] = (PathNode){neighbors[i], newGCost, calculateHeuristic(neighbors[i], end), newGCost + calculateHeuristic(neighbors[i], end), &current};
            } else if (newGCost < pathNodes[neighbors[i].y * WIDTH + neighbors[i].x].gCost) {
                pathNodes[neighbors[i].y * WIDTH + neighbors[i].x].gCost = newGCost;
                pathNodes[neighbors[i].y * WIDTH + neighbors[i].x].fCost = newGCost + pathNodes[neighbors[i].y * WIDTH + neighbors[i].x].hCost;
                pathNodes[neighbors[i].y * WIDTH + neighbors[i].x].parent = &current;
            }
        }
    }

    *pathLength = 0;
    return NULL;
}

int main() {
    int grid[HEIGHT][WIDTH] = {
        {0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 1, 1, 1, 0},
        {0, 1, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 1, 1, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    Node start = {0, 0}; 
    Node end = {9, 9};
    Node path[MAX_NODES];
    int pathLength = 0;

    if (findPath(grid, start, end, path, &pathLength)) {
        printf("Path found:\n");
        printGrid(grid, path, pathLength);
    } else {
        printf("No path found!\n");
    }

    return 0;
}