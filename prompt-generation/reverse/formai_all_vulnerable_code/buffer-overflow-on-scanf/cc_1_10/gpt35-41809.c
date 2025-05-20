//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int n, m, x, y, g[MAX][MAX]; //n is the number of vertices, m is the number of edges

void color_graph(int vertex_colors[], int vertex_index) {
    //check if all the vertices have been colored
    if (vertex_index == n) {
        printf("Congratulations!! Your graph has been successfully colored in happy colors!");
        printf("\nColors assigned to vertices: \n");
        for (int i = 0; i < n; i++) {
            printf("Vertex %d : Happy color %d \n", i+1, vertex_colors[i]);
        }
        exit(0);
    }
    for (int i = 1; i <= 4; i++) { //4 happy colors are available
        //check if the current color is valid for the current vertex
        int valid_color = 1;
        for (int j = 0; j < n; j++) {
            if (g[vertex_index][j] && i == vertex_colors[j]) { //there is an edge between the current vertex and another vertex with the same color
                valid_color = 0;
                break;
            }
        }
        if (valid_color) { //assign the current color to the current vertex
            vertex_colors[vertex_index] = i;
            color_graph(vertex_colors, vertex_index+1); //recurse to the next vertex
            vertex_colors[vertex_index] = 0; //backtrack
        }
    }
}

int main() {
    printf("Welcome to the Graph Coloring Problem solver! This program will color your graph in happy colors.\n");
    printf("Enter the number of vertices in your graph (max 50): ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX) {
        printf("Invalid input! Try again.\n");
        return 0;
    }
    printf("Enter the number of edges in your graph: ");
    scanf("%d", &m);
    if (m <= 0) {
        printf("Invalid input! Try again.\n");
        return 0;
    }
    printf("Enter the edge pairs in your graph (separated by space): \n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        if (x <= 0 || x > n || y <= 0 || y > n) {
            printf("Invalid input! Try again.\n");
            return 0;
        }
        g[x-1][y-1] = 1; //strengthening the undirected graph by setting the edge for both vertices
        g[y-1][x-1] = 1;
    }
    int vertex_colors[MAX] = {0}; //initialize all vertex colors to 0 (no color assigned)
    color_graph(vertex_colors, 0); //color the graph
    return 0;
}