//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROWS 5
#define COLS 5

int grid[ROWS][COLS] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0}
};

typedef struct Node {
    int row, col, distance;
    struct Node *parent;
} Node;

Node* createNode(int row, int col, int distance, Node* parent)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->distance = distance;
    newNode->parent = parent;
    return newNode;
}

void destroyNode(Node* node)
{
    free(node);
}

Node* findPath(int startRow, int startCol, int endRow, int endCol)
{
    Node* queue[ROWS * COLS];
    int queueStart = 0, queueEnd = 0;
    queue[queueEnd++] = createNode(startRow, startCol, 0, NULL);

    while (queueStart < queueEnd) {
        Node* current = queue[queueStart++];
        if (current->row == endRow && current->col == endCol)
            return current;

        if (current->row > 0 && grid[current->row - 1][current->col] != 1)
            queue[queueEnd++] = createNode(current->row - 1, current->col, current->distance + 1, current);

        if (current->col > 0 && grid[current->row][current->col - 1] != 1)
            queue[queueEnd++] = createNode(current->row, current->col - 1, current->distance + 1, current);
        
        if (current->row < ROWS - 1 && grid[current->row + 1][current->col] != 1)
            queue[queueEnd++] = createNode(current->row + 1, current->col, current->distance + 1, current);
        
        if (current->col < COLS - 1 && grid[current->row][current->col + 1] != 1)
            queue[queueEnd++] = createNode(current->row, current->col + 1, current->distance + 1, current);
    }

    return NULL;
}

void printPath(Node* endNode)
{
    int pathLength = 0;
    Node* current = endNode;
    while (current) {
        current = current->parent;
        pathLength++;
    }

    int path[pathLength][2];
    current = endNode;
    int i = pathLength-1;
    while (current) {
        path[i][0] = current->row;
        path[i][1] = current->col;
        current = current->parent;
        i--;
    }

    printf("Shortest path from (%d,%d) to (%d,%d):\n", path[pathLength-1][0], path[pathLength-1][1], path[0][0], path[0][1]);
    for (int i = 0; i < pathLength; i++) {
        printf("(%d,%d)", path[i][0], path[i][1]);
        if (i != pathLength-1)
            printf(" -> ");
    }
}

int main()
{
    Node* endNode = findPath(0,0,4,3);
    if (endNode)
        printPath(endNode);
    else
        printf("No path found.");
    destroyNode(endNode);
    return 0;
}