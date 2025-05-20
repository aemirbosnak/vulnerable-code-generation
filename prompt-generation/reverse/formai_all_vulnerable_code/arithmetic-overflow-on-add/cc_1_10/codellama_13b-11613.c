//Code Llama-13B DATASET v1.0 Category: Graph Coloring Problem ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_COLORS 10

typedef struct {
    int node;
    int color;
} Node;

int colorGraph(int numNodes, int numColors, int adjMat[MAX_NODES][MAX_NODES]) {
    Node nodes[MAX_NODES];
    int colors[MAX_COLORS];
    int i, j, k, colorCount;

    // Initialize nodes and colors
    for (i = 0; i < numNodes; i++) {
        nodes[i].node = i;
        nodes[i].color = 0;
    }
    for (i = 0; i < numColors; i++) {
        colors[i] = 0;
    }

    // Assign colors to nodes
    colorCount = 1;
    for (i = 0; i < numNodes; i++) {
        // Check if node is already colored
        if (nodes[i].color == 0) {
            // Check if node can be colored with current color
            for (j = 0; j < numNodes; j++) {
                if (adjMat[i][j] == 1 && nodes[j].color == colorCount) {
                    goto NODE_ALREADY_COLOR;
                }
            }

            // Assign color to node
            nodes[i].color = colorCount;
            colors[colorCount - 1]++;
            colorCount++;
        }

        NODE_ALREADY_COLOR: ;
    }

    // Print colors
    for (i = 0; i < numNodes; i++) {
        printf("%d ", nodes[i].color);
    }
    printf("\n");

    return 0;
}

int main() {
    int adjMat[MAX_NODES][MAX_NODES] = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0}
    };

    colorGraph(5, 3, adjMat);

    return 0;
}