//FormAI DATASET v1.0 Category: Graph representation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 20
#define INF 999

int adjacencyMatrix[MAX_NODES][MAX_NODES];
int n;

void initializeGraph() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                adjacencyMatrix[i][j] = 0;
            } else {
                adjacencyMatrix[i][j] = INF;
            }
        }
    }
}

void addEdge(int u, int v, int weight) {
    adjacencyMatrix[u][v] = weight;
    adjacencyMatrix[v][u] = weight;
}

void displayAdjacencyMatrix() {
    printf("Adjacency Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    initializeGraph();

    printf("Enter the number of edges: ");
    int m;
    scanf("%d", &m);

    printf("Enter the edges and their weights:\n");
    int u, v, w;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    displayAdjacencyMatrix();

    return 0;
}