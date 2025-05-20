//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 100

typedef struct {
    int id;
    char name[20];
} Node;

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];

int num_nodes, num_edges;

void add_node(int id, char* name) {
    if (num_nodes >= MAX_NODES) {
        printf("Error: Maximum number of nodes exceeded.\n");
        return;
    }
    nodes[num_nodes].id = id;
    strcpy(nodes[num_nodes].name, name);
    num_nodes++;
}

void add_edge(int src, int dest, int weight) {
    if (num_edges >= MAX_EDGES) {
        printf("Error: Maximum number of edges exceeded.\n");
        return;
    }
    edges[num_edges].src = src;
    edges[num_edges].dest = dest;
    edges[num_edges].weight = weight;
    num_edges++;
}

void display_nodes() {
    printf("Nodes:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("%d. %s\n", nodes[i].id, nodes[i].name);
    }
}

void display_edges() {
    printf("\nEdges:\n");
    for (int i = 0; i < num_edges; i++) {
        printf("(%d,%d) - %d\n", edges[i].src, edges[i].dest, edges[i].weight);
    }
}

int main() {
    int choice;
    char name[20];

    do {
        printf("\n1. Add Node\n2. Add Edge\n3. Display Nodes\n4. Display Edges\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter node ID: ");
            scanf("%d", &num_nodes);
            printf("Enter node name: ");
            scanf("%s", name);
            add_node(num_nodes, name);
            break;
        case 2:
            printf("Enter source node ID: ");
            scanf("%d", &edges[num_edges].src);
            printf("Enter destination node ID: ");
            scanf("%d", &edges[num_edges].dest);
            printf("Enter edge weight: ");
            scanf("%d", &edges[num_edges].weight);
            num_edges++;
            break;
        case 3:
            display_nodes();
            break;
        case 4:
            display_edges();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}