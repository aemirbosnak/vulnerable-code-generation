//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_LINKS 100
#define MAX_NODES_PER_LINK 10

typedef struct {
    int id;
    double latency;
    double throughput;
    int num_links;
    int *links;
} Node;

typedef struct {
    int id;
    double latency;
    double throughput;
    int num_links;
    int *links;
} Link;

Node nodes[MAX_NODES];
Link links[MAX_LINKS];
int num_nodes = 0;
int num_links = 0;

void add_node(int id, double latency, double throughput) {
    Node *node = &nodes[num_nodes];
    node->id = id;
    node->latency = latency;
    node->throughput = throughput;
    num_nodes++;
}

void add_link(int id, int node1, int node2, double latency, double throughput) {
    Link *link = &links[num_links];
    link->id = id;
    link->latency = latency;
    link->throughput = throughput;
    link->num_links = 2;
    link->links = malloc(sizeof(int) * link->num_links);
    link->links[0] = node1;
    link->links[1] = node2;
    num_links++;
}

int main(int argc, char **argv) {
    add_node(1, 10, 100);
    add_node(2, 20, 200);
    add_node(3, 30, 300);
    add_node(4, 40, 400);
    add_node(5, 50, 500);

    add_link(1, 1, 2, 5, 500);
    add_link(2, 2, 3, 10, 1000);
    add_link(3, 3, 4, 15, 1500);
    add_link(4, 4, 5, 20, 2000);

    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: Latency = %.2fms, Throughput = %.2fMbps\n", nodes[i].id, nodes[i].latency, nodes[i].throughput);
    }

    for (int i = 0; i < num_links; i++) {
        printf("Link %d: Latency = %.2fms, Throughput = %.2fMbps\n", links[i].id, links[i].latency, links[i].throughput);
    }

    return 0;
}