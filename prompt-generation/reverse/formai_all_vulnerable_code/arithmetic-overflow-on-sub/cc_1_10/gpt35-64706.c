//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAXV 100    // Maximum number of vertices that can be handled

// Global variables
int n;              // Number of vertices
int m;              // Number of edges
int adj[MAXV][MAXV];    // Adjacency matrix
int colors[MAXV];   // Color of each vertex
int num_colors;     // Total number of colors used

// Function to check if the current color assignment is valid
int is_valid(int v, int c) {
    for(int i=0; i<n; i++) {
        if(adj[v][i] && colors[i]==c)
            return 0;
    }
    return 1;
}

// Function to assign colors to the vertices using recursive backtracking
void assign_color(int v) {
    if(v==n) {
        printf("Valid coloring found:\n");
        for(int i=0; i<n; i++)
            printf("%d ", colors[i]);
        printf("\n\n");
        num_colors++;
        return;
    }
    for(int c=1; c<=n; c++) {
        if(is_valid(v, c)) {
            colors[v] = c;
            assign_color(v+1);
            colors[v] = 0;
        }
    }
}

// Main function
int main() {
    // Read input
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    printf("Enter edges (by vertex number):\n");
    for(int i=0; i<m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u-1][v-1] = adj[v-1][u-1] = 1;
    }

    // Initialize colors to 0
    for(int i=0; i<n; i++)
        colors[i] = 0;

    // Assign colors and print results
    num_colors = 0;
    assign_color(0);
    if(num_colors==0)
        printf("No valid coloring possible.\n");

    return 0;
}