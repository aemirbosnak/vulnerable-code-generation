//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: recursive
#include <stdio.h>
#include <stdbool.h>
#define MAX_NODES 10
#define MAX_EDGES 20

int color[MAX_NODES]; // Array to store the color of the nodes
int graph[MAX_NODES][MAX_NODES]; // The graph structure
int num_nodes, num_edges; // Number of nodes and edges in the graph

// Recursive function to do the actual coloring
bool recursive_color(int node, int c)
{
    color[node] = c; // Assign the given color to the current node
    
    // Check if any adjacent nodes have the same color
    for(int i=0; i<num_nodes; i++)
    {
        if(graph[node][i]) // If there is an edge between node and i
        {
            if(color[i] == c) // If the adjacent node has the same color as the current node
            {
                return false; // This coloring is invalid, backtrack and try another color
            }
            else if(color[i] == 0) // If the adjacent node is not yet colored
            {
                if(!recursive_color(i, -c)) // Recursively color the adjacent node with the opposite color
                {
                    return false; // If the coloring is invalid, backtrack and try another color
                }
            }
        }
    }
    return true; // This coloring is valid
}

// Function to check if the graph can be colored with 2 colors
bool can_color_graph()
{
    for(int i=0; i<num_nodes; i++)
    {
        if(color[i] == 0) // If the node is not yet colored
        {
            if(!recursive_color(i, 1)) // Start coloring the graph from the current node
            {
                return false; // If the coloring is invalid, the graph cannot be colored with 2 colors
            }
        }
    }
    return true; // The graph can be colored with 2 colors
}

int main()
{
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    
    for(int i=0; i<num_edges; i++)
    {
        int u, v;
        printf("Enter edge %d (u, v): ", i+1);
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1; // Add the edge to the graph
    }
    
    if(can_color_graph()) // If the graph can be colored with 2 colors
    {
        printf("The graph can be colored with 2 colors.\n");
        printf("The colors of the nodes are:\n");
        for(int i=0; i<num_nodes; i++)
        {
            printf("Node %d: %s\n", i, (color[i] == 1) ? "Red" : "Blue"); // Print the color of each node
        }
    }
    else // If the graph cannot be colored with 2 colors
    {
        printf("The graph cannot be colored with 2 colors.\n");
    }
    
    return 0;
}