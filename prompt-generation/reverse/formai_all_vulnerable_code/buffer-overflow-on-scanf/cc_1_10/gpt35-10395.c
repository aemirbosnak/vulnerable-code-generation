//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int graph[MAX][MAX]; // 2D array for storing edges of graph
int colors[MAX]; // array for storing colors of each vertex
int n, m; // n is number of vertices, m is number of edges

void input_graph(){ // function to input a graph
    int a, b;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    printf("Enter edges (vertex a, vertex b):\n");
    for(int i=0; i<m; i++){
        scanf("%d%d", &a, &b);
        graph[a][b] = graph[b][a] = 1; // make an edge between vertices a and b
    }
}

int is_valid(int vertex, int color){ // function to check if the given color is valid for the given vertex
    for(int i=0; i<n; i++){
        if(graph[vertex][i] && colors[i] == color){
            return 0;
        }
    }
    return 1;
}

int graph_coloring(int vertex){ // recursive function to color the graph
    if(vertex == n){ // if all vertices have been processed, return 1
        return 1;
    }
    for(int i=1; i<=n; i++){ // loop for trying all possible colors for the current vertex
        if(is_valid(vertex, i)){ // if the current color is valid, assign it to the current vertex and move on to the next vertex
            colors[vertex] = i;
            if(graph_coloring(vertex+1)){ // if the next vertex can be colored, return 1
                return 1;
            }
            colors[vertex] = 0; // if not, reset the color of the current vertex and try the next color
        }
    }
    return 0; // if no color is valid for the current vertex, return 0
}

void print_colors(){ // function to print the colors of each vertex
    printf("Colors of vertices:\n");
    for(int i=0; i<n; i++){
        printf("Vertex %d: %d\n", i, colors[i]);
    }
}

int main(){
    printf("========================================\n");
    printf("\tGRAPH COLORING PROBLEM\n");
    printf("========================================\n");

    input_graph();
    printf("Processing...\n");

    if(graph_coloring(0)){ // if graph can be colored, print the colors of each vertex
        print_colors();
    }
    else{
        printf("Graph cannot be colored with %d colors.\n", n);
    }

    return 0;
}