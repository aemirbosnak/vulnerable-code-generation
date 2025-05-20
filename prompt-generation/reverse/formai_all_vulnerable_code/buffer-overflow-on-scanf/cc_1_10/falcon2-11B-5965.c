//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

typedef struct {
    int node;
    int color;
} NodeColor;

bool isValidColor(int color, int numColors) {
    for (int i = 0; i < numColors; i++) {
        if (color == i) {
            return false;
        }
    }
    return true;
}

NodeColor* createNodeColor(int node, int color) {
    NodeColor* nodeColor = (NodeColor*)malloc(sizeof(NodeColor));
    nodeColor->node = node;
    nodeColor->color = color;
    return nodeColor;
}

void printNodeColors(NodeColor* nodeColors, int numColors) {
    for (int i = 0; i < numColors; i++) {
        printf("Node %d: Color %d\n", nodeColors[i].node, nodeColors[i].color);
    }
}

int main() {
    int numNodes, numColors;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
    printf("Enter the number of colors: ");
    scanf("%d", &numColors);

    NodeColor* nodeColors = (NodeColor*)malloc(numNodes * sizeof(NodeColor));
    int numColorsUsed = 0;
    int numColorsLeft = numColors;

    while (numColorsLeft > 0) {
        int node, color;
        printf("Enter the node and color: ");
        scanf("%d %d", &node, &color);

        if (!isValidColor(color, numColorsUsed)) {
            printf("Invalid color.\n");
            continue;
        }

        nodeColors[node].color = color;
        numColorsUsed++;
        numColorsLeft--;
    }

    printNodeColors(nodeColors, numColorsUsed);
    printf("\n");

    return 0;
}