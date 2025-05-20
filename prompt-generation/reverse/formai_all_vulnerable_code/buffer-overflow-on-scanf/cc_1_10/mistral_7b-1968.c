//MISTRAL-7B DATASET v1.0 Category: Network Topology Mapper ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct {
    char name[30];
    int visited;
    int degree;
    int *neighbors;
} Node;

Node *nodes[MAX_NODES];
int num_nodes = 0;

void add_node(char *name) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->visited = 0;
    new_node->degree = 0;
    nodes[num_nodes++] = new_node;
}

void add_edge(char *node1, char *node2) {
    int i, j;

    for (i = 0; i < num_nodes; i++) {
        if (strcmp(nodes[i]->name, node1) == 0) {
            Node *node = nodes[i];
            node->degree++;
            node->neighbors = (int *)realloc(node->neighbors, sizeof(int) * (node->degree + 1));
            for (j = 0; j < num_nodes; j++) {
                if (strcmp(nodes[j]->name, node2) == 0) {
                    node->neighbors[node->degree++] = j;
                    nodes[j]->degree++;
                    nodes[j]->neighbors = (int *)realloc(nodes[j]->neighbors, sizeof(int) * (nodes[j]->degree + 1));
                    nodes[j]->neighbors[nodes[j]->degree - 1] = i;
                    break;
                }
            }
            break;
        }
    }
}

void traverse(int start) {
    Node *node = nodes[start];
    int i;

    node->visited = 1;
    printf("%s -> %s\n", node->name, "-");

    for (i = 0; i < node->degree; i++) {
        traverse(nodes[node->neighbors[i]]->name);
    }
}

int main() {
    char nodes_str[100][30];
    int edges_num;
    int i, j;

    printf("Enter number of nodes and edges:\n");
    scanf("%d%d", &num_nodes, &edges_num);

    for (i = 0; i < num_nodes; i++) {
        printf("Enter node %d name:\n", i + 1);
        scanf("%s", nodes_str[i]);
        add_node(nodes_str[i]);
    }

    printf("Enter edges:\n");

    for (i = 0; i < edges_num; i++) {
        char node1[30], node2[30];
        scanf("%s%s", node1, node2);
        add_edge(node1, node2);
    }

    traverse(nodes[0]->name);

    return 0;
}