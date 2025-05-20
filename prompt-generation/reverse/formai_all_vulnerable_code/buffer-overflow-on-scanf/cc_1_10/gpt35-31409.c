//FormAI DATASET v1.0 Category: Graph representation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define TRUE 1
#define FALSE 0

// Node structure to maintain adjacency list
struct node {
    int value;
    struct node* next;
};

// Graph structure to store nodes
struct graph {
    struct node* nodes[MAX_NODES];
    int visited[MAX_NODES];
};

// Function to create a new node
struct node* createNode(int val) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value = val;
    new_node->next = NULL;
    return new_node;
}

// Function to add edge to the graph
void addEdge(struct graph* g, int src, int dest) {
    struct node* new_node = createNode(dest);
    new_node->next = g->nodes[src];
    g->nodes[src] = new_node;
}

// Function to print the graph
void printGraph(struct graph* g, int nodes) {
    for(int i = 0; i < nodes; i++) {
        struct node* temp = g->nodes[i];
        printf("%d -> ", i);
        while(temp != NULL) {
            printf("%d -> ", temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Function to DFS Traversal of Graph
void DFS(struct graph* g, int node) {
    g->visited[node] = TRUE;
    printf("%d -> ", node);
    struct node* temp = g->nodes[node];
    while(temp != NULL) {
        int adj_node = temp->value;
        if(g->visited[adj_node] == FALSE) {
            DFS(g, adj_node);
        }
        temp = temp->next;
    }
}

int main() {
    int nodes, edges;
    printf("Enter number of nodes: ");
    scanf("%d", &nodes);
    struct graph* g = (struct graph*)malloc(sizeof(struct graph));
    for(int i = 0; i < nodes; i++) {
        g->nodes[i] = NULL;
        g->visited[i] = FALSE;
    }
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    for(int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter source and dest of edge %d: ", i+1);
        scanf("%d %d", &src, &dest);
        addEdge(g, src, dest);
    }
    printf("The Graph is:\n");
    printGraph(g, nodes);
    printf("DFS Traversal:\n");
    DFS(g, 0);
    return 0;
}