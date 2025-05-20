//Falcon2-11B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    int cost;
    Position next;
} Node;

Node openSet[MAX_ROWS * MAX_COLS];
int numOpen = 0;

Node closedSet[MAX_ROWS * MAX_COLS];
int numClosed = 0;

int heuristic(int startRow, int startCol, int endRow, int endCol) {
    int xDist = abs(startRow - endRow);
    int yDist = abs(startCol - endCol);
    return xDist + yDist;
}

int getParent(int row, int col) {
    int parentRow = row - 1;
    int parentCol = col - 1;
    return parentRow * MAX_COLS + parentCol;
}

void addToOpenSet(int row, int col, int cost) {
    Node node = {.cost = cost,.next = getParent(row, col)};
    if (numOpen < MAX_ROWS * MAX_COLS) {
        openSet[numOpen++] = node;
        printf("Added to open set: (%d, %d) -> (%d, %d)\n", row, col, node.next.row, node.next.col);
    } else {
        printf("Open set is full, cannot add node to open set.\n");
    }
}

void addToClosedSet(int row, int col) {
    Node node = {.cost = INT_MAX,.next = getParent(row, col)};
    if (numClosed < MAX_ROWS * MAX_COLS) {
        closedSet[numClosed++] = node;
        printf("Added to closed set: (%d, %d)\n", row, col);
    } else {
        printf("Closed set is full, cannot add node to closed set.\n");
    }
}

void printOpenSet() {
    for (int i = 0; i < numOpen; i++) {
        Node node = openSet[i];
        printf("(%d, %d) -> (%d, %d) (cost: %d)\n", node.next.row, node.next.col, node.next.row, node.next.col, node.cost);
    }
}

void printClosedSet() {
    for (int i = 0; i < numClosed; i++) {
        Node node = closedSet[i];
        printf("(%d, %d)\n", node.next.row, node.next.col);
    }
}

int main() {
    int startRow = 0;
    int startCol = 0;
    int endRow = 0;
    int endCol = 0;

    printf("Enter start row: ");
    scanf("%d", &startRow);
    printf("Enter start col: ");
    scanf("%d", &startCol);
    printf("Enter end row: ");
    scanf("%d", &endRow);
    printf("Enter end col: ");
    scanf("%d", &endCol);

    printf("Start: (%d, %d)\n", startRow, startCol);
    printf("End: (%d, %d)\n", endRow, endCol);

    Node startNode = {.cost = 0,.next = getParent(startRow, startCol)};
    addToOpenSet(startRow, startCol, startNode.cost);

    while (numOpen > 0) {
        Node currentNode = openSet[0];
        int currentRow = currentNode.next.row;
        int currentCol = currentNode.next.col;
        printf("Current node: (%d, %d) (cost: %d)\n", currentRow, currentCol, currentNode.cost);

        if (currentRow == endRow && currentCol == endCol) {
            printf("Found path!\n");
            printOpenSet();
            printClosedSet();
            break;
        }

        addToClosedSet(currentRow, currentCol);
        numClosed++;

        int neighbors[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        for (int i = 0; i < 4; i++) {
            int neighborRow = currentRow + neighbors[i][0];
            int neighborCol = currentCol + neighbors[i][1];
            Node neighborNode = {.cost = heuristic(currentRow, currentCol, neighborRow, neighborCol),.next = getParent(neighborRow, neighborCol)};
            if (neighborRow >= 0 && neighborRow < MAX_ROWS && neighborCol >= 0 && neighborCol < MAX_COLS) {
                if (numClosed == 0) {
                    addToOpenSet(neighborRow, neighborCol, neighborNode.cost);
                } else if (neighborNode.cost < closedSet[0].cost) {
                    addToOpenSet(neighborRow, neighborCol, neighborNode.cost);
                }
            }
        }

        numOpen--;
    }

    printf("No path found.\n");

    return 0;
}