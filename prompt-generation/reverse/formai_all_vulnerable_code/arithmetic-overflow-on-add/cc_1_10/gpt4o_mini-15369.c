//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10 // Size of the grid

// A structure to hold the position of cells in the grid
typedef struct {
    int x;
    int y;
} Position;

// A structure to hold the information of each cell
typedef struct {
    Position pos;
    int cost;
    int heuristic;
    int f_value;
    struct Node *parent;
} Node;

// Function to create a new node
Node* createNode(int x, int y, int cost, int heuristic, Node *parent) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->pos.x = x;
    newNode->pos.y = y;
    newNode->cost = cost;
    newNode->heuristic = heuristic;
    newNode->f_value = cost + heuristic;
    newNode->parent = parent;
    return newNode;
}

// Function to calculate heuristic (Manhattan distance)
int calculateHeuristic(Position a, Position b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// Check if a position is within grid bounds
bool isValid(int x, int y, int grid[N][N], bool closedList[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && grid[x][y] == 0 && !closedList[x][y]);
}

// Function to trace the path from goal to start
void tracePath(Node *currentNode) {
    if (currentNode == NULL) return;
    
    tracePath(currentNode->parent);
    
    printf("(%d, %d) ", currentNode->pos.x, currentNode->pos.y);
}

// A* Search algorithm
void aStar(int grid[N][N], Position start, Position goal) {
    Node *openList[N * N], *currentNode, *neighbor;
    
    bool closedList[N][N] = {false};
    int openListCount = 0;

    // Add the starting node to the open list
    openList[openListCount++] = createNode(start.x, start.y, 0,
        calculateHeuristic(start, goal), NULL);

    while (openListCount > 0) {
        // Find the node with the lowest f_value
        int lowestIndex = 0;
        for (int i = 1; i < openListCount; i++) {
            if (openList[i]->f_value < openList[lowestIndex]->f_value) {
                lowestIndex = i;
            }
        }

        currentNode = openList[lowestIndex];

        // Check if we've reached the goal
        if (currentNode->pos.x == goal.x && currentNode->pos.y == goal.y) {
            printf("Path found: ");
            tracePath(currentNode);
            printf("\n");
            return;
        }

        // Remove the current node from open list and add to closed list
        openList[lowestIndex] = openList[--openListCount];
        closedList[currentNode->pos.x][currentNode->pos.y] = true;

        // Generate neighbors (up, down, left, right)
        Position directions[4] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };

        for (int i = 0; i < 4; i++) {
            int newX = currentNode->pos.x + directions[i].x;
            int newY = currentNode->pos.y + directions[i].y;

            // Check if it's valid and not in the closed list
            if (isValid(newX, newY, grid, closedList)) {
                // Create a new node for the neighbor
                neighbor = createNode(newX, newY, currentNode->cost + 1,
                    calculateHeuristic((Position){newX, newY}, goal), currentNode);
                
                // Check if the neighbor is already in open list
                bool inOpenList = false;
                for (int j = 0; j < openListCount; j++) {
                    if (openList[j]->pos.x == neighbor->pos.x && openList[j]->pos.y == neighbor->pos.y) {
                        inOpenList = true;
                        if (openList[j]->f_value > neighbor->f_value) {
                            openList[j] = neighbor; // Replace with better node
                        }
                        break;
                    }
                }

                if (!inOpenList) {
                    // Add neighbor to open list
                    openList[openListCount++] = neighbor;
                } else {
                    free(neighbor); // Free unused memory
                }
            }
        }
        free(currentNode); // Free memory of current node
    }
    
    printf("No path found.\n");
}

int main() {
    int grid[N][N] = {
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 1, 1},
        {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 1, 1, 0, 0}
    };

    Position start = {0, 0};
    Position goal = {9, 9};

    aStar(grid, start, goal);

    return 0;
}