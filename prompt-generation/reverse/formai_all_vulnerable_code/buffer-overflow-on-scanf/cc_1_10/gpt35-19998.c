//FormAI DATASET v1.0 Category: Graph representation ; Style: systematic
#include <stdio.h>
#define MAX 20      // define maximum number of vertices
#define TRUE 1
#define FALSE 0

int numVertices = 0;   // variable to keep track of number of vertices in graph

// adjacency matrix to represent the graph
int graph[MAX][MAX];

// function to add a vertex to the graph
void addVertex() {
    if(numVertices < MAX) {
        printf("Enter the name of the vertex: ");
        char vertexName;
        scanf(" %c", &vertexName);
        int newVertexIndex = numVertices++;
        graph[newVertexIndex][newVertexIndex] = 0;   // initialize connecting edge weight of new vertex as 0
        printf("Added vertex '%c' with index %d\n", vertexName, newVertexIndex);
    }
    else {
        printf("Error: Maximum number of vertices reached\n");
    }
}

// function to add an edge to the graph
void addEdge() {
    printf("Enter the indices of the vertices to connect (separated by a space): ");
    int vertex1, vertex2;
    scanf("%d %d", &vertex1, &vertex2);
    if(vertex1 >= 0 && vertex1 < numVertices && vertex2 >= 0 && vertex2 < numVertices) {
        printf("Enter the weight of the edge: ");
        int weight;
        scanf("%d", &weight);
        graph[vertex1][vertex2] = weight;
        graph[vertex2][vertex1] = weight;
        printf("Added edge from vertex %d to vertex %d with weight %d\n", vertex1, vertex2, weight);
    }
    else {
        printf("Error: Invalid vertex indices entered\n");
    }
}

// function to print the graph
void printGraph() {
    printf("The graph is:\n");
    for(int i=0; i<numVertices; i++) {
        for(int j=0; j<numVertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int running = TRUE;
    while(running) {
        printf("Choose an option:\n");
        printf("1. Add a vertex\n");
        printf("2. Add an edge\n");
        printf("3. Print the graph\n");
        printf("4. Quit\n");
        int option;
        scanf("%d", &option);
        switch(option) {
            case 1:
                addVertex();
                break;
            case 2:
                addEdge();
                break;
            case 3:
                printGraph();
                break;
            case 4:
                running = FALSE;
                break;
            default:
                printf("Error: Invalid option entered\n");
        }
    }

    return 0;
}