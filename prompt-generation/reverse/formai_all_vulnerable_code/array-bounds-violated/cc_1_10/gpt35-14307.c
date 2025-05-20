//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Define maximum number of vertices the graph can have
#define MAX_VERTICES 100

// Define the colors that the graph vertices can have
#define RED 0
#define BLUE 1
#define GREEN 2
#define YELLOW 3

// Define color names
const char* colors[] = {"Red", "Blue", "Green", "Yellow"};

// Declare global variables
int graph[MAX_VERTICES][MAX_VERTICES];
int n_vertices, n_edges;
int colors_used[MAX_VERTICES];
int vertex_colors[MAX_VERTICES];

// Method to print the graph
void print_graph(){
    for(int i=0; i<n_vertices; i++){
        printf("%d: ", i);
        for(int j=0; j<n_vertices; j++){
            if(graph[i][j]){
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

// Method to color the graph recursively
bool color_graph(int vertex){
    if(vertex == n_vertices) return true; // All vertices colored successfully
    for(int i=0; i<4; i++){ // Try coloring the current vertex with each color
        if(!colors_used[i]){ // The color has not been used yet
            // Mark color as used and color the vertex with this color
            vertex_colors[vertex] = i;
            colors_used[i] = 1;

            // Check if this coloring is valid for all vertices
            bool valid = true;
            for(int j=0; j<n_vertices; j++){
                if(graph[vertex][j] && vertex_colors[j] == i){
                    valid = false;
                    break;
                }
            }

            // Recursive call to color the next vertex
            if(valid && color_graph(vertex+1)){
                return true;
            }

            // Backtracking step
            colors_used[i] = 0;
            vertex_colors[vertex] = -1;
        }
    }
    return false; // Could not color the graph
}

int main(){

    printf("Enter the number of vertices: ");
    scanf("%d", &n_vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &n_edges);

    // Initialize graph to have no edges
    for(int i=0; i<n_vertices; i++){
        for(int j=0; j<n_vertices; j++){
            graph[i][j] = 0;
        }
    }

    // Add edges to the graph
    printf("Enter the edges as pairs of vertices (e.g. 0 1): \n");
    for(int i=0; i<n_edges; i++){
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = 1;
        graph[v2][v1] = 1; // The graph is undirected
    }

    printf("Graph:\n");
    print_graph();

    // Color the graph
    if(color_graph(0)){
        printf("The graph can be colored with the following colors:\n");
        for(int i=0; i<n_vertices; i++){
            printf("Vertex %d: %s\n", i, colors[vertex_colors[i]]);
        }
    } else {
        printf("The graph cannot be colored.\n");
    }

    return 0;
}