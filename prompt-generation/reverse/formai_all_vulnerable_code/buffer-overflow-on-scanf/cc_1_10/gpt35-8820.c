//FormAI DATASET v1.0 Category: Graph representation ; Style: sophisticated
#include<stdio.h> 
#include<stdlib.h> 

struct Edge
{
    int start_vertex;
    int end_vertex;
    int weight;
};

int main()
{
    int totalVertices, totalEdges, start_vertex, end_vertex, weight;
    printf("Enter the total number of vertices: ");
    scanf("%d", &totalVertices);
  
    printf("\nEnter total number of edges: ");
    scanf("%d", &totalEdges);

    struct Edge graph[totalEdges];

    printf("\nEnter start vertex, end vertex and weight of the edge separated by spaces.");

    for(int i = 0; i < totalEdges; i++)
    {
        printf("\nEdge %d: ", i+1);
        scanf("%d %d %d", &start_vertex, &end_vertex, &weight);
        graph[i].start_vertex = start_vertex;
        graph[i].end_vertex = end_vertex;
        graph[i].weight = weight;
    }

    printf("\nGraph representation using adjacency list:\n\n");

    for(int i = 1; i <= totalVertices; i++)
    {
        printf("Vertex %d: ",i);

        for(int j = 0; j < totalEdges; j++)
        {
            if(graph[j].start_vertex == i)
                printf("%d(%d) ", graph[j].end_vertex, graph[j].weight);

            if(graph[j].end_vertex == i)
                printf("%d(%d) ", graph[j].start_vertex, graph[j].weight);
        }
        printf("\n");
    }
    return 0;
}