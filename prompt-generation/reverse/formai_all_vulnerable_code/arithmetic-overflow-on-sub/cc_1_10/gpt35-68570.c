//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n; //Number of vertices in the graph
int m; //Number of edges in the graph

typedef struct Edge {
    int src;
    int dest;
} Edge;

Edge *graph; //Graph stored as an array of edges
int *color; //Array to store color of each vertex

int isValidColor(int vertex, int c) { //Function to check if color c is valid for vertex
    for (int i = 0; i < m; i++) {
        if (graph[i].src == vertex || graph[i].dest == vertex) { //Check for adjacent vertices
            if (color[graph[i].src] == c || color[graph[i].dest] == c) {
                return 0; //Color is not valid
            }
        }
    }
    return 1; //Color is valid
}

int graphColoring(int vertex) { //Recursive function to color the graph
    if (vertex == n) { //If all vertices have been colored
        return 1; //Solution found
    }

    for (int i = 1; i <= n; i++) { //Try all possible colors for vertex
        if (isValidColor(vertex, i)) {
            color[vertex] = i; //Assign color to vertex
            if (graphColoring(vertex + 1) == 1) { //Color the next vertex recursively
                return 1; //Solution found
            }
            color[vertex] = 0; //Backtrack
        }
    }
    return 0; //No solution found
}

int main() {
    srand(time(NULL)); //Seed for randomizing

    printf("Enter number of vertices in the graph: ");
    scanf("%d", &n);

    m = n*(n-1)/2; //Calculate number of edges for a complete graph

    graph = (Edge*) malloc(m * sizeof(Edge)); //Allocate memory for graph
    color = (int*) malloc(n * sizeof(int)); //Allocate memory for color

    int count = 0;
    for (int i = 1; i <= n; i++) { //Generate edges of complete graph
        for (int j = i+1; j <= n; j++) {
            graph[count].src = i;
            graph[count].dest = j;
            count++;
        }
    }

    int randIndex;
    Edge temp; //Shuffle edges randomly to create a random graph
    for (int i = m-1; i > 0; i--) {
        randIndex = rand() % (i+1);
        temp = graph[i];
        graph[i] = graph[randIndex];
        graph[randIndex] = temp;
    }

    int result = graphColoring(0); //Color the graph recursively

    if (result == 1) { //Print the solution
        printf("\nGraph can be colored using the following colors:\n");
        for (int i = 0; i < n; i++) {
            printf("Vertex %d: Color %d\n", i+1, color[i]);
        }
    } else { //No solution found
        printf("\nGraph cannot be colored.\n");
    }

    free(graph); //Free allocated memory
    free(color);

    return 0; //Exit program
}