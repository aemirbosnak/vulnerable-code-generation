//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_LINES 1000

typedef struct {
    char name[20];
    int num_links;
    int *links;
} Node;

Node nodes[MAX_NODES];

void add_node(char *name) {
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        if (nodes[i].name[0] == '\0') {
            strcpy(nodes[i].name, name);
            nodes[i].num_links = 0;
            nodes[i].links = NULL;
            return;
        }
    }
    printf("Error: Maximum number of nodes reached.\n");
    exit(1);
}

void add_link(char *node1, char *node2) {
    int i, j;
    for (i = 0; i < MAX_NODES; i++) {
        if (strcmp(nodes[i].name, node1) == 0) {
            for (j = 0; j < nodes[i].num_links; j++) {
                if (strcmp(nodes[i].links[j], node2) == 0) {
                    printf("Error: Link already exists.\n");
                    return;
                }
            }
            nodes[i].links = realloc(nodes[i].links, sizeof(int) * (nodes[i].num_links + 1));
            nodes[i].links[nodes[i].num_links++] = -1; // -1 indicates end of links for this node
            return;
        }
    }
    printf("Error: Node not found.\n");
    exit(1);
}

void print_links(int node_index) {
    int i;
    for (i = 0; i < nodes[node_index].num_links; i++) {
        printf("%s ", nodes[node_index].links[i]);
    }
    printf("\n");
}

void print_topology() {
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        if (nodes[i].name[0]!= '\0') {
            printf("Node %s:\n", nodes[i].name);
            print_links(i);
        }
    }
}

int main() {
    char input[100];
    int choice, node1_index, node2_index;

    printf("Enter the name of the first node:\n");
    scanf("%s", input);
    add_node(input);

    while (1) {
        printf("\n1. Add node\n2. Add link\n3. Print topology\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the name of the new node:\n");
            scanf("%s", input);
            add_node(input);
            break;

        case 2:
            printf("Enter the names of the two nodes to link:\n");
            scanf("%s %s", input, input+strlen(input));
            add_link(input, input+strlen(input));
            break;

        case 3:
            printf("\nTopology:\n");
            print_topology();
            break;

        case 4:
            exit(0);

        default:
            printf("Error: Invalid choice.\n");
        }
    }

    return 0;
}