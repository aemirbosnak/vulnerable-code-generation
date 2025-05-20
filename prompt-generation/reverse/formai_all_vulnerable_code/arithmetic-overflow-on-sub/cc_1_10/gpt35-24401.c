//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_VERTICES 50

int vertices, edges;
int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];

bool isSafe(int vertex_index, int color_index){
    for (int i=0; i<vertices; i++){
        if (graph[vertex_index][i] && color_index == colors[i]){
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int vertex_index, int max_colors){
    if (vertex_index == vertices){
        return true;
    }

    for (int color_index=1; color_index<=max_colors; color_index++){
        if (isSafe(vertex_index, color_index)){
            colors[vertex_index] = color_index;
            if (graphColoringUtil(vertex_index+1, max_colors)){
                return true;
            }
            colors[vertex_index] = 0;
        }
    }
    return false;
}

bool graphColoring(int max_colors){
    for (int i=0; i<vertices; i++){
        colors[i] = 0;
    }

    if (!graphColoringUtil(0, max_colors)){
        printf("Given graph cannot be colored with at most %d colors\n", max_colors);
        return false;
    }

    printf("Graph colored successfully with at most %d colors\n", max_colors);
    printf("Vertex --> Color\n");
    for (int i=0; i<vertices; i++){
        printf("%d --> %d\n", i+1, colors[i]);
    }
    return true;
}

int main(){
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // initialize graph matrix with zeros
    for (int i=0; i<vertices; i++){
        for (int j=0; j<vertices; j++){
            graph[i][j] = 0;
        }
    }

    int vertex1, vertex2;
    // input edges
    for (int i=0; i<edges; i++){
        printf("Enter vertices for edge %d: ", i+1);
        scanf("%d %d", &vertex1, &vertex2);

        // add edge to graph matrix
        graph[vertex1-1][vertex2-1] = 1;
        graph[vertex2-1][vertex1-1] = 1;
    }

    int max_colors;
    printf("Enter maximum number of colors: ");
    scanf("%d", &max_colors);

    graphColoring(max_colors);
    
    return 0;
}