//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8888
#define MAX_NODES 100
#define INFECTED_THRESHOLD 0.5

struct node {
    int id;
    int state;
    struct node *next;
};

struct network {
    struct node *head;
    int num_nodes;
};

void init_network(struct network *net) {
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        struct node *node = malloc(sizeof(struct node));
        node->id = i;
        node->state = 0; // not infected
        node->next = NULL;
        if (i % 2 == 0) {
            node->state = 1; // infected
        }
        net->head = node;
        net->num_nodes++;
    }
}

void infect_nodes(struct network *net) {
    int i;
    for (i = 0; i < net->num_nodes; i++) {
        struct node *node = net->head;
        if (node->state == 0) {
            node->state = 1; // infect node
            node->next->state = 1; // infect neighbor
        }
        node = node->next;
    }
}

void print_network(struct network *net) {
    int i;
    for (i = 0; i < net->num_nodes; i++) {
        struct node *node = net->head;
        if (node->state == 1) {
            printf("Infected node %d\n", node->id);
        } else {
            printf("Not infected node %d\n", node->id);
        }
        node = node->next;
    }
}

int main() {
    struct network net;
    init_network(&net);

    // simulate time passing
    int time = 0;
    while (time < 100) {
        // infect nodes
        infect_nodes(&net);

        // print network state
        print_network(&net);

        // update time
        time++;
    }

    return 0;
}