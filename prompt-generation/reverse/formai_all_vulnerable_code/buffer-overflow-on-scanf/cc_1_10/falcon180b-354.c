//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VERTEX 100
#define MAX_EDGE 1000

typedef struct {
    char name[10];
    int index;
} Vertex;

typedef struct {
    int start;
    int end;
    int weight;
} Edge;

Vertex vertices[MAX_VERTEX];
Edge edges[MAX_EDGE];
int numVertices, numEdges;

void addVertex(char name[]) {
    int i;
    for (i = 0; i < numVertices; i++) {
        if (strcmp(name, vertices[i].name) == 0) {
            printf("Vertex already exists!\n");
            return;
        }
    }
    strcpy(vertices[numVertices].name, name);
    vertices[numVertices].index = numVertices;
    numVertices++;
}

void addEdge(int start, int end, int weight) {
    Edge edge;
    edge.start = start;
    edge.end = end;
    edge.weight = weight;
    edges[numEdges] = edge;
    numEdges++;
}

void printVertices() {
    int i;
    for (i = 0; i < numVertices; i++) {
        printf("%d. %s\n", i, vertices[i].name);
    }
}

void printEdges() {
    int i;
    for (i = 0; i < numEdges; i++) {
        printf("Edge %d: %d - %d (Weight: %d)\n", i, edges[i].start, edges[i].end, edges[i].weight);
    }
}

int main() {
    int i, j, choice;
    char name[10];

    numVertices = 0;
    numEdges = 0;

    while (1) {
        printf("\n1. Add Vertex\n2. Add Edge\n3. Print Vertices\n4. Print Edges\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter vertex name: ");
            scanf("%s", name);
            addVertex(name);
            break;
        case 2:
            printf("Enter start vertex index: ");
            scanf("%d", &i);
            printf("Enter end vertex index: ");
            scanf("%d", &j);
            addEdge(i, j, 0);
            break;
        case 3:
            printVertices();
            break;
        case 4:
            printEdges();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}