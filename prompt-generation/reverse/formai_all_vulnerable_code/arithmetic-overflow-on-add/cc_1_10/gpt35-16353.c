//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int x;
    int y;
    int dist;
    struct Node* parent;
};

void printPath(struct Node* currNode) {
    if (currNode == NULL) {
        return;
    }
    printPath(currNode->parent);
    printf("(%d,%d) ", currNode->x, currNode->y);
}

int isValid(int x, int y, int n, int m, int arr[][m], int visited[][m]) {
    if (x < 0 || y < 0 || x >= n || y >= m || arr[x][y] == 0 || visited[x][y] == 1) {
        return 0;
    }
    return 1;
}

void BFS(int n, int m, int arr[][m], int startX, int startY, int endX, int endY) {
    int visited[n][m];
    struct Node* head = calloc(1,sizeof(struct Node));
    head->x = startX;
    head->y = startY;
    head->dist = 0;
    head->parent = NULL;
    
    int queueSize = 1;
    struct Node** queue = malloc(queueSize*sizeof(struct Node*));
    queue[0] = head;
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    while(queueSize != 0) {
        struct Node* currNode = queue[0];
        queueSize--;
        for (int i = 0; i < queueSize; i++) {
            queue[i] = queue[i+1];
        }
        if (currNode->x == endX && currNode->y == endY) {
            printPath(currNode);
            printf("\n");
            return;
        }
        visited[currNode->x][currNode->y] = 1;
        for (int i = 0; i < 4; i++) {
            int newX = currNode->x + dx[i];
            int newY = currNode->y + dy[i];
            if (isValid(newX, newY, n, m, arr, visited)) {
                struct Node* newNode = calloc(1,sizeof(struct Node));
                newNode->x = newX;
                newNode->y = newY;
                newNode->dist = currNode->dist + 1;
                newNode->parent = currNode;
                queueSize++;
                queue = realloc(queue, queueSize*sizeof(struct Node*));
                queue[queueSize-1] = newNode;
            }
        }
    }
    printf("No path found.\n");
}

int main() {
    int n = 5;
    int m = 4;
    int arr[5][4] = {
        {1, 1, 1, 1},
        {0, 0, 1, 0},
        {1, 1, 1, 1},
        {1, 0, 0, 0},
        {1, 1, 1, 1}
    };
    BFS(n, m, arr, 0, 1, 3, 2);
    return 0;
}