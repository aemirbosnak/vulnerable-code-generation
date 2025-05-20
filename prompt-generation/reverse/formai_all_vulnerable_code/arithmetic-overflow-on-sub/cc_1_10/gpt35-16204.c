//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// define the maximum number of vertices
#define MAX_VERTICES 100

// define the colors for graph vertices
#define RED 1
#define BLUE 2
#define GREEN 3

// define the adjacency matrix for the graph
int adj_matrix[MAX_VERTICES][MAX_VERTICES];

// define the number of vertices and edges of the graph
int num_vertices, num_edges;

// define an array to store the color of each vertex
int colors[MAX_VERTICES];

// function to check if it is safe to color a vertex with a certain color
int is_safe(int vertex, int color)
{
    int i;
    for (i = 0; i < num_vertices; i++)
        if (adj_matrix[vertex][i] && colors[i] == color)
            return 0;
    return 1;
}

// function to color a graph with the minimum number of colors
void color_graph()
{
    int i, j, k, flag;
    for (i = 0; i < num_vertices; i++)
        colors[i] = 0;
    colors[0] = RED;
    for (i = 1; i < num_vertices; i++) {
        flag = 0;
        for (j = 1; j <= 3; j++) {
            if (is_safe(i, j)) {
                colors[i] = j;
                flag = 1;
                break;
            }
        }
        if (!flag) {
            printf("It is not possible to color the graph with 3 colors.\n");
            return;
        }
    }
}

// function to print the colored graph
void print_graph()
{
    int i, j;
    printf("The graph coloring solution is:\n");
    for (i = 0; i < num_vertices; i++) {
        printf("Vertex %d: ", i + 1);
        switch (colors[i]) {
        case RED:
            printf("Red\n");
            break;
        case BLUE:
            printf("Blue\n");
            break;
        case GREEN:
            printf("Green\n");
            break;
        }
    }
}

int main()
{
    int i, j, v1, v2;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    for (i = 0; i < num_vertices; i++)
        for (j = 0; j < num_vertices; j++)
            adj_matrix[i][j] = 0;
    for (i = 0; i < num_edges; i++) {
        printf("Enter edge %d: ", i + 1);
        scanf("%d %d", &v1, &v2);
        adj_matrix[v1 - 1][v2 - 1] = adj_matrix[v2 - 1][v1 - 1] = 1;
    }
    color_graph();
    print_graph();
    return 0;
}