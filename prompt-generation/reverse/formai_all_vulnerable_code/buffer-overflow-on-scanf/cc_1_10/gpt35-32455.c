//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: modular
/*
This is an example program of A* pathfinding algorithm.
The program takes a 2D grid as input and finds the shortest path
between a start point and an end point using the A* algorithm.
The program outputs the path and the total cost.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

typedef struct Node {
    int row, col;
    int fValue, gValue, hValue;
    struct Node* parent;
} Node;

// define the grid
int grid[ROW][COL] = {
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int hValue(int row, int col, int targetRow, int targetCol) {
    return abs(row - targetRow) + abs(col - targetCol);
}

bool isValid(int row, int col) {
    return (row >= 0) && (row < ROW) &&
           (col >= 0) && (col < COL);
}

bool isFree(int row, int col) {
    return grid[row][col] != 1;
}

bool isDestination(int row, int col, Node* dest) {
    return (row == dest->row) && (col == dest->col);
}

Node* createNode(int row, int col, int fValue, int gValue, int hValue, Node* parent) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->fValue = fValue;
    node->gValue = gValue;
    node->hValue = hValue;
    node->parent = parent;
    return node;
}

void printPath(Node* current) {
    if (current->parent == NULL) {
        printf("(%d,%d)", current->row, current->col);
        return;
    }
    printPath(current->parent);
    printf(" -> (%d,%d)", current->row, current->col);
}

void AStar(int startRow, int startCol, int targetRow, int targetCol) {
    if (!isValid(startRow, startCol)) {
        printf("Start position is not valid.\n");
        return;
    }
    if (!isValid(targetRow, targetCol)) {
        printf("Target position is not valid.\n");
        return;
    }
    if (!isFree(startRow, startCol)) {
        printf("Start position is not free.\n");
        return;
    }
    if (!isFree(targetRow, targetCol)) {
        printf("Target position is not free.\n");
        return;
    }
    if (isDestination(startRow, startCol, createNode(targetRow, targetCol, 0, 0, 0, NULL))) {
        printf("Already at destination.\n");
        return;
    }

    int h = hValue(startRow, startCol, targetRow, targetCol);
    Node* start = createNode(startRow, startCol, h, 0, h, NULL);
    Node* current = NULL;

    // create open list and closed list
    Node* openList[ROW * COL];
    int openListCount = 0;
    Node* closedList[ROW * COL];
    int closedListCount = 0;

    // add start node to open list
    openList[openListCount++] = start;

    while (openListCount > 0) {
        // find node with lowest fValue
        int lowestF = openList[0]->fValue;
        int lowestFIndex = 0;
        for (int i = 1; i < openListCount; i++) {
            if (openList[i]->fValue < lowestF) {
                lowestF = openList[i]->fValue;
                lowestFIndex = i;
            }
        }

        // take out from open list and add to closed list
        current = openList[lowestFIndex];
        openList[lowestFIndex] = openList[--openListCount];
        closedList[closedListCount++] = current;

        // check if target has been reached
        if (isDestination(current->row, current->col, createNode(targetRow, targetCol, 0, 0, 0, NULL))) {
            printf("Path Found: ");
            printPath(current);
            printf("\nTotal Cost: %d\n", current->fValue);
            return;
        }

        // generate neighbors
        Node* neighbor = NULL;
        for (int rowOffset = -1; rowOffset <= 1; rowOffset++) {
            for (int colOffset = -1; colOffset <= 1; colOffset++) {
                if (rowOffset == 0 && colOffset == 0) {
                    continue;
                }
                int neighborRow = current->row + rowOffset;
                int neighborCol = current->col + colOffset;

                if (isValid(neighborRow, neighborCol) && isFree(neighborRow, neighborCol)) {
                    int neighborH = hValue(neighborRow, neighborCol, targetRow, targetCol);
                    int neighborG = current->gValue + 1;
                    int neighborF = neighborH + neighborG;
                    neighbor = createNode(neighborRow, neighborCol, neighborF, neighborG, neighborH, current);

                    // check if neighbor is already on the closed list
                    bool onClosedList = false;
                    for (int i = 0; i < closedListCount; i++) {
                        if (neighbor->row == closedList[i]->row && neighbor->col == closedList[i]->col) {
                            onClosedList = true;
                            break;
                        }
                    }

                    if (!onClosedList) {
                        // check if neighbor is already on the open list
                        int index = -1;
                        for (int i = 0; i < openListCount; i++) {
                            if (neighbor->row == openList[i]->row && neighbor->col == openList[i]->col) {
                                index = i;
                                break;
                            }
                        }

                        if (index == -1) {
                            // add neighbor to the open list
                            openList[openListCount++] = neighbor;
                        } else {
                            // check if going through current is a better path to the neighbor
                            if (neighborG < openList[index]->gValue) {
                                openList[index]->gValue = neighborG;
                                openList[index]->fValue = neighborF;
                                openList[index]->parent = current;
                            }
                            free(neighbor);
                        }
                    } else {
                        free(neighbor);
                    }
                }
            }
        }
    }

    printf("Path not found.\n");
}

int main() {
    int startRow, startCol, targetRow, targetCol;
    printf("Enter start position: ");
    scanf("%d,%d", &startRow, &startCol);
    printf("Enter target position: ");
    scanf("%d,%d", &targetRow, &targetCol);
    AStar(startRow, startCol, targetRow, targetCol);
    return 0;
}