//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_WEIGHT 1000000

int graph[MAX_NODES][MAX_NODES];

// Function to color the vertices of the graph
bool graphColoring(int vertices, int colors) {
    int node_color[vertices];
    for(int i=0;i<vertices;i++) {
        node_color[i] = 0;
    }

    for(int i=0;i<vertices;i++) {
        for(int j=0;j<vertices;j++) {
            if(graph[i][j] && node_color[j] == node_color[i]) {
                node_color[j] = (node_color[i] + 1) % colors;
            }
        }
    }

    // Printing the colored nodes
    for(int i=0;i<vertices;i++) {
        printf("Node %d: Color %d\n", i, node_color[i]);
    }

    // Checking if the graph is properly colored
    for(int i=0;i<vertices;i++) {
        for(int j=0;j<vertices;j++) {
            if(graph[i][j] && node_color[j] == node_color[i]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int vertices, edges, colors;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter the number of colors: ");
    scanf("%d", &colors);

    // Initializing the graph with large values
    for(int i=0;i<vertices;i++) {
        for(int j=0;j<vertices;j++) {
            if(i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = MAX_WEIGHT;
            }
        }
    }

    // Taking input of edges and weights and creating the adjacency matrix
    for(int i=1;i<=edges;i++) {
        int u, v;
        printf("Enter the start and end node of edge%d: ", i);
        scanf("%d %d", &u, &v);
        printf("Enter the weight of edge%d: ", i);
        scanf("%d", &graph[u][v]);
        graph[v][u] = graph[u][v];
    }

    // Coloring the vertices of the graph
    if(graphColoring(vertices, colors)) {
        printf("The graph can be properly colored by using %d colors.\n", colors);
    } else {
        printf("The graph cannot be colored by using %d colors.\n", colors);
    }

    return 0;
}