//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_V 100
#define MAX_E 1000
#define INF INT_MAX

// Graph representation using adjacency matrix
int adj_matrix[MAX_V][MAX_V];

// Function to add an edge to the graph
void add_edge(int u, int v) {
    adj_matrix[u][v] = 1;
    adj_matrix[v][u] = 1;
}

// Function to perform graph coloring using backtracking
void graph_coloring(int v, int color[MAX_V], int k) {
    // If all vertices are assigned colors, print the coloring
    if(k == 0) {
        for(int i=0; i<v; i++) {
            printf("%d ", color[i]);
        }
        printf("\n");
        return;
    }

    // Try assigning the current vertex a color from 1 to v
    for(int c=1; c<=v; c++) {
        // If the color is valid, assign it and recurse
        if(is_valid(v, color, c)) {
            color[k] = c;
            k--;
            graph_coloring(v, color, k);
            k++;
        }
    }
}

// Function to check if a color is valid for a vertex
int is_valid(int v, int color[MAX_V], int c) {
    // Check if the color is already assigned to a neighbor
    for(int i=0; i<v; i++) {
        if(adj_matrix[i][color[i]] == c) {
            return 0;
        }
    }
    return 1;
}

// Main function to initialize the graph and call the coloring function
int main() {
    int v, e;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &v, &e);

    // Initialize the graph with edges
    for(int i=0; i<e; i++) {
        int u, v;
        printf("Enter the vertices for edge %d: ", i+1);
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    // Initialize the color array
    int color[MAX_V];
    for(int i=0; i<v; i++) {
        color[i] = -1;
    }

    // Call the coloring function for each uncolored vertex
    for(int i=0; i<v; i++) {
        if(color[i] == -1) {
            graph_coloring(v, color, v-1);
        }
    }

    return 0;
}