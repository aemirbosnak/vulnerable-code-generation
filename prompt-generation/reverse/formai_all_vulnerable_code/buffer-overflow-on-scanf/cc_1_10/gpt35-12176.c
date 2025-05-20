//FormAI DATASET v1.0 Category: Graph representation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node NODE;

void add_edge(NODE **head_ref, int src, int dest, int V) {
    if(src >= V || dest >= V) {
        printf("\nInvalid edge\n");
        return;
    }

    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    new_node->data = dest;
    new_node->next = head_ref[src];
    head_ref[src] = new_node;
}

void print_graph(NODE **head_ref, int V) {
    int i;

    for(i = 0; i < V; i++) {
        NODE *trav_ptr = head_ref[i];
        printf("\n%d : ", i);

        while(trav_ptr) {
            printf("%d ", trav_ptr->data);
            trav_ptr = trav_ptr->next;
        }
    }
}

int main() {
    int V, E, i, src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    NODE **head_ref = malloc(V * sizeof(NODE*));
    for(i = 0; i < V; i++) {
        head_ref[i] = NULL;
    }

    printf("\nEnter the number of edges: ");
    scanf("%d", &E);

    printf("\nEnter the edges (source, destination):\n");
    for(i = 0; i < E; i++) {
        scanf("%d%d", &src, &dest);
        add_edge(head_ref, src, dest, V);
    }

    printf("\nGraph Adjacency List:\n");
    print_graph(head_ref, V);

    return 0;
}