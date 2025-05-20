//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: portable
#include <stdio.h>
#define MAX_NODES 20
 
int graph[MAX_NODES][MAX_NODES], color[MAX_NODES];
int num_nodes, num_colors;
 
void print_colors() {
    for(int i = 0; i < num_nodes; i++)
        printf("Node %d: Color %d\n", i+1, color[i]+1);
}
 
int isSafe(int node, int c) {
    for(int i = 0; i < num_nodes; i++)
        if(graph[node][i] && c == color[i])
            return 0;
    return 1;
}
 
int graphColor(int node) {
    if(node == num_nodes)
        return 1;
     
    for(int c = 0; c < num_colors; c++) {
        if(isSafe(node, c)) {
            color[node] = c;
            if(graphColor(node+1))
                return 1;
            color[node] = -1;
        }
    }
     
    return 0;
}
 
int main() {
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &num_nodes);
     
    printf("Enter the adjacency matrix for the graph:\n");
    for(int i = 0; i < num_nodes; i++)
        for(int j = 0; j < num_nodes; j++)
            scanf("%d", &graph[i][j]);
     
    printf("Enter the number of colors to be used: ");
    scanf("%d", &num_colors);
     
    for(int i = 0; i < num_nodes; i++)
        color[i] = -1;
     
    if(graphColor(0))
        print_colors();
    else
        printf("No solution exists with the given parameters.\n");
         
    return 0;
}