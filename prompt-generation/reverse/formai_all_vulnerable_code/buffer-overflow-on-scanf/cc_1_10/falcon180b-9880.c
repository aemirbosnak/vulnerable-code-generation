//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    int id;
    char name[20];
    int degree;
    int *adjacent;
} Node;

typedef struct {
    int from;
    int to;
} Edge;

Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];
int numEdges = 0;

void addEdge(int from, int to) {
    Edge e = {from, to};
    edges[numEdges++] = e;
}

void addNode(int id, char *name) {
    Node n = {id, id, 0, NULL};
    strcpy(n.name, name);
    for (int i = 0; i < numEdges; i++) {
        if (edges[i].from == id || edges[i].to == id) {
            n.degree++;
        }
    }
    nodes[id] = n;
}

void printGraph() {
    for (int i = 0; i < numEdges; i++) {
        printf("%d -> %d\n", edges[i].from, edges[i].to);
    }
}

int main() {
    int numNodes = 0;
    char input[100];

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        printf("Enter the ID and name of node %d: ", i+1);
        scanf("%s", input);
        addNode(atoi(input), input);
    }

    printf("Enter the edges (in the format from_node_id to_node_id):\n");
    while (scanf("%s", input)!= EOF) {
        int from, to;
        sscanf(input, "%d %d", &from, &to);
        addEdge(from, to);
    }

    printGraph();

    return 0;
}