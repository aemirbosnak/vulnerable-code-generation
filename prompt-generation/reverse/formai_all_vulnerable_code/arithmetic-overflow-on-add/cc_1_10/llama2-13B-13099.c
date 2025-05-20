//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Graph structure using linked lists
struct Graph {
    int num_vertices;
    struct List* adjacency_list;
};

// List structure for storing adjacency list
struct List {
    int size;
    struct Node* head;
};

// Node structure for storing vertices
struct Node {
    int data;
    struct Node* next;
};

// Function to create a graph
struct Graph* create_graph(int num_vertices) {
    struct Graph* g = malloc(sizeof(struct Graph));
    g->num_vertices = num_vertices;
    g->adjacency_list = malloc(sizeof(struct List));
    g->adjacency_list->size = 0;
    return g;
}

// Function to add edge to graph
void add_edge(struct Graph* g, int v1, int v2) {
    struct Node* node1 = malloc(sizeof(struct Node));
    node1->data = v1;
    struct Node* node2 = malloc(sizeof(struct Node));
    node2->data = v2;
    node1->next = g->adjacency_list->head;
    g->adjacency_list->head = node1;
    g->adjacency_list->size++;
    struct Node* current = g->adjacency_list->head;
    while (current != NULL) {
        if (current->data == v2) {
            current->next = node2;
            break;
        }
        current = current->next;
    }
}

// Function to traverse the graph
void traverse(struct Graph* g) {
    struct Node* current = g->adjacency_list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Graph* g = create_graph(5);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 4);
    add_edge(g, 3, 4);
    traverse(g);
    return 0;
}