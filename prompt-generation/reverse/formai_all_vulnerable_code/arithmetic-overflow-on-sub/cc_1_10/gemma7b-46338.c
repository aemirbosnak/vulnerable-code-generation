//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct Node {
    int index;
    struct Node* next;
} Node;

void mapNetwork(int nodes, Node** network) {
    for (int i = 0; i < nodes; i++) {
        network[i] = (Node*)malloc(sizeof(Node));
        network[i]->index = i;
        network[i]->next = NULL;
    }

    for (int i = 0; i < nodes - 1; i++) {
        int source, destination;
        scanf("Enter source and destination nodes: ", &source, &destination);

        Node* sourceNode = network[source];
        Node* destinationNode = network[destination];

        sourceNode->next = destinationNode;
        destinationNode->next = sourceNode;
    }

    printf("Network topology map:\n");
    for (int i = 0; i < nodes; i++) {
        Node* node = network[i];
        printf("Node %d: ", node->index);
        Node* neighbor = node->next;
        while (neighbor) {
            printf("-> Neighbor %d ", neighbor->index);
            neighbor = neighbor->next;
        }
        printf("\n");
    }
}

int main() {
    int nodes;
    printf("Enter number of nodes: ");
    scanf("%d", &nodes);

    Node** network = (Node**)malloc(sizeof(Node*) * nodes);

    mapNetwork(nodes, network);

    return 0;
}