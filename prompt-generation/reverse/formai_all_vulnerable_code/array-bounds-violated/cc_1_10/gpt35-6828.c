//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_COLORS 4

int adj_list[100][100]; // Adjacency List to represent graph
int N, M; // N -> Number of vertices, M -> Number of edges

int color_map[100]; // Stores color for each vertex
int is_colored[100]; // Tracks whether a vertex is colored or not

// Returns true if there is a conflict in coloring, else returns false
int check_conflict(int vertex, int color) {
    for(int i=1; i<=N; i++) {
        if(adj_list[vertex][i]) {
            if(color_map[i] == color)
                return 1; // Conflict found
        }
    }
    return 0;
}

// Backtracking function to color the vertices in the graph
int color_vertices(int vertex) {
    // Base case: Last vertex is colored
    if(vertex > N)
        return 1;
  
    // Try coloring the current vertex with all possible colors
    for(int i=1; i<=MAX_COLORS; i++) {
        if(!check_conflict(vertex, i)) {
            color_map[vertex] = i; // Color the vertex with color i
            is_colored[vertex] = 1; // Mark the vertex as colored
          
            // Recur for the next vertex
            if(color_vertices(vertex+1))
                return 1; // Solution found
          
            // Backtrack: Remove the color for the current vertex
            color_map[vertex] = 0;
            is_colored[vertex] = 0;
        }
    }
  
    return 0; // Can't color any vertex with any color
}

int main() {
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &N);
  
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &M);
  
    int u, v;
    printf("Enter the vertices that form each edge:\n");
    for(int i=1; i<=M; i++) {
        scanf("%d%d", &u, &v);
        adj_list[u][v] = adj_list[v][u] = 1;
    }
  
    // Initially mark all vertices as uncolored
    memset(is_colored, 0, sizeof(is_colored));
  
    // Call the backtracking function to color the vertices
    if(color_vertices(1)) {
        printf("\nThe graph can be colored using the following colors:\n\n");
        for(int i=1; i<=N; i++)
            printf("Vertex %d -> Color %d\n", i, color_map[i]);
    }
    else
        printf("\nSorry, the graph can't be colored with only %d colors.\n", MAX_COLORS);
  
    return 0;
}