//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

// adjacency matrix
int adj[MAX_NODES][MAX_NODES];
// visited nodes
bool visited[MAX_NODES] = {false};

// print the network topology
void printTopology(int nodeCount) {
    printf("Network Topology:\n");
    for(int i=0;i<nodeCount;i++) {
        printf("%c -> ", 'A'+i);
        for(int j=0;j<nodeCount;j++) {
            if(adj[i][j]==1) {
                printf("%c ", 'A'+j);
            }
        }
        printf("\n");
    }
}

// recursive function to explore the nodes
void exploreNodes(int node, int nodeCount) {
    visited[node] = true;
    for(int i=0;i<nodeCount;i++) {
        if(adj[node][i]==1 && visited[i]==false) {
            exploreNodes(i, nodeCount);
        }
    }
}

// find the number of connected components
int findConnectedComponents(int nodeCount) {
    int count = 0;
    for(int i=0;i<nodeCount;i++) {
        if(visited[i]==false) {
            exploreNodes(i, nodeCount);
            count++;
        }
    }
    return count;
}

int main() {
    int nodeCount, edgeCount;
    printf("Enter the number of nodes in the network topology: ");
    scanf("%d", &nodeCount);
    printf("Enter the number of edges in the network topology: ");
    scanf("%d", &edgeCount);
    for(int i=0;i<edgeCount;i++) {
        char nodeA, nodeB;
        printf("Enter the two nodes that are connected (Example: A B): ");
        scanf(" %c %c", &nodeA, &nodeB);
        // mapping the nodes to indices
        int indexA = nodeA - 'A';
        int indexB = nodeB - 'A';
        adj[indexA][indexB] = adj[indexB][indexA] = 1;
    }
    printTopology(nodeCount);
    int count = findConnectedComponents(nodeCount);
    printf("Number of Connected Components: %d\n", count);
    return 0;
}