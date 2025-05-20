//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for a node in the graph
struct Node {
    char name[10];
    struct Node* next;
};

// Struct for a graph
struct Graph {
    struct Node* head;
    int num_nodes;
};

// Function to create a new node
struct Node* create_node(char* name) {
    struct Node* node = malloc(sizeof(struct Node));
    strcpy(node->name, name);
    node->next = NULL;
    return node;
}

// Function to add a new node to the graph
void add_node(struct Graph* graph, char* name) {
    struct Node* node = create_node(name);
    if (graph->head == NULL) {
        graph->head = node;
    } else {
        struct Node* current = graph->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
    graph->num_nodes++;
}

// Function to remove a node from the graph
void remove_node(struct Graph* graph, char* name) {
    if (graph->head == NULL) {
        return;
    }
    struct Node* current = graph->head;
    if (strcmp(current->name, name) == 0) {
        graph->head = current->next;
        free(current);
        graph->num_nodes--;
        return;
    }
    while (current->next != NULL) {
        if (strcmp(current->next->name, name) == 0) {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp);
            graph->num_nodes--;
            return;
        }
        current = current->next;
    }
}

// Function to print the graph
void print_graph(struct Graph* graph) {
    struct Node* current = graph->head;
    while (current != NULL) {
        printf("%s ", current->name);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->head = NULL;
    graph->num_nodes = 0;

    add_node(graph, "A");
    add_node(graph, "B");
    add_node(graph, "C");
    add_node(graph, "D");

    remove_node(graph, "C");

    print_graph(graph);

    return 0;
}