//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

typedef struct {
    int data;
    int degree;
    bool visited;
    struct node *next;
} Node;

Node *graph[MAX_NODES];
int num_nodes;
int num_edges;

void add_edge(int u, int v) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = v;
    new_node->degree = 0;
    new_node->visited = false;
    new_node->next = graph[u];
    graph[u] = new_node;
    num_edges++;
}

void dfs(int start_node) {
    Node *current_node = graph[start_node];
    while (current_node!= NULL) {
        if (!current_node->visited) {
            printf("%d ", current_node->data);
            current_node->visited = true;
            dfs(current_node->data);
        }
        current_node = current_node->next;
    }
}

int main() {
    int u, v, i, j;
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    for (i = 0; i < num_nodes; i++) {
        graph[i] = NULL;
    }

    printf("Enter the edges:\n");
    for (i = 0; i < num_edges; i++) {
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    printf("Depth First Search:\n");
    for (i = 0; i < num_nodes; i++) {
        if (graph[i]!= NULL) {
            printf("Node %d:\t", i);
            dfs(i);
            printf("\n");
        }
    }

    return 0;
}