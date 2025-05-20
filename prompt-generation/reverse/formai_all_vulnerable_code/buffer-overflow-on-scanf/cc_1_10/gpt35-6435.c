//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: intelligent
#include<stdio.h>

//Function to check if the given color is allowed for the vertex v
int isAllowed(int vertex, int color, int graph[50][50], int n, int coloredGraph[50]) {
    for(int i=0; i<n; i++) {
        if(graph[vertex][i] && coloredGraph[i]==color)
            return 0;
    }
    return 1;
}

//Function to implement graph coloring using backtracking algorithm
int graphColoring(int vertex, int graph[50][50], int n, int coloredGraph[50], int numOfColors) {
    //Base case: all vertices are assigned a color
    if(vertex == n)
        return 1;
    //Iterating over all the possible colors for the vertex and selecting the one which is allowed
    for(int i=1; i<=numOfColors; i++) {
        if(isAllowed(vertex, i, graph, n, coloredGraph)) {
            coloredGraph[vertex] = i;
            //Recursively checking if the remaining vertices can be colored
            if(graphColoring(vertex+1, graph, n, coloredGraph, numOfColors))
                return 1;
            else
                coloredGraph[vertex] = 0;  //Backtracking: removing the color of the current vertex and trying the next possible color
        }
    }
    //If no color can be assigned to the vertex, return 0
    return 0;
}

int main() {
    int n, numOfColors, graph[50][50], coloredGraph[50];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors available: ");
    scanf("%d", &numOfColors);

    //Initializing the coloredGraph array with all 0s
    for(int i=0; i<n; i++) {
        coloredGraph[i] = 0;
    }

    //Calling the graphColoring function to color the vertices
    if(graphColoring(0, graph, n, coloredGraph, numOfColors)) {
        printf("The vertices can be colored with %d colors as follows:\n",numOfColors);
        for(int i=0; i<n; i++) {
            printf("Vertex %d is assigned the color %d\n", i+1, coloredGraph[i]);
        }
    } else {
        printf("The vertices cannot be colored with %d colors.\n",numOfColors);
    }

    return 0;
}