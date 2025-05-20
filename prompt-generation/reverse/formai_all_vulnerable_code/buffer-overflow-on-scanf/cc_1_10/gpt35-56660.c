//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100 // set maximum number of nodes for the network
#define MAX_EDGES 1000 // set maximum number of edges for the network

// define the data structure for the network topology
typedef struct {
    int source;
    int destination;
    int weight;
} Edge;

// define the data structure for the network nodes
typedef struct {
    char name[20];
    int id;
} Node;

// functions to be used in the program
int addNode(Node *nodes, int numNodes, char *name);
int getNodeIndex(Node *nodes, int numNodes, char *name);
void addEdge(Edge *edges, int *numEdges, int source, int dest, int weight);
void printTopology(Node *nodes, int numNodes, Edge *edges, int numEdges);

int main() {
    Node nodes[MAX_NODES]; // array of nodes for the network
    Edge edges[MAX_EDGES]; // array of edges for the network
    int numNodes = 0; // number of nodes currently in the network
    int numEdges = 0; // number of edges currently in the network
    int choice; // variable to hold user's choice
    char nodeName[20]; // variable to hold node name input
    char sourceName[20]; // variable to hold source node name input
    char destName[20]; // variable to hold destination node name input
    int sourceIndex; // variable to hold source node index
    int destIndex; // variable to hold destination node index
    int weight; // variable to hold weight input
    bool exitFlag = false; // flag to exit program
    
    printf("Welcome to Network Topology Mapper!\n");
    
    while (!exitFlag) {
        printf("\nPlease choose from the following options:\n");
        printf("1. Add node to the network\n");
        printf("2. Add edge to the network\n");
        printf("3. Print network topology\n");
        printf("4. Exit program\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            
            case 1: // add node to the network
                printf("Enter the name of the node: ");
                scanf("%s", nodeName);
                addNode(nodes, numNodes, nodeName);
                numNodes++;
                printf("Node added to the network.\n");
                break;
                
            case 2: // add edge to the network
                printf("Enter the name of the source node: ");
                scanf("%s", sourceName);
                printf("Enter the name of the destination node: ");
                scanf("%s", destName);
                printf("Enter the weight of the edge: ");
                scanf("%d", &weight);
                sourceIndex = getNodeIndex(nodes, numNodes, sourceName);
                destIndex = getNodeIndex(nodes, numNodes, destName);
                addEdge(edges, &numEdges, sourceIndex, destIndex, weight);
                printf("Edge added to the network.\n");
                break;
                
            case 3: // print network topology
                printTopology(nodes, numNodes, edges, numEdges);
                break;
                
            case 4: // exit program
                exitFlag = true;
                printf("Goodbye!\n");
                break;
                
            default: // invalid input
                printf("Invalid choice.\n");
                break;
        }
    }
    
    return 0; // indicate successful program termination
}

// function to add a node to the network
int addNode(Node *nodes, int numNodes, char *name) {
    Node newNode;
    strcpy(newNode.name, name);
    newNode.id = numNodes;
    nodes[numNodes] = newNode;
    return numNodes;
}

// function to get the index of a node in the network
int getNodeIndex(Node *nodes, int numNodes, char *name) {
    int i;
    for (i = 0; i < numNodes; i++) {
        if (strcmp(nodes[i].name, name) == 0) {
            return i;
        }
    }
    return -1; // indicate node doesn't exist in network
}

// function to add an edge to the network
void addEdge(Edge *edges, int *numEdges, int source, int dest, int weight) {
    Edge newEdge;
    newEdge.source = source;
    newEdge.destination = dest;
    newEdge.weight = weight;
    edges[*numEdges] = newEdge;
    (*numEdges)++;
}

// function to print the network topology
void printTopology(Node *nodes, int numNodes, Edge *edges, int numEdges) {
    int i;
    printf("\nNetwork Topology:\n");
    for (i = 0; i < numNodes; i++) {
        printf("Node %d (%s): ", nodes[i].id, nodes[i].name);
        int j;
        for (j = 0; j < numEdges; j++) {
            if (edges[j].source == i) {
                printf("%s (%d) ", nodes[edges[j].destination].name, edges[j].weight);
            }
            else if (edges[j].destination == i) {
                printf("%s (%d) ", nodes[edges[j].source].name, edges[j].weight);
            }
        }
        printf("\n");
    }
}