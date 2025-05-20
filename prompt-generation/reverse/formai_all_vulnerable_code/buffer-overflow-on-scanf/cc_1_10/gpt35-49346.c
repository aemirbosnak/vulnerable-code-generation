//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 10

int adjMat[MAX_NODES][MAX_NODES];
int numNodes;

void printHeader()
{
    printf("\n");
    printf("**********************************************\n");
    printf("          NETWORK TOPOLOGY MAPPER\n");
    printf("**********************************************\n\n");
}

void printMenu()
{
    printf("COMMAND MENU\n\n");
    printf("1. Add node\n");
    printf("2. Remove node\n");
    printf("3. Add connection\n");
    printf("4. Remove connection\n");
    printf("5. Display topology\n");
    printf("6. Exit\n\n");
}

void addNode()
{
    if (numNodes == MAX_NODES)
    {
        printf("Sorry, maximum number of nodes (%d) have already been added.\n", MAX_NODES);
    }
    else
    {
        char nodeName;
        printf("Enter node name: ");
        scanf(" %c", &nodeName);
        adjMat[numNodes][numNodes] = 1;
        printf("Node %c has been added.\n", nodeName);
        numNodes++;
    }
}

void removeNode()
{
    if (numNodes == 0)
    {
        printf("Sorry, there are no nodes to remove.\n");
    }
    else
    {
        int index;
        printf("Enter index of node to remove: ");
        scanf("%d", &index);
        if (index < 0 || index >= numNodes)
        {
            printf("Invalid index. Please try again.\n");
        }
        else
        {
            char nodeName = 'A' + index;
            for (int i = index; i < numNodes - 1; i++)
            {
                for (int j = 0; j < numNodes; j++)
                {
                    adjMat[i][j] = adjMat[i+1][j];
                }
            }
            for (int i = index; i < numNodes - 1; i++)
            {
                for (int j = 0; j < numNodes; j++)
                {
                    adjMat[j][i] = adjMat[j][i+1];
                }
            }
            for (int i = 0; i < numNodes; i++)
            {
                adjMat[numNodes-1][i] = 0;
                adjMat[i][numNodes-1] = 0;
            }
            numNodes--;
            printf("Node %c has been removed.\n", nodeName);
        }
    }
}

void addConnection()
{
    if (numNodes < 2)
    {
        printf("Sorry, you need at least 2 nodes to add a connection.\n");
    }
    else
    {
        int index1, index2;
        printf("Enter index of first node: ");
        scanf("%d", &index1);
        printf("Enter index of second node: ");
        scanf("%d", &index2);
        if (index1 < 0 || index1 >= numNodes || index2 < 0 || index2 >= numNodes || index1 == index2)
        {
            printf("Invalid indices. Please try again.\n");
        }
        else
        {
            adjMat[index1][index2] = 1;
            adjMat[index2][index1] = 1;
            printf("Connection between nodes %c and %c has been added.\n", 'A' + index1, 'A' + index2);
        }
    }
}

void removeConnection()
{
    if (numNodes < 2)
    {
        printf("Sorry, you need at least 2 nodes to remove a connection.\n");
    }
    else
    {
        int index1, index2;
        printf("Enter index of first node: ");
        scanf("%d", &index1);
        printf("Enter index of second node: ");
        scanf("%d", &index2);
        if (index1 < 0 || index1 >= numNodes || index2 < 0 || index2 >= numNodes || index1 == index2)
        {
            printf("Invalid indices. Please try again.\n");
        }
        else if (adjMat[index1][index2] == 0)
        {
            printf("There is no connection between nodes %c and %c.\n", 'A' + index1, 'A' + index2);
        }
        else
        {
            adjMat[index1][index2] = 0;
            adjMat[index2][index1] = 0;
            printf("Connection between nodes %c and %c has been removed.\n", 'A' + index1, 'A' + index2);
        }
    }
}

void displayTopology()
{
    printf("TOPOLOGY\n\n");
    printf("   ");
    for (int i = 0; i < numNodes; i++)
    {
        printf("%c ", 'A' + i);
    }
    printf("\n");
    for (int i = 0; i < numNodes; i++)
    {
        printf("%c  ", 'A' + i);
        for (int j = 0; j < numNodes; j++)
        {
            if (adjMat[i][j] == 1)
            {
                printf("X ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main()
{
    printHeader();
    numNodes = 0;
    int choice;
    do
    {
        printMenu();
        printf("Enter command number: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                addNode();
                break;
            case 2:
                removeNode();
                break;
            case 3:
                addConnection();
                break;
            case 4:
                removeConnection();
                break;
            case 5:
                displayTopology();
                break;
            case 6:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid command number. Please try again.\n");
                break;
        }
    } while (choice != 6);
    return 0;
}