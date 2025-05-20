//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Claude Shannon
#include <stdio.h>

#define MAX 100

int graph[MAX][MAX], coloredGraph[MAX];
int nodes, colors;

int isSafe(int node, int color, int coloredGraph[]) {
    for(int i = 0; i < nodes; i++) {
        if(graph[node][i] && color == coloredGraph[i]) {
            return 0;
        }
    }
    return 1;
}

int graphColoring(int node, int coloredGraph[]) {
    if(node == nodes) {
        printf("The graph can be colored with %d colors\n", colors);
        for(int i = 0; i < nodes; i++) {
            printf("Node %d has color %d\n", i, coloredGraph[i]);
        }
        return 1;
    }

    for(int i = 1; i <= colors; i++) {
        if(isSafe(node, i, coloredGraph)) {
            coloredGraph[node] = i;
            if(graphColoring(node+1, coloredGraph)) {
                return 1;
            }
            coloredGraph[node] = 0;
        }
    }
    return 0;
}

int main() {
    int edges, u, v;

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &nodes);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    for(int i = 0; i < edges; i++) {
        printf("Enter the nodes that are connected to edge %d (u v): ", i+1);
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Enter the number of colors that can be used: ");
    scanf("%d", &colors);

    if(!graphColoring(0, coloredGraph)) {
        printf("The graph cannot be colored with %d colors", colors);
    }

    return 0;
}