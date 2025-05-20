//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

#define N 10

int main()
{
    int graph[N][N];  // declaring an adjacency matrix
    int color[N];     // declaring an array to store colors of vertices
    int numberOfColors;   // variable to store the number of colors used in coloring
    int i,j;

    // initializing the adjacency matrix
    printf("Enter the adjacency matrix of the graph:\n");
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    // initializing the colors of all vertices as 0
    for(i=0; i<N; i++)
    {
        color[i] = 0;
    }

    // finding the minimum number of colors required to color all the vertices
    for(i=0; i<N; i++)
    {
        // initializing the available colors list as all the colors
        int availableColors[N];
        for(j=0; j<N; j++)
        {
            availableColors[j] = j+1;
        }

        // checking the colors of all the adjacent vertices and removing them from the available colors list
        for(j=0; j<N; j++)
        {
            if(graph[i][j] && color[j]!=0)
            {
                availableColors[color[j]-1] = 0;
            }
        }

        // finding the smallest color available
        for(j=0; j<N; j++)
        {
            if(availableColors[j]!=0)
            {
                color[i] = availableColors[j];
                break;
            }
        }
        
        // updating the number of colors used
        if(color[i]>numberOfColors)
        {
            numberOfColors = color[i];
        }
    }

    // displaying the colors of all the vertices
    printf("The colors of all the vertices are:\n");
    for(i=0; i<N; i++)
    {
        printf("Vertex %d : Color %d\n", i+1, color[i]);
    }

    // displaying the number of colors used
    printf("The minimum number of colors required to color all the vertices is %d\n", numberOfColors);

    return 0;
}