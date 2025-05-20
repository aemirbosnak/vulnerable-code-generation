//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 100
#define MAX_COLOR 10

int graph[MAX_VERTEX][MAX_VERTEX];
int color[MAX_VERTEX];

void initializeGraph(int numVertices) {
    int i, j;
    for(i = 0; i < numVertices; i++) {
        for(j = 0; j < numVertices; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int v1, int v2) {
    graph[v1][v2] = 1;
    graph[v2][v1] = 1;
}

void printGraph(int numVertices) {
    int i, j;
    for(i = 0; i < numVertices; i++) {
        for(j = 0; j < numVertices; j++) {
            if(graph[i][j] == 1) {
                printf("%d - %d\n", i, j);
            }
        }
    }
}

void colorGraph(int numVertices, int start) {
    int i, j, k;
    int maxColor = 0;
    int vertexColor[MAX_VERTEX];
    for(i = 0; i < numVertices; i++) {
        vertexColor[i] = -1;
    }
    vertexColor[start] = 0;
    for(i = 0; i < numVertices; i++) {
        for(j = 0; j < numVertices; j++) {
            if(graph[i][j] == 1 && vertexColor[i]!= -1 && vertexColor[j] == -1) {
                vertexColor[j] = 1 + vertexColor[i];
                if(vertexColor[j] > maxColor) {
                    maxColor = vertexColor[j];
                }
            }
        }
    }
    printf("Maximum number of colors required: %d\n", maxColor);
    for(i = 0; i < numVertices; i++) {
        printf("%d: %d\n", i, color[i]);
    }
}

int main() {
    int numVertices, start;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    initializeGraph(numVertices);
    printf("Enter the edges:\n");
    int v1, v2;
    while(scanf("%d %d", &v1, &v2) == 2) {
        addEdge(v1, v2);
    }
    colorGraph(numVertices, start);
    return 0;
}