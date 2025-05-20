//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

/* Define the maximum number of vertices and colors */
#define MAXV 100
#define MAXC 25

/* Create a boolean data type */
typedef enum {false, true} bool;

/* Create a struct that represents a vertex */
typedef struct {
    int degree;
    int color;
    int adj[MAXV];
} Vertex;

/* Declare global variables */
Vertex graph[MAXV];
int colors[MAXC];
int num_vertices, num_colors;

/* Function to check if a particular color is already used by a connected vertex */
bool is_color_used(int vertex, int color)
{
    int i;
    for (i = 0; i < graph[vertex].degree; i++)
        if (graph[graph[vertex].adj[i]].color == color)
            return true;
    return false;
}

/* Function to assign colors to all vertices */
void graph_coloring(int vertex)
{
    int i, j, color;
    bool color_used[MAXC];

    /* Base case: all vertices have been colored */
    if (vertex == num_vertices)
        return;

    /* Initialize color_used array */
    for (i = 0; i < num_colors; i++)
        color_used[i] = false;

    /* Check what colors are already used by the adjacent vertices */
    for (i = 0; i < graph[vertex].degree; i++) {
        int adj_vertex = graph[vertex].adj[i];
        if (graph[adj_vertex].color != -1) {
            color_used[graph[adj_vertex].color] = true;
        }
    }

    /* Find the first unused color and assign it to the vertex */
    for (color = 0; color < num_colors; color++) {
        if (!color_used[color]) {
            graph[vertex].color = color;
            graph_coloring(vertex + 1);
            graph[vertex].color = -1;
        }
    }
}

int main()
{
    int i, j;

    /* Read in the graph */
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < num_vertices; i++) {
        graph[i].degree = 0;
        graph[i].color = -1;
        for (j = 0; j < num_vertices; j++) {
            int adj;
            scanf("%d", &adj);
            if (adj) {
                graph[i].adj[graph[i].degree++] = j;
            }
        }
    }

    /* Call the graph coloring function */
    graph_coloring(0);

    /* Print out the color assignments for each vertex */
    printf("Vertex Colors:\n");
    for (i = 0; i < num_vertices; i++) {
        printf("Vertex %d: Color %d\n", i, graph[i].color);
    }

    return 0;
}