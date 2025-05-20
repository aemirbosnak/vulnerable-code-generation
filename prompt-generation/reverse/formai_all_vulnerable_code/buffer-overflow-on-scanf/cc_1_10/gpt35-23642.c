//FormAI DATASET v1.0 Category: Graph representation ; Style: beginner-friendly
#include <stdio.h>
#define MAX_VERTICES 100 // Maximum number of vertices that the graph can have
#define MAX_EDGES 1000 // Maximum number of edges that the graph can have

int vertices = 0; // Counter for the number of vertices entered
int edges = 0; // Counter for the number of edges entered

typedef struct {
    int x; // Starting vertex of the edge
    int y; // Ending vertex of the edge
} Edge;

Edge edgeArr[MAX_EDGES]; // Array to store all the edges in the graph

void addEdge(int x, int y) { // Function to add an edge to the graph
    edgeArr[edges].x = x;
    edgeArr[edges].y = y;
    edges++;
}

void printGraph(int adjMatrix[][MAX_VERTICES], int n) { // Function to print the graph in the form of an adjacency matrix
    int i, j;
    printf("\nAdjacency matrix of the given graph:\n\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void graphRepresentation() {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // Declaration of matrix to store adjacency information
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            adjMatrix[i][j] = 0; // Initializing the matrix with 0
        }
    }

    for(int i=0;i<edges;i++){
        int x = edgeArr[i].x;
        int y = edgeArr[i].y;

        adjMatrix[x][y] = 1; // Setting the value at the corresponding vertices to 1
        adjMatrix[y][x] = 1;
    }
    printGraph(adjMatrix, vertices); // Calling printGraph() to print adjacency matrix
}

int main() {
    printf("Enter the number of vertices in the graph: ");
    scanf("%d",&vertices);

    printf("\nEnter the edges of the graph (x,y) : \n");

    int x,y;
    for(int i=0;i<MAX_EDGES;i++){
        printf("\nEnter edge %d (Enter -1 -1 to end) : \n",i+1);
        scanf("%d%d",&x,&y);
        if(x == -1 && y == -1){
                break;
        }
        addEdge(x,y); // Calling addEdge() to add the entered edge to the graph
    }

    graphRepresentation(); // Calling the function to print the graph in adjacency matrix form

    return 0;
}