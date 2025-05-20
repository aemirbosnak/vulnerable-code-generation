//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char* name;
    int count;
};

struct node* new_node(char* name, int count) {
    struct node* node = malloc(sizeof(struct node));
    node->name = name;
    node->count = count;
    return node;
}

void free_node(struct node* node) {
    free(node->name);
    free(node);
}

int main() {
    struct node* nodes[10];
    int num_nodes = 0;
    int num_edges = 0;
    int max_count = 0;

    printf("Enter the number of nodes (max 10): ");
    scanf("%d", &num_nodes);

    for (int i = 0; i < num_nodes; i++) {
        printf("Enter the name and count of node %d: ", i + 1);
        char* name = malloc(sizeof(char) * 50);
        scanf("%s", name);
        int count = 0;
        scanf("%d", &count);
        nodes[i] = new_node(name, count);
        if (count > max_count)
            max_count = count;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    for (int i = 0; i < num_edges; i++) {
        printf("Enter the source node and destination node (separated by a space): ");
        char* source = malloc(sizeof(char) * 50);
        char* destination = malloc(sizeof(char) * 50);
        scanf("%s %s", source, destination);
        int source_index = 0;
        int destination_index = 0;
        for (int j = 0; j < num_nodes; j++) {
            if (strcmp(nodes[j]->name, source) == 0) {
                source_index = j;
                break;
            }
        }
        for (int j = 0; j < num_nodes; j++) {
            if (strcmp(nodes[j]->name, destination) == 0) {
                destination_index = j;
                break;
            }
        }
        nodes[source_index]->count += nodes[destination_index]->count;
    }

    printf("Node 1: %s, Count: %d\n", nodes[0]->name, nodes[0]->count);
    for (int i = 1; i < num_nodes; i++) {
        printf("Node %d: %s, Count: %d\n", i + 1, nodes[i]->name, nodes[i]->count);
    }

    printf("Max Count: %d\n", max_count);

    free(nodes[0]->name);
    free(nodes[1]->name);
    free(nodes[2]->name);
    free(nodes[3]->name);
    free(nodes[4]->name);
    free(nodes[5]->name);
    free(nodes[6]->name);
    free(nodes[7]->name);
    free(nodes[8]->name);
    free(nodes[9]->name);

    for (int i = 0; i < num_nodes; i++) {
        free_node(nodes[i]);
    }

    return 0;
}