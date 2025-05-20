//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MAX 1000

int graph[MAX][MAX];
int visited[MAX];
int parent[MAX];
int numVertices;
int numEdges;

void initGraph() {
    numVertices = 0;
    numEdges = 0;
    memset(graph, 0, sizeof(graph));
    memset(visited, 0, sizeof(visited));
    memset(parent, -1, sizeof(parent));
}

void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
    numEdges++;
}

void bfs(int start) {
    int queue[MAX];
    int front = 0, rear = 0;
    int i, j, k;

    visited[start] = 1;
    parent[start] = -2;
    queue[rear++] = start;

    while (front < rear) {
        i = queue[front++];
        for (j = 0; j < numVertices; j++) {
            if (graph[i][j] == 1 && visited[j] == 0) {
                visited[j] = 1;
                parent[j] = i;
                queue[rear++] = j;
            }
        }
    }
}

void printSolution(int v) {
    if (v == -1)
        return;
    printSolution(parent[v]);
    printf("%d ", v);
}

int main() {
    int i, j, k;
    char ch;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    initGraph();

    printf("Enter the edges (u v): ");
    while (scanf("%d %d", &i, &j) == 2) {
        addEdge(i, j);
    }

    int start = 0;
    bfs(start);

    printf("Vertex\tParent\n");
    for (i = 0; i < numVertices; i++) {
        if (parent[i]!= -1)
            printf("%d\t%d\n", i, parent[i]);
    }

    printf("\nBFS traversal starting from vertex %d: ", start);
    printSolution(start);

    return 0;
}