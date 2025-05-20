//FormAI DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>

#define MAX_VERTICES 10

int adj_matrix[MAX_VERTICES][MAX_VERTICES]; //Adjacency matrix representation of a graph
int num_vertices = 0;

//Function to add an edge between two vertices
void add_edge(int u, int v, int w) {
    adj_matrix[u][v] = w;
    adj_matrix[v][u] = w;
}

//Function to print the adjacency matrix
void print_matrix() {
    printf("\nAdjacency Matrix:\n");
    printf("  ");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d ", i);
        for (int j = 0; j < num_vertices; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the number of vertices in the graph (max %d): ", MAX_VERTICES);
    scanf("%d", &num_vertices);
    printf("\n");

    //Initialize all elements of adjacency matrix to 0
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            adj_matrix[i][j] = 0;
        }
    }

    //Add edges to the graph
    add_edge(0, 1, 5);
    add_edge(0, 4, 3);
    add_edge(1, 2, 4);
    add_edge(1, 3, 9);
    add_edge(2, 3, 2);
    add_edge(3, 4, 7);

    //Print the adjacency matrix
    print_matrix();

    return 0;
}