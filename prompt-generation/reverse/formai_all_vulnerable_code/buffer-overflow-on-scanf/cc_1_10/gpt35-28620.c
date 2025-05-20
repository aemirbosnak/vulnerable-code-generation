//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10    // Maximum number of elements 

int main()
{
    int circuit[MAX_SIZE][MAX_SIZE], node[MAX_SIZE], branch[MAX_SIZE];
    int num_nodes, num_branches, i, j;

    printf("Enter the number of nodes in the circuit: ");
    scanf("%d", &num_nodes);
    printf("Enter the number of branches in the circuit: ");
    scanf("%d", &num_branches);

    // Initializing circuit matrix to all zeros 
    for(i=0;i<MAX_SIZE;i++)  
        for(j=0;j<MAX_SIZE;j++)
            circuit[i][j] = 0; 

    // Reading node data 
    printf("Enter the node data: \n");
    for(i=0;i<num_nodes;i++)
    {
        printf("Node %d: ", i+1);
        scanf("%d", &node[i]);
    }

    // Reading branch data 
    printf("\nEnter the branch data: \n");
    for(i=0;i<num_branches;i++)
    {
        printf("Branch %d: ", i+1);
        scanf("%d", &branch[i]);
    }

    // Populating circuit matrix with branch data 
    printf("\nEnter the branch connections: \n");
    for(i=0;i<num_branches;i++)
    {
        int start_node, end_node;

        printf("Branch %d connects node: ", i+1);
        scanf("%d", &start_node);

        printf("Branch %d connects to node: ", i+1);
        scanf("%d", &end_node);

        circuit[start_node-1][end_node-1] = branch[i];
        circuit[end_node-1][start_node-1] = -branch[i];
    }

    // Matrix printing 
    printf("\nMatrix Representation of the Circuit:\n\n");

    for(i=0;i<num_nodes;i++)
    {
        for(j=0;j<num_nodes;j++)
        {
            printf("%d ", circuit[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}