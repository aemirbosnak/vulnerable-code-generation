//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES] = {0};
int color[MAX_VERTICES] = {0};
int num_vertices, num_edges;

void input_graph(){
    int source, destination;
    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter number of edges: ");
    scanf("%d", &num_edges);
    printf("Enter the edges as source and destination pairs:\n");
    for(int i=0; i<num_edges; ++i){
        scanf("%d%d", &source, &destination);
        graph[source][destination] = 1;
        graph[destination][source] = 1;
    }
}

bool is_safe(int v, int c){
    for(int i=0; i<num_vertices; ++i){
        if(graph[v][i] && color[i]==c)
            return false;
    }
    return true;
}

bool graph_coloring_helper(int v){
    if(v == num_vertices)
        return true;
    for(int i=1; i<=num_vertices; ++i){
        if(is_safe(v, i)){
            color[v] = i;
            if(graph_coloring_helper(v+1))
                return true;
            color[v] = 0;
        }
    }
    return false;
}

void graph_coloring(){
    if(!graph_coloring_helper(0)){
        printf("Coloring not possible!\n");
        return;
    }
    printf("The colors of the vertices are:\n");
    for(int i=0; i<num_vertices; ++i){
        printf("Vertex %d : Color %d\n", i, color[i]);
    }
}

int main(){
    printf("Welcome to the Graph Coloring Problem Solver!\n");
    printf("============================================\n");
    input_graph();
    graph_coloring();
    printf("============================================\n");
    printf("Thank you for using the Graph Coloring Problem Solver :)\n");
    return 0;
}