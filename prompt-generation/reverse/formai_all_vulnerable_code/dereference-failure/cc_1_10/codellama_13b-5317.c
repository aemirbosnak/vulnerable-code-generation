//Code Llama-13B DATASET v1.0 Category: Graph Coloring Problem ; Style: rigorous
/*
 * Graph Coloring Problem Example Program
 *
 * Description: Given an undirected graph G = (V, E) and an integer k,
 * find a proper coloring of the graph with at most k colors.
 *
 * Complexity: O(n^2) time and O(n) space
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for the graph
typedef struct node {
    int value;
    struct node* next;
} node;

// Graph structure
typedef struct graph {
    int num_vertices;
    int num_edges;
    node** adj_list;
} graph;

// Create a new graph
graph* create_graph(int num_vertices, int num_edges) {
    graph* g = malloc(sizeof(graph));
    g->num_vertices = num_vertices;
    g->num_edges = num_edges;
    g->adj_list = malloc(num_vertices * sizeof(node*));
    for (int i = 0; i < num_vertices; i++) {
        g->adj_list[i] = malloc(sizeof(node));
        g->adj_list[i]->next = NULL;
    }
    return g;
}

// Add an edge to the graph
void add_edge(graph* g, int u, int v) {
    node* new_node = malloc(sizeof(node));
    new_node->value = v;
    new_node->next = g->adj_list[u]->next;
    g->adj_list[u]->next = new_node;
}

// Print the graph
void print_graph(graph* g) {
    for (int i = 0; i < g->num_vertices; i++) {
        node* current = g->adj_list[i];
        printf("%d: ", i);
        while (current != NULL) {
            printf("%d ", current->value);
            current = current->next;
        }
        printf("\n");
    }
}

// Check if the graph is connected
bool is_connected(graph* g) {
    bool visited[g->num_vertices];
    for (int i = 0; i < g->num_vertices; i++) {
        visited[i] = false;
    }
    visited[0] = true;
    int queue[g->num_vertices];
    int front = 0;
    int rear = 0;
    queue[rear++] = 0;
    while (front != rear) {
        int u = queue[front++];
        node* current = g->adj_list[u];
        while (current != NULL) {
            int v = current->value;
            if (!visited[v]) {
                visited[v] = true;
                queue[rear++] = v;
            }
            current = current->next;
        }
    }
    for (int i = 0; i < g->num_vertices; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

// Check if the graph is bipartite
bool is_bipartite(graph* g) {
    bool visited[g->num_vertices];
    for (int i = 0; i < g->num_vertices; i++) {
        visited[i] = false;
    }
    visited[0] = true;
    int queue[g->num_vertices];
    int front = 0;
    int rear = 0;
    queue[rear++] = 0;
    while (front != rear) {
        int u = queue[front++];
        node* current = g->adj_list[u];
        while (current != NULL) {
            int v = current->value;
            if (!visited[v]) {
                visited[v] = true;
                queue[rear++] = v;
            }
            current = current->next;
        }
    }
    for (int i = 0; i < g->num_vertices; i++) {
        if (visited[i]) {
            return true;
        }
    }
    return false;
}

// Check if the graph is k-colorable
bool is_k_colorable(graph* g, int k) {
    int colors[g->num_vertices];
    for (int i = 0; i < g->num_vertices; i++) {
        colors[i] = 0;
    }
    for (int i = 0; i < g->num_vertices; i++) {
        node* current = g->adj_list[i];
        while (current != NULL) {
            int v = current->value;
            if (colors[i] == colors[v]) {
                return false;
            }
            current = current->next;
        }
    }
    return true;
}

// Main function
int main() {
    int num_vertices = 10;
    int num_edges = 15;
    graph* g = create_graph(num_vertices, num_edges);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 1, 4);
    add_edge(g, 2, 5);
    add_edge(g, 2, 6);
    add_edge(g, 3, 7);
    add_edge(g, 3, 8);
    add_edge(g, 4, 9);
    add_edge(g, 4, 10);
    print_graph(g);
    printf("Is connected: %d\n", is_connected(g));
    printf("Is bipartite: %d\n", is_bipartite(g));
    printf("Is 3-colorable: %d\n", is_k_colorable(g, 3));
    return 0;
}