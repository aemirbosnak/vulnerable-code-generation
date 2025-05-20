//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    int id;
    char name[10];
    int degree;
    int *neighbors;
} Node;

typedef struct {
    int source;
    int destination;
    int weight;
} Edge;

Node nodes[MAX_NODES];
int num_nodes = 0;
Edge edges[MAX_EDGES];
int num_edges = 0;

void add_node(int id, char *name) {
    if (num_nodes >= MAX_NODES) {
        printf("Error: Maximum number of nodes exceeded.\n");
        exit(1);
    }
    nodes[num_nodes].id = id;
    strcpy(nodes[num_nodes].name, name);
    nodes[num_nodes].degree = 0;
    nodes[num_nodes].neighbors = NULL;
    num_nodes++;
}

void add_edge(int source, int destination, int weight) {
    if (num_edges >= MAX_EDGES) {
        printf("Error: Maximum number of edges exceeded.\n");
        exit(1);
    }
    Edge edge = { source, destination, weight };
    edges[num_edges++] = edge;
    nodes[source - 1].degree++;
}

void print_graph() {
    printf("Network Topology:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %s, Degree: %d\n", i + 1, nodes[i].name, nodes[i].degree);
        if (nodes[i].neighbors!= NULL) {
            printf("Neighbors: ");
            for (int j = 0; j < nodes[i].degree; j++) {
                printf("%d ", nodes[i].neighbors[j] + 1);
            }
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    int choice;
    char name[10];
    int id, source, destination, weight;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    for (int i = 0; i < num_nodes; i++) {
        printf("Enter the ID and name of node %d: ", i + 1);
        scanf("%d %s", &id, name);
        add_node(id, name);
    }

    do {
        printf("\nChoose an option:\n");
        printf("1. Add an edge\n");
        printf("2. Print the graph\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the source and destination IDs and the weight of the edge: ");
                scanf("%d %d %d", &source, &destination, &weight);
                add_edge(source, destination, weight);
                break;
            case 2:
                print_graph();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}