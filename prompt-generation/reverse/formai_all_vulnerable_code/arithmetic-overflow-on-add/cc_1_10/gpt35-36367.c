//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 7
#define COLS 7

typedef struct Node {
    int row, col;
    int g, h;
    struct Node* parent;
} Node;

Node* openList[ROWS * COLS];
Node* closedList[ROWS * COLS];
Node* startNode;
Node* endNode;
int openIndex = -1;
int closedIndex = -1;
char grid[ROWS][COLS] = {
    {'S', '-', '-', '*', '-', '-', '-'},
    {'-', '*', '-', '-', '*', '-', '-'},
    {'-', '*', '-', '-', '*', '-', '-'},
    {'-', '*', '-', '-', '*', '-', '-'},
    {'-', '-', '-', '-', '*', '-', '-'},
    {'-', '*', '-', '*', '*', '-', '-'},
    {'-', '-', '-', '-', '*', 'F', '-'}
};

bool isValid(int row, int col) {
    if (row < 0 || col < 0 || row >= ROWS || col >= COLS) {
        return false;
    }
    if (grid[row][col] == '*') {
        return false;
    }
    return true;
}

bool isOpen(int row, int col) {
    for (int i = 0; i <= openIndex; i++) {
        if (openList[i]->row == row && openList[i]->col == col) {
            return true;
        }
    }
    return false;
}

bool isClosed(int row, int col) {
    for (int i = 0; i <= closedIndex; i++) {
        if (closedList[i]->row == row && closedList[i]->col == col) {
            return true;
        }
    }
    return false;
}

int heuristic(int row, int col) {
    int dx = abs(row - endNode->row);
    int dy = abs(col - endNode->col);
    return dx + dy;
}

void addToOpen(Node* node) {
    openList[++openIndex] = node;
}

void removeFromOpen(Node* node) {
    for (int i = 0; i <= openIndex; i++) {
        if (openList[i] == node) {
            openList[i] = openList[openIndex--];
            break;
        }
    }
}

bool isEndNode(int row, int col) {
    if (row == endNode->row && col == endNode->col) {
        return true;
    }
    return false;
}

void backtrackPath(Node* node) {
    if (node->parent != NULL) {
        backtrackPath(node->parent);
    }
    printf("(%d,%d) ", node->row, node->col);
}

void aStarSearch(Node* node) {
    Node* childNode;
    int currentRow = node->row;
    int currentCol = node->col;
    int childG;
    int childH;

    // check North
    if (isValid(currentRow-1, currentCol)) {
        childNode = (Node*)malloc(sizeof(Node));
        childNode->row = currentRow - 1;
        childNode->col = currentCol;
        childG = node->g + 1;
        childH = heuristic(childNode->row, childNode->col);
        childNode->g = childG;
        childNode->h = childH;
        childNode->parent = node;
        if (isEndNode(childNode->row, childNode->col)) {
            printf("Path: ");
            backtrackPath(node);
            printf("(%d,%d) \n", endNode->row, endNode->col);
            return;
        }
        if (!isOpen(childNode->row, childNode->col) && !isClosed(childNode->row, childNode->col)) {
            addToOpen(childNode);
        }
    }

    // check South
    if (isValid(currentRow+1, currentCol)) {
        childNode = (Node*)malloc(sizeof(Node));
        childNode->row = currentRow + 1;
        childNode->col = currentCol;
        childG = node->g + 1;
        childH = heuristic(childNode->row, childNode->col);
        childNode->g = childG;
        childNode->h = childH;
        childNode->parent = node;
        if (isEndNode(childNode->row, childNode->col)) {
            printf("Path: ");
            backtrackPath(node);
            printf("(%d,%d) \n", endNode->row, endNode->col);
            return;
        }
        if (!isOpen(childNode->row, childNode->col) && !isClosed(childNode->row, childNode->col)) {
            addToOpen(childNode);
        }
    }

    // check East
    if (isValid(currentRow, currentCol+1)) {
        childNode = (Node*)malloc(sizeof(Node));
        childNode->row = currentRow;
        childNode->col = currentCol + 1;
        childG = node->g + 1;
        childH = heuristic(childNode->row, childNode->col);
        childNode->g = childG;
        childNode->h = childH;
        childNode->parent = node;
        if (isEndNode(childNode->row, childNode->col)) {
            printf("Path: ");
            backtrackPath(node);
            printf("(%d,%d) \n", endNode->row, endNode->col);
            return;
        }
        if (!isOpen(childNode->row, childNode->col) && !isClosed(childNode->row, childNode->col)) {
            addToOpen(childNode);
        }
    }

    // check West
    if (isValid(currentRow, currentCol-1)) {
        childNode = (Node*)malloc(sizeof(Node));
        childNode->row = currentRow;
        childNode->col = currentCol - 1;
        childG = node->g + 1;
        childH = heuristic(childNode->row, childNode->col);
        childNode->g = childG;
        childNode->h = childH;
        childNode->parent = node;
        if (isEndNode(childNode->row, childNode->col)) {
            printf("Path: ");
            backtrackPath(node);
            printf("(%d,%d) \n", endNode->row, endNode->col);
            return;
        }
        if (!isOpen(childNode->row, childNode->col) && !isClosed(childNode->row, childNode->col)) {
            addToOpen(childNode);
        }
    }

    // move current node to closed list
    removeFromOpen(node);
    closedList[++closedIndex] = node;

    // select next node
    int bestFValue = 1000000;
    Node* nextNode;
    for (int i = 0; i <= openIndex; i++) {
        if (openList[i]->g + openList[i]->h < bestFValue) {
            bestFValue = openList[i]->g + openList[i]->h;
            nextNode = openList[i];
        }
    }
    aStarSearch(nextNode);
}

void initialize() {
    // initialize start and end nodes
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 'S') {
                startNode = (Node*)malloc(sizeof(Node));
                startNode->row = i;
                startNode->col = j;
                startNode->g = 0;
                startNode->h = heuristic(i, j);
                startNode->parent = NULL;
            } else if (grid[i][j] == 'F') {
                endNode = (Node*)malloc(sizeof(Node));
                endNode->row = i;
                endNode->col = j;
                endNode->g = 0;
                endNode->h = 0;
                endNode->parent = NULL;
            }
        }
    }
    // add start node to open list
    addToOpen(startNode);
}

int main() {
    initialize();
    aStarSearch(startNode);
    return 0;
}