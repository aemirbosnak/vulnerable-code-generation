//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100  //maximum number of vertices
#define MAX_COLORS 10   //maximum number of allowed colors

int graph[MAX_VERTICES][MAX_VERTICES];  
int colors[MAX_VERTICES];  // array to hold the colors assigned to each vertex
int no_of_vertices;   // number of vertices in the graph

void read_graph () {
    int i, j;
    printf("Enter the number of vertices in the graph (maximum %d) : ", MAX_VERTICES);
    scanf("%d", &no_of_vertices);
    printf("\nEnter the adjacency matrix of the graph (0 if no edge exists): \n");
    for (i = 0; i < no_of_vertices; i++) {
        printf("\n Enter row %d\n", i+1);
        for (j = 0; j < no_of_vertices; j++)
            scanf("%d", &graph[i][j]);
    }
}

int is_safe(int vertex, int color) {
    int i;
    for (i = 0; i < no_of_vertices; i++) {
        if (graph[vertex][i] && color == colors[i])  // check if any adjacent vertices have the same color
            return 0;
    }
    return 1;
}

//recursive function for coloring the graph
int color_graph(int vertex) {
    int i, j;
    if (vertex == no_of_vertices)  //base case when all vertices are colored
        return 1;

    for (i = 1; i <= MAX_COLORS; i++) {  // try all possible colors for current vertex
        if (is_safe(vertex, i)) {
            colors[vertex] = i;   // color the vertex with a valid color
            if (color_graph(vertex+1))  //check if the next vertex can be colored with a valid color
                return 1;
            colors[vertex] = 0;  // if the next vertex cannot be colored, reset the color of current vertex to 0.
        }
    }
    return 0;
}

int main() {
    read_graph();  //read the graph

    if (color_graph(0)) {  //color the graph starting from vertex 1
        printf("\n The graph can be colored with the following colors : \n");
        for (int i = 0; i < no_of_vertices; i++)
            printf(" Vertex %d -> Color %d \n", i+1, colors[i]);
    }
    else
        printf("\n The graph cannot be colored with %d colors \n", MAX_COLORS);
    return 0;
}