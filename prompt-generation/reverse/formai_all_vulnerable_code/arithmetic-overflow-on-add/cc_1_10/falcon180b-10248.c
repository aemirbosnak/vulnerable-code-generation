//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_LINKS 200

typedef struct {
    char name[20];
    int id;
    int links[MAX_LINKS];
    int num_links;
} Node;

void add_link(Node* node1, Node* node2) {
    int i;
    for(i = 0; i < node1->num_links; i++) {
        if(node1->links[i] == node2->id) {
            return;
        }
    }
    node1->links[node1->num_links] = node2->id;
    node1->num_links++;
}

int main() {
    int i, j, num_nodes;
    Node nodes[MAX_NODES];

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    for(i = 0; i < num_nodes; i++) {
        printf("Enter the name of node %d: ", i+1);
        scanf("%s", nodes[i].name);
        nodes[i].id = i+1;
        nodes[i].num_links = 0;
    }

    printf("Enter the links between nodes:\n");
    while(1) {
        printf("Enter the ID of the first node: ");
        scanf("%d", &i);
        printf("Enter the ID of the second node: ");
        scanf("%d", &j);
        add_link(&nodes[i-1], &nodes[j-1]);
    }

    for(i = 0; i < num_nodes; i++) {
        printf("Node %d: %s\n", nodes[i].id, nodes[i].name);
        printf("Links:");
        for(j = 0; j < nodes[i].num_links; j++) {
            printf(" %d", nodes[i].links[j]);
        }
        printf("\n");
    }

    return 0;
}