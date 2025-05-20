//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PEERS 20
#define MAX_NODES 50
#define MAX_NAME 50

typedef struct {
    char name[MAX_NAME];
    int port;
    int index;
} Peer;

typedef struct {
    int id;
    char name[MAX_NAME];
    int num_peers;
    Peer peers[MAX_PEERS];
} Node;

Node nodes[MAX_NODES];
int num_nodes = 0;

void add_node(Node *node) {
    nodes[num_nodes++] = *node;
}

void print_nodes() {
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %s\n", nodes[i].id, nodes[i].name);
        for (int j = 0; j < nodes[i].num_peers; j++) {
            printf("  Peer %d: %s:%d\n", nodes[i].peers[j].index, nodes[i].peers[j].name, nodes[i].peers[j].port);
        }
    }
}

int main() {
    char buffer[1024];
    int i, j, k, m, n, id, port, num_peers;
    char name[MAX_NAME];
    Node node;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    for (i = 0; i < num_nodes; i++) {
        printf("Enter the name of node %d: ", i + 1);
        scanf("%s", name);

        printf("Enter the number of peers for node %s: ", name);
        scanf("%d", &num_peers);

        node.id = i + 1;
        strcpy(node.name, name);
        node.num_peers = num_peers;

        for (j = 0; j < num_peers; j++) {
            printf("Enter the name of peer %d for node %s: ", j + 1, name);
            scanf("%s", name);

            printf("Enter the port number for peer %s: ", name);
            scanf("%d", &port);

            strcpy(node.peers[j].name, name);
            node.peers[j].port = port;
            node.peers[j].index = j + 1;
        }

        add_node(&node);
    }

    print_nodes();

    return 0;
}