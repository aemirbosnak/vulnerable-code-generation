//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 10

typedef struct vertex {
    int color;
    int edges[MAX_VERTEX];
} Vertex;

void color(Vertex *graph, int size);

int main() {
    int n, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    Vertex *graph = (Vertex*) malloc(sizeof(Vertex) * n);
    
    for(i = 0; i < n; i++) {
        graph[i].color = 0;
        for(j = 0; j < n; j++) {
            graph[i].edges[j] = 0;
        }
    }
    
    for(i = 0; i < n; i++) {
        printf("Vertex %d:", i);
        for(j = 0; j < n; j++) {
            if(graph[i].edges[j] == 1) {
                printf(" %d", j);
            }
        }
        printf("\n");
    }
    
    color(graph, n);
    
    printf("\nGraph after coloring:\n");
    for(i = 0; i < n; i++) {
        printf("Vertex %d:", i);
        for(j = 0; j < n; j++) {
            if(graph[i].edges[j] == 1) {
                printf(" %d", graph[i].color);
            }
        }
        printf("\n");
    }
    
    return 0;
}

void color(Vertex *graph, int size) {
    int i, j, k;
    for(i = 0; i < size; i++) {
        graph[i].color = 0;
    }
    
    for(i = 0; i < size; i++) {
        if(graph[i].color == 0) {
            for(j = 0; j < size; j++) {
                if(graph[i].edges[j] == 1 && graph[j].color == 0) {
                    graph[i].color = 1;
                    graph[j].color = 1;
                }
            }
        }
    }
}