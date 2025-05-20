//FormAI DATASET v1.0 Category: Graph representation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_nodes, node, vertex;
    printf("Welcome to the cheerful Graph representation example program!\n");
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    int** graph = (int**) malloc(num_nodes * sizeof(int*)); //allocating memory for adjacency matrix

    for(int i=0;i<num_nodes;i++)
        graph[i] = (int*) calloc(num_nodes , sizeof(int));

    printf("\nGreat! Now let's create the graph...\n");

    for(node = 0; node < num_nodes; node++)
    {
        printf("Enter the number of vertices connected to node %d: ", node+1);
        scanf("%d", &vertex);

        printf("Enter the connected vertices (separated by space): ");
        for(int i = 0; i < vertex; i++)
        {
            int connected;
            scanf("%d", &connected);
            graph[node][connected-1] = 1;
        }
    }

    printf("\nYay! You have successfully created the graph.\n");
    printf("\nHere's the adjacency matrix representation of the graph:\n\n");

    // printing the adjacency matrix
    printf("\t");
    for(int i=0; i<num_nodes; i++)
        printf("Node %d\t", i+1);
    printf("\n\n");

    for(node = 0; node < num_nodes; node++)
    {
        printf("Node %d\t", node+1);
        for(vertex = 0; vertex < num_nodes; vertex++)
            printf("%d\t\t", graph[node][vertex]);
        printf("\n\n");
    }

    printf("Yippee! You did it. Stay cheerful and keep coding!");

    //freeing the memory
    for(int i=0; i<num_nodes; i++)
        free(graph[i]);
    free(graph);

    return 0;
}