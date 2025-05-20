//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: romantic
#include<stdio.h>
#include<stdlib.h>

#define max_size 100

int color[max_size]; // Initializing an array to store colors
int graph[max_size][max_size]; // Initializing the 2-d graph

// Function to check if color can be used in a vertex
int check(int vertex, int c, int n) {
    for(int i = 0; i < n; i++) {
        if(graph[vertex][i] == 1 && c == color[i]) return 0; // If color assigned to adjacent vertex is similar to current vertex, return 0
    }
    return 1; // Else return 1
}

// Function to assign colors to the vertices recursively
void assign_colors(int vertex, int n, int m) {
    if(vertex == n) { // If all vertices are colored, print the output
        printf("You and me belong to a perfect combination of %d colors. \n", m);
        for(int i = 0; i < n; i++) printf("The vertex %d is assigned color %d. \n", i+1, color[i]);
        return;
    }

    for(int c = 1; c <= m; c++) { // Iterating over all the possible colors
        if(check(vertex, c, n)) { // if color c is feasible to assign to the vertex recursively assign other vertices colors
            color[vertex] = c;
            assign_colors(vertex+1, n, m);
            color[vertex] = 0; // backtracking
        }
    }
}

int main() {
    int n, m;
    printf("Lets color our love story! \nEnter number of vertices(n) : ");
    scanf("%d", &n);

    // Initializing the graph
    printf("Enter the adjacency matrix: \n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter number of colors(m) : ");
    scanf("%d", &m);

    assign_colors(0, n, m); // Initiating the assignment of colors

    return 0;
}