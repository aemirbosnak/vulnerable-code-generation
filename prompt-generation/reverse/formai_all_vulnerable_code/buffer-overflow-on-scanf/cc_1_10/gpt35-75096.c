//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: genious
#include <stdio.h>

#define MAX_NODES 100 // maximum number of nodes
#define MAX_COLORS 10 // maximum number of colors

int num_nodes, num_edges, color_assigned[MAX_NODES];
int graph[MAX_NODES][MAX_NODES];

// function to check if the current color is safe for the current node
int is_safe(int node, int color) {
    for(int i=0; i<num_nodes; i++) {
        if(graph[node][i] && color_assigned[i] == color) {
            return 0; // color is not safe
        }
    }
    return 1; // color is safe
}

// function to solve the graph coloring problem using backtracking
int solve(int node, int num_colors) {
    // if all nodes are assigned a color, the problem is solved
    if(node == num_nodes) {
        return 1;
    }

    // try assigning a color to the current node
    for(int i=0; i<num_colors; i++) {
        if(is_safe(node, i)) {
            color_assigned[node] = i;

            // recursively solve for the remaining nodes
            if(solve(node+1, num_colors)) {
                return 1; // solution found
            }

            // backtrack: unassign the color from the current node
            color_assigned[node] = -1;
        }
    }

    // could not find a solution with the current num_colors
    return 0;
}

int main() {
    // read input
    printf("Enter number of nodes: ");
    scanf("%d", &num_nodes);

    printf("Enter adjacency matrix:\n");
    for(int i=0; i<num_nodes; i++) {
        for(int j=0; j<num_nodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // initialize color_assigned array with -1
    for(int i=0; i<num_nodes; i++) {
        color_assigned[i] = -1;
    }

    // solve the graph coloring problem
    int num_colors = 1; // start with one color
    while(!solve(0, num_colors)) {
        num_colors++; // try with one more color
    }

    // print the solution
    printf("Solution:\n");
    for(int i=0; i<num_nodes; i++) {
        printf("Node %d: Color %d\n", i+1, color_assigned[i]+1);
    }

    return 0;
}