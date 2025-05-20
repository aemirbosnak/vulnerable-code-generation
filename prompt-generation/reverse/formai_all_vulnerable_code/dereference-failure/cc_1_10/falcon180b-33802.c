//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct node{
    int id;
    int degree;
    int *neighbors;
}Node;

typedef struct edge{
    int src;
    int dest;
    int weight;
}Edge;

int num_nodes;
int num_edges;

Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];

void add_node(int id){
    num_nodes++;
    nodes[num_nodes-1].id = id;
    nodes[num_nodes-1].degree = 0;
    nodes[num_nodes-1].neighbors = (int*)malloc(sizeof(int));
    nodes[num_nodes-1].neighbors[0] = -1;
}

void add_edge(int src, int dest, int weight){
    num_edges++;
    edges[num_edges-1].src = src;
    edges[num_edges-1].dest = dest;
    edges[num_edges-1].weight = weight;
    nodes[src-1].degree++;
    nodes[dest-1].degree++;
    int *temp = (int*)realloc(nodes[src-1].neighbors, sizeof(int)*nodes[src-1].degree);
    nodes[src-1].neighbors = temp;
    temp[nodes[src-1].degree-1] = dest;
}

void print_nodes(){
    for(int i=0; i<num_nodes; i++){
        printf("%d ", nodes[i].id);
    }
}

void print_edges(){
    for(int i=0; i<num_edges; i++){
        printf("%d %d %d\n", edges[i].src, edges[i].dest, edges[i].weight);
    }
}

int main(){
    int num_vertices = 5;
    add_node(1);
    add_node(2);
    add_node(3);
    add_node(4);
    add_node(5);
    add_edge(1, 2, 3);
    add_edge(2, 3, 2);
    add_edge(3, 4, 4);
    add_edge(4, 5, 2);
    add_edge(5, 1, 1);
    print_nodes();
    print_edges();
    return 0;
}