//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: Sherlock Holmes
// A unique C Graph representation example program in a Sherlock Holmes style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a graph
struct Graph
{
    int vertices; // Number of vertices
    int edges; // Number of edges
    int** matrix; // Adjacency matrix
};

// Structure to represent a vertex
struct Vertex
{
    char name; // Name of the vertex
    int visited; // Whether the vertex has been visited
};

// Function to create a new graph
struct Graph* createGraph(int vertices)
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->edges = 0;
    graph->matrix = malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++)
    {
        graph->matrix[i] = malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++)
        {
            graph->matrix[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge to a graph
void addEdge(struct Graph* graph, int v1, int v2)
{
    graph->matrix[v1][v2] = 1;
    graph->matrix[v2][v1] = 1;
    graph->edges++;
}

// Function to print the graph
void printGraph(struct Graph* graph)
{
    printf("Graph has %d vertices and %d edges\n", graph->vertices, graph->edges);
    for (int i = 0; i < graph->vertices; i++)
    {
        for (int j = 0; j < graph->vertices; j++)
        {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform a DFS traversal of a graph
void dfs(struct Graph* graph, int vertex)
{
    struct Vertex* vertexList = malloc(graph->vertices * sizeof(struct Vertex));
    for (int i = 0; i < graph->vertices; i++)
    {
        vertexList[i].name = i;
        vertexList[i].visited = 0;
    }
    vertexList[vertex].visited = 1;
    while (vertex != -1)
    {
        printf("%c ", vertexList[vertex].name);
        for (int i = 0; i < graph->vertices; i++)
        {
            if (graph->matrix[vertex][i] && !vertexList[i].visited)
            {
                vertexList[i].visited = 1;
                vertex = i;
                break;
            }
        }
    }
    free(vertexList);
}

// Driver code
int main()
{
    struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 0);
    printGraph(graph);
    dfs(graph, 0);
    return 0;
}