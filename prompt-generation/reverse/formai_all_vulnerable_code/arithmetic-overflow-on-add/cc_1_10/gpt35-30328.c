//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Define constants
#define ROW 10
#define COL 10
#define NUM_PLAYERS 2

// Declare global variables
int maze[ROW][COL] = {{1,1,1,1,1,1,0,1,1,1},
                      {1,0,0,0,0,1,0,1,0,1},
                      {1,1,1,0,1,1,1,1,0,1},
                      {1,1,0,0,0,0,0,0,0,1},
                      {1,1,1,0,1,1,1,1,1,1},
                      {1,0,1,0,1,0,0,0,0,1},
                      {1,0,0,0,1,0,1,1,0,1},
                      {1,0,1,1,1,1,1,0,1,1},
                      {1,1,0,0,0,0,0,0,0,1},
                      {1,1,1,1,1,1,1,1,1,1}};
bool visited[ROW][COL];
int players[NUM_PLAYERS][2] = {{1,1}, {8,8}};

// Define structures
struct Node {
    int x, y;
    int distance;
    struct Node *prev;
};

// Declare helper functions
bool isSafe(int x, int y);
bool isDestination(int x, int y, int destX, int destY);
void findPath(int playerIndex, int destX, int destY);
struct Node* createNode(int x, int y, int distance, struct Node* prev);
bool isValid(struct Node* node);

/* Main function */
int main() {
    int destX = 9, destY = 9;
    int currentPlayer = 0;
    while(!isDestination(players[currentPlayer][0], players[currentPlayer][1], destX, destY)) {
        findPath(currentPlayer, destX, destY);
        currentPlayer = (currentPlayer + 1) % NUM_PLAYERS;
    }
    printf("Destination reached!");
    return 0;
}

/* Check if a cell is safe to visit */
bool isSafe(int x, int y) {
    return (x >= 0) && (x < ROW) && (y >= 0) && (y < COL) && maze[x][y] && !visited[x][y];
}

/* Check if a cell is the destination */
bool isDestination(int x, int y, int destX, int destY) {
    return (x == destX) && (y == destY);
}

/* Find path to the destination */
void findPath(int playerIndex, int destX, int destY) {
    struct Node *startNode = createNode(players[playerIndex][0], players[playerIndex][1], 0, NULL);
    struct Node *queue[ROW * COL];
    int front = -1, rear = -1;
    queue[++rear] = startNode;
    visited[startNode->x][startNode->y] = true;
    int row[] = {-1, 0, 0, 1};
    int col[] = {0, -1, 1, 0};
    while(front <= rear) {
        struct Node *node = queue[++front];
        if(isDestination(node->x, node->y, destX, destY)) {
            int distance = node->distance;
            while(node != NULL) {
                printf("(%d, %d) -> ", node->x, node->y);
                node = node->prev;
            }
            for(int i = 0; i < NUM_PLAYERS; i++) {
                if(i != playerIndex && players[i][0] == node->x && players[i][1] == node->y) {
                    printf("Player %d knocked out!\n", i+1);
                    players[i][0] = 1;
                    players[i][1] = 1;
                }
            }
            printf("\n");
            return;
        }
        for(int i = 0; i < 4; i++) {
            int x = node->x + row[i];
            int y = node->y + col[i];
            if(isSafe(x, y)) {
                visited[x][y] = true;
                struct Node *nextNode = createNode(x, y, node->distance + 1, node);
                queue[++rear] = nextNode;
            }
        }
    }
}

/* Create and initialize a new node */
struct Node* createNode(int x, int y, int distance, struct Node* prev) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->x = x;
    newNode->y = y;
    newNode->distance = distance;
    newNode->prev = prev;
    return newNode;
}