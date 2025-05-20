//FormAI DATASET v1.0 Category: Graph representation ; Style: Claude Shannon
// This program represents a simple undirected graph using an adjacency list
// in a Claude Shannon style

#include <stdio.h>
#include <stdlib.h>

// The maximum number of vertices in the graph
#define MAX_VERTICES 10

// A structure to represent each vertex in the graph
struct vertex {
    int value;
    struct edge *adj_list;
};

// A structure to represent each edge in the graph
struct edge {
    int weight;
    struct vertex *dest;
    struct edge *next;
};

// A function to create a new vertex with a given value
struct vertex *create_vertex(int value) {
    struct vertex *v = malloc(sizeof(struct vertex));
    v->value = value;
    v->adj_list = NULL;
    return v;
}

// A function to create a new edge with a given weight and destination vertex
struct edge *create_edge(int weight, struct vertex *dest) {
    struct edge *e = malloc(sizeof(struct edge));
    e->weight = weight;
    e->dest = dest;
    e->next = NULL;
    return e;
}

// A function to add an edge to the graph between two vertices
void add_edge(struct vertex *v1, struct vertex *v2, int weight) {
    struct edge *e1 = create_edge(weight, v2);
    struct edge *e2 = create_edge(weight, v1);
    e1->next = v1->adj_list;
    v1->adj_list = e1;
    e2->next = v2->adj_list;
    v2->adj_list = e2;
}

int main() {
    int num_vertices;
    printf("Enter the number of vertices in the graph (maximum %d): ", MAX_VERTICES);
    scanf("%d", &num_vertices);

    // Create the vertices
    struct vertex *vertices[MAX_VERTICES];
    for (int i = 0; i < num_vertices; i++) {
        vertices[i] = create_vertex(i);
    }

    // Add the edges
    add_edge(vertices[0], vertices[1], 1);
    add_edge(vertices[0], vertices[2], 2);
    add_edge(vertices[1], vertices[3], 3);
    add_edge(vertices[2], vertices[4], 4);
    add_edge(vertices[3], vertices[4], 5);

    // Print the graph
    printf("Graph:\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d", vertices[i]->value);
        for (struct edge *curr = vertices[i]->adj_list; curr != NULL; curr = curr->next) {
            printf(" --(%d)--> %d", curr->weight, curr->dest->value);
        }
        printf("\n");
    }

    return 0;
}