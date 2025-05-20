//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTEX 100       
#define MAX_COLOR  20  

int graph[MAX_VERTEX][MAX_VERTEX];     // adjacency matrix
int color[MAX_VERTEX];                // array of color of each vertex

bool isSafe(int vertex, int col, int vertices){
    for (int i = 0; i < vertices; i++)
        if (graph[vertex][i] && col == color[i])
            return false;
    return true;
}

bool graphColoringUtil(int vertices, int colors, int vertex){
    if (vertex == vertices)
        return true;

    for (int col = 1; col <= colors; col++){
        if (isSafe(vertex, col, vertices)){
            color[vertex] = col;
            if (graphColoringUtil(vertices, colors, vertex + 1))
                return true;
            color[vertex] = 0;
        }
    }
    return false;
}

bool graphColoring(int vertices, int colors){
    for (int i = 0; i < vertices; i++)
        if (!graphColoringUtil(vertices, colors, i))
            return false;
    return true;
}

int main(){
    int vertices, edges, colorCount;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter the number of colors: ");
    scanf("%d", &colorCount); 

    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph[i][j] = 0;

    int u, v;
    for (int i = 0; i < edges; i++){
        printf("Enter the vertex numbers of edge %d: ", i + 1);
        scanf("%d%d", &u, &v);
        graph[u][v] = 1;                // creating edges using adjacency matrix
        graph[v][u] = 1;
    }

    if (graphColoring(vertices, colorCount)){
        printf("Possible to color the graph with %d colors, and the coloring is:\n", colorCount);
        for (int i = 0; i < vertices; i++)
            printf("Vertex %d -> Color %d\n", i, color[i]);
    }
    else
        printf("The provided graph cannot be colored with %d colors.", colorCount);

    return 0;
}