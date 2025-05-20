//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Structures for the futuristic data structures
struct Node {
    int data;
    struct Node *next;
};

struct LinkedList {
    struct Node *head;
};

struct Heap {
    struct Node *root;
};

struct Tree {
    struct Node *root;
};

struct Graph {
    struct Node **adjacency_list;
};

// Functions for the futuristic data structures
void insert_node(struct LinkedList *list, int data) {
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
}

void insert_node_heap(struct Heap *heap, int data) {
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = heap->root;
    heap->root = new_node;
}

void insert_node_tree(struct Tree *tree, int data) {
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = tree->root;
    tree->root = new_node;
}

void insert_node_graph(struct Graph *graph, int data) {
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = graph->adjacency_list[data];
    graph->adjacency_list[data] = new_node;
}

// Main function
int main() {
    // Linked list example
    struct LinkedList list;
    list.head = NULL;

    insert_node(&list, 1);
    insert_node(&list, 2);
    insert_node(&list, 3);

    printf("Linked list: ");
    struct Node *curr = list.head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    // Heap example
    struct Heap heap;
    heap.root = NULL;

    insert_node_heap(&heap, 1);
    insert_node_heap(&heap, 2);
    insert_node_heap(&heap, 3);

    printf("Heap: ");
    struct Node *curr_heap = heap.root;
    while (curr_heap != NULL) {
        printf("%d ", curr_heap->data);
        curr_heap = curr_heap->next;
    }
    printf("\n");

    // Tree example
    struct Tree tree;
    tree.root = NULL;

    insert_node_tree(&tree, 1);
    insert_node_tree(&tree, 2);
    insert_node_tree(&tree, 3);

    printf("Tree: ");
    struct Node *curr_tree = tree.root;
    while (curr_tree != NULL) {
        printf("%d ", curr_tree->data);
        curr_tree = curr_tree->next;
    }
    printf("\n");

    // Graph example
    struct Graph graph;
    graph.adjacency_list = malloc(sizeof(struct Node *) * 10);

    insert_node_graph(&graph, 1);
    insert_node_graph(&graph, 2);
    insert_node_graph(&graph, 3);

    printf("Graph: ");
    struct Node *curr_graph = graph.adjacency_list[1];
    while (curr_graph != NULL) {
        printf("%d ", curr_graph->data);
        curr_graph = curr_graph->next;
    }
    printf("\n");

    return 0;
}