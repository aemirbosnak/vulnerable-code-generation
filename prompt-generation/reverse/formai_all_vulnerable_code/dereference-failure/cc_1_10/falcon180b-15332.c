//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define MAX_COLORS 7
#define MAX_NODES 1000
#define MAX_EDGES 10000

// Define the structure of a node
typedef struct {
    int id;
    int color;
    int degree;
    bool visited;
    struct node* edges[MAX_EDGES];
} Node;

// Define the structure of an edge
typedef struct {
    int target;
    int weight;
} Edge;

// Initialize the random seed
void init_random_seed() {
    srand(time(NULL));
}

// Generate a random color
int get_random_color() {
    return rand() % MAX_COLORS;
}

// Create a new node with the given ID and color
Node* create_node(int id, int color) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->id = id;
    node->color = color;
    node->degree = 0;
    node->visited = false;
    for (int i = 0; i < MAX_EDGES; i++) {
        node->edges[i] = NULL;
    }
    return node;
}

// Create a new edge from node1 to node2 with the given weight
Edge* create_edge(Node* node1, Node* node2, int weight) {
    Edge* edge = (Edge*) malloc(sizeof(Edge));
    edge->target = node2->id;
    edge->weight = weight;
    node1->edges[node1->degree] = edge;
    node1->degree++;
    return edge;
}

// Connect all nodes in the graph with random edges
void connect_nodes(Node** nodes, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        for (int j = i + 1; j < num_nodes; j++) {
            int weight = rand() % 100 + 1;
            create_edge(nodes[i], nodes[j], weight);
        }
    }
}

// Print the graph in a readable format
void print_graph(Node* node, int color) {
    printf("%d (%d)", node->id, color);
    for (int i = 0; i < node->degree; i++) {
        Edge* edge = node->edges[i];
        printf(" -> %d (%d)", edge->target, edge->weight);
    }
    printf("\n");
}

// Perform a depth-first search on the graph starting from the given node
void dfs(Node* node, int color) {
    node->visited = true;
    printf("%d (%d) visited.\n", node->id, color);
    for (int i = 0; i < node->degree; i++) {
        Edge* edge = node->edges[i];
        Node* target = edge->target;
        if (!target->visited) {
            dfs(target, color);
        }
    }
}

int main() {
    init_random_seed();
    int num_nodes = rand() % MAX_NODES + 1;
    Node** nodes = (Node**) malloc(sizeof(Node*) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        nodes[i] = create_node(i, get_random_color());
    }
    connect_nodes(nodes, num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d:\n", i);
        print_graph(nodes[i], nodes[i]->color);
        dfs(nodes[i], nodes[i]->color);
    }
    return 0;
}