//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 20

int graph[MAX_VERTICES][MAX_VERTICES] = {0};
int colors[MAX_VERTICES] = {0};

void printGraph(int vertices) {
    printf("\nThe Graph:\n");
    for(int i = 1; i <= vertices; i++) {
        for(int j = 1; j <= vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int vertices, int vertex, int color) {
    for(int i = 1; i <= vertices; i ++) {
        if(graph[vertex][i] && color == colors[i]) {
            return false;
        }
    }
    return true;
}

bool graphColorUtil(int vertices,int vertex, int numOfColors) {
    if(vertex == vertices + 1) {
        return true;
    }
    for(int color = 1; color <= numOfColors; color++) {
        if(isSafe(vertices, vertex, color)) {
            colors[vertex] = color;
            if(graphColorUtil(vertices, vertex + 1, numOfColors)) {
                return true;
            }
            colors[vertex] = 0;
        }
    }
    return false;
}

void graphColor(int vertices, int numOfColors) {
    bool result = graphColorUtil(vertices, 1, numOfColors);
    if(result) {
        printf("\nGraph is colored successfully using %d colors:\n", numOfColors);
        for(int vertex = 1; vertex <= vertices; vertex++) {
            printf("Vertex %d - Color %d\n", vertex, colors[vertex]);
        }
    }
    else {
        printf("\nGraph can not be colored with %d colors.\n", numOfColors);
    }
}

int main() {
    int vertices, edges, vertex1, vertex2, numOfColors;    
    printf("Enter the number of vertices in your graph (MAX is %d): ", MAX_VERTICES);
    scanf("%d", &vertices);
    printf("Enter the number of edges in your graph: ");
    scanf("%d", &edges);
    printf("Enter the number of colors (MAX is %d): ", vertices);
    scanf("%d", &numOfColors);
    for(int i = 1; i <= edges; i++) {
        printf("\nEdge %d - Enter Vertex 1: ", i);
        scanf("%d", &vertex1);
        printf("Edge %d - Enter Vertex 2: ", i);
        scanf("%d", &vertex2);
        graph[vertex1][vertex2] = 1;
        graph[vertex2][vertex1] = 1;
    }
    printGraph(vertices);
    graphColor(vertices, numOfColors);
    return 0;
}