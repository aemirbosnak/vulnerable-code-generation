//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAXNODES 100

int adjMatrix[MAXNODES][MAXNODES], colors[MAXNODES];
int num_nodes;

//Function to check if it is safe to color a given node with a given color
int is_safe(int node, int color) {
    for (int i = 0; i < num_nodes; i++) {
        if (adjMatrix[node][i] && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

//Function to perform graph coloring using backtracking
int graph_color(int node, int num_colors) {
    if (node == num_nodes) {
        return 1;
    }
    for (int color = 1; color <= num_colors; color++) {
        if (is_safe(node, color)) {
            colors[node] = color;
            if (graph_color(node + 1, num_colors)) {
                return 1;
            }
            colors[node] = 0;
        }
    }
    return 0;
}

int main() {
    int num_edges, max_colors;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &num_nodes);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &num_edges);

    //Initialize adjacency matrix to all 0's
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    //Read in edges and populate the adjacency matrix
    int i=0,j=0;
    printf("Enter the pair of vertex with an edge between them i.e from v1 to v2<space separated>:  \n");
    while (num_edges--) {
        scanf("%d %d", &i, &j);
        adjMatrix[i][j] = 1;
        adjMatrix[j][i] = 1;
    }
    printf("Enter the maximum number of colors allowed: ");
    scanf("%d", &max_colors);
    //Initialize colors to all 0's
    for (int i = 0; i < num_nodes; i++) {
        colors[i] = 0;
    }
    //Seed the random number generator with current time
    srand(time(NULL));
    if (graph_color(0, max_colors)) {
        printf("The graph can be colored using %d colors as shown below:\n", max_colors);
        for (int i = 0; i < num_nodes; i++) {
            printf("Node %d: Color %d\n", i, colors[i]);
        }
    } else {
        printf("The graph cannot be colored using %d colors\n", max_colors);
    }
    return 0;
}