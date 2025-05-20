//FormAI DATASET v1.0 Category: Graph representation ; Style: inquisitive
// Hey there! Are you ready to learn about graph representation in C programming? Let's dive in!

#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Let's create a maximum limit of 100 vertices for simplicity

int adjMatrix[MAX][MAX]; // Our graph will be represented by an adjacency matrix

int main()
{
    int vertices, edges; // The number of vertices and edges in our graph

    // Let's get input from the user
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    // Initialize all elements of the adjacency matrix to 0
    for(int i=0; i<vertices; i++)
    {
        for(int j=0; j<vertices; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }


    printf("Enter the vertices of the edges in the graph (e.g. 1 2): \n");

    // Now we'll input the edges for each vertex
    for(int i=0; i<edges; i++)
    {
        int v1, v2;
        scanf("%d %d", &v1, &v2); // Input the vertices for this edge

        // Add the edges to the adjacency matrix
        adjMatrix[v1][v2] = 1;
        adjMatrix[v2][v1] = 1; // We'll assume this is an undirected graph
    }

    // Now let's print out the resulting adjacency matrix
    printf("Here is the adjacency matrix for your graph:\n");

    for(int i=0; i<vertices; i++)
    {
        for(int j=0; j<vertices; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    return 0; // That's it for our program, happy graphing!
}