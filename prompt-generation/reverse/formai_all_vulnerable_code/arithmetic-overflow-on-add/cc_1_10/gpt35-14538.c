//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 100

// Structure to represent a node in the network
typedef struct {
    char name[20];
    int id;
    bool visited;
} Node;

// Structure to represent an edge in the network
typedef struct {
    int from;
    int to;
} Edge;

int n, e;
Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];
int adjacency_matrix[MAX_NODES][MAX_NODES];

// Function to add a new node to the network
void addNode(char* name, int id) {
    Node node;
    strcpy(node.name, name);
    node.id = id;
    node.visited = false;
    nodes[id] = node;
}

// Function to add a new edge to the network
void addEdge(int from, int to) {
    Edge edge;
    edge.from = from;
    edge.to = to;
    edges[e++] = edge;
}

// Function to build the network topology
void buildNetwork() {
    printf("Enter the number of nodes in the network: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        char name[20];
        printf("Enter the name of node %d: ", i+1);
        scanf("%s", name);
        addNode(name, i);
    }

    printf("\nEnter the number of edges in the network: ");
    scanf("%d", &e);
    for(int i=0; i<e; i++) {
        int from, to;
        printf("Enter the IDs of the nodes connected by edge %d (from to): ", i+1);
        scanf("%d %d", &from, &to);
        addEdge(from, to);
    }
}

// Function to print the network topology
void printTopology() {
    printf("\nNetwork Topology:\n");
    for(int i=0; i<n; i++) {
        printf("%d. %s\n", nodes[i].id, nodes[i].name);
    }
    printf("\n");
    for(int i=0; i<e; i++) {
        printf("%s -> %s\n", nodes[edges[i].from].name, nodes[edges[i].to].name);
        adjacency_matrix[edges[i].from][edges[i].to] = 1;
        adjacency_matrix[edges[i].to][edges[i].from] = 1;
    }
}

// Function to perform depth-first search of the network
void dfs(int node_id) {
    printf("%s ", nodes[node_id].name);
    nodes[node_id].visited = true;

    for(int i=0; i<n; i++) {
        if(adjacency_matrix[node_id][i] && !nodes[i].visited) {
            dfs(i);
        }
    }
}

int main() {
    buildNetwork();
    printTopology();

    printf("\nPerforming Depth-First Search:\n");
    for(int i=0; i<n; i++) {
        if(!nodes[i].visited) {
            dfs(i);
        }
    }

    return 0;
}