//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 1000

typedef struct node {
    int id;
    int x, y;
    struct node *next;
} Node;

Node *graph = NULL;
int num_nodes = 0;

void init() {
    srand(time(0));
    graph = NULL;
    num_nodes = 0;
}

void add_node() {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->id = num_nodes++;
    new_node->x = rand() % 1000;
    new_node->y = rand() % 1000;
    new_node->next = NULL;

    if (graph == NULL) {
        graph = new_node;
    } else {
        Node *last_node = graph;
        while (last_node->next!= NULL) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }
}

void print_graph() {
    Node *curr_node = graph;
    while (curr_node!= NULL) {
        printf("Node %d: (%d, %d)\n", curr_node->id, curr_node->x, curr_node->y);
        curr_node = curr_node->next;
    }
}

int main() {
    init();

    int num_edges;
    scanf("%d", &num_edges);

    for (int i = 0; i < num_edges; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);

        Node *node1_ptr = graph;
        while (node1_ptr!= NULL && node1_ptr->id!= node1) {
            node1_ptr = node1_ptr->next;
        }

        Node *node2_ptr = graph;
        while (node2_ptr!= NULL && node2_ptr->id!= node2) {
            node2_ptr = node2_ptr->next;
        }

        if (node1_ptr == NULL || node2_ptr == NULL) {
            printf("Invalid node IDs\n");
            continue;
        }

        node1_ptr->next = node2_ptr;
    }

    print_graph();

    return 0;
}