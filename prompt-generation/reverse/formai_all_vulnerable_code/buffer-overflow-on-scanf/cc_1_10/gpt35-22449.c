//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
    int distance;
    int visited;
};

int **graph;

int num_vertices;
Node *vertices;
int source = 0;

void dijkstra_algorithm() {
    vertices[source].distance = 0;

    int i;
    for(i = 0; i < num_vertices - 1; ++i) {
        int j, min_distance = -1, min_vertex;
        for(j = 0; j < num_vertices; ++j) {
            if(!vertices[j].visited && (min_distance == -1 || vertices[j].distance < min_distance)) {
                min_distance = vertices[j].distance;
                min_vertex = j;
            }
        }

        vertices[min_vertex].visited = 1;

        for(j = 0; j < num_vertices; ++j) {
            int dist = graph[min_vertex][j] + vertices[min_vertex].distance;
            if(graph[min_vertex][j] >= 0 && dist < vertices[j].distance) {
                vertices[j].distance = dist;
            }
        }
    }
}

int main() {
    int j, i;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    graph = malloc(sizeof(int *) * num_vertices);
    for(i = 0; i < num_vertices; ++i) {
        graph[i] = malloc(sizeof(int) * num_vertices);
        for(j = 0; j < num_vertices; ++j) {
            graph[i][j] = -1;
        }
    }

    for(i = 0; i < num_vertices; ++i) {
        printf("Enter distances from vertex %d: ", i);
        for(j = 0; j < num_vertices; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }

    vertices = malloc(sizeof(Node) * num_vertices);
    for(i = 0; i < num_vertices; ++i) {
        vertices[i].distance = -1;
        vertices[i].visited = 0;
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra_algorithm();

    printf("\nShortest distances from vertex %d to:\n", source);
    for(i = 0; i < num_vertices; ++i) {
        printf("Vertex %d: %d\n", i, vertices[i].distance);
    }

    return 0;
}