//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: innovative
#include<stdio.h> 

int V; //number of vertices
int E; //number of edges
int color[20]; // The color array stores colors assigned to particular vertices

//Graph Coloring function where we assign colors to vertices recursively
void graphColoring(int graph[V][V], int vertex)
{
    int nextVertex; //next vertex to be colored
    
    //if all vertices are colored print the solution
    if(vertex == V)
    {
        printf("Solution: [ ");
        for(int i=0; i<V; i++)
            printf("%d ", color[i]);
        printf("]\n");
    }
    else
    {
        for(int c=1; c<=V; c++) //coloring the vertex in all possible ways
        {
            nextVertex = vertex + 1;
            
            if(isPossible(graph, c, vertex)) //if assigning this color is safe, assign it.
            {
                color[vertex] = c; 
                graphColoring(graph, nextVertex);
                color[vertex] = 0;
            }
        }
    }
}

//Utility function to check if it is safe to color a vertex with given color
int isPossible(int graph[V][V], int c, int vertex)
{
    //Checking if any of the neighboring vertices already have the assigned color
    for(int i=0; i<V; i++)
        if(graph[vertex][i] && c == color[i])
            return 0;
    return 1;
}

int main()
{
    int graph[20][20]; //Adjacency Matrix to store graph
    int i, j, x, y;
    
    
    //Get number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d",&V);
    printf("Enter number of edges: ");
    scanf("%d",&E);
    
    //Initializing the graph with all vertices being not connected
    for(i=0; i<V; i++)
        for(j=0; j<V; j++)
            graph[i][j] = 0;
    
    //Creating graph by taking input for edges
    for(i=0; i<E; i++)
    {
        printf("Enter edge %d (x,y) format: ",i+1);
        scanf("%d %d",&x,&y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    
    //Printing the adjacency matrix representation of the Graph
    printf("\nAdjacency Matrix representation of graph: \n");
    for(i=0; i<V; i++)
    {
        for(j=0; j<V; j++)
            printf("%d ",graph[i][j]);
        printf("\n");
    }
    
    //Calling Graph Coloring function
    graphColoring(graph, 0);
    
    return 0;
}