//MISTRAL-7B DATASET v1.0 Category: Network Topology Mapper ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 50
#define EDGE_CHAR '>'
#define NODE_SIZE 2

typedef struct {
    int id;
    int connections[MAX_NODES];
    int num_connections;
} Node;

void create_random_network(Node* nodes, int num_nodes) {
    int i, j, k;

    srand(time(NULL));

    for (i = 0; i < num_nodes; ++i) {
        nodes[i].id = i;
        nodes[i].num_connections = 0;
    }

    for (i = 0; i < num_nodes; ++i) {
        for (j = i + 1; j < num_nodes; ++j) {
            k = rand() % (i + 1);
            if (k <= i) continue;

            nodes[i].connections[nodes[i].num_connections] = j;
            nodes[j].connections[nodes[j].num_connections] = i;
            nodes[i].num_connections++;
            nodes[j].num_connections++;
        }
    }
}

void print_network(Node* nodes, int num_nodes) {
    int i, j;

    for (i = 0; i < num_nodes; ++i) {
        printf("%d :", nodes[i].id);

        for (j = 0; j < nodes[i].num_connections; ++j) {
            printf("%c%d", EDGE_CHAR, nodes[nodes[i].connections[j]].id);
        }

        printf(".\n");
    }
}

int main() {
    Node nodes[MAX_NODES];
    int num_nodes, i;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    if (num_nodes > MAX_NODES) {
        printf("Error: Too many nodes.\n");
        return 1;
    }

    create_random_network(nodes, num_nodes);
    print_network(nodes, num_nodes);

    return 0;
}