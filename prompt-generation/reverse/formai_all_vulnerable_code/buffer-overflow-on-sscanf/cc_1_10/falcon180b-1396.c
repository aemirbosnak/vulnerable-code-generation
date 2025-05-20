//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_PORT_LEN 6
#define MAX_LINE_LEN 1024
#define MAX_CONNECTIONS 100

typedef struct {
    char hostname[MAX_HOSTNAME_LEN];
    int port;
    char status[MAX_PORT_LEN];
} node_t;

node_t nodes[MAX_CONNECTIONS];
int num_nodes = 0;

void add_node(const char* hostname, int port) {
    if (num_nodes >= MAX_CONNECTIONS) {
        printf("Maximum number of connections reached.\n");
        return;
    }

    node_t* new_node = &nodes[num_nodes];
    strcpy(new_node->hostname, hostname);
    new_node->port = port;
    strcpy(new_node->status, "OK");

    num_nodes++;
}

void remove_node(int index) {
    if (index < 0 || index >= num_nodes) {
        printf("Invalid node index.\n");
        return;
    }

    memset(&nodes[index], 0, sizeof(node_t));
    num_nodes--;
}

void update_node_status(int index, const char* status) {
    if (index < 0 || index >= num_nodes) {
        printf("Invalid node index.\n");
        return;
    }

    strcpy(nodes[index].status, status);
}

void print_network_topology() {
    printf("Network Topology:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("%s:%d - %s\n", nodes[i].hostname, nodes[i].port, nodes[i].status);
    }
}

int main() {
    FILE* fp;
    char line[MAX_LINE_LEN];
    char hostname[MAX_HOSTNAME_LEN];
    int port;

    fp = fopen("nodes.txt", "r");
    if (fp == NULL) {
        printf("Error opening nodes file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        sscanf(line, "%s:%d", hostname, &port);
        add_node(hostname, port);
    }

    fclose(fp);

    print_network_topology();

    return 0;
}