//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_COLORS 7

typedef struct {
    int color;
    int adj[MAX_NODES];
    bool visited;
} Node;

int main() {
    Node nodes[MAX_NODES];
    int numNodes = 0;

    // Read in the number of nodes and edges
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    // Create the nodes
    for (int i = 0; i < numNodes; i++) {
        nodes[i].color = i;
        nodes[i].visited = false;
    }

    // Read in the edges
    printf("Enter the number of edges: ");
    scanf("%d", &numNodes);
    for (int i = 0; i < numNodes; i++) {
        int node1, node2;
        printf("Enter edge %d: ", i + 1);
        scanf("%d %d", &node1, &node2);
        nodes[node1 - 1].adj[node2 - 1] = 1;
        nodes[node2 - 1].adj[node1 - 1] = 1;
    }

    // Initialize the graph coloring algorithm
    int colorCount[MAX_COLORS];
    for (int i = 0; i < MAX_COLORS; i++) {
        colorCount[i] = 0;
    }
    bool foundSolution = false;
    int color = 0;

    // Try coloring the graph with different colors
    while (!foundSolution) {
        // Color the nodes
        for (int i = 0; i < numNodes; i++) {
            if (!nodes[i].visited) {
                nodes[i].visited = true;
                colorCount[color]++;
                color++;
                if (color == MAX_COLORS) {
                    color = 0;
                }
            }
        }

        // Check if the coloring is valid
        for (int i = 0; i < numNodes; i++) {
            for (int j = 0; j < numNodes; j++) {
                if (nodes[i].adj[j] && nodes[i].color == nodes[j].color) {
                    foundSolution = false;
                    break;
                }
            }
            if (!foundSolution) {
                break;
            }
        }
    }

    // Print the solution
    printf("Solution: ");
    for (int i = 0; i < numNodes; i++) {
        printf("%d ", nodes[i].color);
    }
    printf("\n");

    return 0;
}