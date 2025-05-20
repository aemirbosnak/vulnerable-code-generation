//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define N 5  // Size of the grid
#define INF INT_MAX

typedef struct {
    int x, y;
} Node;

typedef struct {
    Node node;
    int cost;
} PathNode;

int grid[N][N] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0}
};

int visited[N][N];
int costGrid[N][N];

// Directions for Up, Down, Left, Right
int row[] = {-1, 1, 0, 0};
int col[] = {0, 0, -1, 1};

bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && grid[x][y] == 0);
}

void printPath(int parent[N][N], int j, int i) {
    if (parent[i][j] == -1) {
        printf("(%d, %d) ", i, j);
        return;
    }
    
    printPath(parent, parent[i][j] / N, parent[i][j] % N);
    printf("-> (%d, %d) ", i, j);
}

void dijkstra(int srcX, int srcY, int destX, int destY) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            costGrid[i][j] = INF;
            visited[i][j] = false;
        }
    }
    
    costGrid[srcX][srcY] = 0; // Cost to reach the source is 0
    visited[srcX][srcY] = true;

    // Parent array for tracking the path
    int parent[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            parent[i][j] = -1;

    // The PathNode structure is used to select the minimum cost cell
    PathNode pq[N*N];
    int pqSize = 0;
    
    pq[pqSize++] = (PathNode){{srcX, srcY}, 0};

    while (pqSize) {
        // Find the node with the minimum cost
        PathNode minNode = pq[0];
        int minIndex = 0;

        for (int i = 1; i < pqSize; i++) {
            if (pq[i].cost < minNode.cost) {
                minNode = pq[i];
                minIndex = i;
            }
        }

        pq[minIndex] = pq[pqSize - 1];
        pqSize--;

        int currentX = minNode.node.x;
        int currentY = minNode.node.y;

        for (int k = 0; k < 4; k++) {
            int adjX = currentX + row[k];
            int adjY = currentY + col[k];

            if (isSafe(adjX, adjY) && !visited[adjX][adjY]) {
                int newCost = costGrid[currentX][currentY] + 1;

                if (newCost < costGrid[adjX][adjY]) {
                    costGrid[adjX][adjY] = newCost;
                    parent[adjX][adjY] = currentX * N + currentY; // Storing parent in a single integer
                    // Add to path
                    pq[pqSize++] = (PathNode){{adjX, adjY}, newCost};
                }
            }
        }

        visited[currentX][currentY] = true;

        if (currentX == destX && currentY == destY) {
            printf("The path from (%d, %d) to (%d, %d) is:\n", srcX, srcY, destX, destY);
            printPath(parent, currentX, currentY);
            printf("\n");
            return;
        }
    }

    printf("No path exists from (%d, %d) to (%d, %d)\n", srcX, srcY, destX, destY);
}

int main() {
    printf("Sherlock Holmes' Pathfinding case:\n");

    int srcX, srcY, destX, destY;
    printf("Enter source coordinates (x y): ");
    scanf("%d %d", &srcX, &srcY);
    
    printf("Enter destination coordinates (x y): ");
    scanf("%d %d", &destX, &destY);

    dijkstra(srcX, srcY, destX, destY);

    return 0;
}