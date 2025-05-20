//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 100

typedef struct {
    int node1;
    int node2;
    int weight;
} Edge;

typedef struct {
    char name[10];
    int degree;
    Edge edges[MAX_EDGES];
} Node;

// Function to add an edge
void addEdge(Node *graph, int node1, int node2, int weight) {
    Edge *e = &graph[node1].edges[graph[node1].degree++];
    e->node1 = node1;
    e->node2 = node2;
    e->weight = weight;
}

// Function to print the graph
void printGraph(Node *graph, int n) {
    printf("Graph:\n");
    for (int i = 0; i < n; i++) {
        printf("Node %d: %s\n", i, graph[i].name);
        for (int j = 0; j < graph[i].degree; j++) {
            printf("\t%d -> %d (%d)\n", i, graph[i].edges[j].node2, graph[i].edges[j].weight);
        }
    }
}

// Function to read the input file
void readInputFile(char *filename, Node *graph, int n) {
    FILE *fp;
    char line[100];
    int node1, node2, weight;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Cannot open input file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %d %d %d", line, &node1, &node2, &weight)!= EOF) {
        addEdge(graph, node1, node2, weight);
    }

    fclose(fp);
}

int main() {
    Node graph[MAX_NODES];
    int n = 0;
    char filename[100];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the names of the nodes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", graph[i].name);
    }

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    readInputFile(filename, graph, n);

    printGraph(graph, n);

    return 0;
}