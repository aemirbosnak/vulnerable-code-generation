//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Ada Lovelace
// Welcome to my C Network Topology Mapper example program, in the style of Ada Lovelace!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

// Define our node and edge structures
typedef struct node {
    int id;
    char ip[16];
} Node;

typedef struct edge {
    int id;
    int from_node;
    int to_node;
    int weight;
} Edge;

// Declare our arrays to hold our nodes and edges
Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];

// Initialize the number of nodes and edges to 0
int num_nodes = 0;
int num_edges = 0;

int main() {
    // Let's read in our topology data from a file
    FILE *topology_file = fopen("topology.txt", "r");

    if (topology_file == NULL) {
        printf("Error opening topology file\n");
        return 1;
    }

    char line[256];

    // Parse each line of the file and add nodes and edges as we go
    while (fgets(line, sizeof(line), topology_file)) {
        if (strstr(line, "Node")) {
            // If we encounter a node line, read in the ID and IP address
            Node n;
            sscanf(line, "Node %d %s", &n.id, n.ip);
            nodes[num_nodes] = n;
            num_nodes++;
        } else if (strstr(line, "Edge")) {
            // If we encounter an edge line, read in the ID, from_node, to_node, and weight
            Edge e;
            sscanf(line, "Edge %d %d %d %d", &e.id, &e.from_node, &e.to_node, &e.weight);
            edges[num_edges] = e;
            num_edges++;
        }
    }
    fclose(topology_file);

    // Print out our nodes and edges to verify that everything was read in correctly
    printf("Nodes:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d - IP address: %s\n", nodes[i].id, nodes[i].ip);
    }

    printf("\nEdges:\n");
    for (int i = 0; i < num_edges; i++) {
        printf("Edge %d - from node: %d, to node: %d, weight: %d\n", 
            edges[i].id, edges[i].from_node, edges[i].to_node, edges[i].weight);
    }

    // Let's also generate a graphviz file to visualize the network topology
    FILE *graph_file = fopen("topology.dot", "w");

    if (graph_file == NULL) {
        printf("Error creating graph file\n");
        return 1;
    }

    fprintf(graph_file, "digraph {\n");

    for (int i = 0; i < num_edges; i++) {
        fprintf(graph_file, "\t%d -> %d [label=%d];\n", 
            edges[i].from_node, edges[i].to_node, edges[i].weight);
    }

    fprintf(graph_file, "}\n");
    fclose(graph_file);

    printf("\nNetwork topology graph created at topology.dot\n");

    return 0;
}