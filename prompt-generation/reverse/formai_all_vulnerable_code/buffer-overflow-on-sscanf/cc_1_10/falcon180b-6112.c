//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NETWORK_SIZE 100
#define MAX_NODE_SIZE 10

typedef struct {
    char name[MAX_NODE_SIZE];
    int id;
    bool is_router;
} Node;

typedef struct {
    int num_nodes;
    Node nodes[MAX_NETWORK_SIZE];
} Network;

void read_nodes_from_file(Network* net, FILE* file) {
    char line[MAX_NODE_SIZE];
    Node node;
    int num_nodes = 0;

    while (fgets(line, MAX_NODE_SIZE, file)!= NULL) {
        strcpy(node.name, line);
        sscanf(line, "%s %d", node.name, &node.id);
        node.is_router = false;

        if (num_nodes >= MAX_NETWORK_SIZE) {
            printf("Error: Maximum number of nodes reached.\n");
            exit(1);
        }

        net->nodes[num_nodes++] = node;
    }

    net->num_nodes = num_nodes;
}

void add_router(Network* net, int node_id) {
    for (int i = 0; i < net->num_nodes; i++) {
        if (net->nodes[i].id == node_id) {
            net->nodes[i].is_router = true;
            return;
        }
    }

    printf("Error: Node not found.\n");
    exit(1);
}

void print_network_topology(Network* net) {
    printf("Network Topology:\n");

    for (int i = 0; i < net->num_nodes; i++) {
        printf("Node %d: %s\n", net->nodes[i].id, net->nodes[i].name);

        if (net->nodes[i].is_router) {
            printf("  Router\n");
        } else {
            printf("  End device\n");
        }
    }
}

int main() {
    Network net;
    FILE* file = fopen("network.txt", "r");

    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    read_nodes_from_file(&net, file);
    fclose(file);

    int num_nodes = net.num_nodes;
    int num_routers = 0;

    for (int i = 0; i < num_nodes; i++) {
        if (net.nodes[i].is_router) {
            num_routers++;
        }
    }

    printf("Number of nodes: %d\n", num_nodes);
    printf("Number of routers: %d\n", num_routers);

    print_network_topology(&net);

    return 0;
}