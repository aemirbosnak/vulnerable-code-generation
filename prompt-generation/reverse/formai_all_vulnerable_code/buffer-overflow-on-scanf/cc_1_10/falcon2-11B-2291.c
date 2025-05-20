//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: happy
/** \mainpage Happy Graph Program **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    struct Node* vertices;
    int numVertices;
};

struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = (struct Node*)malloc(numVertices * sizeof(struct Node));
    graph->numVertices = numVertices;
    return graph;
}

void addEdge(struct Graph* graph, int vertex1, int vertex2) {
    struct Node* temp = graph->vertices + vertex1;
    while (temp!= NULL && temp->vertex!= vertex2) {
        temp = temp->next;
    }
    temp->next = graph->vertices + vertex2;
}

void printGraph(struct Graph* graph) {
    struct Node* temp = graph->vertices;
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d -> ", temp->vertex);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    struct Graph* graph = createGraph(numVertices);

    printf("Enter the edges of the graph:\n");
    for (int i = 0; i < numVertices; i++) {
        int vertex1, vertex2;
        printf("Enter vertex %d: ", i + 1);
        scanf("%d", &vertex1);
        printf("Enter vertex %d: ", i + 1);
        scanf("%d", &vertex2);
        addEdge(graph, vertex1, vertex2);
    }

    printf("The graph is:\n");
    printGraph(graph);

    return 0;
}

/** End of Happy Graph Program **/