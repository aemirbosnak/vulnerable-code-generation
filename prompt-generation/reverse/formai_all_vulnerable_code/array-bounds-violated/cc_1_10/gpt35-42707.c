//FormAI DATASET v1.0 Category: Graph representation ; Style: visionary
#include<stdio.h>

int main()
{
    //Welcome message
    printf("Welcome to the Future!\n");

    //Creating nodes of the graph
    struct graphNode {
        int data;
        int connectedNodes[4]; //a node can have max of 4 connections
    };

    //Creating connections between nodes
    struct graphNode nodes[5]; //let's assume we have 5 nodes

    //Creating connections for Node 1
    nodes[0].data = 1;
    nodes[0].connectedNodes[0] = 2;
    nodes[0].connectedNodes[1] = 3;
    nodes[0].connectedNodes[2] = 4;

    //Creating connections for Node 2
    nodes[1].data = 2;
    nodes[1].connectedNodes[0] = 1;
    nodes[1].connectedNodes[1] = 4;

    //Creating connections for Node 3
    nodes[2].data = 3;
    nodes[2].connectedNodes[0] = 1;
    nodes[2].connectedNodes[1] = 4;

    //Creating connections for Node 4
    nodes[3].data = 4;
    nodes[3].connectedNodes[0] = 1;
    nodes[3].connectedNodes[1] = 2;
    nodes[3].connectedNodes[2] = 3;
    nodes[3].connectedNodes[3] = 5;

    //Creating connections for Node 5
    nodes[4].data = 5;
    nodes[4].connectedNodes[0] = 4;

    //Printing the graph representation
    printf("\nGraph Representaion:\n");
    for(int i=0; i<5; i++)
    {
        printf("Node %d: ", nodes[i].data);
        for(int j=0; nodes[i].connectedNodes[j]!=0 && j<4; j++)
        {
            printf("%d ", nodes[i].connectedNodes[j]);
        }
        printf("\n");
    }

    //Goodbye message
    printf("\nThanks for visiting the Future, goodbye!");

    return 0;
}