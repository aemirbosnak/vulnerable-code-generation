//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

typedef struct node {
    int x;
    int y;
    int f;
    int g;
    int h;
    struct node *parent;
} Node;

int grid[ROW][COL] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

Node *openList[ROW * COL];
Node *closedList[ROW * COL];

int openListCount = 0;
int closedListCount = 0;

Node *startNode = NULL;
Node *endNode = NULL;

// calculate the g value for a node
int getGValue(Node *node) {
    if (node->parent == NULL) {
        return 0;
    } else {
        int diffX = abs(node->x - node->parent->x);
        int diffY = abs(node->y - node->parent->y);

        if (diffX > diffY) {
            return 14 + 10 * (diffX - diffY);
        } else {
            return 14 + 10 * (diffY - diffX);
        }
    }
}

// calculate the h value for a node
int getHValue(Node *node) {
    return abs(node->x - endNode->x) + abs(node->y - endNode->y);
}

// calculate the f value for a node
void getFValue(Node *node) {
    node->g = getGValue(node);
    node->h = getHValue(node);
    node->f = node->g + node->h;
}

// check if a node is on the open list
int isOnOpenList(Node *node) {
    for (int i = 0; i < openListCount; i++) {
        if (openList[i]->x == node->x && openList[i]->y == node->y) {
            return 1;
        }
    }
    return 0;
}

// check if a node is on the closed list
int isOnClosedList(Node *node) {
    for (int i = 0; i < closedListCount; i++) {
        if (closedList[i]->x == node->x && closedList[i]->y == node->y) {
            return 1;
        }
    }
    return 0;
}

// get the node with the lowest f value from the open list
Node *getLowestFValueNode() {
    Node *selectedNode = openList[0];
    int lowestFValue = openList[0]->f;

    for (int i = 1; i < openListCount; i++) {
        if (openList[i]->f < lowestFValue) {
            selectedNode = openList[i];
            lowestFValue = openList[i]->f;
        }
    }

    return selectedNode;
}

// add a node to the open list
void addToOpenList(Node *node) {
    openList[openListCount++] = node;
}

// remove a node from the open list
void removeFromOpenList(Node *node) {
    for (int i = 0; i < openListCount; i++) {
        if (openList[i]->x == node->x && openList[i]->y == node->y) {
            for (int j = i; j < openListCount - 1; j++) {
                openList[j] = openList[j + 1];
            }
            openListCount--;
            return;
        }
    }
}

// add a node to the closed list
void addToClosedList(Node *node) {
    closedList[closedListCount++] = node;
}

// get the neighbors of a node
Node **getNeighbors(Node *node, int grid[][COL]) {
    Node **neighbors = (Node **) malloc(sizeof(Node *) * 8);

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int x = node->x + i;
            int y = node->y + j;
            if (x < 0 || x >= ROW || y < 0 || y >= COL) {
                continue;
            }
            if (grid[x][y] == 1) {
                continue;
            }
            Node *neighbor = (Node *) malloc(sizeof(Node));
            neighbor->x = x;
            neighbor->y = y;
            neighbor->parent = node;
            neighbors[i * 3 + j + 4] = neighbor;
        }
    }

    return neighbors;
}

// free memory used by a node
void freeNode(Node *node) {
    free(node);
}

// free memory used by the open and closed lists
void freeLists() {
    for (int i = 0; i < openListCount; i++) {
        freeNode(openList[i]);
    }
    for (int i = 0; i < closedListCount; i++) {
        freeNode(closedList[i]);
    }
}

// print the path from the start node to the end node
void printPath(Node *node) {
    if (node->parent == NULL) {
        printf("(%d,%d)", node->x, node->y);
        return;
    }
    printPath(node->parent);
    printf(" -> (%d,%d)", node->x, node->y);
}

// perform A* search
void aStarSearch() {
    addToOpenList(startNode);

    while (openListCount > 0) {
        Node *currentNode = getLowestFValueNode();
        removeFromOpenList(currentNode);
        addToClosedList(currentNode);

        if (currentNode->x == endNode->x && currentNode->y == endNode->y) {
            printPath(currentNode);
            freeLists();
            return;
        }

        Node **neighbors = getNeighbors(currentNode, grid);
        for (int i = 0; i < 8; i++) {
            Node *neighbor = neighbors[i];
            if (neighbor == NULL) {
                continue;
            }
            if (isOnClosedList(neighbor)) {
                freeNode(neighbor);
                continue;
            }
            int newGValue = currentNode->g + getGValue(neighbor);
            if (!isOnOpenList(neighbor) || newGValue < neighbor->g) {
                neighbor->g = newGValue;
                getFValue(neighbor);

                if (!isOnOpenList(neighbor)) {
                    addToOpenList(neighbor);
                }
            } else {
                freeNode(neighbor);
            }
        }
        free(neighbors);
    }

    printf("No path found.");
}

int main() {
    startNode = (Node *) malloc(sizeof(Node));
    startNode->x = 3;
    startNode->y = 2;
    getFValue(startNode);

    endNode = (Node *) malloc(sizeof(Node));
    endNode->x = 8;
    endNode->y = 9;

    aStarSearch();

    return 0;
}