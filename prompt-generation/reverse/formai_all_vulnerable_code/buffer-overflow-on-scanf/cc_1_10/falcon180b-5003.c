//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    int id;
    char name[20];
    int connected_nodes[MAX_NODES];
    int num_connected_nodes;
} Node;

typedef struct {
    int src_node_id;
    int dest_node_id;
    int weight;
} Edge;

Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];

void add_node(int id, char* name) {
    int i;
    for(i = 0; i < MAX_NODES; i++) {
        if(nodes[i].id == -1) {
            nodes[i].id = id;
            strcpy(nodes[i].name, name);
            nodes[i].num_connected_nodes = 0;
            break;
        }
    }
}

void add_edge(int src_id, int dest_id, int weight) {
    int i;
    for(i = 0; i < MAX_EDGES; i++) {
        if(edges[i].src_node_id == -1) {
            edges[i].src_node_id = src_id;
            edges[i].dest_node_id = dest_id;
            edges[i].weight = weight;
            break;
        }
    }
}

void print_nodes() {
    int i;
    for(i = 0; i < MAX_NODES; i++) {
        if(nodes[i].id!= -1) {
            printf("Node ID %d: %s\n", nodes[i].id, nodes[i].name);
            printf("Connected Nodes: ");
            int j;
            for(j = 0; j < nodes[i].num_connected_nodes; j++) {
                printf("%d ", nodes[i].connected_nodes[j]);
            }
            printf("\n");
        }
    }
}

void print_edges() {
    int i;
    for(i = 0; i < MAX_EDGES; i++) {
        if(edges[i].src_node_id!= -1) {
            printf("Edge: %d -> %d (weight %d)\n", edges[i].src_node_id, edges[i].dest_node_id, edges[i].weight);
        }
    }
}

int main() {
    int num_nodes, num_edges, i;
    char name[20];
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    printf("Enter the name of each node:\n");
    for(i = 0; i < num_nodes; i++) {
        scanf(" %s", name);
        add_node(i, name);
    }
    printf("Enter the source node ID, destination node ID, and weight of each edge:\n");
    for(i = 0; i < num_edges; i++) {
        scanf("%d %d %d", &edges[i].src_node_id, &edges[i].dest_node_id, &edges[i].weight);
        add_edge(edges[i].src_node_id, edges[i].dest_node_id, edges[i].weight);
    }
    print_nodes();
    print_edges();
    return 0;
}