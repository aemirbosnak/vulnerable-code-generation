//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct node{
    int id;
    char name[10];
    struct edge* edges[MAX_EDGES];
} node;

typedef struct edge{
    int weight;
    struct node* start;
    struct node* end;
} edge;

void add_edge(node* start, node* end, int weight){
    edge* new_edge = malloc(sizeof(edge));
    new_edge->start = start;
    new_edge->end = end;
    new_edge->weight = weight;
    start->edges[start->id] = new_edge;
    start->id++;
}

void print_graph(node* nodes[], int num_nodes){
    printf("Printing graph...\n");
    for(int i=0; i<num_nodes; i++){
        printf("%d (%s) -> ", nodes[i]->id, nodes[i]->name);
        for(int j=0; j<nodes[i]->id; j++){
            printf("%s (%d) -> ", nodes[i]->edges[j]->end->name, nodes[i]->edges[j]->weight);
        }
        printf("NULL\n");
    }
}

int main(){
    node* nodes[MAX_NODES];
    int num_nodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    for(int i=0; i<num_nodes; i++){
        nodes[i] = malloc(sizeof(node));
        nodes[i]->id = 0;
        printf("Enter the name of node %d: ", i+1);
        scanf("%s", nodes[i]->name);
    }
    for(int i=0; i<num_nodes; i++){
        int num_edges;
        printf("Enter the number of edges for node %s: ", nodes[i]->name);
        scanf("%d", &num_edges);
        for(int j=0; j<num_edges; j++){
            int end_node_id, weight;
            printf("Enter the end node ID for edge %d (starting from %s): ", j+1, nodes[i]->name);
            scanf("%d", &end_node_id);
            printf("Enter the weight for edge %d (starting from %s and ending at %s): ", j+1, nodes[i]->name, nodes[end_node_id-1]->name);
            scanf("%d", &weight);
            add_edge(nodes[i], nodes[end_node_id-1], weight);
        }
    }
    print_graph(nodes, num_nodes);
    return 0;
}