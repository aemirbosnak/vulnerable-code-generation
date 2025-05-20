//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 1000

int numNodes, numColors;
int graph[MAX][MAX], color[MAX];

bool isSafe(int node, int c) {
    for(int i = 0; i < numNodes; i++) {
        if(graph[node][i] && color[i] == c)
            return false;
    }
    return true;
}

bool graphColoring(int node) {
    if(node == numNodes)
        return true;

    for(int c = 1; c <= numColors; c++) {
        if(isSafe(node, c)) {
            color[node] = c;
            if(graphColoring(node+1))
                return true;
            color[node] = 0;
        }
    }
    return false;
}

int main() {
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);
    printf("Enter the number of colors: ");
    scanf("%d", &numColors);
    printf("Enter the graph adjacency matrix:\n");

    for(int i = 0; i < numNodes; i++) {
        for(int j = 0; j < numNodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    memset(color, 0, sizeof(color));

    if(graphColoring(0)) {
        printf("The graph can be colored using %d colors.\n", numColors);
        printf("The color assigned to each node is: ");
        for(int i = 0; i < numNodes; i++) {
            printf("%d ", color[i]);
        }
    } else {
        printf("The graph cannot be colored using %d colors.\n", numColors);
    }

    return 0;
}