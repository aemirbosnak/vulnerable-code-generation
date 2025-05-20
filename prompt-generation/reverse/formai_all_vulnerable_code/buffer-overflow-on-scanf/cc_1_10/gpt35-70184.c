//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>

struct Vertex {
    int color;
    int degree;
    int neighbors[100];
};

void insertEdge(struct Vertex nodes[], int u, int v) {
    nodes[u].neighbors[nodes[u].degree++] = v;
    nodes[v].neighbors[nodes[v].degree++] = u;
}

int canColor(struct Vertex nodes[], int nodeIndex, int color) {
    for(int i = 0; i < nodes[nodeIndex].degree; i++) {
        if(nodes[nodes[nodeIndex].neighbors[i]].color == color) {
            return 0;
        }
    }
    return 1;
}

int graphColoring(struct Vertex nodes[], int nodeCount, int k) {
    if(nodeCount == 0) {
        return 1;
    }

    for(int i = 1; i <= k; i++) {
        if(canColor(nodes, nodeCount, i)) {
            nodes[nodeCount].color = i;
            if(graphColoring(nodes, nodeCount - 1, k)) {
                return 1;
            }
            nodes[nodeCount].color = 0;
        }
    }

    return 0;
}

int main() {
    int nodeCount, edgeCount, k;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &nodeCount);
    struct Vertex nodes[nodeCount + 1];
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edgeCount);
    printf("Enter the value of k: ");
    scanf("%d", &k);
    for(int i = 0; i <= nodeCount; i++) {
        nodes[i].degree = 0;
        nodes[i].color = 0;
    }
    printf("Enter the edges:\n");
    for(int i = 0; i < edgeCount; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        insertEdge(nodes, u, v);
    }
    if(graphColoring(nodes, nodeCount, k)) {
        printf("Graph can be colored with %d colors:\n", k);
        for(int i = 1; i <= nodeCount; i++) {
            printf("Node %d: Color %d\n", i, nodes[i].color);
        }
    }
    else {
        printf("Graph cannot be colored with %d colors.", k);
    }
    return 0;
}